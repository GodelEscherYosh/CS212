#include <stdio.h>

int main()
{
	int A[6];
	int *B[6];

	*A = 1;
	*(A+1) = 2;
	*(A+2) = 3;

	printf("B: %d\n", (B));
	printf("A[0]: %d\n", (*A));
	printf("A[1], %d\n", A[1]);
	printf("A[2], %d\n", A[2]);

}

