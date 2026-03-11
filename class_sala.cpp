
# include <iostream>
#include "class_sala.h"
#include "GestorArchivos.h"
#include "GestorSalas.h"
#include "GestorPelicula.h"
#include <string>
#include <cstring>


 using namespace std;

    void Sala::setNumSala(int numSala){
        _numSala = numSala;
    }
    void Sala::setNombre(string nombre){
        strcpy(_nombre,nombre.c_str());
    }
    void Sala::setTipoSala(int tipoSala){
        _tipoSala = tipoSala;
    }
    void Sala::setMaxButacas(int MaxButacas){
    _cantButacasMax= MaxButacas;
      }
    void Sala::setPeliculaSala(string peliculaSala){
    strcpy(_peliculaSala,peliculaSala.c_str());
    }


    ////GETTERS
    int Sala::getNumSala(){
        return _numSala;
    }
    string Sala::getNombre(){
        return _nombre;
    }
    int Sala::getTipoSala(){
        return _tipoSala;
    }

    int Sala::getMaxButacas(){
        return _cantButacasMax;
    }
    string Sala::getPeliculaSala(){
        return _peliculaSala;
    }



    void Sala::cargarSala(){

        Sala _sala;
        GestorSalas gestor;
        int numSala, tipoSala, cantButacasDisp,posp;
        string nombre;
        string PeliculaN;

        do{cout<<"INGRESE EL NUMERO DE SALA: \t"<<endl;
        cin>>numSala;}while((gestor.validSalaExistente(numSala)));

        cin.ignore();
        cout<<"INGRESE EL NOMBRE DE LA SALA: \t"<<endl;
        getline(cin,nombre);
        cout<<"INGRESE TIPO DE SALA: (1-ESTANDAR, 2- PREMIUM, 3-CONFORT PLUS \t"<<endl;
        cin>>tipoSala;
        cout<<"INGRESE CANTIDAD DE BUTACAS DISPONIBLES \t"<<endl;
        cin>>cantButacasDisp;

        system("cls");
        GestorPelicula _peli;
        GestorArchivos gestorcito(1);
        _peli.ListarMenuDePeliculas();
        cout<<"Ingrese numero de peli asignada a la sala : "<<endl;
        cin>>posp;
        posp--;

PeliculaN = gestorcito.LlamadoDePelicula(posp);



    Sala::setNumSala(numSala);
    Sala::setNombre(nombre);
    Sala::setTipoSala(tipoSala);
    Sala::setMaxButacas(cantButacasDisp);
    Sala::setPeliculaSala(PeliculaN);

    }

    void Sala::mostrarSala(){
     GestorArchivos _gestor(3);
     cout<<"================================"<<endl;
    cout<<"NUMERO DE SALA: " <<_numSala<<endl;
    cout<<"NOMBRE DE LA SALA: " <<_nombre<<endl;
    cout<<"TIPO DE SALA " ;
    if(getTipoSala()==1){
        cout<<"ESTANDAR "<<endl;
    }
    else if (getTipoSala()==2){
        cout<<"PREMIUM "<<endl;
    }
    else{
        cout<<"CONFORT PLUS "<<endl;
    }
    cout<<"CANTIDAD TOTAL DE CAPACIDAD: "<<_cantButacasMax<<endl;

    cout<<"CANTIDAD DE BUTACAS DISPONIBLES: "<< _gestor.conseguimeDisp(_numSala)<<endl;

    cout<<"PELICULA ASIGNADA PARA LA SALA: "<<_peliculaSala<<endl;

    cout<<endl;
    }


    void Sala::CambiarPeliSala(){
    GestorPelicula _peli;
    GestorSalas _sala;




    }
