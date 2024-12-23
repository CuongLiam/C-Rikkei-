#include <stdio.h>
int main(){
	int arr[5] = {1,2,3,4,5};
	
	for(int index=0; index < 5;index++){
		printf("%d\n",arr[index]);
	}
	printf("%d (byte)",sizeof(arr));
	return 0;
}
