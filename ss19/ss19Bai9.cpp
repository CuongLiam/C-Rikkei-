#include <stdio.h>
#include <string.h>
#define max 50
struct Student{
	int id;
	char name[25];
	int age;
	char phone[12];
	
};

void showStudentList(struct Student S[], int *n);
void addStu(struct Student S[], int *n);
void editStu(struct Student *S, int *n);

void removeStu(struct Student *S, int *n);

int findStu();
void arrangeStuList();

int main(void){
	struct Student S[max];
//	struct Student *ptr = S;
	int n = 5;
	
	S[0] = (struct Student){1, "Bmessy jr", 20, "0123456789"};
    S[1] = (struct Student){2, "Nrandom guy 2", 22, "0987654321"};
    S[2] = (struct Student){3, "Zhi there", 21, "0912345678"};
    S[3] = (struct Student){4, "Chehe", 19, "0945678123"};
    S[4] = (struct Student){5, "Aok", 23, "0934567890"};
    
	showStudentList(S, &n);
	
	int choice;
	do{
        printf("\n========= MENU =========\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach\n");
        printf("7. Thoat\n");
        printf("moi ban chon: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                showStudentList(S, &n);
                break;
            case 2:
                addStu(S, &n);
                break;
            case 3:
                editStu(S, &n);
                break;
            case 4:
//                removeStu(S, n);
                break;
            case 5:
//                findStu(S, *n);
                break;
            case 6:
//                arrangeStuList(S, *n);
                break;
            case 7:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le! Moi nhap lai\n");
        }
    } while (choice != 7);
	
	return 0;
};

void showStudentList(struct Student S[], int *n){
	printf("============DANH SACH HOC SINH HIEN GIO=========\n");
	printf("+--+-------------------------+---+--------------\n");
	printf("|%-2s|%-25s|%-3s|%-12s|\n","ID", "Ten", "Tuoi", "Sdt");
	printf("+--+-------------------------+---+--------------\n");
	for(int i=0; i<*n; i++){
		printf("|%-2d|%-25s|%-3d|%-12s|\n",S[i].id, S[i].name, S[i].age, S[i].phone);
		printf("+--+-------------------------+---+--------------\n");
	}
};

void addStu(struct Student S[], int *n){
	
	S[*n].id = *n +1;
	printf("\nNhap ten sinh vien muon them ");
	fgets(S[*n].name, 25, stdin);
	S[*n].name[strcspn(S[*n].name, "\n")] = '\0';
	
	printf("\nNhap tuoi: ");
	scanf("%d", &S[*n].age);
	getchar();
	printf("\nNhap sdt sinh vien muon them ");
	fgets(S[*n].phone, 12, stdin);
	S[*n].phone[strcspn(S[*n].phone, "\n")] = '\0';
	
	(*n)++;
};

void editStu(struct Student *S, int *n){
	int IDtoEdit;
	printf("Nhap id sinh vien muon sua: ");
	scanf("%d", &IDtoEdit);
	getchar();
	
	int flag = -1;
	for(int i=0; i < *n; i++){
		if(IDtoEdit == S[i].id){
			flag = i;
			break;
		}
	}
	
	if(flag == -1){
		printf("ID khong hop le");
		return;
	}
	
	printf("Moi sua ten (hien tai la %s): ", S[flag].name);
    fgets(S[flag].name, sizeof(S[flag].name), stdin);
    S[flag].name[strcspn(S[flag].name, "\n")] = '\0';
    
    printf("Sua tuoi (hien tai la %d): ", S[flag].age);
    scanf("%d", &S[flag].age);
    getchar();
    
    printf("Sua sdt (hien tai la %s): ", S[flag].phone);
    fgets(S[flag].phone, sizeof(S[flag].phone), stdin);
    S[flag].phone[strcspn(S[flag].phone, "\n")] = '\0';
	
};

void removeStu(struct Student *S, int *n){
	
};

