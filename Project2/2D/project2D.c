#include <stdio.h>
#include <stdlib.h>

typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
   DIV,
   UNSUPPORTED
} MathOperation;

void IssueBadNumberError()
{
    printf("The string does not represent a floating point number.\n");
    exit(EXIT_FAILURE);
}
void IssueBadOperationError()
{
    printf("The string does not represent a valid operation.\n");
    exit(EXIT_FAILURE);
}

MathOperation GetOperation(char *op)
{
   if(op[1])
	   IssueBadOperationError();
   if(*op == 43)
  	return ADD;
   else if(*op == 'x')
	return MULT;
   else if(*op == 45)
	return SUBTRACT;
   else if(*op == 47)
	return DIV;
   else
	return UNSUPPORTED;
}


double StringToDouble(char *str)
{
	//782
	double num = 0;
	int isNegative = 1;
	int isDecimal = 0;
	int pow = 0;
	//Get length of array
	//For loop till hits null pointer which is end of array
	if (str[0] == '-')
	{
	       isNegative = -1;	
	       str++;
	}
	for(int i=0; str[i] != '\0';i++)
	{
		if(str[i] == '.' & isDecimal != 1)
		{
			isDecimal = 1;
			continue;
		}
		//Convert ASC value to number value
		if( str[i] > '9' || str[i] < '0' || str[i] == '-' || str[i] == '.')
		{ 
			IssueBadNumberError();
		}
		if(isDecimal)
		{
			pow++;
		}
		int x = (str[i] - 48);
		num = (num*10) + x;

	}

	for (int j = 0; j++<pow; num /=10);
		

	return (num * isNegative);

}

int main(int argc, char *argv[])
{
    double v = StringToDouble(argv[1]);
    MathOperation op = GetOperation(argv[2]);
    double v2 = StringToDouble(argv[3]);
    double result = 0.;
	switch (op)
    {
       case ADD:
	       result = v+v2;
         break;
       case SUBTRACT:
       	       result = v-v2;
	 break;
       case MULT:
       	       result = v*v2;
	 break;
       case DIV:
       	       result = v/v2;
	 break;
       case UNSUPPORTED:
	 IssueBadOperationError();
	 break;

    }
    printf("%d\n", (int) result);
 
    return 0;
}
