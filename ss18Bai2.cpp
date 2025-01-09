#include <stdio.h>
#include <string.h>

struct Students{
	char name[25];
	int age;
	char phoneNumber[11];
};

int main(void){
	struct Students A;
	
	printf("Hoc sinh A\nVui long nhap ten: ");
	fgets(A.name, 25, stdin);
	fflush(stdin);
	printf("Nhap tuoi: ");
	scanf("%d", &A.age);
	fflush(stdin);
	printf("Nhap sdt: ");
	fgets(A.phoneNumber, 11, stdin);
	
	printf("\nTen: %s", A.name);
	printf("Tuoi: %d", A.age);
	printf("\nsdt: %s", A.phoneNumber);
	
	return 0;
}
