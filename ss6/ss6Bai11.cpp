#include <stdio.h>

int main() {
    int n;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Vui long nhap so nguyen duong.\n");
        return 0;
    }

    int count = 0;
    int check = 2;   

    printf("Cac so nguyen to dau tien la: ");
    while (count < n) {
        int flag = 1;
        for (int i = 2; i * i <= check; i++) {
            if (check % i == 0){
                flag = 0;
                break;
            }
        }
        if(flag){
            printf("%d ",check);
            count++;
        }
        check++;
    }

    printf("\n");
    return 0;
}

