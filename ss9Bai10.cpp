#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int arr[MAX][MAX];
    int m = 0, n = 0; 
    int choice;

    do {
        printf("\n==========MENU==============\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In gia tri cac phan tu la le va tinh tong\n");
        printf("4. In ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("6. In ra cac phan tu nam tren duong cheo phu\n");
        printf("7. In ra dong co tong gia tri cac phan tu la lon nhat\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Nhap so dong m: ");
                scanf("%d", &m);
                printf("Nhap so cot n: ");
                scanf("%d", &n);

                printf("Nhap cac phan tu cua mang:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("arr[%d][%d] = ", i, j);
                        scanf("%d", &arr[i][j]);
                    }
                }
                break;
            }
            case 2: {
                printf("Gia tri cac phan tu cua mang theo ma tran:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                int sumOdd = 0;
                printf("Cac phan tu la so le: ");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        if (arr[i][j] % 2 != 0) {
                            printf("%d ", arr[i][j]);
                            sumOdd += arr[i][j];
                        }
                    }
                }
                printf("\nTong cac so le: %d\n", sumOdd);
                break;
            }
            case 4: {
                long long product = 1;
                printf("Cac phan tu nam tren duong bien: ");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                            printf("%d ", arr[i][j]);
                            product *= arr[i][j];
                        }
                    }
                }
                printf("\nTich cac phan tu tren duong bien: %lld\n", product);
                break;
            }
            case 5: {
                printf("Cac phan tu tren duong cheo chinh: ");
                for (int i = 0; i < m && i < n; i++) {
                    printf("%d ", arr[i][i]);
                }
                printf("\n");
                break;
            }
            case 6: {
                printf("Cac phan tu tren duong cheo phu: ");
                for (int i = 0; i < m && i < n; i++) {
                    printf("%d ", arr[i][n - i - 1]);
                }
                printf("\n");
                break;
            }
            case 7: {
                int maxSum = 0, maxRow = 0;
                for (int i = 0; i < m; i++) {
                    int rowSum = 0;
                    for (int j = 0; j < n; j++) {
                        rowSum += arr[i][j];
                    }
                    if (rowSum > maxSum) {
                        maxSum = rowSum;
                        maxRow = i;
                    }
                }
                printf("Dong co tong gia tri lon nhat: %d (Tong = %d)\n", maxRow, maxSum);
                printf("Cac phan tu cua dong do: ");
                for (int j = 0; j < n; j++) {
                    printf("%d ", arr[maxRow][j]);
                }
                printf("\n");
                break;
            }
            case 8: {
                printf("Thoat chuong trinh.\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le, vui long thu lai!\n");
            }
        }
    } while (1);

    return 0;
}

