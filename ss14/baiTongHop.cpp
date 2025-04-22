#include <stdio.h>
#include <string.h>
#define max 50
char str[max];

void inputString();
int countCharacters();
int countOccurrences(char ch);
void reverseString();
void printString();

int main(void){
	inputString();
	printString();
	
	char ch;
	printf("ban muon nhan biet ki tu nao? ");
	scanf("%c", &ch);
//	fflush(stdin);
	
	printf("\nki tu %c xuat hien thuong xuyen %d",ch,countOccurrences(ch));
	printf("\n");
	reverseString();
	return 0;
};
void inputString(){
	printf("pls input your string : ");
	fgets(str, max, stdin);
	printf("\nsuccessfully added");
};
int countCharacters(){
	return strlen(str);
};

int countOccurrences(char ch){
	int count = 0;
	for(int i = 0; i < strlen(str); i++){
		if(str[i] == ch){
			count++;
		}
	}
	return count;
};

void reverseString(){
	for(int i=0; i < strlen(str)/2 ; i++){
		int temp = str[i] ;
		str[i] = str[strlen(str) - i - 1];
		str[strlen(str) - i -1] = temp;
	}
	printf("Chuoi sau khi reverse: %s",str);
};
void printString(){
	printf("\nchuoi co gia tri la :%s",str);
};

