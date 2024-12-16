#include <stdio.h>
int main(){
	int n;
	printf("Nhap vao 1 so nguyen : ");
	scanf("%d",&n);
	if(n==0){
		printf("So 0 la so ao");
		return 1;
	}
	
	if(n>0){
		printf("So %d la so duong",n);
	} else {
		printf("So %d la so am",n);
	}
	return 0;
}
