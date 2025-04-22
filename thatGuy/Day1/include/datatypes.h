#ifndef datatypes.h

#define datatypes.h

#include <stdbool.h>


typedef struct
{
	char student_id[10];
	
	char classroom_id[10];
		
	char name[25];
		
	bool gender;
		
	char phone[20];
		
	char email[30];
		
	char password[20];
	
} Student;
	

typedef struct
{
	char class_id[6];
		
	char teacher_id[10];
		
	char class_name[10];
	
} Class;


typedef struct
{
	int day;
	
	int month;
	
	int year;

} Date;



#endif
