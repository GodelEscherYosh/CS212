#include <stdio.h>

int main()
{
    int i;
    int A[21];
    int *B[3];

    A[0] = 0;
    A[1] = 1;
    A[2] = 1;
    for (i = 3 ; i < 21 ; i++)
        A[i] = A[i-3]+A[i-2]+A[i-1];

    for (i = 0 ; i < 21 ; i++)
        printf("%d: %d\n", i, A[i]);

    B[0] = A;
    B[1] = A+7;
    B[2] = A+14;

    
    printf("Solution: %d\n", A[2] );
    
	  }
