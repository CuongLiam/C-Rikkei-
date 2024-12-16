#include <stdio.h>
int main(){
	int n;
	printf("Nhap vao 1 so nguyen : ");
	scanf("%d",&n);
	
	if(n%2==0){
		printf("\n%d la so chan",n);
	} else{
		printf("\n%d la so le",n);
	}
	return 0;
}
