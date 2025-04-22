#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
char students[MAX][6][20];
int n; // 1,2,3,4,5,(index = 5)


int pressAnyKey(){
	char c;
	fflush(stdin);
	printf("\tAn phim bat ky de quay lai menu! \n");
	scanf("%c",&c);	
}

void showListStudents(){
	if(n == 0){
		printf("\t-----------Danh sach trong---------\n");
		return;	
	}
	printf("\t------------------------Danh sach sinh vien--------------------------\n");
	printf("\t+-----+---------------+-----------+-----------+-----+----------+\n");
	printf("\t|%-5s|%-15s|%-11s|%-11s|%-5s|%-10s|\n","ID","Name","Birthday","Phone","Sex","Status");
	printf("\t+-----+---------------+-----------+-----------+-----+----------+\n");
	for(int i =0; i<n;i++){
		printf("\t|%-5s|%-15s|%-11s|%-11s|%-5s|%-10s|\n",students[i][0],students[i][1],students[i][2],students[i][3],students[i][4],students[i][5]);
		printf("\t+-----+---------------+-----------+-----------+-----+----------+\n");	
	}
}
void copyStudent(char stu1[6][20], char stu2[6][20]){
	strcpy(stu1[0], stu2[0]);
	strcpy(stu1[1], stu2[1]);
	strcpy(stu1[2], stu2[2]);
	strcpy(stu1[3], stu2[3]);
	strcpy(stu1[4], stu2[4]);
	strcpy(stu1[5], stu2[5]);
}
void swapStr(char str1[], char str2[]){
	char temp[20];
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}
void swap(char stu1[6][20], char stu2[6][20]){
	for(int i =0 ; i <6 ; i++){
		swapStr(stu1[i], stu2[i]);
	}

}
void sortByName(){
	for(int i = 0; i< n -1; i++){
		for(int j =0; j < n-i-1 ; i++){
			if(strcmp(students[i][1],students[i+1][1]) > 0){
				swap(students[i],students[i+1]);
			}
		}	
	}
}
void addNewStudent(){
	if(n == MAX){
		printf("\tMang day\n");
		return;	
	}
	fflush(stdin);
	printf("\tNhap ma sv : ");
	gets(students[n][0]); 	
	printf("\tNhap ten sv : ");
	gets(students[n][1]); 	
	printf("\tNhap ngay sinh sv : ");
	gets(students[n][2]); 	
	printf("\tNhap so dien thoai sv : ");
	gets(students[n][3]); 	
	printf("\tNhap gioi tinh sv (Nam / Nu) : ");
	gets(students[n][4]); 	
	printf("\tNhap trang thai sv (Dang hoc/Bo hoc): ");
	gets(students[n][5]); 
	n++;		
}
void deleteStudent(){ // st1,st2,st4,st5,st6 : st3 = st4;
	fflush(stdin);
	printf("\t Nhap id sinh vien can xoa : ");
	char id[20];
	gets(id);
	int isMove = 0;
	for(int i = 0; i< n - 1 ; i++){
		if(strcmp(students[i][0],id)==0){
			isMove = 1;	
		}
		if(isMove){
			copyStudent(students[i], students[i+1]);	
		}
	}
	n--;	
}
int main(){
	// gets(doc den ki tu \n hoac EOF, bien \n th?nh \0) v? fgets(them ki tu \0 sau \n) kh?c nhau nhu n?o 
	int choice;
	system("color 0");
	while(1){
		printf("\t===============MENU=============\n");
		printf("\t1.showing\n");
		printf("\t2.adding student lists\n");
		printf("\t3.edit student lists\n");
		printf("\t4.delete a student\n");
		printf("\t7.qit\n");
		printf("\t>>>> choose : ");
		scanf("%d",&choice);
		switch(choice){
			case 1: 
				showListStudents();
				break;
			case 2: 
				addNewStudent();
				break;
			case 4:
				deleteStudent();
				break;
			case 6:
				sortByName();
				break;
			case 7 :
				exit(0);
				break;
			default	:
				break;	
		}

		pressAnyKey();
		system("cls");
	}	
	
	
}

