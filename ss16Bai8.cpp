#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	char *inputString, *reverseString;
	
	inputString = (char *) malloc(50*sizeof(char));
	reverseString = (char *) malloc(50*sizeof(char));
	
	printf("Nhap chuoi can input: ");
	gets(inputString);
	
	strcpy(reverseString, inputString);
	strrev(reverseString);
	
	printf("Ur input string: %s", inputString);
	printf("\nUr reversed string: %s", reverseString);
	
	
	return 0;
}
