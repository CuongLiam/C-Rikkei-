#include <stdio.h>
#include <string.h>
int countLetters(char letters[]);

int main(void){
	char str[50];
	
	printf("Nhap mot chuoi: ");
	fgets(str, sizeof(str), stdin);
	fflush(stdin);
	
	printf("\nso chu cai co trong chuoi la: %d",countLetters(str));
	
	return 0;
};
int countLetters(char letters[]){
	int count=0, flag=1;
	
	for(int i=0; letters[i] != '\0' ; i++){
		if(letters[i] <= 'z' && letters[i] >= 'a' || letters[i] <= 'Z' && letters[i] >= 'A' ){
			count ++;
		}
	} 
	return count;
};
