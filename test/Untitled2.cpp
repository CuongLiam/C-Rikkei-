#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10  // S? t?ng t?i da

typedef struct {
    int currentFloor;
} Elevator;

void goToFloor(Elevator *elevator, int floor) {
    if (floor < 1 || floor > MAX_FLOORS) {
        printf("T?ng không h?p l?! (Ch? t? 1 d?n %d)\n", MAX_FLOORS);
        return;
    }
    printf("Thang máy dang di chuy?n t? t?ng %d d?n t?ng %d...\n", elevator->currentFloor, floor);
    elevator->currentFloor = floor;
    printf("Ðã d?n t?ng %d!\n", elevator->currentFloor);
}

int main() {
    Elevator elevator;
    elevator.currentFloor = 1;

    int choice;
    while (1) {
        printf("\nThang máy hi?n t?i ? t?ng: %d\n", elevator.currentFloor);
        printf("Nh?p t?ng mu?n d?n (1-%d, 0 d? thoát): ", MAX_FLOORS);
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thoát chuong trình!\n");
            break;
        }
        goToFloor(&elevator, choice);
    }

    return 0;
}

