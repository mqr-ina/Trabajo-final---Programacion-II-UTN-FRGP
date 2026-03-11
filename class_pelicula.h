#ifndef CLASS_PELICULA_H_INCLUDED
#define CLASS_PELICULA_H_INCLUDED
#include <string>
#include <cstring>
#include "class_Fecha.h"

using namespace std;

class pelicula{
protected:

char _idpeli[6];
char _nombrepeli[30];
int  _clasificacionpeli;
char _generopeli[30];
char _Director[40];
Fecha _FechaEstreno;
bool _estadopeli;
int _EntraVen;
Fecha _FechaLimiteDeProyeccion; //podriamos haberlo puesto en sala pero nunca se sabe si una pelicula tiene varias salas!

public:

//setters//

void setIdpeli(string);
void setNombrepeli(string);
void setClasificacionpeli(int);
void setGeneropeli(string);
void setDirector(string);
void setFechaEstreno(Fecha);
void setEstadopeli(bool);
void setEntradaVen(int);
void setFechaLimiteProyeccion(Fecha);

//gets//

string getIdpeli();
string getNombrepeli();
int getClasificacionpeli();
string getGeneropeli();
string getDirector();
Fecha getFechaEstreno();
bool getEstadopeli();
int getEntradaVen();
Fecha getFechaLimiteProyeccion();

//Metodos//
pelicula();
void CargarPeli(Fecha &_FechaEstreno, Fecha &_FechaLimiteDeProyeccion);
void MostrarPeli(Fecha &_FechaEstreno, Fecha &_FechaLimiteDeProyeccion);
void BuscarPeliPorNombre(string);
string generarIdPeli();
bool verificarIdExistente(string);

//validaciones//
bool validarnum(string);
bool validtamanio(string);
bool validgen(string);

} ;


#endif // CLASS_PELICULA_H_INCLUDED
