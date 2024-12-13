#include <stdio.h>
int main(){
	int n;
	printf("Nhap so nguyen duong n :");
	scanf("%d",&n);
	
	if(n<2){
		printf("%d khong phai la so nguyen to ");
		return 1;
	}
	
	printf("%d so nguyen to dau tien la ",n);
	int count,check;
	count = 0; check = 2;
	while(count<n){
		int isPrime = 1;
		for(int i =2 ; i*i <= check ; i++){
			if(check%i==0){
				isPrime = 0;
				break;
			}
		}
		if(isPrime == 1){
			printf("%d ",check);
			count++;
		}
		check++;
	}
	return 0;
}
