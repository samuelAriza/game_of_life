
// Definiciones para manejar el tablero con operaciones a nivel de bits
#ifndef BITBOARD_H
#define BITBOARD_H

#include <stdint.h>
#include "config.h"

// Tipo para una fila del tablero, uso 64 bits para optimizar memoria
typedef uint64_t BoardRow;

// Estructura del tablero, un arreglo de filas de 64 bits
typedef struct {
    BoardRow grid[BOARD_ROWS]; // Cada fila es un entero de 64 bits
} GameBoard;

// Inicializa el tablero con celdas vivas aleatorias
void initialize_random_board(GameBoard *board);

// Cuenta los vecinos vivos de una celda en la posición (row, col)
int count_living_neighbors(const GameBoard *board, int row, int col);

// Calcula la siguiente generación del tablero usando hilos
void compute_next_generation(const GameBoard *current, GameBoard *next);

#endif 