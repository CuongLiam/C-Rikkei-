#include <stdio.h>
int main(){
	int n;
	printf("Nhap so nam : ");
	scanf("%d",&n);
	
	if((n%4==0 && n%100!=0) || (n%400==0)){
		printf("%d la nam nhuan ",n);
	} else{
		printf("%d ko phai nam nhuan",n);
	}
	return 0;
		
}
