#include <stdio.h>
int main() {
    char c;
    printf("Nhap cac ky tu (nhan Ctrl+D de ket thuc):\n");
    while ((c = getchar()) != EOF) {     
        putchar(c); 
    }
    return 0;
}
