// Manejo del tablero usando operaciones de bits y OpenMP

#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include "bitboard.h"
#include "config.h"

// Llena el tablero con celdas vivas de forma aleatoria
void initialize_random_board(GameBoard *board) {
    srand((unsigned)time(NULL));
    #pragma omp parallel for num_threads(NUM_THREADS) // Paraleliza el trabajo por filas
    for (int row_idx = 0; row_idx < BOARD_ROWS; row_idx++) {
        BoardRow current_row = 0;
        for (int col_idx = 0; col_idx < BOARD_COLS; col_idx++) {
            if (rand() % 2) {
                current_row |= (1ULL << col_idx); // Pone en 1 el bit si la celda está viva
            }
        }
        board->grid[row_idx] = current_row;
    }
}

// Cuenta cuántas vecinas vivas tiene una celda en la posición (fila, columna)
int count_living_neighbors(const GameBoard *board, int row, int col) {
    int count = 0;
    int fila_anterior = (row - 1 + BOARD_ROWS) % BOARD_ROWS; // Borde toroidal arriba
    int fila_siguiente = (row + 1) % BOARD_ROWS; // Borde toroidal abajo
    int columna_anterior = (col - 1 + BOARD_COLS) % BOARD_COLS; // Borde toroidal izquierda
    int columna_siguiente = (col + 1) % BOARD_COLS; // Borde toroidal derecha

    count += (board->grid[fila_anterior] >> columna_anterior) & 1; // Superior-izquierda
    count += (board->grid[fila_anterior] >> col) & 1; // Superior
    count += (board->grid[fila_anterior] >> columna_siguiente) & 1; // Superior-derecha
    count += (board->grid[row] >> columna_anterior) & 1; // Izquierda
    count += (board->grid[row] >> columna_siguiente) & 1; // Derecha
    count += (board->grid[fila_siguiente] >> columna_anterior) & 1; // Inferior-izquierda
    count += (board->grid[fila_siguiente] >> col) & 1; // Inferior
    count += (board->grid[fila_siguiente] >> columna_siguiente) & 1; // Inferior-derecha

    return count;
}

// Calcula la siguiente generación aplicando las reglas del Juego de la Vida
void compute_next_generation(const GameBoard *current, GameBoard *next) {
    #pragma omp parallel for num_threads(NUM_THREADS) // Distribuye las filas entre los hilos
    for (int row_idx = 0; row_idx < BOARD_ROWS; row_idx++) {
        BoardRow next_gen_row = 0;
        for (int col_idx = 0; col_idx < BOARD_COLS; col_idx++) {
            int cantidad_vecinos_vivos = count_living_neighbors(current, row_idx, col_idx);
            int esta_viva = (current->grid[row_idx] >> col_idx) & 1;

            if (esta_viva && (cantidad_vecinos_vivos == 2 || cantidad_vecinos_vivos == 3)) {
                next_gen_row |= (1ULL << col_idx); // La celda se mantiene viva
            } else if (!esta_viva && cantidad_vecinos_vivos == 3) {
                next_gen_row |= (1ULL << col_idx); // Una nueva celda nace
            }
        }
        next->grid[row_idx] = next_gen_row;
    }
}