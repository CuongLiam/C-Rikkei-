#include <stdio.h>

int findingUCLN(int a, int b);

int main(void){
	int n,m;
	printf("nhap so nguyen thu 1: ");
	scanf("%d",&n);
	printf("nhap so nguyen thu 2: ");
	scanf("%d",&m);
	
	printf("Uoc chung lon nhat cua hai so la: %d",findingUCLN(n,m));
	
	return 0;
};

int findingUCLN(int a, int b){
	if(a==0 || b==0){
		return 0;
	}
	int min = a<b ? a:b;
	for(int i=min ; i>=1; i--){
		if(a%i ==0 && b%i ==0){
			return i;
		}
	}
	return 1;
};
