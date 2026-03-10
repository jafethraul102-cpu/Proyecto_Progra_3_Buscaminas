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
void ArtAsciiInicio();
string leerTextoNoVacio(const string &mensaje);
int leerEnteroSeguro(const string &mensaje);

void menuMiCuenta(vector<Usuario> &usuarios);
void cargarUsuariosDesdeArchivo(vector<Usuario> &usuarios);
void guardarUsuariosEnArchivo(const vector<Usuario> &usuarios);
int buscarUsuario(const vector<Usuario> &usuarios,string nombre);
bool registrarUsuario(vector<Usuario> &usuarios);
bool loginUsuario(vector<Usuario> &usuarios);

int main()
{
    system("color 0F");
    system("title BUSCAMINAS");

    SetConsoleOutputCP(CP_UTF8);
    vector<Usuario> usuarios;

    cargarUsuariosDesdeArchivo(usuarios);

    ArtAsciiInicio();

    menuRegistro(usuarios);

    return 0;
}

void ArtAsciiInicio(){

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
        cout <<'|'<< string(38, '-') <<'|'<< endl;
        cout << "|2)Login.(📝)                          |" << endl;
        cout <<'|'<< string(38, '-') <<'|'<< endl;
        cout << "|3)salir.(⏪)                          |" << endl;
        cout << string(40, '=') << endl;
        cout << '|';
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
            cout << "Opcion invalida.\n";
        }
        }
    } while (opcionReg != 3);
}


bool registrarUsuario(vector<Usuario> &usuarios){
    cout << string(40, '=') << endl;
    cout <<"==============➕REGISTRO➕==============" << endl;
    cout << string(40, '=') << endl;
    cout << "Ingrese el nombre del nuevo usuario." << endl;
    string nombre = leerTextoNoVacio("Nombre: ");

    if(buscarUsuario(usuarios,nombre) != -1){
        cout<<"Ese usuario ya existe.\n";
        return false;
    }
    cout << string(40, '=') << endl;
    cout << "Ingrese la contraseña del nuevo usuario." << endl;
    string contrasena = leerTextoNoVacio("Contraseña: ");
    cout << string(40, '=') << endl;

    Usuario nuevo;
    nuevo.Nombre = nombre;
    nuevo.contrasena = contrasena;
    nuevo.puntuacion = 0;

    usuarios.push_back(nuevo);

    guardarUsuariosEnArchivo(usuarios);

    usuarioActual = new Usuario(nuevo);

    cout<<"Usuario registrado y logueado.\n";
    cout << string(40, '=') << endl;

    return true;
}

bool loginUsuario(vector<Usuario> &usuarios){
    cout << string(40, '=') << endl;
    cout <<"================👤LOGIN👤===============" << endl;
    cout << string(40, '=') << endl;
    cout << "Ingrese su nombre de usuario." << endl;
    string nombre = leerTextoNoVacio("Nombre: ");
    cout << string(40, '=') << endl;
    cout << "Ingrese su contraseña." << endl;
    string contrasena = leerTextoNoVacio("Contraseña: ");

    int pos = buscarUsuario(usuarios,nombre);

    if(pos == -1){
        cout << string(40, '=') << endl;
        cout<<"Usuario no existe.\n";
        cout << string(40, '=') << endl;
        cout << endl;
        return false;
    }

    if(usuarios[pos].contrasena == contrasena){

        usuarioActual = new Usuario(usuarios[pos]);
        cout << string(40, '=') << endl;
        cout<<"Login exitoso.\n";
        cout << string(40, '=') << endl;
        return true;
    }
    cout << string(40, '=') << endl;
    cout<<"Contraseña incorrecta.\n";
    cout << string(40, '=') << endl;
    cout << endl;
    return false;
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
        cout <<'|'<< string(38, '-') <<'|'<< endl;
        cout << "|2)Mi Cuenta.(👤)                      |" << endl;
        cout <<'|'<< string(38, '-') <<'|'<< endl;
        cout << "|3)Rankin.(👑)                         |" << endl;
        cout <<'|'<< string(38, '-') <<'|'<< endl;
        cout << "|4)salir.(⏪)                          |" << endl;
        cout << string(40, '=') << endl;
        opcionPri = leerEnteroSeguro("Elija una opcion: ");
        cout << string(40, '=') << endl;

        switch(opcionPri)
        {
        case 1:{
            menuPartidas();
            break;
        }
        case 2:{
            menuMiCuenta(usuarios);
            break;
        }
        case 3:{
            cout<<"Rankin\n";
            break;
        }
        case 4:{
            if(usuarioActual != nullptr){
                delete usuarioActual;
                usuarioActual = nullptr;
            }
            cargarUsuariosDesdeArchivo(usuarios);
            cout<<"Sesion cerrada\n";
            cout << string(40, '=') << endl;
            cout << endl;
            break;
        }
        default:{
            cout << "Opcion invalida.\n";
        }
        }

    } while (opcionPri != 4);
}

void menuMiCuenta(vector<Usuario> &usuarios){
    int opcion;

    do{
        cout << endl;
        cout << string(40,'=') << endl;
        cout << setw(45) << "=======🚩🚩💣💣MI  CUENTA💣💣🚩🚩";
        cout << "=======" << endl;
        cout << string(40,'=') << endl;

        cout << "|1) Ver mis datos.(👤)                 |\n";
        cout << "|" << string(38,'-') << "|\n";
        cout << "|2) Cambiar contraseña.(🔑)            |\n";
        cout << "|" << string(38,'-') << "|\n";
        cout << "|3) Eliminar mi cuenta.(🗑)             |\n";
        cout << "|" << string(38,'-') << "|\n";
        cout << "|4) Volver.(⏪)                        |\n";
        cout << string(40,'=') << endl;

        opcion = leerEnteroSeguro("Elija una opcion: ");
        cout << string(40, '=') << endl;

        switch(opcion){

        case 1:{
            if(usuarioActual != nullptr){
                cout << endl;
                cout << string(40,'=') << endl;
                cout << "===== MIS DATOS =====\n";
                cout << string(40,'=') << endl;
                cout << "Usuario: " << usuarioActual->Nombre << endl;
                cout << string(40,'=') << endl;
                cout << "Puntuacion: " << usuarioActual->puntuacion << endl;
                cout << string(40,'=') << endl;
            }
            break;
        }

        case 2:{
            cout << endl;
            cout << string(40,'=') << endl;
            cout << "Ingrese su contraseña actual.\n";
            cout << string(40,'=') << endl;
            string passActual = leerTextoNoVacio("Contraseña actual: ");

            if(passActual != usuarioActual->contrasena){
                cout << string(40,'=') << endl;
                cout << "Contraseña incorrecta.\n";
                cout << string(40,'=') << endl;
                break;
            }
            cout << string(40,'=') << endl;
            cout << "Ingrese la nueva contraseña.\n";
            string nuevaPass = leerTextoNoVacio("Nueva contraseña: ");

            int pos = buscarUsuario(usuarios, usuarioActual->Nombre);

            if(pos != -1){
                cout << string(40,'=') << endl;
                usuarios[pos].contrasena = nuevaPass;
                usuarioActual->contrasena = nuevaPass;

                guardarUsuariosEnArchivo(usuarios);

                cout << "Contraseña cambiada correctamente.\n";
            }
            cout << string(40,'=') << endl;
            break;
        }

        case 3:{
            cout << string(40,'=') << endl;
            cout << "Ingrese su contraseña actual.\n";
            string passActual = leerTextoNoVacio("Contraseña actual: ");

            if(passActual != usuarioActual->contrasena){
                cout << "Contraseña incorrecta.\n";
                cout << string(40,'=') << endl;
                break;
            }
            int confirm;
            cout << string(40,'=') << endl;
            cout << "¿Seguro que desea eliminar su cuenta? (si=1/no=0): ";
            confirm = leerEnteroSeguro("¿Seguro que desea eliminar su cuenta? \n(si=1/no=0): ");
            cout<<endl;
            if(confirm == 1){

                int pos = buscarUsuario(usuarios, usuarioActual->Nombre);

                if(pos != -1){

                    usuarios.erase(usuarios.begin() + pos);

                    guardarUsuariosEnArchivo(usuarios);

                    delete usuarioActual;
                    usuarioActual = nullptr;

                    cout << "Cuenta eliminada correctamente.\n";
                    cout << string(40,'=') << endl;
                    menuRegistro(usuarios);
                    return;
                }
            }
            break;
        }

        case 4:{
            return;
        }

        default:
            cout << "Opcion invalida.\n";
        }

    }while(true);
}

void menuPartidas(){
    int opcionPar;
    do {
        cout << "" << endl;
        cout << "========================================" << endl;
        cout << "==========🕹🕹 TIPOS DE JUEGO🕹🕹 ==========" << endl;
        cout << "========================================" << endl;
        cout << "|1) Partida niveles secuenciales.👾    |" << endl;
        cout << "|" << string(38,'-') << "|\n";
        cout << "|2) partida Facil.(😊)                 |" << endl;
        cout << "|" << string(38,'-') << "|\n";
        cout << "|3) Partida Normal.(😅)                |" << endl;
        cout << "|" << string(38,'-') << "|\n";
        cout << "|4) Partida Dificil.(💀)               |" << endl;
        cout << "|" << string(38,'-') << "|\n";
        cout << "|5) Salir.(⏪)                         |"<< endl;
        cout << string(40, '=') << endl;
        opcionPar = leerEnteroSeguro("Elija una opcion: ");
        cout << string(40, '=') << endl;

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
            cout << "Opcion invalida.\n";
        }
        }
    } while (opcionPar != 5);
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
        cout<<"Entrada invalida porfavor escriba un numero entero.\n";
    }
}

string leerTextoNoVacio(const string &mensaje){
    string texto;
    while(true){
        cout<<mensaje;
        getline(cin,texto);

        if(!texto.empty()){
            return texto;
        }

        cout<<"Este campo no puede quedar vacio intente de nuevo.";

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
        cout<<"ERROR: no se puede abrir el archivo.\n";
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
//busqueda lineal
int buscarUsuario(const vector<Usuario> &usuarios,string nombre){
    for(int i=0;i<(int)usuarios.size();i++){

        if(usuarios[i].Nombre == nombre){
            return i;
        }

    }

    return -1;
}
