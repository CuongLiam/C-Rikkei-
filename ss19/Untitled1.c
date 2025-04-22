#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include "function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Student{
//	char classroomID[6];
	int id;
	char name[25];
//	int sex;
	int age;
	char phoneNumber[12];
};

int main(int argc, char *argv[]) {	
	system("color B");
	
	struct Student S[max];
	int n=5;
	S[0] = (struct Student){1, "Bmessy jr", 20, "0123456789"};
    S[1] = (struct Student){2, "Nrandom guy 2", 22, "0987654321"};
    S[2] = (struct Student){3, "Zhi there", 21, "0912345678"};
    S[3] = (struct Student){4, "Chehe", 19, "0945678123"};
    S[4] = (struct Student){5, "Aok", 23, "0934567890"};
	
	while (1){
		showStudentMenu();
		printf("%10senter your choice: ", " ");
		
		int choice = inputChoice();
		
		switch(choice){
			case 1:{
				addStu(S, &n);
				break;
			}
			case 2:{
				showStudentList(S, &n);
				break;
			}
			case 0:{
				EndProgram();
				return 0;
			}
			default:{
				break;
			}
		}
		
	}	
	return 0;
}
