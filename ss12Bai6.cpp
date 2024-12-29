#include <stdio.h>

int isPerfect(int a);

int main(void){
	int n1,n2;
	printf("nhap so nguyen thu 1: ");
	scanf("%d",&n1);
	printf("\nnhap so nguyen thu 2: ");
	scanf("%d",&n2);	

	if(isPerfect(n1)){
		printf("\n%d la so hoan hao",n1);
	} else{
		printf("\n%d ko la so hoan hao",n1);
	}
	
	if(isPerfect(n2)){
		printf("\n%d la so hoan hao",n2);
	} else{
		printf("\n%d ko la so hoan hao",n2);
	}
	return 0;
};

int isPerfect(int a){
	if(a<=0){
		return 0;
	}
	int sum =0;
	for(int i=1 ; i<=a/2; i++){
		if(a % i == 0){
			sum += i;
		}
	}
	return sum==a;
};
