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
void manageTeacher();

int isValidEmail(const char *email);

void readTeacherBinaryFile();
void writeTeacherBinaryFile();

void addTeacher(struct Teacher T[], int *n);
void editTeacher();
void removeTeacher();
//bubble
void arrangeTeacher();
//linear search:(
void searchTeacher();


//===========STUDENT IN ADMIN===========
void readBinaryFile();
void writeBinaryFile();

void showStudentMenu();
void manageStudent();
void addStudent(struct Student S[], int *n);
void editStudent();
void removeStudent();
//bubble
void arrangeStudent();
//linear aswell
void searchStudent();
//====================================================
void endProgram();

int inputChoice();

