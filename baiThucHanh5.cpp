#include <stdio.h>
#include <math.h>
int main(){
	int n,m,i;
	printf("Nhap 1 so nguyen duong : ");
	scanf("%d",&n);
	
	if(n<=1){
		printf("%d khong phai la so nguyen to",n);
		return 1;
	}
	m = 1;
	for (i=2;i<sqrt(n);i++){
		if(n%i==0){
			m = 0;
			break;
		}
	}
	
	if(m==1){
		printf("%d la so nguyen to",n);
	} else {
		printf("%d ko phai la so nguyen to",n);
	}
	return 0;
}
