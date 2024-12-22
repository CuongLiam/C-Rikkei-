#include <stdio.h>
int const maxSize = 100;

int main(){
	int arr[maxSize],size;
	
	printf("Nhap vao so phan tu ma ban muon nhap vao mang ");
	scanf("%d",&size);
	
	for(int i=0 ; i < size;i++){
		printf("\nNhap vao phan tu array[%d] ",i);
		scanf("%d",&arr[i]);
	}
	
	printf("\nCac phan tu ban vua nhap la ");
	for(int i=0 ; i < size;i++){
		printf("%d ",arr[i]);
	}
	
	int flag = 1;
	while(flag){
	int removePosition;
	printf("\nNhap vi tri ban muon xoa trong mang (0-%d)",size-1);
	scanf("%d",&removePosition);
	if(removePosition<0 || removePosition> size){
		printf("\nvi tri khong hop le hay nhap lai");
		break;
	}
	
	for(int i = removePosition ; i < size ; i++){
		arr[i] = arr[i+1]; 
	}
	size--;
	
	printf("\nda xoa thanh cong!!");
	printf("\nCac phan tu hien gio la: ");
	for(int i=0 ; i < size;i++){
		printf("%d ",arr[i]);
	}
	flag = 0;
	
	}
	
	return 0;
}
