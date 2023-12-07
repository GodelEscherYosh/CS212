#include <stdio.h>

int main() 
{
	int i;

	for ( i = 0; i <  101; i++) 
	{
		if ( i % 3 == 0 )
		{
			printf("Fizz");
		}
		else if ( i % 5 == 0) 
		{
			printf("Buzz");
		}
		else
		{
			printf("%d \n", i);
		}
	}
}

	
