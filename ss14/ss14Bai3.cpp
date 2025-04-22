#include <stdio.h>
#include <string.h>

int main(void){
	char str[] = "Hello my man";
	printf("chuoi truoc khi dao nguoc: %s\n", str);
	
	for(int i=0; i < strlen(str)/2 ; i++){
		int temp = str[i];
		str[i] = str[strlen(str) - i - 1];
		str[strlen(str) - i -1] = temp;
	}
	
	printf("\nchuoi sau khi dao nguoc: %s ", str);
	return 0;
}
