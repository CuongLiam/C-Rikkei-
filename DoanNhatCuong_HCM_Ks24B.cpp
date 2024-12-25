#include <stdio.h>
const int MaxSize = 100;
int size = 0;

int main(){
	int arr[MaxSize];
	while(1){
		printf("\n   Menu\n");
		printf("==============\n");
		printf("1. Nhap so phan tu va gia tri mang\n");
		printf("2. In ra gia tri cac phan tu mang theo dang (arr[0] = 1, arr[1] = 5 …)\n");
		printf("3. Dem so luong so hoan hao\n");
		printf("4. Tim gia tri lon thu 2 trong mang\n");
		printf("5. Them phan tu\n");
		printf("6. Xoa phan tu\n");
		printf("7. Sap xep theo gia tri tang dan\n");
		printf("8. tim kiem\n");
		printf("9. So chan dung truoc so le dung sau \n");
		printf("10. Dao nguoc thu tu cua cac phan tu co trong mang\n");
		printf("===============\n");
		int choice;
		printf("Lua chon cua ban: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				int n;
				printf("Nhap so luong phan tu cho mang(max100): ");
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
				
			case 2:
				if(size == 0){
					printf("array cua ban rong vui long input phan tu vao array\n");
					break;
				}
				printf("\ncac phan tu trong array ban vua nhap la: ");
				for(int i = 0 ; i < size; i++){
					printf("arr[%d] = %d , ",i,arr[i]);
				}
				break;
			case 3:
//				int dem = 0;
//
//			    for(int i = 0; i < n; i++){
//			        int tong = 0;
//	
//			        for(int j = 1; j <= arr[i] / 2; j++){
//			            if(arr[i] % j == 0){
//			                tong += j;
//			            }
//			        }
//	
//			        if(tong == arr[i] && arr[i] > 1){
//			            dem++;
//			        }
//			    }
//  		  		printf("so luong so hoan hao: %d\n", dem);
				break;
			case 4:
//			    int max1 = INT_MIN; 
//			    for (int i = 0; i < n; i++) {
//			        if (arr[i] > max1) {
//			            max1 = arr[i];
//			        }
//			    }
//			
//			    int max2 = INT_MIN; 
//			    for (int i = 0; i < n; i++) {
//			        if (arr[i] > max2 && arr[i] < max1) {
//			            max2 = arr[i];
//			        }
//			    }
//			
//			    if (max2 == INT_MIN) {
//			        printf("k co gia tri lon thu 2.\n");
//			    } else {
//			        printf("gia tri lon thu 2 la : %d\n", max2);
				break;
			case 5:
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
					arr[i] = arr[i-1];
				}
				arr[position] = addValue;
				size++;
				printf("\nThem thanh cong\n");
				
				break;
			case 6:
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
				printf("Xoa thanh cong!! (%d)",removePosition);
				
				break;
				
			case 7:
				for(int i=1 ; i<n; i++){
					int key = arr[i];
					int j = i-1;
					for(; j>=0 && key > arr[j] ; j--){
						arr[j+1] = arr[j];
					}
					arr[j+1] = key;
				}
				printf("Sorted thanh cong!");
				
				
				
				break;	
			case 8:
				for(int i = 0; i< size-1; i++){
					for(int j = 0; j< size-1-i; j++){
						if(arr[j] > arr[j+1]){
							int temp = arr[j];
							arr[j] = arr[j+1];
							arr[j+1] = temp;
						}	
					}	
				}
				
				int find;
				printf("Nhap mot gia tri muon tim ");
				scanf("%d",&find);
				
				for(int i=0 ;i< size; i++){
					printf("%d ", arr[i])	;
				}
				int start, end, mid;
				start = 0;
				end = size;
				while(start <= end){
					mid = start + (end-start)/2;					
					if(arr[mid]== find){					
						printf("\n%d duoc tim thay tai vi tri %d ", find, mid);
						break;
					}else if(arr[mid]< find){							
						start = mid +1;
					}else{						
						end = mid -1;
					}
				}
				if(start > end){
						printf("\nko tim thay gia tri %d trong mang",find);
				}
				break;
			case 9:
				break;
			case 10:
				
				
				
				break;		
				
				
			default:
                printf("Lua chon ko hop le, vui long nhap lai\n");
                break;
		}
		
		
	}
	return 0;	
}
