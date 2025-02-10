//trien khai ham
#include "datatype.h"

int inputChoice(){
	int choice;
	scanf("%d", &choice);
	return choice;
};

void showMainMenu(){
	printf("+-----+-----+-----+-----+-----+-----+-----+\n");
	printf("*** Students Management System Using C ***\n\n");
	printf("%29s\n", "CHOSE YOUR ROLE");
	printf("%33s\n", "=======================");
	printf("%10s[1] Admin.\n", " ");
	printf("%10s[2] Student.\n", " ");
	printf("%10s[3] Teacher.\n", " ");
	printf("%10s[0] Exit the program.\n", " ");
	printf("%33s\n", "=======================");
};

void showAdminMenu(){
	printf("+-----+-----+-----+-----+-----+-----+-----+\n");
	printf("*** Students Management System Using C ***\n\n");
	printf("%17sMENU\n", " ");
	printf("%33s\n", "=======================");
	printf("%10s[1] Students management.\n", " ");
	printf("%10s[2] Classroom management.\n", " ");
	printf("%10s[3] Teacher management.\n", " ");
	printf("%10s[0] Exit the program.\n", " ");
	printf("%33s\n", "=======================");
};

void showStudentMenu(){
	printf("+-----+-----+-----+-----+-----+-----+-----+\n");
	printf("*** Students Management System Using C ***\n\n");
	printf("%17sSTUDENT MENU\n", " ");
	printf("%33s\n", "=======================");
	printf("%10s[1] Add a new student.\n", " ");
	printf("%10s[2] Show all student.\n", " ");
	printf("%10s[3] Search a student.\n", " ");
	printf("%10s[0] Exit the program.\n", " ");
	printf("%33s\n", "=======================");
};
void EndProgram(){
	printf("\n%33s\n", "=======================");
	printf("%10sThank You!\n", " ");
	printf("%10sSee you soon <3\n", " ");
	printf("%33s\n", "=======================");
};

void showStudentList(struct Student S[], int *n){
	printf("\n============DANH SACH HOC SINH HIEN GIO=========\n");
	printf("+--+-------------------------+---+--------------\n");
	printf("|%-2s|%-25s|%-3s|%-12s|\n","ID", "Ten", "Tuoi", "Sdt");
	printf("+--+-------------------------+---+--------------\n");
	int i;
	for(i=0; i<*n; i++){
		printf("|%-2d|%-25s|%-3d|%-12s|\n",S[i].id, S[i].name, S[i].age, S[i].phoneNumber);
		printf("+--+-------------------------+---+--------------\n");
	}
};

void addStudent(struct Student S[], int *n){
	S[*n].id = *n +1;
	printf("\nInput student name you want to add: ");
	fgets(S[*n].name, 25, stdin);
	S[*n].name[strcspn(S[*n].name, "\n")] = '\0';
	
	printf("\nNhap tuoi: ");
	scanf("%d", &S[*n].age);
	getchar();
	printf("\nNhap sdt sinh vien muon them ");
	fgets(S[*n].phoneNumber, 12, stdin);
	S[*n].phoneNumber[strcspn(S[*n].phoneNumber, "\n")] = '\0';
	
	(*n)++;
	
	printf("\nSuccessfully added!\n");
};
