#include <stdio.h>
const int MaxSize = 10;
int size = 0;

int main(void){
	int arr[MaxSize];
	while(1){
		printf("\n   Menu\n");
		printf("==============\n");
		printf("1. Nhap vao mang\n");
		printf("2. Hien thi mang\n");
		printf("3. Them phan tu\n");
		printf("4. Sua phan tu\n");
		printf("5. Xoa phan tu\n");
		printf("6. Thoat\n");
		printf("===============\n");
		int choice;
		printf("Lua chon cua ban: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: //nhap so luong va them tung phan tu cho array
				int n;
				printf("Nhap so luong phan tu cho mang(max10): ");
				scanf("%d",&n);
				if(n<=0 || n>MaxSize){
					printf("so luong khong hop le, vui long nhap tu 1 - %d\n",MaxSize);
					break;
				}
				for(int i=0; i<n; i++){
					printf("Nhap array[%d]",i);
					scanf("%d",&arr[i]);
				}
				size = n;
                printf("Ban vua nhap thanh cong cho %d phan tu \n",size);
                break;
				
			case 2: //hien thi array
				if(size == 0){
					printf("array cua ban rong vui long input phan tu vao array\n");
					break;
				}
				printf("\ncac phan tu trong array ban vua nhap la: ");
				for(int i = 0 ; i < size; i++){
					printf("%d ",arr[i]);
				}
				break;
			case 3:
				int addValue,position;
				printf("Nhap vi tri phan tu ban muon them: (0-%d) ",size-1);
				scanf("%d",&position);
				printf("Nhap gia tri muon them ");
				scanf("%d",&addValue);
				
				if(position <0 || position > size){
					printf("\n====Vi tri khong hop le se khong them gi ca ====\n");
					break;
				}
				for(int i = size ; i> position; i--){
					arr[i] = arr[i-1];  //sau cho truoc (1,2,3,4,5)<------ gan trai qua phai = sau cho truoc
				}
				arr[position] = addValue;
				size++;
				printf("\nSuccessfully added!\n");
				break;
			case 4:
				int editValue,editPosition,temp;
				printf("Nhap vi tri phan tu ban muon sua: (0-%d)",size-1);
				scanf("%d",&editPosition);
				
				if(editPosition > size || editPosition < 0){
					printf("\n=====vi tri khong hop le se khong lam gi ca======\n");
					break;
				}
				printf("Nhap gia tri ban muon sua thanh (hien tai la %d)",arr[editPosition]);
				scanf("%d",&editValue);
				
				temp = arr[editPosition];
				arr[editPosition] = editValue;
				printf("Succesfully edited!! (%d to %d)",temp,arr[editPosition]);
				
				
				break;
			case 5:
				int removePosition;
				printf("Nhap vi tri phan tu ban muon xoa: (0-%d)",size-1);
				scanf("%d",&removePosition);
				
				if(removePosition > size || removePosition < 0){
					printf("\n=====vi tri khong hop le se khong lam gi ca======\n");
					break;
				}
				//1,2,removePosition,4,5
				for(int i = removePosition; i < size ; i++){
					arr[i] = arr[i+1];
				}
				
				size--;
				printf("Succesfully deleted!! (%d)",removePosition);
				
				break;
			case 6:
				return 1;
				break;
			default:
                printf("Lua chon ko hop le, vui long nhap lai\n");
                break;
		}
		
		
	}
	return 0;	
}
