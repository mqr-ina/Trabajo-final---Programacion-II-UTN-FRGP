#ifndef CLASS_SALA_H_INCLUDED
#define CLASS_SALA_H_INCLUDED

#include <string>
#include <cstring>

using namespace std;

class Sala{
protected:
    int _numSala;
    char _nombre[30];
    int _tipoSala;
    //int _cantButacasDisp;
    int _cantButacasMax;
    char _peliculaSala[30];

public:
    ////Setters
    void setNumSala(int);
    void setNombre(string);
    void setTipoSala(int);
    void setCantButacasDisp(int);
    void setMaxButacas(int);
    void setPeliculaSala(string);


    ////GETTERS
    int getNumSala();
    string getNombre();
    int getTipoSala();
//    int getCantButacasDisp();
    int getMaxButacas();
    string getPeliculaSala();


    ////Metodos
    void cargarSala();
    void mostrarSala();
    void CambiarPeliSala();


    ////Archivos
bool cargarEnDisco();
void mostrarSalas();

};






#endif // CLASS_SALA_H_INCLUDED
