#include <stdio.h>
#include <string.h>

struct Students{
	char name[25];
	int age;
	char phoneNumber[11];
};

int main(void){
	int n;
	printf("Nhap so hoc sinh muon add: ");
	scanf("%d", &n);
	fflush(stdin);
	struct Students students[n];
	
	for(int i = 0; i<n ; i++){
		printf("Ten Hoc sinh %d: ",i+1);
			fgets(students[i].name, 25, stdin);
			fflush(stdin);
		printf("Tuoi hoc sinh %d: ", i+1);
			scanf("%d", &students[i].age);
			getchar();
		printf("sdt: ");
			fgets(students[i].phoneNumber, 11, stdin);
			fflush(stdin);
	}
	
	for(int i = 0; i<n ; i++){
		printf("\nTen Hoc sinh %d: %s",i+1, students[i].name);
		printf("\nTuoi hoc sinh %d: %d", i+1, students[i].age);	
		printf("\nsdt: %s", students[i].phoneNumber);
	}
	return 0;
}
