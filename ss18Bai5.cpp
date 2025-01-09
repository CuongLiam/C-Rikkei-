#include <stdio.h>
#include <string.h>
#define max 50

struct Students{
	int id;
	char name[25];
	int age;
	char phoneNumber[11];
};

int main(void){
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
	
	printf("Truoc khi chinh sua:\n");
	for(int i = 0; i<n ; i++){
		printf("\nid: %d", students[i].id);
		printf("\nTen Hoc sinh %d: %s",i+1, students[i].name);
		printf("\nTuoi hoc sinh %d: %d", i+1, students[i].age);	
		printf("\nsdt: %s", students[i].phoneNumber);
	}
	
	int editID;
	printf("\nNhap ID can chinh sua: ");
	scanf("%d", &editID);
	
	
	int flag=0;
	for(int i=0; i<n; i++){
		if(editID == students[i].id){
			flag=1;
		}
	}
	
	int choice;
	if(flag){
		printf("Nhap gia tri can sua: ");
		printf("\n1.ten: ");
		printf("\n2.tuoi: ");
		printf("\n3.sdt: \n");
		scanf("%d", &choice);
		fflush(stdin);
	}else{
		printf("ID ko hop le, tam biet");
		return 0;
	}
	
	char editValue[max];
	int editAge;
	switch(choice){
		case 1:{
			printf("\nBan muon sua %s lai thanh la: ", students[editID-1].name);
			fgets(editValue, max, stdin);
			fflush(stdin);
			strcpy(students[editID-1].name, editValue);
			
			printf("\nSua thanh cong !\n");
			
			break;
		}
		case 2:{
			printf("\nBan muon sua %d lai thanh la: ", students[editID-1].age);
			scanf("%d", &editAge);
			fflush(stdin);
			students[editID-1].age = editAge;
			
			printf("\nSua thanh cong !\n");
			break;
		}
		case 3:{
			printf("\nBan muon sua %s lai thanh la: ", students[editID-1].phoneNumber);
			fgets(editValue, max, stdin);
			fflush(stdin);
			strcpy(students[editID-1].phoneNumber, editValue);
			
			printf("\nSua thanh cong !\n");
			break;
		}
		
	}
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
