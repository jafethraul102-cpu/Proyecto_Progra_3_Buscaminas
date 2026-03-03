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

int opcion, opcion2, opcion3;

int main()
{
    do {
        cout << "--BUSCAMINAS--" << endl;
        cout << "1)login" << endl;
        cout << "2)registrar" << endl;
        cout << "3)salir." << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
        case 2:

            do {
                cout << "--BUSCAMINAS--" << endl;
                cout << "1)PARTIDAS." << endl;
                cout << "2)Rankin." << endl;
                cout << "3)salir." << endl;
                cin >> opcion2;

                switch(opcion2)
                {
                case 1:
                    do {
                        cout << "1) Partida niveles secuenciales" << endl;
                        cout << "2) partida Facil" << endl;
                        cout << "3) Partida Normal." << endl;
                        cout << "4) Partida Dificil" << endl;
                        cin >> opcion3;

                        switch(opcion3)
                        {
                        case 1:
                            cout << "Elegiste niveles secuenciales\n";
                            break;
                        case 2:
                            cout << "Elegiste partida facil\n";
                            break;
                        case 3:
                            cout << "Elegiste partida normal\n";
                            break;
                        case 4:
                            cout << "Elegiste partida dificil\n";
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Opcion invalida\n";
                        }

                    } while (opcion3 != 5);
                    break;

                case 2:
                    cout << "Mostrando ranking...\n";
                    break;

                case 3:
                    break;

                default:
                    cout << "Opcion invalida\n";
                }

            } while (opcion2 != 3);
            break;

        case 3:
            cout << "Saliendo del sistema...\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (opcion != 3);

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
