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

void arrangeStu(struct Student S[], int *n);


int main(void){
	struct Student S[max];
	int n = 5;
	
	S[0] = (struct Student){1, "Amessy jr", 20, "0123456789"};
    S[1] = (struct Student){2, "Nrandom guy 2", 22, "0987654321"};
    S[2] = (struct Student){3, "Zhi there", 21, "0912345678"};
    S[3] = (struct Student){4, "Chehe", 19, "0945678123"};
    S[4] = (struct Student){5, "Yok", 23, "0934567890"};
	
	printf("Danh sach sinh vien luc dau:\n");
	for(int i = 0; i < n; i++){
        printf("\nID: %d", S[i].id);
        printf("\nTen: %s", S[i].name);
        printf("\nTuoi: %d", S[i].age);
        printf("\nSDT: %s", S[i].phone);
    }
	
	
	
	//xsap xep theo ten
	arrangeStu(S, &n);
	
	
	printf("\nDanh sach sinh vien theo ten luc sau:\n");
	for(int i = 0; i < n; i++){
       printf("\nID: %d", S[i].id);
       printf("\nTen: %s", S[i].name);
       printf("\nTuoi: %d", S[i].age);
       printf("\nSDT: %s", S[i].phone);
    }
	return 0;
}

void arrangeStu(struct Student S[], int *n){
	char temp[25];
	for(int i=0 ; i<*n ; i++){
		for(int j= 0; j<*n-1-i; j++){
			if(strcmp(S[j].name, S[j+1].name) > 0){
				strcpy(temp, S[j].name);
				strcpy(S[j].name, S[j+1].name);
				strcpy(S[j+1].name, temp);
			}
		}
	}
	
};
