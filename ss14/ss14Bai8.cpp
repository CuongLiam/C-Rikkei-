#include <stdio.h>
#include <string.h>

void upperCase(char str[]);

int main(void){
	char str[50];
	printf("Nhap 1 chuoi: ");
	fgets(str , 50 , stdin);
	
	upperCase(str);
	printf("\nChuoi sau khi viet hoa la : %s", str);
	
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

