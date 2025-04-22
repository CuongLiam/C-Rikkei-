#include <stdio.h>
int main(void){
	int n;
	printf("Nhap so nguyen duong (1-10) : ");
	scanf("%d",&n);
	
	printf("Bang cuu chuong cua so %d\n",n);
	for(int i =1; i<=10; i++){
		printf("%d * %d = %d\n",n,i,n*i);
	}
	
	return 0;
}
