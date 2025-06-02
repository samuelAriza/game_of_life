// Funciones para la simulación del juego
#ifndef GAME_H
#define GAME_H

#include "bitboard.h"

// Corre la simulación mostrando cada generación
// is_manual decide si se pausa con Enter o automáticamente
void run_simulation(GameBoard *board, int generations, int is_manual);

#endif 