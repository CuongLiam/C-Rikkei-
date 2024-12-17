#include <stdio.h>

int main() {
    int a,b,c,temp;
    printf("Input a: ");
    scanf("%d", &a);
    printf("Input b: ");
    scanf("%d", &b);
    printf("Input c: ");
    scanf("%d", &c);

    if (a>b){ 
        temp = a;
        a = b;
        b = temp;
    }
    if (a>c){ 
        temp = a;
        a = c;
        c = temp;
    }
    if (b>c){ 
        temp = b;
        b = c;
        c = temp;
    }
    printf("Nho den lon: %d, %d, %d\n",a,b,c);

    return 0;
}

