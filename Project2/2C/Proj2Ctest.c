#include <stdio.h>

int main()
{
	int *A=0x8000;
	int *B[3]= {A, A+7, A+14};

	printf("A[2], %d\n", A[2]);
}i

