#include <stdio.h>

int isPrime(int a);

int main(void){
	int n1,n2;
	printf("nhap so nguyen thu 1: ");
	scanf("%d",&n1);
	printf("\nnhap so nguyen thu 2: ");
	scanf("%d",&n2);	

	if(isPrime(n1)){
		printf("\n%d la so nguyen to",n1);
	} else{
		printf("\n%d ko la so nguyen to",n1);
	}
	
	if(isPrime(n2)){
		printf("\n%d la so nguyen to",n2);
	} else{
		printf("\n%d ko la so nguyen to",n2);
	}
	return 0;
};

int isPrime(int a){
	if(a<2){
		return 0;
	}
	for(int i=2; i*i<=a; i++){
		if(a % i == 0){
			return 0;
		}
	}
	return 1;
};
