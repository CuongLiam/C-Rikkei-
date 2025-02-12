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

	// Move to the end of the file to determine its size.
    fseek(f, 0, SEEK_END);
    long fileSize = ftell(f);
    // Calculate the number of student records in the file.
    int count = fileSize / sizeof(struct Student);
    // Return to the beginning of the file.
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
        // Move to the end of the file and get its size.
        fseek(f, 0, SEEK_END);
        long fileSize = ftell(f);
        // Determine the number of records already in the file.
        currentCount = fileSize / sizeof(struct Student);
//         printf("DEBUG: currentCount = %d\n", currentCount);
        fclose(f);
    }
    // currentCount now holds the number of existing records.
    // For example, if there are 5 records already, currentCount will be 5.
    
    // Create an array to hold our new student record.
    // (Since we only need to add one record, you could also use a single variable.)
    struct Student S[max];
    int n = currentCount;  // n represents the number of records before adding a new one.
    
    // The addStudent function uses S[n] to store the new record and then increments n.
    addStudent(S, &n);
    // After calling addStudent(), the new student is stored at index n-1.
    
    // Open the file in append-binary mode ("ab") so that we add the new record at the end.
    f = fopen(STUDENT_PATH, "ab");
    if(f == NULL){
        perror("Error opening file for appending");
        exit(1);
    }
    
    // Write only the new student record.
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
	
	printf("\nNhap tuoi: ");
	scanf("%d", &S[*n].age);
	getchar();
	printf("\nNhap sdt sinh vien muon them ");
	fgets(S[*n].phoneNumber, 12, stdin);
	S[*n].phoneNumber[strcspn(S[*n].phoneNumber, "\n")] = '\0';
	
	(*n)++;
};

void editStudent(){
	readBinaryFile();
    int IDtoEdit;
    printf("Nhap id sinh vien muon sua: ");
    scanf("%d", &IDtoEdit);
    getchar();

    // Open the file in read/update mode (binary)
    FILE *f = fopen(STUDENT_PATH, "rb+");
    if(f == NULL){
        perror("Error opening file for editing");
        return;
    }
    
    // Determine the number of records in the file.
    fseek(f, 0, SEEK_END);
    long fileSize = ftell(f);
    int recordCount = fileSize / sizeof(struct Student);//(cal struct Student)
    rewind(f);  // go back to the beginning

    // Check that the provided ID is within the valid range.
    if(IDtoEdit < 1 || IDtoEdit > recordCount){
        printf("Student with ID %d does not exist.\n", IDtoEdit);
        fclose(f);
        return;
    }
    
    // Calculate the offset of the record: record index is (IDtoEdit - 1)
    //Multiplying by sizeof(struct Student) gives the exact byte offset where the record starts.
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
    
    printf("\nNhap ten moi (press Enter to keep unchanged): ");
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = '\0'; // remove newline
    if(strlen(newName) > 0) {
        strncpy(s.name, newName, sizeof(s.name)-1);
        s.name[sizeof(s.name)-1] = '\0';
    }
    
    printf("Nhap tuoi moi (enter -1 to keep unchanged): ");
    int newAge;
    scanf("%d", &newAge);
    getchar();
    if(newAge != -1) {
        s.age = newAge;
    }
    
    char newSDT[20];
    printf("Nhap sdt moi (press Enter to keep unchanged): ");
    fgets(newSDT, sizeof(newSDT), stdin);
    newSDT[strcspn(newSDT, "\n")] = '\0';
    if(strlen(newSDT) > 0) {
        strncpy(s.phoneNumber, newSDT, sizeof(s.phoneNumber)-1);
        s.phoneNumber[sizeof(s.phoneNumber)-1] = '\0';
    }
    
    // Seek back to the record position so we can overwrite the old record.
    fseek(f, offset, SEEK_SET);
    if(fwrite(&s, sizeof(struct Student), 1, f) != 1) {
        perror("Error writing updated student record");
    } else {
        printf("\nStudent record updated successfully!\n");
    }
    
    fclose(f);
}

