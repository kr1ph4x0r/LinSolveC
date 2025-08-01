#include <stdio.h>
#include <math.h>
#include "cholesky.h"

#define N 3

int cholesky_decay(double A[N][N], double L[N][N]) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<=i; j++) {
			double sum = 0;
			for (int k=0; k<j; k++)
				sum += L[i][k] * L[j][k];
			if (i == j) {
				double val = A[i][i] - sum;
				if (val <= 0) return 1;
				L[i][j] = sqrt(val);
			} else {
				L[i][j] = (1.0 / L[j][j]) * (A[i][j] - sum);
			}
		}
		for (int j = i+1; j<N; j++)
			L[i][j] = 0;
	}
	return 0;
}

void forward_subs(double L[N][N], double b[N], double y[N]) {
	for (int i=0; i<N; i++) {
		double sum = 0;
		for (int j = 0; j<i; j++)
			sum += L[i][j] * y[j];
		y[i] = (b[i] - sum) / L[i][i];
	}
}

void backward_subs(double L[N][N], double y[N], double x[N]) {
	for (int i = N-1; i>=0; i--) {
		double sum = 0;
		for (int j = i+1; j<N; j++)
			sum += L[j][i] * x[j];
		x[i] = (y[i] - sum) / L[i][i];
	}
}