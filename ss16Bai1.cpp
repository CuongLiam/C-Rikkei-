#include <stdio.h>

int main(void){
	int a=10, *ptr = &a;
	
	printf("C1: Dia chi bien a la %p", &a);
	printf("\nC1: Gia tri bien a la %d", a);
	
	printf("\n\nC2: Dia chi bien a la %p", ptr);
	printf("\nC2: Gia tri bien a la %d", *ptr);
	return 0;
}
