#include <stdio.h>
#include <stdlib.h>

int main()
{
	for(int i =0; i<10; i++)
	{
		int x = rand() % 10;
		printf("Rand() = %d \n", x);
	}
}

