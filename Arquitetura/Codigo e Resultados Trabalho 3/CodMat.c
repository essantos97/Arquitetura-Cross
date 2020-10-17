#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define BLOCKSIZE 64
#define NUM_LINHAS 1920
#define NUM_COLUNAS 1920



double* aloca_Matrizes(int num_Linhas, int num_Colunas){
    double *M;
    M = malloc(num_Linhas * num_Colunas * sizeof(double));
    for(int i = 0; i < num_Linhas; i++){
            for(int j = 0; j < num_Colunas; j++){
                    M[(i*num_Colunas) + j] = 1;
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
    struct timeval start, stop;
    double valorIni, valorFim, resultado;

    gettimeofday(&start, NULL);
    for (int sj = 0; sj < n; sj += BLOCKSIZE) {
        for (int si = 0; si < n; si += BLOCKSIZE) {
            for (int sk = 0; sk < n; sk += BLOCKSIZE) {
                do_block(n, si, sj, sk, A, B, C);
            }
        }
    }
    gettimeofday(&stop, NULL);

    valorIni = (start.tv_sec + (((double) start.tv_usec) /1000000));
    valorFim = (stop.tv_sec +(((double) stop.tv_usec) /1000000));
    resultado = valorFim - valorIni;
    escreve_Tempo(resultado);

}
double* dgemm (size_t n, double* A, double* B, double* C) {
    struct timeval start, stop;
    double valorIni, valorFim, resultado;

    gettimeofday(&start, NULL);
    for (size_t i = 0; i < n; ++i) {
        for(size_t j = 0; j < n; ++j) {
            double cij = 0;
            for (size_t k=0; k < n; k++) {
                cij += A[i+k*n] * B[k+j*n]; /*cij +=A[i][k]*B[k][j]*/
            }
            C[i+j*n] = cij; /* C[i][j] = cij*/
        }
    }

    gettimeofday(&stop, NULL);
    valorIni = (start.tv_sec + (((double) start.tv_usec) /1000000));
    valorFim = (stop.tv_sec +(((double) stop.tv_usec) /1000000));
    resultado = valorFim - valorIni;
    escreve_Tempo(resultado);
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
    double *matriz;
    double *matrizB;
    double *matrizC;
    int subMatriz = 64;

    printf("main\n");

    /*As linhas abaixo devem ser descomentadas para inicializar
    a matriz que será usada no restante do código*/

    //matriz = aloca_Matrizes(NUM_LINHAS, NUM_COLUNAS);
    //matrizB = aloca_Matrizes(NUM_LINHAS, NUM_COLUNAS);
    //matrizC = aloca_Matrizes(NUM_LINHAS, NUM_COLUNAS);
    matriz = aloca_Matrizes(subMatriz, subMatriz);
    matrizB = aloca_Matrizes(subMatriz, subMatriz);
    matrizC = aloca_Matrizes(subMatriz, subMatriz);

    //preenche_Matrizes(matriz, NUM_LINHAS, NUM_COLUNAS);
    //escreve_Conteudo(NUM_LINHAS, NUM_COLUNAS, matriz);
    //libera_Matrizes(matriz);

    /*Esta linha acima deve ser utilizada apenas
    para iniciar a matriz principal*/


    /*Método de multiplicação de matrizes*/

    //matriz = carregando_Conteudo(subMatriz, subMatriz);
    //matrizB = carregando_Conteudo(subMatriz, subMatriz);
    //matrizC = dgemm(subMatriz, matriz, matrizB, matrizC);

    /*Método de multiplicação de matrizes block*/

    matriz = carregando_Conteudo(subMatriz, subMatriz);
    matrizB = carregando_Conteudo(subMatriz, subMatriz);
    dgemm_blocked(subMatriz, matriz, matrizB, matrizC);

    escreve_Resultado(subMatriz,subMatriz, matrizC);
    libera_Matrizes(matriz);
    libera_Matrizes(matrizB);
    libera_Matrizes(matrizC);


}
