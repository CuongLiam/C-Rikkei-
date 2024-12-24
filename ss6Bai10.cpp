#include <stdio.h>
int main(void){
	int n;
	scanf("%d",&n);
	
	if(n<2){
		printf("%d k phai la so nguyen to",n);
		return 1;
	}
	int flag = 1;
	for(int i = 2 ; i*i<=n; i++){
		if(n%i==0){
			flag = 0 ;
			break;
		}
	}
	if(flag){
		printf("%d la so nguyen to",n);
	} else{
		printf("%d k phai so nguyen to",n);
	}
	
	return 0;
}
