#include <iostream>
#include <string>
#include <cstring>
#include "class_sala.h"
#include "class_pelicula.h"
#include "class_Fecha.h"
#include "class_Entradas.h"
#include "GestorArchivos.h"
#include "menu.h"
#include "rlutil.h"
#include <ctime>

using namespace std;

int main()
{


    srand(time(NULL));
    Menu menu;

    menu.ejecutarMenu();

    /*pelicula _pelicula;
    Fecha _fecha;
    Sala _sala;
    Entradas entradas;
    entradas.cargarEntrada(_pelicula,_sala,_fecha);
    entradas.mostrarEntrada(_pelicula,_sala,_fecha);
*/
//    Fecha fechaEstreno;
//   fechaEstreno.cargar();
//    fechaEstreno.mostrar();
/* pelicula obj;
    obj.CargarPeli();
    GestorArchivos gestor(2);
    gestor.GuardarenDiscoPelicula(obj);
    gestor.LeerDeDiscoTODASPeliculas();
*/
//    obj.MostrarPeli();
    /*Sala sala;
    sala.cargarSala();
    sala.mostrarSala();*/

    system("pause");
   return 0;
}
