#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

struct Students{
	int id;
	char name[25];
	int age;
	char phoneNumber[11];
};

int main(void){
	system("color 3");
	struct Students students[50]; //ten: students
	int n;
	printf("Nhap so hoc sinh muon add: ");
	scanf("%d", &n);
	fflush(stdin);
	
	for(int i = 0; i<n ; i++){
		students[i].id = i+1;
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
	
	printf("Truoc khi them:\n");
	for(int i = 0; i<n ; i++){
		printf("\nid: %d", students[i].id);
		printf("\nTen Hoc sinh %d: %s",i+1, students[i].name);
		printf("\nTuoi hoc sinh %d: %d", i+1, students[i].age);	
		printf("\nsdt: %s", students[i].phoneNumber);
	}
	
	printf("\n moi ban them 1 sinh vien: \n");
	
	students[n].id = n+1;
		printf("Ten Hoc sinh %d: ",n+1);
			fgets(students[n].name, 25, stdin);
			fflush(stdin);
		printf("Tuoi hoc sinh %d: ", n+1);
			scanf("%d", &students[n].age);
			getchar();
		printf("sdt: ");
			fgets(students[n].phoneNumber, 11, stdin);
			fflush(stdin);
	n++;
	
	printf("\n==================\n");
	printf("\nsau khi chinh sua:\n");
	for(int i = 0; i<n ; i++){
		printf("\nid: %d", students[i].id);
		printf("\nTen Hoc sinh %d: %s",i+1, students[i].name);
		printf("\nTuoi hoc sinh %d: %d", i+1, students[i].age);	
		printf("\nsdt: %s", students[i].phoneNumber);
	}
	
	
	return 0;
}
