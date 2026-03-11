#include <iostream>
#include "class_pelicula.h"
#include <string>
#include <cstring>
#include "rlutil.h"
#include<regex> //validaciones strings//
#include <ctime>

using namespace std;

//Metodos//

pelicula::pelicula(){

strcpy(_idpeli,"--------");
strcpy(_nombrepeli,"--------");
_clasificacionpeli=-1;
strcpy(_generopeli,"--------");
strcpy(_Director,"NO_INGRESADO_SISTEMA");
// fecha
_estadopeli=0;

}

void pelicula::CargarPeli(Fecha &_FechaEstreno, Fecha &_FechaLimiteDeProyeccion){

pelicula _pelicula;
int clasificacion;
bool estado, valid;
//
string id, nombre, genero, director;

id = generarIdPeli();

do{cout<<"Cargue Nombre de pelicula"<<endl;
getline(cin,nombre);
valid=validtamanio(nombre);
}while(valid!=true);
do{cout<<"Cargue Clasificacion(1=APTA TODO PUBLICO, 2=MAYORES 14 ANIOS, 3=MAYORES 18 ANIOS)"<<endl;
cin>>clasificacion;
}while(clasificacion!=1 && clasificacion!=2 &&clasificacion!=3);
cin.ignore();
do{cout<<"Cargue Genero de pelicula"<<endl;
getline(cin,genero);
valid=validgen(genero);
}while(valid!=true);
do{cout<<"Cargue Director de pelicula"<<endl;
getline(cin,director);
valid=validtamanio(director);
}while(valid!=true);

cout<<"Cargue Fecha de estreno"<<endl;
_FechaEstreno.cargar();

cout<<"Cargue la fecha LIMITE de proyeccion" <<endl;
_FechaLimiteDeProyeccion.cargar();


do{cout<<"Ingrese Estado de pelicula"<<endl;
cin>>estado;
}while(estado!=1 && estado!=0);


setIdpeli(id);
setNombrepeli(nombre);
setClasificacionpeli(clasificacion);
setGeneropeli(genero);
setDirector(director);
setFechaEstreno(_FechaEstreno);
setEstadopeli(estado);
setEntradaVen(0);
setFechaLimiteProyeccion(_FechaLimiteDeProyeccion);
}
void pelicula::MostrarPeli(Fecha &_FechaEstreno, Fecha &_FechaLimiteDeProyeccion){
cout<<"   PELICULA: "<<_nombrepeli<<endl;
cout<<"--------------------------------"<<endl;
cout<<"ID: "<<_idpeli<<endl;
cout<<"Clasificacion: ";

if(getClasificacionpeli()==1){
    cout<<"Apta todo Publico"<<endl;
}else if(getClasificacionpeli()==2){
    cout<<"Mayores de 14 Anios"<<endl;
}else{
    cout<<"Mayores de 18 Anios"<<endl;
}

cout<<"Genero: "<<_generopeli<<endl;
cout<<"Director: "<<_Director<<endl;
 // cout<<"ID: "<<_idpeli<<endl;*/
cout<<"Fecha de Estreno: " <<_FechaEstreno.getDia()<<"/"<<_FechaEstreno.getMes()<<"/"<<_FechaEstreno.getAnio()<<endl;
cout<<"FECHA LIMITE DE PROYECCION (es modificable): " <<_FechaLimiteDeProyeccion.getDia()<<"/"<<_FechaLimiteDeProyeccion.getMes()<<"/"<<_FechaLimiteDeProyeccion.getAnio()<<endl;
cout<<"Estado: "<<(getEstadopeli() ? "Activo" : "Inactivo")<<endl;


}



//Setters

void pelicula::setIdpeli(string Idpeli){

strcpy(_idpeli,Idpeli.c_str());

}
void pelicula::setNombrepeli(string Nombrepeli){

strcpy(_nombrepeli,Nombrepeli.c_str());

}
void pelicula::setClasificacionpeli(int Clasificacionpeli){

_clasificacionpeli=Clasificacionpeli;

}
void pelicula::setGeneropeli(string Generopeli){

strcpy(_generopeli,Generopeli.c_str());

}
void pelicula::setDirector(string director){

strcpy(_Director,director.c_str());

}
//void pelicula::setFecha()
void pelicula::setEstadopeli(bool Estadopeli){

_estadopeli=Estadopeli;

}

void pelicula::setFechaEstreno(Fecha fecha){
    _FechaEstreno = fecha;
}

void pelicula::setEntradaVen(int entra){
    _EntraVen= entra;

}

void pelicula::setFechaLimiteProyeccion(Fecha FechaLimite){
    _FechaLimiteDeProyeccion = FechaLimite;
}

//Get//
string pelicula::getIdpeli(){

return _idpeli;

}
string pelicula::getNombrepeli(){

return _nombrepeli;

}
int pelicula::getClasificacionpeli(){

return _clasificacionpeli;

}
string pelicula::getGeneropeli(){

return _generopeli;

}
string pelicula::getDirector(){

return _Director;

}

Fecha pelicula::getFechaEstreno(){
    return _FechaEstreno;

}

bool pelicula::getEstadopeli(){

return _estadopeli;

}

int pelicula::getEntradaVen(){

return _EntraVen;
}

Fecha pelicula::getFechaLimiteProyeccion(){
    return _FechaLimiteDeProyeccion;
}

//Validaciones//

bool pelicula::validarnum(string NU){

regex patron("^[0-9]{5,5}+$");  // ^inicio del string, $fin del string,+no vacio,{min,max}//

if(regex_match(NU,patron)){


    return true;
}else{
rlutil::setColor(rlutil::BLACK);//Opcion Incorrecta mano remarcado por boludo
        std::cout << "INGRESO INVALIDO" << std::endl;
        rlutil::setColor(rlutil::WHITE);//proba otra vez
        system("pause");
        system("cls");
return false;
}

}

bool pelicula::validtamanio(string Str){

regex patron("^.{1,30}$");//nota, hay que poner siempre los valores que puede tomar los caracteres, poniendo un "." toma todo//

if (regex_match(Str,patron)){

    return true;
}else {
rlutil::setColor(rlutil::BLACK);//Opcion Incorrecta mano remarcado por boludo
        std::cout << "INGRESO INVALIDO" << std::endl;
        rlutil::setColor(rlutil::WHITE);//proba otra vez
        system("pause");
        system("cls");
return false;
}


}

bool pelicula::validgen(string ge){

regex patron("^[A-Z]+$");  // ^inicio del string, $fin del string,+no vacio,{min,max}//

if(regex_match(ge,patron)){


    return true;
}else{
rlutil::setColor(rlutil::BLACK);//Opcion Incorrecta mano remarcado por boludo
        std::cout << "INGRESO INVALIDO" << std::endl;
        rlutil::setColor(rlutil::WHITE);//proba otra vez
        system("pause");
        system("cls");
return false;
}}

void pelicula::BuscarPeliPorNombre(string Busqueda){


pelicula reg;

    FILE *p;
    p = fopen("Peliculas.dat", "rb+");
    if(p==NULL){
        exit(10);
    }
    bool encontrado=false;
    int i=0;
    while(fread(&reg, sizeof(pelicula),1, p)){

        string nombre = reg.getNombrepeli();       ///Pasa siempre los char a string pa todo mambo de find///

        if(nombre.find(Busqueda) != string::npos){ ///relacionalo siempre a ::string sino no te lo toma///

            Fecha Fechaa=reg.getFechaEstreno();
            Fecha FechaLimite = reg.getFechaLimiteProyeccion();
            reg.MostrarPeli(Fechaa, FechaLimite);
            encontrado=true;
        }


    }
        if(!encontrado){

            cout<<"NO HAY COINCIDENCIAS"<<endl;
            system("pause");
        }

        system("pause");
        fclose(p);
}

bool pelicula::verificarIdExistente(string Id){
    FILE *p;
    pelicula reg;
    p = fopen("Peliculas.dat","rb+");
    if(p==NULL){
        exit(02);
    }

    bool existente = false;

    while(fread(&reg,sizeof(pelicula),1,p)){
        if(strcmp(reg.getIdpeli().c_str(),Id.c_str())==0){
            existente = true;
            break;
        }
    }
    fclose(p);
    return existente;
}


string pelicula::generarIdPeli(){
    string id;
    const int LIMITE = 10;

    do {
        id = "";
        for (int i = 0; i < 5; i++) {
            int num = rand() % LIMITE;   // genera número 0–9
            id += to_string(num);
        }
    } while (verificarIdExistente(id));  // repetir mientras exista

    return id;
}


