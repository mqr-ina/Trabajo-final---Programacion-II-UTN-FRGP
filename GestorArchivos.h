#ifndef GESTORARCHIVOS_H_INCLUDED
#define GESTORARCHIVOS_H_INCLUDED
#include "class_sala.h"
#include "class_pelicula.h"
#include "class_Fecha.h"
#include "class_Entradas.h"

class GestorArchivos{

protected:
    string _rutadire;
public:

    ///ARRANCAMOS//

    void ArrancanDatos();
    GestorArchivos(int);

    int obtenerCantRegistros();

    ///Peliculas

    //consultas
    void BuscarPeliculaPorGenero(Fecha, Fecha);
    void MostrarPeliculasActivas();
    void ConsultaDeSalaPorNombre(string);
    void ConsultaDeVentaPorDNI(string);
    void ConsultaPorButacasVendidas(int);


   ///Ventas
    bool GuardarenDiscoVenta(Entradas);
    void ListarTodasLasVentas();
    void ListarMenuDeSalas();
    void ListarMenuDePeliculas();
    void RecaudacionAnual(Entradas);

    ///
    void MostrarCantidadButacasVendidas();
    void MostrarPeliMVendida();
    string LlamadoDePelicula(int);
    int LlamadoDeSala(int);
    Fecha LLamadoDeFechaLimite(int);
    bool buscarCantButacasPos(int,int);
    void Ventpeli(int,int);


    //
    int conseguimeDisp(int);
    int conseguimeMax(int);
    bool verificarVentaDuplicada(string,string,Fecha);
     bool ReiniciarSala(int);
};


#endif // GESTORARCHIVOS_H_INCLUDED
