#include <stdio.h>
int factorial(int a);

int main(){
	int n;
	printf("nhap so nguyen n ");
	scanf("%d",&n);
	
	if(n<0){
		printf("ko tinh giai thua cho so am\n");
	} else{
		int answer = factorial(n);
		printf("%d! = %d",n,answer);
	}
	return 0;
};

int factorial(int a){
	int result = 1;
	for(int i=1; i<=a; i++){
		result *= i;
	}
	return result;
};
