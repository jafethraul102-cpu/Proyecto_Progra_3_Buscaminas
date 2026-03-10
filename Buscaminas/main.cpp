#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <windows.h>
#include "funciones.h"
#include <vector>
#include <fstream>
#include <cstdlib>

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

const string NOMBRE_ARCHIVO = "usuarios.txt";
const char DELIMITADOR = '|';
Usuario* usuarioActual = nullptr;

void menuPrincipal(vector<Usuario> &usuarios);
void menuRegistro(vector<Usuario> &usuarios);
void menuPartidas();
string leerTextoNoVacio(const string &mensaje);
int leerEnteroSeguro(const string &mensaje);


void cargarUsuariosDesdeArchivo(vector<Usuario> &usuarios);
void guardarUsuariosEnArchivo(const vector<Usuario> &usuarios);
int buscarUsuario(const vector<Usuario> &usuarios,string nombre);
bool registrarUsuario(vector<Usuario> &usuarios);
bool loginUsuario(vector<Usuario> &usuarios);

int main()
{
    system("color 87");
    system("title BUSCAMINAS");

    SetConsoleOutputCP(CP_UTF8);
    vector<Usuario> usuarios;

    cargarUsuariosDesdeArchivo(usuarios);

    cout << R"(
_§§§§§§___§§__§§-§§§§§§__§§§§§§__§§§§___
_§§___§§__§§__§§_§§___§__§§_____§§__§§__
_§§§§§§___§§__§§__§§§____§§_____§§§§§§__
_§§___§§__§§__§§_§___§§__§§_____§§__§§__
_§§§§§§___§§§§§§_§§§§§§__§§§§§§_§§__§§__
________________________________________
_§§§_§§§__§§__§§___§§__§§§§__§§§§§§_____
_§§_§_§§__§§__§§§§_§§_§§__§§_§§___§_____
_§§___§§__§§__§§-§§§§_§§§§§§___§§_______
_§§___§§__§§__§§___§§_§§__§§_§___§§_____
_§§___§§__§§ _§§___§§_§§__§§_§§§§§§_____
________________________________________
´´´´´´´´´´´´´´´´´´´´´´´$¶´´´´´¶´´´´´¶¢´´
´´´´´´´´´´´¶¶¶¶¶¶¶´´´´´´´¶¢´´´¶´´´ø¶´´´´
´´´´´´´´´´¶¶´´´´ø¶¶¶´´´´´´oø´´ø´´øo´´´´´
´´´´´´´´´´¶7´´´´´´´¶¶¶´´´´´´1´´´1´´´´1o´
´´´´´´´¶¶¶¶¶¶¶´´´´´´´¶¶¶7´´´´´´´´1o¶¶¶ø´
´´´´´´´¶¶¶¶¶¶¶´´´´´´´´´¶¶¶¶¶¶¶¶´´1´´´´´´
´´´´´o¶¶¶¶¶¶¶¶¶ø´´´´´´´´´´´´´´´´´´o$¢´´´
´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´´¢´´1ø´´´1¶¶´
´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶o´´´´´´´1$´´´¶´´´´´´´
´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´¶´´´´o¶´´´´´´
´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´¶¶´´´´´´´´´´´´
´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´´´´´´´´´´´´
´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´´´´´´´´´´´´´
´´´´´¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´´´´´´´´´´´´´´´
´´´´´´´¶¶¶¶¶¶¶¶´´´´´´´´´´´´´´´´´´´´´´´´´

)";

    menuRegistro(usuarios);

    return 0;
}

void menuRegistro(vector<Usuario> &usuarios){
    string nombre, contrasena;
    int opcionReg;
    do {
        cout << string(40, '=') << endl;
        cout << setw(50)<< "=======🚩🚩💣💣BUSCAMINAS 💣💣🚩🚩";
        cout <<"======"<< endl;
        cout << string(40, '=') << endl;
        cout << "|1)Registro.(🙋)                       |" << endl;
        cout << "|2)Login.(📝)                          |" << endl;
        cout << "|3)salir.(⏪)                          |" << endl;
        cout << string(40, '=') << endl;
        opcionReg = leerEnteroSeguro("Elija una opcion: ");
        cout << string(40, '=') <<'\n'<< endl;


        switch(opcionReg)
        {
        case 1:{

            if(registrarUsuario(usuarios)){
                menuPrincipal(usuarios);
            }
            break;
        }
        case 2:{
            if(loginUsuario(usuarios)){
                menuPrincipal(usuarios);
            }
            break;
        }
        case 3:{
            break;
        }
        default:{
            cout << "Opcion invalida. ✘\n";
        }
        }
    } while (opcionReg != 3);
}

void menuPartidas(){
    int opcionPar;
    do {
        cout << "" << endl;
        cout << "========================================" << endl;
        cout << "==========🕹🕹 TIPOS DE JUEGO 🕹🕹==========" << endl;
        cout << "========================================" << endl;
        cout << "|n1) Partida niveles secuenciales.👾   |" << endl;
        cout << "|2) partida Facil.(😊)                 |" << endl;
        cout << "|3) Partida Normal.(😅)                |" << endl;
        cout << "|4) Partida Dificil.(💀)               |" << endl;
        cout << "|5) Salir.(⏪)                         |"<< endl;
        opcionPar = leerEnteroSeguro("Elija una opcion: ");

        switch(opcionPar)
        {
        case 1:{
            cout << "Partidas en modo secuencial.👾" << endl;
            funciones funciones;
            funciones.imprimirTablero();

            break;
        }
        case 2:{
            cout << "Modo facil.😊" << endl;
            break;
        }
        case 3:{
            cout << "Modo Normal.😅" << endl;
            break;
        }
        case 4:{
            cout << "Modo Dificl.💀" << endl;
            break;
        }
        case 5:{
            break;

        }
        default:{
            cout << "Opcion invalida. ✘\n";
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

        cout<<"Este campo no puede quedar vacio intente de nuevo. ✘";

    }
}

void menuPrincipal(vector<Usuario> &usuarios){
int opcionPri;
    do {
        cout <<endl;
        cout << string(40, '=') << endl;
        cout << setw(45)<< "=====🚩🚩💣💣MENU PRINCIPAL💣💣🚩🚩";
        cout <<"====="<< endl;
        cout << string(40, '=') << endl;
        cout << "|1)PARTIDAS.(🕹)                        |" << endl;
        cout << "|2)Rankin.(👑)                         |" << endl;
        cout << "|3)salir.(⏪)                          |" << endl;
        opcionPri = leerEnteroSeguro("Elija una opcion: ");

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
            if(usuarioActual != nullptr){
                delete usuarioActual;
                usuarioActual = nullptr;
            }
            cargarUsuariosDesdeArchivo(usuarios);
            cout<<"Sesion cerrada\n";
            break;
        }
        default:{
            cout << "Opcion invalida. ✘\n";
        }
        }

    } while (opcionPri != 3);
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
        cout<<"Entrada invalida porfavor escriba un numero entero. ✘\n";
    }
}

void cargarUsuariosDesdeArchivo(vector<Usuario> &usuarios){

    ifstream archivoEntrada(NOMBRE_ARCHIVO.c_str());
    usuarios.clear();

    if(!archivoEntrada.is_open()){
        return;
    }

    string linea;

    while(getline(archivoEntrada,linea)){

        if(linea.empty()){
            continue;
        }

        size_t p1 = linea.find(DELIMITADOR);
        size_t p2 = linea.find(DELIMITADOR,p1+1);

        if(p1==string::npos || p2==string::npos){
            continue;
        }

        Usuario usuarioLeido;

        usuarioLeido.Nombre = linea.substr(0,p1);
        usuarioLeido.contrasena = linea.substr(p1+1,p2-(p1+1));

        string puntTexto = linea.substr(p2+1);

        try{
            usuarioLeido.puntuacion = stoi(puntTexto);
        }catch(...){
            usuarioLeido.puntuacion = 0;
        }

        usuarios.push_back(usuarioLeido);
    }

    archivoEntrada.close();
}

void guardarUsuariosEnArchivo(const vector<Usuario> &usuarios){

    ofstream archivoSalida(NOMBRE_ARCHIVO.c_str(),ios::trunc);

    if(!archivoSalida.is_open()){
        cout<<"ERROR: no se puede abrir el archivo. ✘\n";
        return;
    }

    for(int i=0;i<(int)usuarios.size();i++){

        archivoSalida
            <<usuarios[i].Nombre<<DELIMITADOR
            <<usuarios[i].contrasena<<DELIMITADOR
            <<usuarios[i].puntuacion<<'\n';

    }

    archivoSalida.close();
}
int buscarUsuario(const vector<Usuario> &usuarios,string nombre){

    for(int i=0;i<(int)usuarios.size();i++){

        if(usuarios[i].Nombre == nombre){
            return i;
        }

    }

    return -1;
}

bool registrarUsuario(vector<Usuario> &usuarios){

    cout<<"\n===== REGISTRO =====\n";

    string nombre = leerTextoNoVacio("Nombre: ");

    if(buscarUsuario(usuarios,nombre) != -1){
        cout<<"Ese usuario ya existe. ✘\n";
        return false;
    }

    string contrasena = leerTextoNoVacio("Contraseña: ");

    Usuario nuevo;
    nuevo.Nombre = nombre;
    nuevo.contrasena = contrasena;
    nuevo.puntuacion = 0;

    usuarios.push_back(nuevo);

    guardarUsuariosEnArchivo(usuarios);

    usuarioActual = new Usuario(nuevo);

    cout<<"Usuario registrado y logueado. ✅\n";
    return true;
}

bool loginUsuario(vector<Usuario> &usuarios){

    cout<<"\n===== LOGIN =====\n";

    string nombre = leerTextoNoVacio("Nombre: ");
    string contrasena = leerTextoNoVacio("Contraseña: ");

    int pos = buscarUsuario(usuarios,nombre);

    if(pos == -1){
        cout<<"Usuario no existe. ✘\n";
        return false;
    }

    if(usuarios[pos].contrasena == contrasena){

        usuarioActual = new Usuario(usuarios[pos]);

        cout<<"Login exitoso. ✅\n";
        return true;
    }

    cout<<"Contraseña incorrecta. ✘\n";
    return false;
}
