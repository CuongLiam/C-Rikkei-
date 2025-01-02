#include <stdio.h>
#include <string.h>
char str[50];

int countWords(char str[]);
int countNum(char str[]);
int countPunctuations(char str[]);

int main(void){
	printf("Nhap chuoi bat ki: ");
	fgets(str, sizeof(str), stdin);

	
	printf("\nSo ky tu la chu cai: %d", countWords(str));
	printf("\nSo ky tu la so: %d", countNum(str));
	printf("\nSo ky tu dac biet: %d", countPunctuations(str));
	
	return 0;
};

int countWords(char str[]){
	int count=0;
	for(int i= 0; i<strlen(str) ; i++){
		if(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z'){
			count++;
		} 
	}
	return count;
};

int countNum(char str[]){
	int count=0;
	for(int i= 0; i<strlen(str) ; i++){
		if(str[i] >= '0' && str[i] <= '9'){
			count++;
		} 
	}
	return count;
};

int countPunctuations(char str[]){
	int count=0;
	for(int i= 0; i<strlen(str) ; i++){
		if(str[i] >= '!' && str[i] <= '/' || str[i] >= ':' && str[i] <= '@'
			|| str[i] >= '[' && str[i] <= '`'
			|| str[i] >= '{' && str[i] <= '~'){
			count++;
		}
	}
	return count;
};
