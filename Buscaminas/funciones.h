#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>

class funciones{
public:
    funciones();

    void InicializarTablero(int filas,int colum,int bombas,char TableroBombas[][50], char TableroVista[][50]);
    void imprimirTablero(int filas,int colum,char TableroVista[][50]);
    int menuJuego(int filas,int colum,int bombas,char TableroBombas[][50],char TableroVista[][50]);
    void ColocarIdentificadoresdeMinas(int filas,int colum,char TableroBombas[][50]);
    void descubrirZona(int filaIngresada,int columnaIngresada,int filas,int colum,char TableroBombas[][50],char TableroVista[][50]);
    bool verificarVictoria(int filas,int colum, char TableroBombas[][50],char TableroVista[][50]);
    int leerEnteroSeguro(const std::string &mensaje);
};

#endif
