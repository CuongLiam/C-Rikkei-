#include <stdio.h>
int main(void){
	int a,b,c;
	printf("Nhap canh a : ");
	scanf("%d",&a);
	printf("\nNhap canh b : ");
	scanf("%d",&b);
	printf("\nNhap canh c : ");
	scanf("%d",&c);
	
	if(a+b>c && a+c>b && b+c>a){
		printf("la 3 canh tam giac");
	} else {
		printf("khong phai canh tam giac");
	}
	return 0;
}
