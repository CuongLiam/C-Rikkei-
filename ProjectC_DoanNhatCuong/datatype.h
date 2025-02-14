//import thu vien, khai bao cac struct
#ifndef DATATYPE_H
#define DATATYPE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 100

struct Date{
	int day, month, year;
};

struct Student{
//	char classroomID[6];
	int id;
	char name[25];
//	int sex;
	int age;
	char phoneNumber[12];
};


#endif
