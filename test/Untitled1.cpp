#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int age;
    float gpa;
} Student;

typedef struct {
    Student data[MAX_STUDENTS];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX_STUDENTS - 1;
}

void push(Stack *s, Student sv) {
    if (!isStackFull(s)) {
        s->data[++s->top] = sv;
    } else {
        printf("Stack is full, cannot undo further!\n");
    }
}

Student pop(Stack *s) {
    if (!isStackEmpty(s)) {
        return s->data[s->top--];
    } else {
        printf("No actions to undo!\n");
        Student emptyStudent = {"", 0, 0.0};
        return emptyStudent;
    }
}

typedef struct {
    Student *list[MAX_STUDENTS];
    int count;
} StudentList;

void initStudentList(StudentList *sl) {
    sl->count = 0;
}

void addStudent(StudentList *sl, Stack *undoStack) {
    if (sl->count >= MAX_STUDENTS) {
        printf("Danh sach sinh vien da day!\n");
        return;
    }
    
    Student *sv = (Student *)malloc(sizeof(Student));
    printf("Nhap ten: ");
    scanf(" %[^]", sv->name);
    printf("Nhap tuoi: ");
    scanf("%d", &sv->age);
    printf("Nhap GPA: ");
    scanf("%f", &sv->gpa);
    
    push(undoStack, *sv);
    sl->list[sl->count++] = sv;
    printf("Sinh vien da duoc them!\n");
}

void editStudent(StudentList *sl, Stack *undoStack) {
    if (sl->count == 0) {
        printf("Danh sach sinh vien rong!\n");
        return;
    }
    
    int index;
    printf("Nhap vi tri sinh vien can sua (1-%d): ", sl->count);
    scanf("%d", &index);
    
    if (index < 1 || index > sl->count) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    
    index--;
    push(undoStack, *sl->list[index]);
    
    printf("Nhap ten moi: ");
    printf("Nhap ten moi: ");
	scanf(" %49[^\n]", sl->list[index]->name);


    printf("Nhap tuoi moi: ");
    scanf("%d", &sl->list[index]->age);
    printf("Nhap GPA moi: ");
    scanf("%f", &sl->list[index]->gpa);
    
    printf("Sinh vien da duoc sua!\n");
}

void deleteStudent(StudentList *sl, Stack *undoStack) {
    if (sl->count == 0) {
        printf("Danh sach sinh vien rong!\n");
        return;
    }
    
    int index;
    printf("Nhap vi tri sinh vien can xoa (1-%d): ", sl->count);
    scanf("%d", &index);
    
    if (index < 1 || index > sl->count) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    
    index--;
    push(undoStack, *sl->list[index]);
    free(sl->list[index]);
    
    for (int i = index; i < sl->count - 1; i++) {
        sl->list[i] = sl->list[i + 1];
    }
    sl->count--;
    printf("Sinh vien da duoc xoa!\n");
}

void undo(StudentList *sl, Stack *undoStack) {
    if (isStackEmpty(undoStack)) {
        printf("Khong co thao tac nao de Undo!\n");
        return;
    }
    
    Student lastStudent = pop(undoStack);
    if (sl->count > 0) {
        free(sl->list[--sl->count]);
        printf("Da undo sinh vien: %s\n", lastStudent.name);
    }
}

void displayStudents(StudentList *sl) {
    if (sl->count == 0) {
        printf("Danh sach sinh vien rong!\n");
        return;
    }
    for (int i = 0; i < sl->count; i++) {
        printf("%d. %s - Tuoi: %d - GPA: %.2f\n", i + 1, sl->list[i]->name, sl->list[i]->age, sl->list[i]->gpa);
    }
}

int main() {
    StudentList sl;
    Stack undoStack;
    initStudentList(&sl);
    initStack(&undoStack);
    
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Them sinh vien\n");
        printf("2. Sua sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Undo\n");
        printf("5. Hien thi danh sach sinh vien\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(&sl, &undoStack);
                break;
            case 2:
                editStudent(&sl, &undoStack);
                break;
            case 3:
                deleteStudent(&sl, &undoStack);
                break;
            case 4:
                undo(&sl, &undoStack);
                break;
            case 5:
                displayStudents(&sl);
                break;
            case 0:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
    
    return 0;
}

