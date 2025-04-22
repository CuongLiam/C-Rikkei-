#include <stdio.h>
#include <string.h>
char str[] = "I can eat my own hello my man";
int countOccurrences(char ch);

int main(void){
	char ch;
	printf("Nhap tu muon tim(trong \"%s\") ",str);
	scanf("%c",&ch);
	
	printf("%c xuat hien %d lan",ch,countOccurrences(ch));
	
	return 0;
};

int countOccurrences(char ch){
	int count=0;
	
	for(int i =0; i<strlen(str); i++){
		if(str[i] == ch){
			count++;
		}
	}
	return count;
};
