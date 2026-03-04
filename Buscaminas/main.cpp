#include <iostream>
#include <limits>
#include <string>
#include <windows.h>

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

void menuPrincipal();
void menuRegistro();
void menuPartidas();
string leerTextoNoVacio(const string &mensaje);
int leerEnteroSeguro(const string &mensaje);

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    cout << R"(
´´´´´´´´´´´´´´´´´´´´´´´$¶´´´´´¶´´´´´¶¢
´´´´´´´´´´´¶¶¶¶¶¶¶´´´´´´´¶¢´´´¶´´´ø¶´´
´´´´´´´´´´¶¶´´´´ø¶¶¶´´´´´´oø´´ø´´øo´´´
´´´´´´´´´´¶7´´´´´´´¶¶¶´´´´´´1´´´1´´´´1o
´´´´´´´¶¶¶¶¶¶¶´´´´´´´¶¶¶7´´´´´´´´1o¶¶¶ø
´´´´´´´¶¶¶¶¶¶¶´´´´´´´´´¶¶¶¶¶¶¶¶´´1´´´´
´´´´´o¶¶¶¶¶¶¶¶¶ø´´´´´´´´´´´´´´´´´´o$¢´
´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´´¢´´1ø´´´1¶¶
´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶o´´´´´´´1$´´´¶´´´´´´
´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´¶´´´´o¶´´´´´
´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´¶¶´´´´´´´´´´´
´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´´´´´´´´´´´
´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´´´´´´´´´´´´
´´´´´¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´´´´´´´´´´´´´´
´´´´´´´¶¶¶¶¶¶¶¶´´´´´´´´´´´´´´´´´´´´´´´´

)";

    menuRegistro();

    return 0;
}

void menuPrincipal(){
    int opcionPri;
    do {
        cout << "\n--💣💣BUSCAMINAS💣💣--" << endl;
        cout << "1)PARTIDAS." << endl;
        cout << "2)Rankin." << endl;
        cout << "3)salir." << endl;
        opcionPri = leerEnteroSeguro("Elija una opcion");

        switch(opcionPri)
        {
        case 1:{
            menuPartidas();
            break;
        }
        case 2:{
            break;
        }
        case 3:{
            cout << endl;
            break;
        }
        default:{
            cout << "Opcion invalida\n";
        }
        }

    } while (opcionPri != 3);
}

void menuRegistro(){
    string nombre, contrasena;
    int opcionReg;
    do {
        cout << "--BUSCAMINAS--" << endl;
        cout << "1)Registro." << endl;
        cout << "2)Login." << endl;
        cout << "3)salir." << endl;
        opcionReg = leerEnteroSeguro("Elija una opcion");

        switch(opcionReg)
        {
        case 1:{
            cout << "== REGISTRO ==" << endl;
            cout << "Ingrese el nombre de usuario." << endl;
            nombre = leerTextoNoVacio("Nombre: ");
            cout << "Ingrese contrasena." << endl;
            contrasena = leerTextoNoVacio("Contraseña: ");
            menuPrincipal();
            break;
        }
        case 2:{
            cout << "== LOGIN ==" << endl;
            cout << "Ingrese el nombre de usuario." << endl;
            cin >> nombre;
            cout << "Ingrese contrasena." << endl;
            cin >> contrasena;
            menuPrincipal();
            break;
        }
        case 3:{
            break;
        }
        default:{
            cout << "Opcion invalida\n";
        }
        }
    } while (opcionReg != 3);
}

void menuPartidas(){
    int opcionPar;
    do {
        cout << "== TIPOS DE JUEGO ==" << endl;
        cout << "\n1) Partida niveles secuenciales." << endl;
        cout << "2) partida Facil." << endl;
        cout << "3) Partida Normal." << endl;
        cout << "4) Partida Dificil." << endl;
        cout << "5) Salir." << endl;
        opcionPar = leerEnteroSeguro("Elija una opcion");

        switch(opcionPar)
        {
        case 1:{
            cout << "Partidas en modo secuencial." << endl;
            break;
        }
        case 2:{
            cout << "Modo facil." << endl;
            break;
        }
        case 3:{
            cout << "Modo Normal." << endl;
            break;
        }
        case 4:{
            cout << "Modo Dificl." << endl;
            break;
        }
        case 5:{
            break;

        }
        default:{
            cout << "Opcion invalida\n";
        }
        }
     } while (opcionPar != 5);
}

string leerTextoNoVacio(const string &mensaje){
    string texto;
    while(true){
        cout<<mensaje;
        getline(cin,texto);

        if(!texto.empty()){
            return texto;
        }

        cout<<"este campo no puede quedar vacio intente de nuevo.";

    }
}

int leerEnteroSeguro(const string &mensaje){
    int numero;
    while(true){
        cout<<mensaje;

        if(cin>>numero){
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            return numero;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Entrada invalida porfavor escriba un numero entero\n";
    }
}
