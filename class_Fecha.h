#ifndef CLASS_FECHA_H_INCLUDED
#define CLASS_FECHA_H_INCLUDED
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

class Fecha{
protected:
    int _anio;
    int _mes;
    int _dia;
public:
    void setAnio(int);
    void setMes(int);
    void setDia(int);

    int getAnio();
    int getMes();
    int getDia();

    ///metodos
    void cargar();
    void mostrar();

///Validacion de dias
bool validacionDias(int, int, int);
bool operator>(const Fecha &f) const;
};




#endif // CLASS_FECHA_H_INCLUDED
