#ifndef DETALLE_VENTA_H_INCLUDED
#define DETALLE_VENTA_H_INCLUDED
#include "class_Entradas.h"
#include <stdio.h>
#include <cstring>


using namespace std;

class Detalle{

private:
string _rutadireS="Salas.dat";
float subtotal;

public:

void DetalleDeVenta(string);

void RecaudacionAnual(int Anio);
void RecaudacionPorMes(int Anio);
void CompararFechaActualConEmision(int,int,int); //esto es para reiniciar las butacas usadas



};


#endif // DETALLE_VENTA_H_INCLUDED
