#ifndef __BOARD__
#define __BOARD__

void printBoard(int* board, int size, int currentScore, int bestScore);
void initializeBoard(int* board, int size);
int checkemptycells(int* board, int size);
int addOneNumber(int* board, int size);
int moveRight(int* board, int size);
int moveLeft(int* board, int size);
int moveUp(int* board, int size);
int moveDown(int* board, int size);
int maxInBoard(int* board, int size);
int hasValidMoves(int* board, int size);
void resetBoard(int* board, int size);
#endif