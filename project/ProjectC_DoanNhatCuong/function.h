//header, khai bao cac ham
#include "datatype.h"


void showMainMenu();
void manageMainMenu();

//===========ADMIN===========
void adminLogin();
int checkLogin(char *username, char *password);
void showAdminMenu();
void manageAdmin();
//===========TEACHER IN ADMIN===========

void showTeacherMenu();
//void manageTeacher();


//===========STUDENT IN ADMIN===========
void readBinaryFile();
void writeBinaryFile();

void showStudentMenu();
void manageStudent();
void addStudent(struct Student S[], int *n);
void editStudent();
void removeStudent();
void arrangeStudent();
void searchStudent();
//====================================================
void endProgram();

int inputChoice();

