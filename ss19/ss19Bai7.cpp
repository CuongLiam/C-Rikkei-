#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

struct Student{
	int id;
	char name[25];
	int age;
	char phone[12];
	
};

void removeStudent(int byebyeID, struct Student S[], int *n);


int main(void){
	struct Student S[max];
	int n = 5, IDtoRemove;
	
	S[0] = (struct Student){1, "messy jr", 20, "0123456789"};
    S[1] = (struct Student){2, "random guy 2", 22, "0987654321"};
    S[2] = (struct Student){3, "hi there", 21, "0912345678"};
    S[3] = (struct Student){4, "hehe", 19, "0945678123"};
    S[4] = (struct Student){5, "ok", 23, "0934567890"};
	
	printf("Danh sach sinh vien luc dau:\n");
	for(int i = 0; i < n; i++){
        printf("\nID: %d", S[i].id);
        printf("\nTen: %s", S[i].name);
        printf("\nTuoi: %d", S[i].age);
        printf("\nSDT: %s", S[i].phone);
    }
	
	printf("\nNhap ID can xoa: ");
	scanf("%d", &IDtoRemove);
	
	//xoa
	removeStudent(IDtoRemove, S, &n);
	
	return 0;
}

void removeStudent(int byebyeID, struct Student S[], int *n){
	int flag=0;
	
	for(int i=0; i<*n; i++){
		if(S[i].id == byebyeID){
			flag = 1;
			break;
		}
	}
	
	if(flag){
		for(int i= *n-1; i>=byebyeID; i--){
			S[i-1].id = S[i].id;
		}
		(*n)--;
		printf("Sinh vien co ID = %d da duoc xoa.\n", byebyeID);
	} else{
		printf("Khong tim thay sinh vien co ID = %d.\n", byebyeID);
	}
	
	printf("\nDanh sach sinh vien luc sau:\n");
	for(int i = 0; i < *n; i++){
       printf("\nID: %d", S[i].id);
       printf("\nTen: %s", S[i].name);
       printf("\nTuoi: %d", S[i].age);
       printf("\nSDT: %s", S[i].phone);
    }
	
	
	
};
