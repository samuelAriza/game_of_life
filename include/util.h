// Funciones para mostrar el tablero y controlar pausas
#ifndef UTIL_H
#define UTIL_H

#include "bitboard.h"

// Imprime el tablero en consola usando O y .
void display_board(const GameBoard *board);

// Pausa entre generaciones, manual con Enter o automática
void pause_execution(int is_manual);

#endif 