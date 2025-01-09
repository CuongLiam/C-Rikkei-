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
	
	printf("Truoc khi xoa:\n");
	for(int i = 0; i<n ; i++){
		printf("\nid: %d", students[i].id);
		printf("\nTen Hoc sinh %d: %s",i+1, students[i].name);
		printf("\nTuoi hoc sinh %d: %d", i+1, students[i].age);	
		printf("\nsdt: %s", students[i].phoneNumber);
	}
	printf("\n==================\n");
	
	fflush(stdin);
	char removeStu[max];
	printf("\nNhap ten day du sinh vien ma ban muon xoa khoi danh sach tren: ");
	fgets(removeStu, max, stdin);
	fflush(stdin);
	
	int flag = 0, storage;
	for(int i=0; i<n; i++){
		if(strcmp(students[i].name, removeStu) == 0){
			storage= i;
			flag = 1;
		}
	}
	if(flag){
		for(int i=storage ; i< n; i++){
			strcpy(students[i].name, students[i+1].name);
			int temp = students[i].age;
			students[i].age = students[i+1].age;
			students[i].age = temp;
			strcpy(students[i].phoneNumber, students[i+1].phoneNumber);
		}
		
	} else{
		printf("\nSinh vien khong ton tai"); return 0;
	}
	
	n--;
	
	printf("\n==================\n");
	printf("\nsau khi xoa:\n");
	for(int i = 0; i<n ; i++){
		printf("\nid: %d", students[i].id);
		printf("\nTen Hoc sinh %d: %s",i+1, students[i].name);
		printf("\nTuoi hoc sinh %d: %d", i+1, students[i].age);	
		printf("\nsdt: %s", students[i].phoneNumber);
	}
	
	
	return 0;
}
