#include <stdio.h>
#include <string.h>

void upperCase(char str[]);
void removeChar(char str[], char ch, char a[]);

int main(void){

	char str[50],ch,after[50];
	printf("Nhap 1 chuoi: ");
	fgets(str , 50 , stdin);
	
	upperCase(str);
	printf("\nChuoi sau khi viet hoa la : %s", str);
	
	printf("\nNhap ki tu can xoa: ");
	scanf("%c", &ch);
	printf("Xoa thanh cong !\n");
	
	removeChar(str, ch, after);
	printf("Chuoi sau khi xoa : %s", after);
	
	return 0;
};
void upperCase(char str[]){
	for(int i=0 ; i<strlen(str) ; i++){
		if(i==0 || (i>0 && str[i-1] == ' '  )){
			if(str[i] >= 'a' && str[i] <= 'z'){
				str[i] -= 32;
				
			}
		}
	}
};

void removeChar(char str[], char ch, char a[]){
	int j=0;
	for(int i=0; str[i] != '\0' ; i++){
		if(str[i] != ch){
			a[j++] = str[i];
		}
	}
	a[j] = '\0';
};

