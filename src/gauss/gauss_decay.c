#include <stdio.h>
#include <math.h>
#include "gauss_decay.h"

#define N 3 // Matrix 3x3

int gauss_decay(double A[N][N], double b[N], double x[N]) {
	int i, j, k;

	// 1. Forward Elimination
	for (k = 0; k < N-1; k++) {
		if (fabs(A[k][k]) < 1e-14)
			return 1;

		for (i = k+1; i<N; i++) {
			double factor = A[i][k] / A[k][k];
			for (j = k; j<N; j++) {
				A[i][j] -= factor * A[k][j];
			}
			b[i] -= factor * b[k];
		}
	}

	// 2. Back-Substitution
	for (i = N-1; i >= 0; i--) {
		double sum = 0;
		for (j = i+1; j<N; j++) {
			sum += A[i][j] * x[j];
		}
		x[i] = (b[i] - sum) / A[i][i];
	}
	return 1;
}