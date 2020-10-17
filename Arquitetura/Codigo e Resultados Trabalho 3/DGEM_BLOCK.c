//Cache blocked version of Double-precision GEneral Matrix Multiply (DGEMM)

#define BLOCKSIZE 32
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
    for (int sj = 0; sj < n; sj += BLOCKSIZE) {
        for (int si = 0; si < n; si += BLOCKSIZE) {
            for (int sk = 0; sk < n; sk += BLOCKSIZE) {
                do_block(n, si, sj, sk, A, B, C);
            }
        }
    }
}
