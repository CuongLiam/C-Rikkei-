#include <stdio.h>
int main(){
	int n;
	printf("Nhap vao 1 so nguyen : ");
	scanf("%d",&n);
	
	if(n%5==0 && n%3==0){
		printf("%d chia het cho ca 3 va 5",n);
	} else if(n%3==0){
		printf("%d chia het cho 3",n);
	} else if(n%5==0){
		printf("%d chia het cho 5",n);
	}
	return 0;	
}
