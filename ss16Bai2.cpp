#include <stdio.h>

void swap(int *a, int *b);
int main(void){
	int a = 10,b = 90;
	
	printf("Truoc khi doi : a = %d , b = %d", a, b);
	swap(&a,&b);
	printf("\nSau khi doi : a = %d , b = %d", a, b);
	
	return 0;
};
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
};
