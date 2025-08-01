#include <stdio.h>
#include <stdint.h>
#include "lu_decay.h"

#define N 3

int lu_decay(double A[N][N]) {
	int i, j, k;
	for (k = 0; k<N; k++) {
		if (fabs(A[k][k]) < 1e-14)
			return 1;
		for (i = k+1; i<N; i++) {
			A[i][k] /= A[k][k];
			for (j = k+1; j<N; j++) {
				A[i][j] -= A[i][j] * A[k][j];
			}
		}
	}
	return 0;
}

void forward_subs(double A[N][N], double b[N], double y[N]) {
	for (int i = 0; i<N; i++) {
		double sum = 0;
		for (int j = 0; j<i; j++)
			sum += A[i][j] * y[j];
		y[i] = b[i] - sum;
	}
}

void backward_subs(double A[N][N], double y[N], double x[N]) {
    for (int i=N-1; i>=0; i--) {
        double sum = 0;
        for (int j = i+1; j<N; j++)
        	sum += A[i][j] * x[j];
        x[i] = (y[i] - sum) / A[i][i];
    }
}