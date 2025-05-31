#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printBoard(int* board, int size, int currentScore, int bestScore)
{
    printf("Score: %d Best: %d\n", currentScore, bestScore);
    // Pointer for traversing the board
    int* current = board;

    // Print initial line of dashes
    for (int d = 0; d < size * 7 + 1; d++) {
        printf("-");
    }
    printf("\n");

    // For each row
    for (int i = 0; i < size; i++) {
        // Print row with values
        for (int j = 0; j < size; j++) {
            printf("|");
            // Print number or spaces for zero
            if (*current == 0) {
                printf("      ");
            }
            else {
                printf(" %3d  ", *current);
            }
            current++;
        }
        printf("|\n");  // End of row

        // Print line of dashes after each row
        for (int d = 0; d < size * 7 + 1; d++) {
            printf("-");
        }
        printf("\n");

    }
}
void initializeBoard(int* board, int size)
{
    //random number generator
    srand(time(NULL));

    // Clear the board (set all cells to 0)
    for (int i = 0; i < size * size; i++) {
        *(board + i) = 0;  // Use pointer arithmetic to set each cell to 0
    }

    // Generate random positions for the first two numbers
    for (int i = 0; i < 2; i++) {
        int position;
        do {
            position = rand() % (size * size);  // Random position in the board
        } while (*(board + position) != 0);  // Ensure the position is empty

        // Place either a 2 or a 4 at the random position
        *(board + position) = (rand() < (RAND_MAX * 0.7)) ? 2 : 4;  // 70% chance for 2 and 30% for 4
    }
}
int addOneNumber(int* board, int size)
{
    //random number generator
    srand(time(NULL));
    int emptyCels = checkemptycells(board, size);
    if (emptyCels == 0) {
        return 0;
    }
    if (emptyCels > 0) {
        // Generate random position
        for (int i = 0; i < 1; i++) {
            int position;
            do {
                position = rand() % (size * size);  // Random position in the board
            } while (*(board + position) != 0);  // Ensure the position is empty

            // Place either a 2 or a 4 at the random position
            *(board + position) = (rand() < (RAND_MAX * 0.7)) ? 2 : 4;  // 70% chance for 2 and 30% for 4
        }
    }
    return 1;
}
int checkemptycells(int* board, int size) {
    int countZeros = 0;
    for (int i = 0; i < size * size;i++) {
        if (*(board + i) == 0)
            countZeros++;
    }
    return countZeros;

}
int maxInBoard(int* board, int size) {
    int max = *board;
    for (int i = 1; i < size * size;i++) {
        if (*(board + i) > max)
            max = *(board + i);
    }
    return max;
}

int moveRight(int* board, int size) {
    int scoreGained = 0; // a variable to track the score gained
    int moved = 0; //0 meanse no tiles moved, 1 means at least one moved
    // For each row
    for (int i = 0; i < size; i++) {
        int* rowStart = board + (i * size);

        // First, move all non-zero numbers to the right
        for (int j = size - 2; j >= 0; j--) {
            if (*(rowStart + j) != 0) {
                int k = j;
                while (k < size - 1 && *(rowStart + k + 1) == 0) {
                    *(rowStart + k + 1) = *(rowStart + k);
                    *(rowStart + k) = 0;
                    moved = 1; // at least one tile moved
                    k++;
                }
            }
        }

        // Then, merge ONLY ONCE per row, starting from rightmost position
        for (int j = size - 1; j > 0; j--) {
            if (*(rowStart + j) != 0 && *(rowStart + j) == *(rowStart + j - 1)) {
                *(rowStart + j) *= 2;
                scoreGained += *(rowStart + j);  // Add merged value to score
                *(rowStart + j - 1) = 0;
                moved = 1; // at least one tile moved

                // Shift remaining numbers right
                for (int k = j - 1; k > 0; k--) {
                    *(rowStart + k) = *(rowStart + k - 1);
                    *(rowStart + k - 1) = 0;
                }
                break;  // Only one merge per row
            }
        }
    }
    return moved ? scoreGained : -1;
}

int moveLeft(int* board, int size) {
    int scoreGained = 0;
    int moved = 0; //0 meanse no tiles moved, 1 means at least one moved
    // For each row
    for (int i = 0; i < size; i++) {
        int* rowStart = board + (i * size);

        // Move all non-zero numbers to the left
        for (int j = 1; j < size; j++) {
            if (*(rowStart + j) != 0) {
                int k = j;
                while (k > 0 && *(rowStart + k - 1) == 0) {
                    *(rowStart + k - 1) = *(rowStart + k);
                    *(rowStart + k) = 0;
                    moved = 1; // at least one tile moved
                    k--;
                }
            }
        }

        // Merge ONLY ONCE per row, starting from leftmost position
        for (int j = 0; j < size - 1; j++) {
            if (*(rowStart + j) != 0 && *(rowStart + j) == *(rowStart + j + 1)) {
                *(rowStart + j) *= 2;
                scoreGained += *(rowStart + j);
                *(rowStart + j + 1) = 0;
                moved = 1; // at least one tile moved

                // Shift remaining numbers left
                for (int k = j + 1; k < size - 1; k++) {
                    *(rowStart + k) = *(rowStart + k + 1);
                    *(rowStart + k + 1) = 0;
                }
                break;  // Only one merge per row
            }
        }
    }
    return moved ? scoreGained : -1;
}

int moveUp(int* board, int size) {
    int scoreGained = 0;
    int moved = 0; //0 meanse no tiles moved, 1 means at least one moved
    // For each column
    for (int j = 0; j < size; j++) {
        // Move all non-zero numbers up
        for (int i = 1; i < size; i++) {
            if (*(board + (i * size) + j) != 0) {
                int k = i;
                while (k > 0 && *(board + ((k - 1) * size) + j) == 0) {
                    *(board + ((k - 1) * size) + j) = *(board + (k * size) + j);
                    *(board + (k * size) + j) = 0;
                    moved = 1; // at least one tile moved
                    k--;
                }
            }
        }

        // Merge ONLY ONCE per column, starting from top
        for (int i = 0; i < size - 1; i++) {
            if (*(board + (i * size) + j) != 0 &&
                *(board + (i * size) + j) == *(board + ((i + 1) * size) + j)) {
                *(board + (i * size) + j) *= 2;
                scoreGained += *(board + (i * size) + j);
                *(board + ((i + 1) * size) + j) = 0;
                moved = 1; // at least one tile moved

                // Shift remaining numbers up
                for (int k = i + 1; k < size - 1; k++) {
                    *(board + (k * size) + j) = *(board + ((k + 1) * size) + j);
                    *(board + ((k + 1) * size) + j) = 0;
                }
                break;  // Only one merge per column
            }
        }
    }
    return moved ? scoreGained : -1;
}

int moveDown(int* board, int size) {
    int scoreGained = 0;
    int moved = 0; //0 meanse no tiles moved, 1 means at least one moved
    // For each column
    for (int j = 0; j < size; j++) {
        // Move all non-zero numbers down
        for (int i = size - 2; i >= 0; i--) {
            if (*(board + (i * size) + j) != 0) {
                int k = i;
                while (k < size - 1 && *(board + ((k + 1) * size) + j) == 0) {
                    *(board + ((k + 1) * size) + j) = *(board + (k * size) + j);
                    *(board + (k * size) + j) = 0;
                    moved = 1; // at least one tile moved
                    k++;
                }
            }
        }

        // Merge ONLY ONCE per column, starting from bottom
        for (int i = size - 1; i > 0; i--) {
            if (*(board + (i * size) + j) != 0 &&
                *(board + (i * size) + j) == *(board + ((i - 1) * size) + j)) {
                *(board + (i * size) + j) *= 2;
                scoreGained += *(board + (i * size) + j);
                *(board + ((i - 1) * size) + j) = 0;
                moved = 1; // at least one tile moved

                // Shift remaining numbers down
                for (int k = i - 1; k > 0; k--) {
                    *(board + (k * size) + j) = *(board + ((k - 1) * size) + j);
                    *(board + ((k - 1) * size) + j) = 0;
                }
                break;  // Only one merge per column
            }
        }
    }
    return moved ? scoreGained : -1;
}
int hasValidMoves(int* board, int size) {
    // Check horizontal adjacent pairs
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (*(board + (i * size) + j) == *(board + (i * size) + j + 1)) {
                return 1;  // Found adjacent equal numbers horizontally
            }
        }
    }

    // Check vertical adjacent pairs
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size - 1; i++) {
            if (*(board + (i * size) + j) == *(board + ((i + 1) * size) + j)) {
                return 1;  // Found adjacent equal numbers vertically
            }
        }
    }

    return 0;  // No possible merges found
}
void resetBoard(int* board, int size) {
    for (int i = 0; i < size * size; i++) {
        *(board + i) = 0;
    }
}
