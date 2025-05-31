#include "game.h"
#include "board.h"
#include "menu.h"
#include <stdio.h>

void playGame(int* board, int size, int scoreToWin) {
    char choice;
    int currentScore = 0;   // Track total score from merges
    int bestScore = 0;
    int highestTile = 0;    // Track highest tile for win condition
    resetBoard(board, size); // Implements zeros each new board size
    printBoard(board, size, currentScore, bestScore);  // Initial board print

    do {
        choice = menu();  // Get the player's choice

        switch (choice) {
        case 'N': case 'n':  // Start a new game
            currentScore = 0;
            printf("-----------------------------------------------\n");
            printf("----  Game 1:  board size %d win value %d -----  \n",size,scoreToWin);
            printf("-----------------------------------------------\n");
            initializeBoard(board, size);  // Initialize the board
            break;
            // In each one of the cases we will first check if a new game has started
        case 'R': case 'r':
        case 'L': case 'l':
        case 'U': case 'u':
        case 'D': case 'd':
            if (highestTile == 0) {  // If the game has not started
                printf("You need to start a new game first!\n");
                continue;
            }
            else {
                int scoreGained = -1; // flag that checks if no tiles were moved
                // Process the move
                if (choice == 'R' || choice == 'r') scoreGained = moveRight(board, size);
                if (choice == 'L' || choice == 'l') scoreGained = moveLeft(board, size);
                if (choice == 'U' || choice == 'u') scoreGained = moveUp(board, size);
                if (choice == 'D' || choice == 'd') scoreGained = moveDown(board, size);

                if (scoreGained == -1) {
                    printf("Nothing to move in this direction, please choose another option!\n");
                    continue;
                }
                currentScore += scoreGained;
                if (currentScore > bestScore) {
                    bestScore = currentScore;
                }


                // Add a new number if the move was valid
                addOneNumber(board, size);

                // Check for game over after adding new number
                if (!hasValidMoves(board, size) && checkemptycells(board, size) == 0) {
                    printBoard(board, size, currentScore, bestScore);
                    printf("GAME OVER! Your score is: %d\n", currentScore);
                    continue;
                }
            }
            break;

        case 'E': case 'e':  // Exit the game
            printf("Exiting the game...\n");
            return;
        }

        // Update score after the move
        highestTile = maxInBoard(board, size);

        printBoard(board, size, currentScore, bestScore);  // Print the updated board

        // Check if the player has won
        if (highestTile == scoreToWin) {
            printf("You won %d! Your score is: %d\n", scoreToWin, currentScore);
            continue;
        }

    } while (choice != 'E' && choice != 'e');  // Continue playing until 'E' is chosen
}