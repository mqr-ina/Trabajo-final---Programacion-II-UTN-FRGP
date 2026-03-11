#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include <string>
#include <cstring>
#include "class_sala.h"
#include "class_pelicula.h"
#include "class_Fecha.h"
#include "class_Entradas.h"
#include "GestorArchivos.h"


using namespace std;

class Menu{
private:
    int _opcion;
    bool _salir;

public:
    void mostrarMenu();
    void MenuPeli();
    void MenuVentas();
    void MenuSalas();
    void obtenerOpcion();
    void ejecutarMenu();
    void opcionesMenu();
    void MenuInformes();
    void MenuConsultas();

    //valid

    bool validGene(string);


Menu();

};



#endif // MENU_H_INCLUDED
