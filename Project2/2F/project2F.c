#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(char *s)
{
    /* Return the length of string s using the C convention of
     * being terminated by the NULL character. 
     * Do not call any other functions whatsoever.
     * Even my_strlen -- no solutions involving recursion. */
	int len = 0;
	int i =0;
	while(s[i] != '\0'){
		len+= 1;
		i++;
	}
	return len;
}

void str_reverse(char *str)
{
    /* Modify s to be the reverse string.
     * If s is "hello" when the function is called, then it
     * should be "olleh" when the function is completed. 
     * The only function you can call is my_strlen.
     * Do not call malloc.  */
	int len = my_strlen(str);
	for (int i =0; i< len/2; i++)
	{
		char prev = str[i];
		str[i] = str[len -i -1];
		str[len -i -1] = prev;
	}
}

int main()
{
    char *str = malloc(strlen("hello world")+1);
    char *str2 = malloc(strlen("cs 212")+1);
    strcpy(str, "hello world");
    strcpy(str2, "cs 212");
    str_reverse(str);
    str_reverse(str2);
    if (strcmp(str, "dlrow olleh") == 0)
    {
        if (strcmp(str2, "212 sc") == 0)
        {
            printf("Congrats!  You have successfully reversed \"hello world\" to \"%s\"\n", str);
            exit(EXIT_SUCCESS);
        }
    }

    printf("Project does not work yet.  You reversed \"hello world\" to \"%s\" and \"cs 212\" to \"%s\"\n", str, str2);
    exit(EXIT_FAILURE);
}
