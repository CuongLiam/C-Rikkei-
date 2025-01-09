#include <stdio.h>
#include <string.h>

struct Students{
	char name[25];
	int age;
	char phoneNumber[11];
};

int main(void){
	struct Students A;
	strcpy(A.name, "Nguyen Van A");
	A.age = 18;
	strcpy(A.phoneNumber, "0987654321");
	
	printf("Ten: %s", A.name);
	printf("\nTuoi: %d", A.age);
	printf("\nsdt: %s", A.phoneNumber);
	
	return 0;
}
