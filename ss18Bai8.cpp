#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

struct Students{
	int id;
	char name[25];
	int age;
	char phoneNumber[12];
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
	
	printf("Truoc khi chen:\n");
	for(int i = 0; i<n ; i++){
		printf("\nid: %d", students[i].id);
		printf("\nTen Hoc sinh %d: %s",i+1, students[i].name);
		printf("\nTuoi hoc sinh %d: %d", i+1, students[i].age);	
		printf("\nsdt: %s", students[i].phoneNumber);
	}
	printf("\n==================\n");
	
	int insertPosition;
	printf("\nNhap vi tri ban muon chen(ID 1 - %d)", students[n-1].id);
	scanf("%d", &insertPosition);
	insertPosition--;
	
	int flag =0;
	for(int i=0; i<n; i++){
		if(insertPosition == students[i].id){
			flag = 1;
		}
	}
	if(flag ==0){
		printf("ID khong hop le");
		return 1;
	}
	
	for(int i = n; i >= insertPosition; i--) {
    students[i] = students[i - 1];
    students[i].id = i + 1;
    }
    
	for(int i = n ; i> insertPosition; i--){
		students[i].age = students[i-1].age;
		strcpy(students[i].name, students[i-1].name);
		strcpy(students[i].phoneNumber, students[i-1].phoneNumber);
	}
	
	//them gia tri
	fflush(stdin);
	students[insertPosition].id = insertPosition+1 ;
	printf("Ten Hoc sinh %d: ", insertPosition+1);
		fgets(students[insertPosition].name, 25, stdin);
		fflush(stdin);
	printf("Tuoi hoc sinh %d: ", insertPosition+1);
		scanf("%d", &students[insertPosition].age);
		getchar();
	printf("sdt: ");
		fgets(students[insertPosition].phoneNumber, 11, stdin);
		fflush(stdin);
	
	n++;	
	printf("\n==================\n");
	printf("\nsau khi chen:\n");
	for(int i = 0; i<n ; i++){
		printf("\nid: %d", students[i].id);
		printf("\nTen Hoc sinh %d: %s",i+1, students[i].name);
		printf("\nTuoi hoc sinh %d: %d", i+1, students[i].age);	
		printf("\nsdt: %s", students[i].phoneNumber);
	}
	
	
	return 0;
}
