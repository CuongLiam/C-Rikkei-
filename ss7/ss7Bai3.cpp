#include <stdio.h>

int main(void){
	int arr[5];

	for(int i = 0 ; i<5 ; i++){
		printf("Nhap array[%d]",i);
		scanf("%d",&arr[i]);
	}

	int flag = 1;
	for(int i = 0 ; i<5 ; i++){
		if(arr[i] % 2 == 0 ){
			printf("%d ",arr[i]);
			flag = 0;
		}
	}

	if(flag == 1){
		for(int i = 0 ; i<5 ; i++){
			if(arr[i] % 2 != 0 ){
				printf("%d ",arr[i]);
			}
		}
	}

	return 0;
}
