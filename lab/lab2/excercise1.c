#include <stdio.h>

int main()
{
	char userInput[14] = { 'a', 'a', 'b', 'b', 'b', 'b', 'b', 'a', 'c', 'x', 'y', 'b', 'z', 'z'}
	char toCount[6] = {'a' , 'b', 'c', 'x', 'y', 'z'}

	int i;
	int j;
	int A[6];
	int ycount = 0;
	for(i=0; i<6; i++)
	{
		ycount = 0;
		char tc = toCount[i];
		for(j=0; i<14; j++)
		{
			if(userInput[j] == tc){
			      ycount++;
			       


		}

		print("%c occurs %d times\n", tc,count);
		}
	}
}


