#include <stdio.h>
#include <string.h>
#define max 50

int main(void){
	char str[max];
	printf("pls input a string ");
	fgets(str, max, stdin);
		
	printf("\nchuoi vua nhap la :");
	printf("%s",str);
	
	return 0;
}
