// Lógica para ejecutar la simulación del Juego de la Vida
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "util.h"

// Ejecuta la simulación mostrando cada generación
void run_simulation(GameBoard *board, int generations, int is_manual) {
    GameBoard next_gen;
    memset(&next_gen, 0, sizeof(GameBoard)); // Borrar el tablero auxiliar

    for (int current_gen = 0; current_gen < generations; current_gen++) {
        display_board(board);
        printf("Generación %d/%d\n", current_gen + 1, generations);
        compute_next_generation(board, &next_gen); // Calcular la siguiente generación
        #pragma omp parallel for num_threads(NUM_THREADS) // Copiar filas en paralelo
        for (int row = 0; row < BOARD_ROWS; row++) {
            board->grid[row] = next_gen.grid[row];
        }
        pause_execution(is_manual); // Hacer una pausa para observar el tablero
    }

    display_board(board); // Muestra el tablero final
    printf("Simulación terminada (%d generaciones).\n", generations);
}