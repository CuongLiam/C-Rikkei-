//import thu vien, khai bao cac struct
#ifndef datatype.h   // If DATATYPE_H is not defined...
#define datatype.h   // ...define it now
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100


struct Student{
//	char classroomID[6];
	int id;
	char name[25];
//	int sex;
	int age;
	char phoneNumber[12];
};
#endif
