#include <stdio.h>

int sumIs(int *a, int *b, int *sum);
int main(void){
	int a = 10,b = 90,sum=0;
	sumIs(&a, &b, &sum);
	printf("sum la = %d", sum);
	
	return 0;
};
int sumIs(int *a, int *b, int *sum){
	return *sum = *a + *b;
};
