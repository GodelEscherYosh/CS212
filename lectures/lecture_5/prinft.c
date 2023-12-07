#include <stdio.h>

void print_char(char c)
{
	printf("%c", c);
	}


void print_string(char *s)
{
	int i;
	for(i=0; i<12; i++){
		print_char[s[i]];
}

int main()
{
	char A[12] = "hello world";
	print_string("%s", A);


}

