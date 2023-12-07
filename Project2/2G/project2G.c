#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int SearchForWord(char *txt, char *searchWord)
{
	int count = 0;
	int len;
	len = strlen(txt);
	int wordLen = strlen(searchWord);

	for (int j = 0; j <= len - wordLen; j++)
	{
		if(strncmp(txt+j, searchWord, wordLen) == 0){
			//Check for unique word
			if((j == 0 || !isalnum(txt[j-1])) && (j+ wordLen == len || !isalnum(txt[j+wordLen]))){

			count += 1;
			}
		}
	}

	return count;
}

int main(int argc,char *argv[]) {

	FILE *inputFile = fopen(argv[1], "rb");

	//Error handling
	if (argc < 3) 
	{
		printf("Usage: %s <filename> <word1> <word2> ...\n", argv[0]);
		return 1;
	}
	if (inputFile == NULL){
		return 1;
	}

		
   	// Determine the size of the file
    	fseek(inputFile, 0, SEEK_END);
    	long file_size = ftell(inputFile);
    	rewind(inputFile);

	//Allocate dynamic memory
    	char *words = (char *)malloc(file_size + 1);
	fread(words, 1, file_size, inputFile);	
	words[file_size] = '\0';

	for(int i = 2; i< (argc); i++)
	{
		int num = SearchForWord(words,argv[i]);
	       	printf("The word \"%s\" occurs %d times.\n", argv[i], num);	
	}

	

	free(words);
	fclose(inputFile);
	return 0;
}
