#include <stdio.h>

#include <stdlib.h>

#include "function.h"

#include "datatypes.h"

#include <windows.h>

#define MAX_STUDENTS 50

#define MAX_CLASSES 20

#define b break

#define n printf("\n\n\t\t\t\t\t\t")

#define c system("cls")

#define p system("pause")


int main(int argc, char *argv[]) 
{	
	system("color 2");
	
	int yourChoice0;
	
	Student students[MAX_STUDENTS];
	
	Class classes[MAX_CLASSES];
	
	int studentCount = 0, classCount = 0, countMajors = 0;
	
	do
		{						
			c;
			
			showMainMenu();
	
			printf("\n\t\t\t\t\t\t-> Enter The Choice: ");
	
			scanf("%d", &yourChoice0);
	
			switch(yourChoice0)
				{
					case 0:
						{
							c;
							
							endProgram();
							
							n;
							
							p;
							
							b;							
							
							exit(1);
						}
						
					case 1:
						{
							c;
							
							adminMenu();
							
							n;
							
							p;
							
							b;
							
						}
						
					case 2:
						{
							c;
							
							manageStudents(students, &studentCount);
							
							n;
							
							p;
							
							b;							
							
						}
						
					case 3:
						{
							c;
							
							showStatisticsTable(students, studentCount, classes, classCount, countMajors);
							
							n;
							
							b;							
						}
						
					default:
						{
							c;
							
							printf("\n\n\t\t\t\t\t\tLua chon khong hop le!");
							
							n;
							
							p;
							
							b;
						}
				}	
		}
		
		while(yourChoice0 != 0);
	
	return 0;
}
