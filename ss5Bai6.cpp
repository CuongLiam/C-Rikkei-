#include <stdio.h>
int main(void){
	int a,b;
	printf("Nhap 2 so bat ki ");
	scanf("%d %d",&a,&b);
	
	printf("\ncalculator");
	printf("\n1. Tong 2 so");
	printf("\n2. Hieu 2 so");
	printf("\n3. Tich 2 so");
	printf("\n4. Thuong 2 so");
	printf("\n5. Thoat 2 so");
	printf("\n Lua chon cua ban ");
	int choice;
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			printf("Tong hai so la %d",a+b);
			break;
		case 2:
			printf("Hieu hai so la %d hoac %d",a-b,b-a);
			break;
		case 3:
			printf("Tich hai so la %d",a*b);
			break;
		case 4:
			printf("Thuong hai so la %d hoac %d",a/b,b/a);
			break;
		case 5:
			printf("Thoat thanh cong");
			break;
		default:
			printf("Gia tri khong hop le");
			break;
	}
	
	return 0;
}
