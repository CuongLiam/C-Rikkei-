#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);
    
    if (n<2) {
        printf("%d khong phai la so nguyen to",n);
        return 1;
    }

    printf("%d so nguyen to dau tien la: ", n);
    int count = 0;
    int number = 2;

    while (count < n) {
        int prime = 1;
        for (int i = 2; i <= sqrt(number); i++) {
            if (number % i == 0) {
                prime = 0;
                break;
            }
        }

        if (prime) {
            printf("%d ", number);
            count++;
        }

        number++;
    }

    printf("\n");
    return 0;
}

