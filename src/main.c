#include <string.h>
#include "bitboard.h"
#include "game.h"
#include "config.h"

int main(int argc, char *argv[]) {
    GameBoard game_board;
    int is_manual_mode = (argc > 1 && strcmp(argv[1], "manual") == 0); // Revisa si es modo manual
    initialize_random_board(&game_board); // Tablero inicial aleatorio
    run_simulation(&game_board, GENERATIONS, is_manual_mode); // Corre la simulación
    
    return 0;
}