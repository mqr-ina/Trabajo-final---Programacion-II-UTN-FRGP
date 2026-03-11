#ifndef GESTORPELICULA_H_INCLUDED
#define GESTORPELICULA_H_INCLUDED

class GestorPelicula{

private:
string _rutadireP="Peliculas.dat";

public:
bool GuardarenDiscoPelicula(pelicula, Fecha, Fecha);
void LeerDeDiscoTODASPeliculas();
bool guardarEnDiscoUNApelicula(pelicula,int, Fecha, Fecha);
pelicula LeerPelicula(int pos);
void MostrarUnaPelicula(int, pelicula, Fecha, Fecha);
void ListarMenuDePeliculas();

};



#endif // GESTORPELICULA_H_INCLUDED
