#include <stdio.h>
#include "menu.h"

char menu() {
    printf("Please choose one of the following options:\n");
    printf("N/n - New Game\n");
    printf("R/r - Move Right\n");
    printf("L/l - Move Left\n");
    printf("U/u - Move Up\n");
    printf("D/d - Move Down\n");
    printf("E/e - Exit\n");

    char choice;    
    do {
        scanf(" %c", &choice); //Assuming the input is only one char
        
        if (choice != 'N' && choice != 'n' &&
            choice != 'R' && choice != 'r' &&
            choice != 'L' && choice != 'l' &&
            choice != 'U' && choice != 'u' &&
            choice != 'D' && choice != 'd' &&
            choice != 'E' && choice != 'e') {
            printf("Invalid input, choose another option.\n");
        }
    } while (choice != 'N' && choice != 'n' &&
        choice != 'R' && choice != 'r' &&
        choice != 'L' && choice != 'l' &&
        choice != 'U' && choice != 'u' &&
        choice != 'D' && choice != 'd' &&
        choice != 'E' && choice != 'e');

    return choice;
}