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
   if(*op == 43)
  	return ADD;
   else if(*op == 'x')
	return MULT;
   else if(*op == 45)
	return SUBTRACT;
   else
	return UNSUPPORTED;
}

int StringLen(char *str){
	int len = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return len;
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

#define STACK_CAPACITY 100

typedef struct {
    int top;
    double array[STACK_CAPACITY];
} Stack;

Stack* createStack(){
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

void push(Stack *stack, double object){
    double num = stack->top;
    if (num >= STACK_CAPACITY -1)
    {
        printf("Stack is full\n");
        
    }
    else{
    stack->top++;
    stack->array[stack->top] = object;   
    }
}

double pop(Stack *stack){
    if (stack->top >= STACK_CAPACITY -1){
        printf("Stack is full\n");
    }
    else{
    double object = stack->array[stack->top];
    stack->top--;
    return object;
    }

}

int main(int argc, char *argv[])
{
	
	Stack *stack = createStack();
	int length = StringLen(*argv);
	//Mathematical Arguments
	for(int i = 1; i < argc; i++){
		MathOperation op = GetOperation(argv[i]);
		if (op == UNSUPPORTED){
			double v = StringToDouble(argv[i]);
			push(stack, v);
			// printf("Push Stack...(%d) \n", v);
		}
		else{
			double num1 = pop(stack);
			double num2 = pop(stack);
			// printf("Pop Stack...(%d,%d)\n", num1, num2);
			double result = 0.;
			switch (op)
				{
				case ADD:
					result = num1+num2;
					break;
				case SUBTRACT:
						result = num2 - num1;
				break;
				case MULT:
						result = num1*num2;
				break; 
				}
			push(stack, result);
			// printf("Push Stack...(%d) \n", result);
		}
	}


	int final = pop(stack);
	printf("The total is %d\n", final);
	free(stack);

    return 0;
}
