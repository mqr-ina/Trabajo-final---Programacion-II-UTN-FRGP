#ifndef CLASS_ENTRADAS_H_INCLUDED
#define CLASS_ENTRADAS_H_INCLUDED
#include "class_pelicula.h"
#include "class_Fecha.h"
#include "class_sala.h"

#include <string>
#include <cstring>

using namespace std;

class Entradas{

protected:

char _IDventa[6];
int _CantVenEntre;
char _DNI[9];
Fecha _fecha;
int _sala;
char _pelicula[30];
float _impValor;


public:


//setters//
void setCantVenEntre(int);
void setDNI(string);
void setFecha(Fecha);
void setSala(int);
void setPelicula(string);
void setImpValor(float);
void setValorTotal(float);
void setIdVenta(string);

//getters//

int getCantVenEntre();
string getDNI();
Fecha getFecha();
int getSala();
string getPelicula();
float getImpValor();
float getValorTotal();
string getIdVenta();

//metodos//
bool cargarEntrada(Fecha &_fecha);
void mostrarEntrada(Fecha &_fecha);
int cargarsalaimp(int);

//Validaciones//

string generarIdVentas();
bool verificarIdExistenteV(string);
bool ValidDNI(string);

};




#endif // CLASS_ENTRADAS_H_INCLUDED
