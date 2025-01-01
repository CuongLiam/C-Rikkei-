#include <stdio.h>
#include <string.h>
int countWords(char word[]);

int main(void){
	char str[50];
	
	printf("Nhap mot chuoi: ");
	fgets(str, sizeof(str), stdin);
	fflush(stdin);
	
	printf("\nso tu co trong chuoi la: %d",countWords(str));
	
	return 0;
};
int countWords(char word[]){
	int count=0, flag=1;
	
	for(int i=0; word[i] != '\0' ; i++){
		if(word[i] != ' '){
			if(flag){
				count++;
				flag = 0;
			}
		} else{
			flag = 1;
		}
	} 
	return count;
};
