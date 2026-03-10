#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"

using namespace std;

funciones::funciones(){}

int NIVEL_BASIC=8;

void funciones::imprimirTablero(){

    char tablero1[8][8];
    char tablero2[8][8];

    for(int i = 0; i < NIVEL_BASIC; i++){
        for(int j = 0; j < NIVEL_BASIC; j++){
            tablero1[i][j] = '.';
            tablero2[i][j] = '.';
        }
    }

    srand(time(0));

    char *simbolo = (char*)"X";

    int colocados = 0;

    while(colocados < 10){

        int fila = rand() % NIVEL_BASIC;
        int columna = rand() % NIVEL_BASIC;

        if(tablero1[fila][columna] != 'X'){
            tablero1[fila][columna] = *simbolo;
            colocados++;
        }

    }
    for(int i = 0; i < NIVEL_BASIC; i++){
        for(int j = 0; j < NIVEL_BASIC; j++){
            cout << tablero2[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < NIVEL_BASIC; i++){
        for(int j = 0; j < NIVEL_BASIC; j++){
            cout << tablero1[i][j]<< " ";
        }
        cout << endl;
    }

}
