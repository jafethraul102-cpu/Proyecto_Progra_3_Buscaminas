#include <iostream>
#include <string>

using namespace std;

//git pull = para descargar los cambios
//git push = para subir los cambios
//git add . = agregar los cambios al repo local tu compu
//git commit -m "msj de lo add" =  si o si va despues del git add .

struct Usuario {
    string Nombre;
    string contrasena;
    int puntuacion;
};

int opcion;

int main()
{
        cout << "--BUSCAMINAS--" << endl;
        cout << "1)login" << endl;
        cout << "2)registrar" << endl;
        cout << "3)salir." << endl;




    return 0;
}
/*
    //MENU1
    cout << "--BUSCAMINAS--" << endl;
    cout << "1)login" << endl;
    cout << "2)registrar" << endl;
    cout << "3)salir." << endl;

    //MENU2
    cout << "--BUSCAMINAS--" << endl;
    cout << "1)PARTIDAS." << endl;
    cout << "2)Rankin." << endl;
    cout << "3)salir." << endl;

    //MENU3
    cout << "1) Partida niveles secuenciales" << endl;
    cout << "2) partida Facil" << endl;
    cout << "3) Partida Normal." << endl;
    cout << "4) Partida Dificil" << endl;

    //Partida
    cout << "1) colocar bandera." << endl;
    cout << "2) quitar bandera." << endl;
    cout << "3) y                  " << endl;
    cout << "4) -----------------" << endl;
    cout << "4) 1| 0 0 0 0 0 0 0 |"<< endl;
    cout << "4) 2| 0 0 0 0 0 0 0 |"<< endl;
    cout << "4) 3| 0 0 0 0 0 0 0 |"<< endl;
    cout << "4) 4| 0 0 0 0 0 0 0 |"<< endl;
    cout << "4) -----------------" << endl;
    cout << "3)    1 2 3 4 5 6 7 -> x" << endl;
    cout << "Escriba la direccion de lacelda(x(espacio)y):"<< endl;
    cout << "5) salir." << endl;
*/
