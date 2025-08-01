#ifndef LU_DECAY_H
#define LU_DECAY_H

#define N 3

int lu_decay(double A[N][N]);

void forward_subs(double A[N][N], double b[N], double x[N]);

void backward_subs(double A[N][N], double y[N], double x[N]);

#endif