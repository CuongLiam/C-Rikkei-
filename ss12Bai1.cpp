#include <stdio.h>

int sum(int a, int b);
int main(void){
	int a,b;
	printf("Nhap 2 so nguyen: ");
	scanf("%d%d",&a,&b);
	
	int result = sum(a,b);
	
	printf("tong la %d",result);
	return 0;
};

int sum(int a, int b){
	return a+b;
};
