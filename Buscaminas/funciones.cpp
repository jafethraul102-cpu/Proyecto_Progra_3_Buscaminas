#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "funciones.h"

using namespace std;

funciones::funciones(){}

void funciones::InicializarTablero(int filas,int colum,int bombas,string TableroBombas[][50],string TableroVista[][50]){

    for(int i=0;i<filas;i++){
        for(int j=0;j<colum;j++){
            TableroBombas[i][j]="0";
            TableroVista[i][j]="-";
        }
    }

    srand(time(0));

    int colocadas=0;

    while(colocadas<bombas){

        int f=rand()%filas;
        int c=rand()%colum;

        if(TableroBombas[f][c]!="*"){
            TableroBombas[f][c]="*";
            colocadas++;
        }
    }

    ColocarIdentificadoresdeMinas(filas,colum,TableroBombas);

    imprimirTablero(filas,colum,TableroVista);
}

void funciones::imprimirTablero(int filas,int colum,string TableroVista[][50]){
    int tamañoLinea=0;
    if(colum==8){
        tamañoLinea=32;
    }else if(colum==16){
        tamañoLinea=55;
    }else{
        tamañoLinea=97;
    }
    cout<<endl;
    cout << string(tamañoLinea, '=') << endl;
    cout<<endl;
    cout<<"    ";
    for(int j=0;j<colum;j++){
        if(j<10) cout<<"| "<<j;
        else cout<<"|"<<j;
    }
    cout<<endl;

    cout<<"   ";
    for(int j=0;j<colum;j++){
        cout<<"---";
    }
    cout<<"--"<<endl;

    for(int i=0;i<filas;i++){

        cout<<setw(3)<<i<<"|";

        for(int j=0;j<colum;j++){
            cout<<"  "<<TableroVista[i][j];
        }

        cout<<endl;
    }
    cout<<endl;
    cout << string(tamañoLinea, '=') << endl;

}

void funciones::ColocarIdentificadoresdeMinas(int filas,int colum,string TableroBombas[][50]){

    int x[8]={-1,-1,-1,0,0,1,1,1};
    int y[8]={-1,0,1,-1,1,-1,0,1};

    string numeros[9] = {"0","1","2","3","4","5","6","7","8"};

    for(int i=0;i<filas;i++){
        for(int j=0;j<colum;j++){

            if(TableroBombas[i][j]=="*"){
                continue;
            }

            int contador=0;

            for(int k=0;k<8;k++){

                int ni=i+x[k];
                int nj=j+y[k];

                if(ni>=0 && ni<filas && nj>=0 && nj<colum){
                    if(TableroBombas[ni][nj]=="*"){
                        contador++;
                    }
                }
            }

            if(contador>0){
                TableroBombas[i][j]=numeros[contador];
            }
        }
    }
}

void funciones::descubrirZona(int fila,int colu,int filas,int colum, string TableroBombas[][50], string TableroVista[][50]){

    if(fila<0 || fila>=filas || colu<0 || colu>=colum){
        return;
    }
    if(TableroVista[fila][colu]!="-"){
        return;
    }

    TableroVista[fila][colu]=TableroBombas[fila][colu];

    if(TableroBombas[fila][colu]!="0"){
        return;
    }

    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){

            if(i==0 && j==0){
                continue;
            }
            descubrirZona(fila+i,colu+j,filas,colum,TableroBombas,TableroVista);
        }
    }
}

int funciones::menuJuego(int filas,int colum,int bombas,string TableroBombas[][50],string TableroVista[][50]){
    int banderas = 0;
    int opcion;

    do{
        cout<<"Banderas: "<<banderas<<"/"<<bombas<<"\n";
        cout << string(40, '=') << endl;
        cout<<"1. Quitar casilla.\n";
        cout<<"2. Poner Bandera.\n";
        cout<<"3. Quitar bandera.\n";
        cout<<"4. Salir.\n";
        cout << string(40, '=') << endl;
        cout<<"Opcion: ";
        cin>>opcion;
        cout << string(40, '=') << endl;
        int fila,colu;

        switch(opcion){

        case 1:

            cout<<"fila(espacio)columna: ";
            cin>>fila>>colu;

            if(fila < 0 || fila >= filas || colu < 0 || colu >= colum){
                cout<<"Coordenadas invalidas\n";
                break;
            }

            if(TableroVista[fila][colu] != "-"){
                cout<<"Esa casilla ya fue usada.\n";
                break;
            }

            if(TableroBombas[fila][colu]=="*"){
                for(int i=0;i<filas;i++){
                    for(int j=0;j<colum;j++){
                        if(TableroBombas[i][j]=="*"){
                            TableroVista[i][j]="*";
                        }
                    }
                }

                imprimirTablero(filas,colum,TableroVista);

                cout<<"PERDISTE\n";
                return 0;
            }

            descubrirZona(fila,colu,filas,colum,TableroBombas,TableroVista);

            imprimirTablero(filas,colum,TableroVista);

            if(verificarVictoria(filas,colum,TableroBombas,TableroVista)){
                return 1;
            }

            break;

        case 2:
            cout<<"fila(espacio)columna: ";
            cin>>fila>>colu;

            if(fila < 0 || fila >= filas || colu < 0 || colu >= colum){
                cout<<"Coordenadas invalidas\n";
                break;
            }

            if(TableroVista[fila][colu] != "-"){
                cout<<"No puedes poner bandera aqui.\n";
                break;
            }

            if(banderas >= bombas){
                cout<<"Ya colocaste todas las banderas.\n";
                break;
            }

            TableroVista[fila][colu]="/";
            banderas++; //

            imprimirTablero(filas,colum,TableroVista);
            break;

        case 3:
            cout<<"fila(espacio)columna: ";
            cin>>fila>>colu;

            if(fila < 0 || fila >= filas || colu < 0 || colu >= colum){
                cout<<"Coordenadas invalidas\n";
                break;
            }

            if(TableroVista[fila][colu] != "/"){
                cout<<"No puedes quitar una bandera porque no hay.\n";
                break;
            }

            TableroVista[fila][colu]="-";
            banderas--;

            imprimirTablero(filas,colum,TableroVista);
            break;

        case 4:
            cout<<"saliendo.\n";
            break;

        default:
            cout<<"opcion incorreccta.\n";
        }


    }while(opcion!=4);

    return 0;
}

bool funciones::verificarVictoria(int filas,int colum, string TableroBombas[][50],string TableroVista[][50]){

    for(int i=0;i<filas;i++){
        for(int j=0;j<colum;j++){
            if(TableroBombas[i][j] != "*" && TableroVista[i][j] == "-"){
                return false;
            }
        }
    }

    return true;
}
