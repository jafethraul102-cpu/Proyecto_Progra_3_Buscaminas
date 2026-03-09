#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"

using namespace std;

funciones::funciones(){}

void funciones::imprimirTablero(){

    char tablero1[8][8];
    char tablero2[8][8];

    // llenar ambos tableros con .
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tablero1[i][j] = '.';
            tablero2[i][j] = '.';
        }
    }

    srand(time(0));

    char *simbolo = (char*)"X";

    int colocados = 0;

    while(colocados < 10){

        int fila = rand() % 8;
        int columna = rand() % 8;

        if(tablero1[fila][columna] != 'X'){
            tablero1[fila][columna] = *simbolo;
            colocados++;
        }

    }

    // SOLO imprimimos el segundo tablero
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << tablero2[i][j] << " ";
        }
        cout << endl;
    }

}
