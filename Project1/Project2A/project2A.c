#include <stdio.h>

int main()
{
	int i;
	int j;
	int factors;
	int number;
	for (i = 2; i < 1000 ; i++)
	{
		number = i;
		factors = 0;
	
		for (j = 2; j < i-1; j++)
		{
			if (number % j == 0)
			{
				factors += 1;
				while (number % j == 0)
				{
					number = number/j;
				}
				
			}
		
		}

		
		if (factors == 3)
		{
			printf("%d has three factors\n", i );
		}

	}
}
		
