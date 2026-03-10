#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"

using namespace std;

funciones::funciones(){}

void funciones::imprimirTablero(int filas, int colum, int bombas){

    char tablero1[filas][colum];
    char tablero2[filas][colum];

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < colum; j++){
            tablero1[i][j] = '.';
            tablero2[i][j] = '.';
        }
    }

    srand(time(0));

    char *simbolo = (char*)"X";

    int colocados = 0;

    while(colocados < bombas){

        int fila = rand() % filas;
        int columna = rand() % colum;

        if(tablero1[fila][columna] != 'X'){
            tablero1[fila][columna] = *simbolo;
            colocados++;
        }

    }
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < colum; j++){
            cout << tablero2[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < colum; j++){
            cout << tablero1[i][j]<< " ";
        }
        cout << endl;
    }

}
