#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <windows.h>
#include "funciones.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cctype>

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
void menuPartidas(vector<Usuario> &usuarios);
void ArtAsciiInicio();
string leerTextoNoVacio(const string &mensaje);
int leerEnteroSeguro(const string &mensaje);

void menuMiCuenta(vector<Usuario> &usuarios);
void cargarUsuariosDesdeArchivo(vector<Usuario> &usuarios);
void guardarUsuariosEnArchivo(const vector<Usuario> &usuarios);
int buscarUsuario(const vector<Usuario> &usuarios,string nombre);
bool registrarUsuario(vector<Usuario> &usuarios);
bool loginUsuario(vector<Usuario> &usuarios);

void mostrarRanking(vector<Usuario> usuarios);
void ordenarUsuarios(vector<Usuario> &usuarios);

int main()
{
    system("color 0F");
    system("title BUSCAMINAS");

    SetConsoleOutputCP(65001);
    vector<Usuario> usuarios;

    cargarUsuariosDesdeArchivo(usuarios);

    ArtAsciiInicio();

    menuRegistro(usuarios);

    return 0;
}

void ArtAsciiInicio(){
//Raw String Litera o cadena de texto cruda o cadena literal sin escape
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

    delete usuarioActual;
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
            menuPartidas(usuarios);
            break;
        }
        case 2:{
            menuMiCuenta(usuarios);
            break;
        }
        case 3:{
            mostrarRanking(usuarios);
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
                cout << "============== MIS  DATOS ==============\n";
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
            int confirm;
            cout << string(40,'=') << endl;
            confirm = leerEnteroSeguro("¿Seguro que desea eliminar su cuenta? \n(si=1/no=0): ");

            if(confirm == 1){

                int pos = buscarUsuario(usuarios, usuarioActual->Nombre);

                if(pos != -1){

                    usuarios.erase(usuarios.begin() + pos);

                    guardarUsuariosEnArchivo(usuarios);

                    delete usuarioActual;
                    usuarioActual = nullptr;
                    cout << string(40,'=') << endl;
                    cout << "Cuenta eliminada correctamente.\n";
                    cout << string(40,'=') << endl;
                    cout<<endl;
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

void menuPartidas(vector<Usuario> &usuarios){
    int opcionPar;
    int bombas =0;
    int colum=0;
    int filas=0;

    char tableroBombas[50][50];
    char tableroVista[50][50];

    funciones funciones;

    do {

        cout << "========================================" << endl;
        cout << "==========🕹🕹 TIPOS DE JUEGO🕹🕹 ==========" << endl;
        cout << "========================================" << endl;
        cout << "|1) Partida niveles secuenciales.👾    |" << endl;
        cout << "|   Gana 5 puntos despues de completar |" << endl;
        cout << "|   los 3 niveles(Facil,Normal,Dificil)|" << endl;
        cout << "|" << string(38,'-') << "|\n";
        cout << "|2) partida Facil.(😊)                 |" << endl;
        cout << "|Gana 1 punto despues de completar la  |" << endl;
        cout << "|partida con el tablero 8x8            |" << endl;
        cout << "|con 10 minas.                         |" << endl;
        cout << "|" << string(38,'-') << "|\n";
        cout << "|3) Partida Normal.(😅)                |" << endl;
        cout << "|Gana 2 punto despues de completar la  |" << endl;
        cout << "|partida con el tablero 16x16          |" << endl;
        cout << "|con 40 minas.                         |" << endl;
        cout << "|" << string(38,'-') << "|\n";
        cout << "|4) Partida Dificil.(💀)               |" << endl;
        cout << "|Gana 3 punto despues de completar la  |" << endl;
        cout << "|partida con el tablero 16x30          |" << endl;
        cout << "|con 99 minas.                         |" << endl;
        cout << "|" << string(38,'-') << "|\n";
        cout << "|5) Salir.(⏪)                         |"<< endl;

        cout << string(40, '=') << endl;

        opcionPar = leerEnteroSeguro("Elija una opcion: ");

        cout << string(40, '=') << endl;

        switch(opcionPar)
        {

        case 1:{
            cout << "Partidas en modo secuencial.👾" << endl;
            int nivelesFilas[3] = {8, 16, 16};
            int nivelesColumnas[3] = {8, 16, 30};
            int nivelesBombas[3] = {10, 40, 99};

            bool ganoTodo = true;

            for(int n = 0; n < 3; n++){

                filas = nivelesFilas[n];
                colum = nivelesColumnas[n];
                bombas = nivelesBombas[n];

                funciones.InicializarTablero(filas,colum,bombas,tableroBombas,tableroVista);

                int resultado = funciones.menuJuego(filas,colum,bombas,tableroBombas,tableroVista);

                if(resultado != 1){
                    ganoTodo = false;
                    break;
                }
            }

            if(ganoTodo){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cout<<"!!!GANASTE 5 PUNTOS¡¡¡\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                usuarioActual->puntuacion += 5;

                int pos = buscarUsuario(usuarios, usuarioActual->Nombre);
                if(pos != -1){
                    usuarios[pos].puntuacion = usuarioActual->puntuacion;
                }

                guardarUsuariosEnArchivo(usuarios);
            }

            break;
        }
        case 2:{
            cout << "Modo facil.😊" << endl;
            filas=8;
            colum=8;
            bombas=10;

            funciones.InicializarTablero(filas,colum,bombas,tableroBombas,tableroVista);
            int Resultado =  funciones.menuJuego(filas,colum,bombas,tableroBombas,tableroVista);

            if(Resultado==1){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cout<<"!!!GANASTE 1 PUNTOS¡¡¡\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                usuarioActual->puntuacion+=1;

                int pos = buscarUsuario(usuarios, usuarioActual->Nombre);
                if(pos != -1){
                    usuarios[pos].puntuacion = usuarioActual->puntuacion;
                }

                guardarUsuariosEnArchivo(usuarios);
            }

            break;
        }
        case 3:{
            cout << "Modo Normal.😅" << endl;
            filas=16;
            colum=16;
            bombas=40;

            funciones.InicializarTablero(filas,colum,bombas,tableroBombas,tableroVista);
            int Resultado = funciones.menuJuego(filas,colum,bombas,tableroBombas,tableroVista);

            if(Resultado==1){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cout<<"!!!GANASTE 2 PUNTOS¡¡¡\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

                usuarioActual->puntuacion+=2;

                int pos = buscarUsuario(usuarios, usuarioActual->Nombre);
                if(pos != -1){
                    usuarios[pos].puntuacion = usuarioActual->puntuacion;
                }

                guardarUsuariosEnArchivo(usuarios);
            }

            break;
        }
        case 4:{
            cout << "Modo Dificl.💀" << endl;
            filas=16;
            colum=30;
            bombas=99;

            funciones.InicializarTablero(filas,colum,bombas,tableroBombas,tableroVista);
            int Resultado = funciones.menuJuego(filas,colum,bombas,tableroBombas,tableroVista);

            if(Resultado==1){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cout<<"!!!GANASTE 3 PUNTOS¡¡¡\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                usuarioActual->puntuacion+=3;

                int pos = buscarUsuario(usuarios, usuarioActual->Nombre);
                if(pos != -1){
                    usuarios[pos].puntuacion = usuarioActual->puntuacion;
                }

                guardarUsuariosEnArchivo(usuarios);
            }
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

void mostrarRanking(vector<Usuario> usuarios){

    ordenarUsuarios(usuarios);

    cout << "\n=====================================\n";
    cout << "                RANKING             \n";
    cout << "=====================================\n";

    cout << left << setw(20) << "Nombre" << "Puntos\n";
    cout << "-------------------------------------\n";

    for(int i = 0; i < usuarios.size(); i++){
        cout << left << setw(20) << usuarios[i].Nombre<< usuarios[i].puntuacion << endl;
    }

    cout << "=====================================\n";
}

//ordenamineto burbuja
void ordenarUsuarios(vector<Usuario> &usuarios){
    for(int i = 0; i < usuarios.size()-1; i++){
        for(int j = 0; j < usuarios.size()-i-1; j++){

            if(usuarios[j].puntuacion < usuarios[j+1].puntuacion){
                Usuario temp = usuarios[j];
                usuarios[j] = usuarios[j+1];
                usuarios[j+1] = temp;
            }
        }
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
    stringstream ss(linea);
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
