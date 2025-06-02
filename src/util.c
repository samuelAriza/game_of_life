// Visualizacion del tablero y manejo de simulación
#include <stdio.h>
#include <unistd.h> // Para usar usleep
#include "util.h"
#include "config.h"

// Imprime el tablero con O para vivas y . para muertas
void display_board(const GameBoard *board) {
    printf("\033[H\033[J"); // Limpia la consola
    for (int row = 0; row < BOARD_ROWS; row++) {
        for (int col = 0; col < BOARD_COLS; col++) {
            printf("%c ", (board->grid[row] >> col) & 1 ? 'O' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Pausa entre generaciones de manera manual o con retraso
void pause_execution(int is_manual) {
    if (is_manual) {
        printf("Presiona Enter para continuar a la siguiente generación...\n");
        getchar(); // Espera tecla Enter
    } else {
        usleep(500000); // Retraso de 0.5 segundos
    }
}