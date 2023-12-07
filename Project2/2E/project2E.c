#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //My approach is to use 5 freads and a moving pointer (from fseek) in order to get array from the binary file
    //This array is of size 25, to store the integers 5 at a time. Let's allocate memory...
    int array[25];

    FILE *inputFile = fopen(argv[1], "rb");
    FILE *outputFile = fopen(argv[2], "w");

    // Read 25 integers in chunks of 5 using 5 fread calls
    // Each time the loop iterates, it moves the file pointer to a different position in the file
    for (int i = 0; i < 5; i++) {
        fseek(inputFile, i*10*sizeof(int), SEEK_SET);
        fread(&array[i*5], sizeof(int), 5, inputFile);
    }

    for(int j = 0; j<25; j++){
	    printf("%d\n", array[j]);
	}
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
