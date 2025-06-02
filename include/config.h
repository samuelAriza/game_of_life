// Constantes para configurar el Juego de la Vida
#ifndef CONFIG_H

#define CONFIG_H
#define BOARD_ROWS 64 // Filas del tablero, 64 para usar uint64_t
#define BOARD_COLS 64 // Columnas, igual que filas para un tablero cuadrado
#define GENERATIONS 100 // Número de generaciones a simular
#define NUM_THREADS 4 // Hilos para OpenMP, probé con 4 por mi máquina

#endif 