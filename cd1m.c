#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMMAT 1920
#define BLOCKSIZE 32
#define NUM_LINHAS 1920
#define NUM_COLUNAS 1920



//void preenche_matriz(int mat[][TAMMAT]){
//
//    int num;
//    int i, j;
//
//    srand(time(NULL));
//
//    for(i=0; i<TAMMAT; i++){
//        for(j=0; j<TAMMAT; j++){
//            num = (rand() % 90) + 10;
//            mat[i][j] = num;
//        }
//    }
//}
//void preenchendo_matriz(double **mat){
//
//    double num;
//
//    srand(time(NULL));
//
//    for(int i=0; i<TAMMAT; i++){
//        for(int j=0; j<TAMMAT; j++){
//            //num = (rand() % 90) + 10;
//            num = ((double)(rand())/(double)(RAND_MAX)*90.0) +10.0;
//            mat[i][j] = num;
//        }
//    }
//}
//void escrevendo_arq(double **mat){
//    double valor;
//    FILE *arq;
//    arq = fopen("matriz.txt","a");
//
//    for(int i=0; i<TAMMAT; i++){
//        for(int j=0; j<TAMMAT; j++){
//            valor = mat[i][j];
//            fprintf(arq, "%f", valor);
//        }
//        fprintf(arq,"\n");
//    }
//
//    fclose(arq);
//
//}
//void escreve_arq(int mat[][TAMMAT]){
//    int i, j, valor;
//    FILE *arq;
//    arq = fopen("matriz.txt","a");
//
//    for(i=0; i<TAMMAT; i++){
//        for(j=0; j<TAMMAT; j++){
//            valor = mat[i][j];
//            fprintf(arq, "%f ", valor);
//        }
//        fprintf(arq,"\n");
//    }
//
//    fclose(arq);
//
//}
//double **aloca_Matriz(int tam){
//    double **M;
//    M = (double **)malloc(tam*sizeof(double*));
//    for(int i = 0; i < tam; i++){
//        M[i]= (double*)malloc(tam*(sizeof(double)));
//    }
//    return M;
//}
//void libera(double **mat){
//    for (int i=0; i<TAMMAT; i++){
//        free (mat[i]);
//    }
//    free (mat);
//}
//void carregando(int tam){
//    double **matt;
//    double valor;
//
//    matt = aloca_Matriz(tam);
//    FILE *arqv;
//    arqv = fopen("matriz.txt","r");
//    if(arqv == NULL)
//        return 0;
//    for(int i=0; i<tam; i++){
//        for(int j=0; j<tam; j++){
//            fscanf(arqv,"%lf",&valor);
//            matt[i][j]= valor;
//            //printf("%lf", valor);
//        }
//    }
//
//    fclose(arqv);
//
//}

double* aloca_Matrizes(int num_Linhas, int num_Colunas){
    double *M;
    M = malloc(num_Linhas * num_Colunas * sizeof(double));
    for(int i = 0; i < num_Linhas; i++){
            for(int j = 0; j < num_Colunas; j++){
                    M[(i*num_Colunas) + j] = 0;
            }
    }
    return M;
}
void preenche_Matrizes(double *mat, int nLinhas, int nColunas){

    double num;

    srand(time(NULL));

    for(int i=0; i<nLinhas; i++){
        for(int j=0; j<nColunas; j++){
            num = ((double)(rand())/(double)(RAND_MAX)*90.0) +10.0;
            mat[(i*nColunas) + j] = num;
        }
    }

}
void libera_Matrizes(double *mat){
    free(mat);
}
double* carregando_Conteudo(int nLinhas, int nColunas){
    double *mat = 0;
    double valor;

    mat = aloca_Matrizes(nLinhas, nColunas);
    FILE *arqv;
    arqv = fopen("matriz.txt","r");
    if(arqv == NULL)
        return 0;
    for(int i=0; i<nLinhas; i++){
        for(int j=0; j<nColunas; j++){
            fscanf(arqv,"%lf",&valor);
            mat[(i*nColunas) + j] = valor;
            //printf("%f", valor);
        }
    }
    return mat;

    fclose(arqv);

}

void escreve_Conteudo(int nLinhas, int nColunas, double *mat){
    double valor;
    FILE *arq;
    arq = fopen("matriz.txt","a");

    for(int i=0; i<nLinhas; i++){
        for(int j=0; j<nColunas; j++){
            valor = mat[(i*nColunas) + j];
            fprintf(arq, "%f ", valor);
        }
        fprintf(arq,"\n");
    }

    fclose(arq);

}

void escreve_Tempo(double tempo){

    FILE *arq;
    arq = fopen("tempos.txt","a");
    fprintf(arq, "%lf \n", tempo);

    fclose(arq);
}
void do_block (int n, int si, int sj, int sk, double *A, double *B, double *C) {
    for (int i = si; i < si+BLOCKSIZE; ++i) {
        for (int j = sj; j < sj+BLOCKSIZE; ++j) {
            double cij = 0;
            for(int k = sk; k < sk+BLOCKSIZE; k++) {
                cij += A[i+k*n] * B[k+j*n]; /* cij +=A[i][k]*B[k][j] */
            }
            C[i+j*n] = cij; /* C[i][j] = cij */
        }
    }
}

void dgemm_blocked (size_t n, double* A, double* B, double* C) {
    clock_t t;
    t = clock();
    for (int sj = 0; sj < n; sj += BLOCKSIZE) {
        for (int si = 0; si < n; si += BLOCKSIZE) {
            for (int sk = 0; sk < n; sk += BLOCKSIZE) {
                do_block(n, si, sj, sk, A, B, C);
            }
        }
    }
    t = clock()-t;
    escreve_Tempo((((double)t)/((CLOCKS_PER_SEC/1000))));

}
double* dgemm (size_t n, double* A, double* B, double* C) {
    clock_t t;
    t = clock();
    for (size_t i = 0; i < n; ++i) {
        for(size_t j = 0; j < n; ++j) {
            double cij = 0;
            for (size_t k=0; k < n; k++) {
                cij += A[i+k*n] * B[k+j*n]; /*cij +=A[i][k]*B[k][j]*/
            }
            C[i+j*n] = cij; /* C[i][j] = cij*/
        }
    }

    t = clock()-t;
    escreve_Tempo((((double)t)/((CLOCKS_PER_SEC/1000))));
    return C;
}
void escreve_Resultado(int nLinhas, int nColunas, double *mat){
    double valor;
    FILE *arq;
    arq = fopen("matrizResult64.txt","a");

    for(int i=0; i<nLinhas; i++){
        for(int j=0; j<nColunas; j++){
            valor = mat[(i*nColunas) + j];
            fprintf(arq, "%f ", valor);
        }
        fprintf(arq,"\n");
    }
    fclose(arq);
}


int main(int argc, char *argv[]){
    clock_t temp_ini, temp_fim, temp_total;
    double *matriz;
    double *matrizB;
    double *matrizC;
    int subMatriz = 64;

    printf("main\n");

    matriz = aloca_Matrizes(NUM_LINHAS, NUM_COLUNAS);
    matrizB = aloca_Matrizes(NUM_LINHAS, NUM_COLUNAS);
    matrizC = aloca_Matrizes(NUM_LINHAS, NUM_COLUNAS);
    printf("main2\n");
    //preenche_Matrizes(matriz, NUM_LINHAS, NUM_COLUNAS);
    printf("main3\n");
    //escreve_Conteudo(NUM_LINHAS, NUM_COLUNAS, matriz);
    printf("main4\n");
    //libera_Matrizes(matriz);
    printf("main5\n");

    /*Método de multiplicação de matrizes*/

    matriz = carregando_Conteudo(subMatriz, subMatriz);
    matrizB = carregando_Conteudo(subMatriz, subMatriz);
    matrizC = dgemm(subMatriz, matriz, matrizB, matrizC);

    /*Método de multiplicação de matrizes block*/

    //matriz = carregando_Conteudo(subMatriz, subMatriz);
    //matrizB = carregando_Conteudo(subMatriz, subMatriz);
    //matrizC = dgemm(subMatriz, matriz, matrizB, matrizC);

    escreve_Resultado(subMatriz,subMatriz, matrizC);
    libera_Matrizes(matriz);
    libera_Matrizes(matrizB);
    libera_Matrizes(matrizC);


}
