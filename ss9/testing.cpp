#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define WIDTH 10
#define HEIGHT 20

// Shapes
int shapes[7][4][4] = {
    {{1, 1, 1, 1}},                             // I
    {{1, 1}, {1, 1}},                          // O
    {{0, 1, 1}, {1, 1, 0}},                    // S
    {{1, 1, 0}, {0, 1, 1}},                    // Z
    {{1, 1, 1}, {0, 1, 0}},                    // T
    {{1, 1, 1}, {1, 0, 0}},                    // L
    {{1, 1, 1}, {0, 0, 1}}                     // J
};

char grid[HEIGHT][WIDTH];
int current_shape[4][4];
int current_x = 0, current_y = 0;

// Function prototypes
void initialize_grid();
void print_grid();
void spawn_shape();
void copy_shape(int shape[4][4]);
int is_valid_position(int dx, int dy);
void place_shape();
void remove_full_lines();
void rotate_shape();
void game_loop();

void initialize_grid() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = '.';
        }
    }
}

void print_grid() {
    system("cls");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c ", grid[y][x]);
        }
        printf("\n");
    }
    printf("\nUse arrow keys to move, 'w' to rotate, 'q' to quit.\n");
}

void spawn_shape() {
    int shape_index = rand() % 7;
    copy_shape(shapes[shape_index]);
    current_x = WIDTH / 2 - 2;
    current_y = 0;
}

void copy_shape(int shape[4][4]) {
    memset(current_shape, 0, sizeof(current_shape));
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            current_shape[y][x] = shape[y][x];
        }
    }
}

int is_valid_position(int dx, int dy) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (current_shape[y][x]) {
                int new_x = current_x + x + dx;
                int new_y = current_y + y + dy;

                if (new_x < 0 || new_x >= WIDTH || new_y >= HEIGHT) {
                    return 0;
                }
                if (new_y >= 0 && grid[new_y][new_x] != '.') {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void place_shape() {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (current_shape[y][x]) {
                grid[current_y + y][current_x + x] = '#';
            }
        }
    }
}

void remove_full_lines() {
    for (int y = HEIGHT - 1; y >= 0; y--) {
        int full = 1;
        for (int x = 0; x < WIDTH; x++) {
            if (grid[y][x] == '.') {
                full = 0;
                break;
            }
        }

        if (full) {
            for (int ny = y; ny > 0; ny--) {
                for (int x = 0; x < WIDTH; x++) {
                    grid[ny][x] = grid[ny - 1][x];
                }
            }
            for (int x = 0; x < WIDTH; x++) {
                grid[0][x] = '.';
            }
            y++; // Check the same line again
        }
    }
}

void rotate_shape() {
    int rotated[4][4] = {0};
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            rotated[x][3 - y] = current_shape[y][x];
        }
    }

    if (is_valid_position(0, 0)) {
        memcpy(current_shape, rotated, sizeof(current_shape));
    }
}

void game_loop() {
    spawn_shape();
    int ch;

    while (1) {
        print_grid();

        // Place the shape on the grid
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                if (current_shape[y][x]) {
                    grid[current_y + y][current_x + x] = '#';
                }
            }
        }

        // Input handling
        if (_kbhit()) {
            ch = _getch();

            if (ch == 'q') break;

            if (ch == 224) { // Arrow keys
                ch = _getch();
                if (ch == 75 && is_valid_position(-1, 0)) current_x--;
                if (ch == 77 && is_valid_position(1, 0)) current_x++;
                if (ch == 80 && is_valid_position(0, 1)) current_y++;
            } else if (ch == 'w') {
                rotate_shape();
            }
        }

        if (!is_valid_position(0, 1)) {
            place_shape();
            remove_full_lines();
            spawn_shape();
            if (!is_valid_position(0, 0)) {
                printf("Game Over!\n");
                break;
            }
        } else {
            current_y++;
        }

        // Delay
        _sleep(500);
    }
}

int main() {
    srand(time(0));
    initialize_grid();
    game_loop();
    return 0;
}

