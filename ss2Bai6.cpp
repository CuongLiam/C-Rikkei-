#include <stdio.h>
int main(){
	float Pi = 3.14;
	int a;
	printf("Nhap ban kinh hinh tron : ");
	scanf("%d",&a);
	
	printf("\nChu vi hinh tron la : %f",(float)2*Pi*a);
	printf("\nDien tich hinh tron la : %f",(float)Pi*a*a);
	
	return 0;
}
