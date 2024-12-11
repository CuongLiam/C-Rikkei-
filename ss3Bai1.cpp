#include <stdio.h>
#include <stdlib.h>
int main(){	
	char a[100];
	printf("Nhep ten : ");
	gets(a);
	fflush(stdin);
	printf("Xin chao %s",&a);
		
	return 0;
}
