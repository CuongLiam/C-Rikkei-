#include <stdio.h>

int main(){
	int n,g,passWord=0,correct=1469;
	
	while(passWord == 0){
		printf("Nhap mat khau(so nguyen) : ");
		scanf("%d",&n);
		if(n==correct){
			passWord = 1;
		}
	}
	printf("access accepted");
	return 0;
}
