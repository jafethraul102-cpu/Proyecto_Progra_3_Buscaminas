#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>

class funciones{
public:
    funciones();


    void InicializarTablero(int filas,int colum,int bombas,std::string TableroBombas[][50], std::string TableroVista[][50]);
    void imprimirTablero(int filas,int colum,std::string TableroVista[][50]);
    int menuJuego(int filas,int colum,int bombas,std::string TableroBombas[][50],std::string TableroVista[][50]);
    void ColocarIdentificadoresdeMinas(int filas,int colum,std::string TableroBombas[][50]);
    void descubrirZona(int fila,int colu,int filas,int colum,std::string TableroBombas[][50],std::string TableroVista[][50]);
    bool verificarVictoria(int filas,int colum, std::string TableroBombas[][50],std::string TableroVista[][50]);
};

#endif
