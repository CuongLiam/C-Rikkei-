#include <stdio.h>

int main(void){
	char str[] = "mama mia";
	
	for(int i=0; str[i] != '\0'; i++){
		printf("%c ", str[i]);
	}
	
	return 0;
}
