#include "gauss/gauss_decay.h"
#include <stdio.h>

int main(void) {
    // 3x3 Matrix
	double A[N][N] = {
		{2, 3, -1},
		{4, 4, -3},
		{-2, 3, 2}
	};

    // Result of the equation
	double b[N] = {5, 3, 7};
    
    // Unknow vector
	double x[N];

	gauss_decay(A, b, x);

	for (int i=0; i<N; i++)
		printf("x%d = %.5f\n", i+1, x[i]);

	return 0;
}