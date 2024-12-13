#include <stdio.h>
int main(){
	int n;
	printf("Nhap so nguyen duong n: ");
	scanf("%d",&n);
	printf("Cac uoc cua %d = ",n);
	for(int m=1;m<n;m++){
		if(n%m==0){
		printf(" %d",m);
		}
	}
	return 0;
}
