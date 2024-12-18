#include <stdio.h>

int main(){
	int n=5,odd=0,even=0,num;
	printf("Nhap vao 5 so nguyen : ");
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		if(num%2==0){
			even++;
		} else {
			odd++;
		}
	}
	printf("Tong so luong so chan la: %d",even);
	printf("\nTong so luong so le la: %d",odd);
	
	return 0;
}
