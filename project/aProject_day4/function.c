#include "datatype.h"
#include "globals.h"
#include "function.h"
//trien khai ham

//===========================MENU=========================================
int inputChoice(){
	int choice;
	scanf("%d", &choice);
	return choice;
};
//====================================MAIN MENU======================================
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

void manageMainMenu(){
	while (1){
		showMainMenu();
		printf("%10senter your choice: ", " ");
		int choice = inputChoice();
		getchar();
		system("cls");
		
		switch(choice){
			case 1:{
				manageAdmin();
				break;
			}
			case 2:{
				
				break;
			}
			case 0:{
				endProgram();
				return;
			}
			default:{
				break;
			}
		}
		
	}
};
//====================================ADMIN MENU======================================
void showAdminMenu(){
	printf("+-----+-----+-----+-----+-----+-----+-----+\n");
	printf("%10s*** WELCOME ADMIN ***\n\n", " ");
	printf("%17sMENU\n", " ");
	printf("%33s\n", "=======================");
	printf("%10s[1] Students management.\n", " ");
	printf("%10s[2] Classroom management.\n", " ");
	printf("%10s[3] Teacher management.\n", " ");
	printf("%10s[0] Go back.\n", " ");
	printf("%33s\n", "=======================");
};

void manageAdmin(){
	while (1){
		showAdminMenu();
		
		printf("%10senter your choice: ", " ");
		int choice = inputChoice();
		getchar();
		system("cls");
		
		switch (choice){
			case 1:{
				manageStudent();
				break;
			}
			case 2:{
				
				break;
			}
			case 0:{
				return;
			}
		}
	}
};
//====================================STUDENTS MENU IN ADMIN======================================
void showStudentMenu(){
	printf("+-----+-----+-----+-----+-----+-----+-----+\n");
	printf("%17sSTUDENT MENU\n", " ");
	printf("%33s\n", "=======================");
	printf("%10s[1] Add a new student.\n", " ");
	printf("%10s[2] Show all student.\n", " ");
	printf("%10s[3] Edit a student.\n", " ");
	printf("%10s[4] Delete a student.\n", " ");
	printf("%10s[5] Arrange list via Names.\n", " ");
	printf("%10s[6] Search a student Names.\n", " ");
	printf("%10s[0] Go back.\n", " ");
	printf("%33s\n", "=======================");
};

void manageStudent(){
	while (1){
		showStudentMenu();
		
		printf("%10senter your choice: ", " ");
		int choice = inputChoice();
		getchar();
		system("cls");
		
		switch (choice){
			case 1:{
				writeBinaryFile();
				break;
			}
			case 2:{
				readBinaryFile();
				break;
			}
			case 3:{
				editStudent();
				break;
			}
			case 4:{
				removeStudent();
				break;
			}
			case 5:{
				arrangeStudent();
				break;
			}
			case 6:{
				searchStudent();
				break;
			}
			case 0:{
				return;
			}
		}
	}
	
};

void endProgram(){
	printf("\n%33s\n", "=======================");
	printf("%10sThank You!\n", " ");
	printf("%10sSee you soon <3\n", " ");
	printf("%33s\n", "=======================");
};

void readBinaryFile(){
	
	FILE *f = fopen(STUDENT_PATH, "rb");
	if(f == NULL){
		//cant open
		exit(1);
	}

	// Move to the end of the file to determine its size
	// to know WHAT n IS :0
    fseek(f, 0, SEEK_END);
    long fileSize = ftell(f);
    // Calculate the number of student records in the file
    int count = fileSize / sizeof(struct Student);
    // Return to the beginning of the file
    rewind(f);
	
	printf("\n**==========STUDENTS LIST RN==========**\n");
	printf("+--+-------------------------+---+--------------\n");
	printf("|%-2s|%-25s|%-3s|%-12s|\n","ID", "Name", "Age", "Sdt");
	printf("+--+-------------------------+---+--------------\n");
	struct Student S;
	int i;
	for (i= 0; i < count; i++){
        if (fread(&S, sizeof(struct Student), 1, f) == 1) {
            printf("|%-2d|%-25s|%-3d|%-12s|\n", S.id, S.name, S.age, S.phoneNumber);
            printf("+--+-------------------------+---+--------------+\n");
        }
    }
	fclose(f);
	
};

void writeBinaryFile(){
    int currentCount = 0;
    FILE *f = fopen(STUDENT_PATH, "rb");
    if(f != NULL){
        // Move to the end of the file and get its size
        fseek(f, 0, SEEK_END);
        long fileSize = ftell(f);
        // Determine the number of records already in the file
        currentCount = fileSize / sizeof(struct Student);
//         printf("DEBUG: currentCount = %d\n", currentCount);
        fclose(f);
    }
    // currentCount now holds the number of existing records
    // For example, if there are 5 records already, currentCount will be 5
    
    // Create an array to hold our new student record.
    // (Since we only need to add one record, you could also use a single variable)
    struct Student S[max];
    int n = currentCount;  // n represents the number of records before adding a new one
    
    // The addStudent function uses S[n] to store the new record and then increments n
    addStudent(S, &n);
    // After calling addStudent(), the new student is stored at index n-1
    
    // Open the file in append-binary mode ("ab") so that we add the new record at the end
    f = fopen(STUDENT_PATH, "ab");
    if(f == NULL){
        perror("Error opening file for appending");
        exit(1);
    }
    
    // Write only the new student record
    if (fwrite(&S[n - 1], sizeof(struct Student), 1, f) != 1) {
        perror("Error writing new student record");
    } else {
        printf("\nStudent record appended successfully!\n");
    }
    
    fclose(f);

	
//	S[0] = (struct Student){1, "Bmessy jr", 20, "0123456789"};
//    S[1] = (struct Student){2, "Nrandom guy 2", 22, "0987654321"};
//    S[2] = (struct Student){3, "Zhi there", 21, "0912345678"};
//    S[3] = (struct Student){4, "Chehe", 19, "0945678123"};
//    S[4] = (struct Student){5, "Aok", 23, "0934567890"};
    
    //// Write only the newly added student, which is stored at index (n - 1)
//	fwrite(&S, sizeof(struct Student), 5, f);
//	
//	fclose(f);
//	printf("\nSuccessfully added!\n");
	
};

//void showStudentList(struct Student S[], int *n){
//	printf("\n============DANH SACH HOC SINH HIEN GIO=========\n");
//	printf("+--+-------------------------+---+--------------\n");
//	printf("|%-2s|%-25s|%-3s|%-12s|\n","ID", "Ten", "Tuoi", "Sdt");
//	printf("+--+-------------------------+---+--------------\n");
//	int i;
//	for(i=0; i<*n; i++){
//		printf("|%-2d|%-25s|%-3d|%-12s|\n",S[i].id, S[i].name, S[i].age, S[i].phoneNumber);
//		printf("+--+-------------------------+---+--------------\n");
//	}
//};

void addStudent(struct Student S[], int *n){
	S[*n].id = *n +1;
    
	printf("\nInput student name you want to add: ");
	fgets(S[*n].name, 25, stdin);
	S[*n].name[strcspn(S[*n].name, "\n")] = '\0';
	
	printf("\nInsert age: ");
	scanf("%d", &S[*n].age);
	getchar();
	printf("\nPhone number: ");
	fgets(S[*n].phoneNumber, 12, stdin);
	S[*n].phoneNumber[strcspn(S[*n].phoneNumber, "\n")] = '\0';
	
	(*n)++;
};

void editStudent(){
	readBinaryFile();
    int IDtoEdit;
    printf("Student's ID u want to edit: ");
    scanf("%d", &IDtoEdit);
    getchar();

    // Open the file in read/update mode (binary)
    FILE *f = fopen(STUDENT_PATH, "rb+");
    if(f == NULL){
        perror("Error opening file for editing");
        return;
    }
    
    // Determine the number of records in the file
    // Know n is for ez works
    fseek(f, 0, SEEK_END);
    long fileSize = ftell(f);
    int recordCount = fileSize / sizeof(struct Student);//(cal struct Student)
    rewind(f);  // go back to the beginning

    // Check that the provided ID is within the valid range
    if(IDtoEdit < 1 || IDtoEdit > recordCount){
        printf("Student with ID %d does not exist.\n", IDtoEdit);
        fclose(f);
        return;
    }
    
    // Calculate the offset of the record: record index is (IDtoEdit - 1)
    //Multiplying by sizeof(struct Student) gives the exact byte offset where the record starts
    //very nice ***+++***
    long offset = (IDtoEdit - 1) * sizeof(struct Student);
    fseek(f, offset, SEEK_SET);
    
    // Read the record
    struct Student s;
    if(fread(&s, sizeof(struct Student), 1, f) != 1){
        perror("Error reading student record");
        fclose(f);
        return;
    }
    
    printf("\nCurrent information:\n");
    printf("+--+-------------------------+---+--------------\n");
    printf("|%-2s|%-25s|%-3s|%-12s|\n","ID", "Name", "Age", "Sdt");
    printf("+--+-------------------------+---+--------------\n");
    printf("|%-2d|%-25s|%-3d|%-12s|\n", s.id, s.name, s.age, s.phoneNumber);
    printf("+--+-------------------------+---+--------------\n");
    
    char newName[50];
    
    printf("\nInput new Name (press Enter to keep unchanged): ");
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = '\0'; // remove newline
    if(strlen(newName) > 0) {
        strncpy(s.name, newName, sizeof(s.name)-1);
        s.name[sizeof(s.name)-1] = '\0';
    }
    
    printf("new Age (enter -1 to keep unchanged): ");
    int newAge;
    scanf("%d", &newAge);
    getchar();
    if(newAge != -1) {
        s.age = newAge;
    }
    
    char newSDT[20];
    printf("new phoneNumber (press Enter to keep unchanged): ");
    fgets(newSDT, sizeof(newSDT), stdin);
    newSDT[strcspn(newSDT, "\n")] = '\0';
    if(strlen(newSDT) > 0) {
        strncpy(s.phoneNumber, newSDT, sizeof(s.phoneNumber)-1);
        s.phoneNumber[sizeof(s.phoneNumber)-1] = '\0';
    }
    
    // Seek back to the record position so we can overwrite the old record
    fseek(f, offset, SEEK_SET);
    if(fwrite(&s, sizeof(struct Student), 1, f) != 1) {
        perror("Error writing updated student record");
    } else {
        printf("\nStudent record updated successfully!\n");
    }
    
    fclose(f);
};

void removeStudent(){
	readBinaryFile();
    int idToRemove;
    printf("Student's ID u want to delete: ");
    scanf("%d", &idToRemove);
    getchar();

    // Open the file in read-binary mode to load all records
    FILE *f = fopen(STUDENT_PATH, "rb");
    if(f == NULL){
        perror("Error opening file for reading");
        return;
    }
    
    // Determine the number of records in the file
    fseek(f, 0, SEEK_END);
    long fileSize = ftell(f);
    int recordCount = fileSize / sizeof(struct Student);
    rewind(f);  // go back to the beginning

    if(recordCount == 0){
        printf("File is empty. No record to remove.\n");
        fclose(f);
        return;
    }
    
    // Allocate memory to hold all student records
    struct Student *students = malloc(recordCount * sizeof(struct Student));
    if(students == NULL){
        perror("Memory allocation error");
        fclose(f);
        return;
    }
    
    // Read all records into the array
    int numRead = fread(students, sizeof(struct Student), recordCount, f);
    fclose(f);

    // Search for the record with the given ID
    int foundIndex = -1;
    int i;
    for (i = 0; i < numRead; i++){
        if(students[i].id == idToRemove){
            foundIndex = i;
            break;
        }
    }
    
    if(foundIndex == -1){
        printf("Student with id %d not found\n", idToRemove);
        free(students);
        return;
    }
    
    // 1,2,\0,4,5   chen sau cho truoc
    int j;
    for (j = foundIndex; j < numRead - 1; j++){
        students[j] = students[j+1];
    }
    
    // update the student IDs to remain sequential
    int k;
    for (k = 0; k < numRead - 1; k++){
        students[k].id = k + 1;
    }
    
    // Open the file in write mode to overwrite it with the updated list
    f = fopen(STUDENT_PATH, "wb");
    if(f == NULL){
        perror("Error opening file for writing");
        free(students);
        return;
    }
    
    int newCount = numRead - 1;
    if(fwrite(students, sizeof(struct Student), newCount, f) != newCount){
        perror("Error writing updated records");
    } else {
        printf("Student with id %d removed successfully!\n", idToRemove);
    }
    
    fclose(f);
    free(students);
};

//bubbleSort
void arrangeStudent(){
    FILE *f = fopen(STUDENT_PATH, "rb");
    if(f == NULL){
        perror("Error opening file for reading");
        return;
    }
    
    // Determine record count
    fseek(f, 0, SEEK_END);
    long fileSize = ftell(f);
    int recordCount = fileSize / sizeof(struct Student);
    rewind(f);
    
    if(recordCount == 0){
        printf("No student records found.\n");
        fclose(f);
        return;
    }
    
    // Allocate memory for the records.
    struct Student *students = malloc(recordCount * sizeof(struct Student));
    if(students == NULL){
        perror("Memory allocation error");
        fclose(f);
        return;
    }
    
    int numRead = fread(students, sizeof(struct Student), recordCount, f);
    fclose(f);
// bubble=====================================
    int i,j;
    for (i = 0; i < numRead - 1; i++) {
        for (j = 0; j < numRead - i - 1; j++) {
            if (strcmp(students[j].name, students[j+1].name) > 0){ //condition
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
    
//selection=====================================
	// Selection sort: for each position, find the smallest element and swap it into place.
//    for ( i = 0; i < numRead - 1; i++){
//        int minIndex = i;
//        for ( j = i + 1; j < numRead; j++){
//            if (strcmp(students[j].name, students[minIndex].name) < 0){
//                minIndex = j;
//            }
//        }
//        if (minIndex != i){
//            struct Student temp = students[i];
//            students[i] = students[minIndex];
//            students[minIndex] = temp;
//        }
//    }
//insertion===============================
// Insertion sort: insert each element into its proper position in the sorted portion.
//    for (i = 1; i < numRead; i++){
//        struct Student key = students[i];
//        j = i - 1;
//        while (j >= 0 && strcmp(students[j].name, key.name) > 0){
//            students[j + 1] = students[j];
//            j--;
//        }
//        students[j + 1] = key;
//    }


    int k;
    for (k = 0; k < numRead; k++){
        students[k].id = k + 1;
    }
    
    // Write the sorted records back to the file.
    f = fopen(STUDENT_PATH, "wb");
    if(f == NULL){
        perror("Error opening file for writing");
        free(students);
        return;
    }
    if (fwrite(students, sizeof(struct Student), numRead, f) != numRead) {
        perror("Error writing sorted records");
    } else {
        printf("Students arranged (Bubble Sort) by name successfully.\n");
    }
    fclose(f);
    free(students);
};
void searchStudent(){
	char searchCondi[50];
	
	printf("enter a name you want to search (or some letters part of that name) : ");
	fgets(searchCondi, sizeof(searchCondi), stdin);
	searchCondi[strcspn(searchCondi, "\n")] = '\0';
	
	FILE *f = fopen(STUDENT_PATH, "rb");
    if(f == NULL){
        perror("Error opening file for reading");
        return;
    }
    
    //same thing
    fseek(f, 0, SEEK_END);
    long fileSize = ftell(f);
    int recordCount = fileSize / sizeof(struct Student);
    rewind(f);
	
	if(recordCount == 0){
        printf("No student records found\n");
        fclose(f);
        return;
    }
    
    //cap phat dynamic
    struct Student *students = malloc(recordCount * sizeof(struct Student));
    if(students == NULL){
        perror("Memory allocation error");
        fclose(f);
        return;
    }
    
    int numRead = fread(students, sizeof(struct Student), recordCount, f);
    fclose(f);
    
    int flag = 0;
    
    printf("\nSearch results for \"%s\":\n", searchCondi);
    printf("+--+-------------------------+---+--------------+\n");
    printf("|%-2s|%-25s|%-3s|%-12s|\n", "ID", "Name", "Age", "Sdt");
    printf("+--+-------------------------+---+--------------+\n");
    
    int i;
    for (i = 0; i < numRead; i++){
        if(strstr(students[i].name, searchCondi) != NULL){  // If found in the name...
            printf("|%-2d|%-25s|%-3d|%-12s|\n", 
                   students[i].id, 
                   students[i].name, 
                   students[i].age, 
                   students[i].phoneNumber);
            printf("+--+-------------------------+---+--------------+\n");
            flag++;
        }
    }
    
    if(flag == 0){
    	printf("No results found\n");
    }
    
    free(students);
};


