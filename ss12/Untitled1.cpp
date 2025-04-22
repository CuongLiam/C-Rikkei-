#include <stdio.h>

int main(void){
	int array[4] = {1,2,3,4};
	
	
	for(int j=0; j<10; j++){
		for(int i=0; i<4; i++){
			printf("%d ",array[i]);
		}
		printf("\n");
	}
}

