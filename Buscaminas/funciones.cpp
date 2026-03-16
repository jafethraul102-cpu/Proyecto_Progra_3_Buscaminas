#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "funciones.h"

using namespace std;

funciones::funciones(){}

void funciones::imprimirTablero(int filas, int colum, int bombas){
    cout<<endl;
    cout<<string(colum*3.5,'=')<<endl<<endl;
    string tablero1[filas][colum];
    string tablero2[filas][colum];

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < colum; j++){
            tablero1[i][j] = "🟩";
            tablero2[i][j] = "🟩";
        }
    }

    srand(time(0));

    int colocados = 0;

    while(colocados < bombas){

        int fila = rand() % filas;
        int columna = rand() % colum;

        if(tablero1[fila][columna] != "💣"){
            tablero1[fila][columna] = "💣";
            colocados++;
        }
    }

    // Encabezado
    cout << "    ";
    for(int j = 0; j < colum; j++){
        if(j<10){
         cout << "| " << j;
        }else{
         cout << "|" << j;
        }

    }
    cout << endl;

    cout << "   ";
    for(int j = 0; j < colum; j++){
        cout << "---";
    }
    cout << "--";
    cout << endl;

    // Tablero
    for(int i = 0; i < filas; i++){

        cout << setw(3) << i << "|";

        for(int j = 0; j < colum; j++){
            cout <<" "<<  tablero2[i][j];

        }


        cout << endl;
    }
    cout << endl;
    cout<<string(colum*3.5,'=')<<endl;
    cout << endl;
}


void funciones::menuJuego(int filas, int colum,int bombas){
    int totalCeldas = filas * colum;
    int celdasDescubiertas = 0;
    int opcion;
    cout<<string(40,'=')<<endl;
    do{
        cout << "====== MENU DE JUEGO ======\n";
        cout << "1. Quitar casilla\n";
        cout << "2. Colocar banderin\n";
        cout << "3. Retirar banderin\n";
        cout << "4. Rendirse\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
        case 1:{

            break;
        }
        case 2:{

            break;
        }
        case 3:{

            break;
        }
        case 4:{

            break;
        }
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }

        if(celdasDescubiertas == totalCeldas - bombas){
            cout<<"🎉 GANASTE! Descubriste todas las casillas libres\n";
            return;
        }
    }while(opcion < 1 || opcion > 4);
    cout<<string(40,'=')<<endl;

    if(celdasDescubiertas == totalCeldas - bombas){
        cout<<"🎉 GANASTE! Descubriste todas las casillas libres\n";
        return;
    }
}
