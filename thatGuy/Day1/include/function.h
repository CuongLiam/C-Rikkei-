#include "datatypes.h"

#ifndef function.h

#define function.h


void showMainMenu();

void adminMenu();

void showStudentMenu();

void exit();

void endProgram();

void showStatisticsTable(const Student students[], int studentCount, Class classes[], int classCount, int countMajors);

void addStudent(Student students[], int *studentCount);

void displayListStudents(const Student students[], int studentCount);

//void addClass(Class classes[], int *classCount, int *countMajors);

//void displayListClasses(const Class classes[], int classCount);

//void manageClasses(Class classes[], int *classCount, int *countMajors);

void manageStudents(Student students[], int *studentCount);

void moreDetailInformation(Student students[], int id);

void writeTextFile(Class classes[], int classCount);

void readTextFile();


#endif
