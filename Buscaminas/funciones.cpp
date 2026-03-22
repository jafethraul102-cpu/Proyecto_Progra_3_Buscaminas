#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <limits>
#include <windows.h>
#include "funciones.h"

using namespace std;

funciones::funciones(){}

void funciones::InicializarTablero(int filas,int colum,int bombas,char TableroBombas[][50],char TableroVista[][50]){

    for(int i=0;i<filas;i++){
        for(int j=0;j<colum;j++){
            TableroBombas[i][j]='0';
            TableroVista[i][j]='-';
        }
    }

    srand(time(0));

    int colocadas=0;

    while(colocadas<bombas){
        int f=rand()%filas;
        int c=rand()%colum;

        if(TableroBombas[f][c]!='*'){
            TableroBombas[f][c]='*';
            colocadas++;
        }
    }

    ColocarIdentificadoresdeMinas(filas,colum,TableroBombas);
    imprimirTablero(filas,colum,TableroVista);
}

void funciones::imprimirTablero(int filas,int colum,char TableroVista[][50]){

    int tamañoLinea=0;

    if(colum==8) tamañoLinea=32;
    else if(colum==16) tamañoLinea=55;
    else tamañoLinea=97;

    cout<<endl;
    cout<<string(tamañoLinea,'=')<<endl;
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

            char c = TableroVista[i][j];

            if(c == '-'){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Amarillo
            }
            else if(c == '/'){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // Azul
            }
            else if(c == '*'){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Rojo
            }
            else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // Verde oscuro (números)
            }

            cout << "  " << c;

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }

        cout<<endl;
    }

    cout<<endl;
    cout<<string(tamañoLinea,'=')<<endl;
}

void funciones::ColocarIdentificadoresdeMinas(int filas,int colum,char TableroBombas[][50]){

    int x[8]={-1,-1,-1,0,0,1,1,1};
    int y[8]={-1,0,1,-1,1,-1,0,1};

    char numeros[9] = {'0','1','2','3','4','5','6','7','8'};

    for(int i=0;i<filas;i++){
        for(int j=0;j<colum;j++){

            if(TableroBombas[i][j]=='*') continue;

            int contador=0;

            for(int k=0;k<8;k++){
                int ni=i+x[k];
                int nj=j+y[k];

                if(ni>=0 && ni<filas && nj>=0 && nj<colum){
                    if(TableroBombas[ni][nj]=='*'){
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

void funciones::descubrirZona(int fila,int col,int filas,int colum,char TableroBombas[][50],char TableroVista[][50]){

    if(fila<0 || fila>=filas || col<0 || col>=colum) return;

    if(TableroVista[fila][col]!='-') return;

    TableroVista[fila][col]=TableroBombas[fila][col];

    if(TableroBombas[fila][col]!='0') return;

    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){

            if(i==0 && j==0) continue;

            descubrirZona(fila+i,col+j,filas,colum,TableroBombas,TableroVista);
        }
    }
}

int funciones::menuJuego(int filas,int colum,int bombas,char TableroBombas[][50],char TableroVista[][50]){

    int banderas = 0;
    int opcion;

    do{
        cout<<"Banderas: "<<banderas<<"/"<<bombas<<"\n";
        cout<<string(40,'=')<<endl;

        cout<<"1. Quitar casillaU(-).\n";
        cout<<"2. Poner bandera(/).\n";
        cout<<"3. Quitar bandera(x->/).\n";
        cout<<"4. Salir(x).\n";

        cout<<string(40,'=')<<endl;

        opcion = leerEnteroSeguro("Opcion: ");

        int fila,col;

        switch(opcion){

        case 1:
            cout<<"fila columna: ";
            cin>>fila>>col;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(fila<0 || fila>=filas || col<0 || col>=colum){
                cout<<"Coordenadas invalidas\n";
                break;
            }

            if(TableroVista[fila][col] != '-'){
                cout<<"Casilla ya usada\n";
                break;
            }

            if(TableroBombas[fila][col]=='*'){

                for(int i=0;i<filas;i++){
                    for(int j=0;j<colum;j++){
                        if(TableroBombas[i][j]=='*'){
                            TableroVista[i][j]='*';
                        }
                    }
                }

                imprimirTablero(filas,colum,TableroVista);
                cout<<"PERDISTE\n";
                return 0;
            }

            descubrirZona(fila,col,filas,colum,TableroBombas,TableroVista);

            imprimirTablero(filas,colum,TableroVista);

            if(verificarVictoria(filas,colum,TableroBombas,TableroVista)){
                cout<<"GANASTE\n";
                return 1;
            }

            break;

        case 2:
            cout<<"fila columna: ";
            cin>>fila>>col;

            if(fila<0 || fila>=filas || col<0 || col>=colum){
                cout<<"Coordenadas invalidas\n";
                break;
            }

            if(TableroVista[fila][col] != '-'){
                cout<<"No puedes poner bandera\n";
                break;
            }

            if(banderas >= bombas){
                cout<<"Ya no puedes poner mas\n";
                break;
            }

            TableroVista[fila][col]='/';
            banderas++;

            imprimirTablero(filas,colum,TableroVista);
            break;

        case 3:
            cout<<"fila columna: ";
            cin>>fila>>col;

            if(fila<0 || fila>=filas || col<0 || col>=colum){
                cout<<"Coordenadas invalidas\n";
                break;
            }

            if(TableroVista[fila][col] != '/'){
                cout<<"No hay bandera\n";
                break;
            }

            TableroVista[fila][col]='-';
            banderas--;

            imprimirTablero(filas,colum,TableroVista);
            break;

        case 4:
            cout<<"Saliendo...\n";
            break;

        default:
            cout<<"Opcion incorrecta\n";
        }

    }while(opcion!=4);

    return 0;
}

bool funciones::verificarVictoria(int filas,int colum,char TableroBombas[][50],char TableroVista[][50]){

    for(int i=0;i<filas;i++){
        for(int j=0;j<colum;j++){
            if(TableroBombas[i][j] != '*' && TableroVista[i][j] == '-'){
                return false;
            }
        }
    }

    return true;
}

int funciones::leerEnteroSeguro(const string &mensaje){

    int numero;

    while(true){
        cout<<mensaje;

        if(cin>>numero){
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            return numero;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Entrada invalida, ingrese un numero\n";
    }
}
