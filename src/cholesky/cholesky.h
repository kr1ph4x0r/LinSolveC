#ifndef CHOLESKY_H
#define CHOLESKY_H

#define N 3

int cholesky_decay(double A[N][N], double L[N][N]);

void forward_subs(double L[N][N], double b[N], double y[N]);

void backward_subs(double L[N][N], double y[N], double x[N]);

#endif