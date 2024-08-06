#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void initializeMaze(char maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            maze[i][j] = (rand() % 2) ? ' ' : '#'; // ' ' = camino, '#' = pared
        }
    }
    maze[0][0] = ' '; // Entrada
    maze[SIZE - 1][SIZE - 1] = ' '; // Salida
}

void printMaze(char maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char maze[SIZE][SIZE];
    int playerX = 0, playerY = 0;
    char move;

    srand(time(NULL)); // Inicializa la semilla para la generación aleatoria
    initializeMaze(maze);

    while (playerX != SIZE - 1 || playerY != SIZE - 1) {
        system("clear"); // Limpia la consola (usa "cls" en Windows)
        printMaze(maze);
        printf("Movimientos: W (arriba), A (izquierda), S (abajo), D (derecha)\n");
        printf("Posición actual: (%d, %d)\n", playerX, playerY);
        printf("Ingrese su movimiento: ");
        scanf(" %c", &move);

        // Actualiza la posición del jugador
        if (move == 'w' && playerX > 0 && maze[playerX - 1][playerY] == ' ') {
            playerX--;
        } else if (move == 's' && playerX < SIZE - 1 && maze[playerX + 1][playerY] == ' ') {
            playerX++;
        } else if (move == 'a' && playerY > 0 && maze[playerX][playerY - 1] == ' ') {
            playerY--;
        } else if (move == 'd' && playerY < SIZE - 1 && maze[playerX][playerY + 1] == ' ') {
            playerY++;
        } else {
            printf("Movimiento inválido. Intenta de nuevo.\n");
            getchar(); // Espera a que el usuario presione una tecla
        }
    }

    printf("¡Felicidades! Has encontrado la salida.\n");
    return 0;
}
