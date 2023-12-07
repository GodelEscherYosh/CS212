#include <stdio.h>
#include <string.h>
// Function to concatenate two strings
void concatStrings(char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    strcpy(str1 + len1, str2);
}
int main() {
    char first_string[40] = "CS 212 Discussion Section! ";
    char second_string[] = "Hello! How are you?";
    int i = 5;
    // Concatenate the strings
    concatStrings(first_string, second_string);
    while(i>0)
    {
        printf("%s\n",first_string);
        i--;
    }
}
