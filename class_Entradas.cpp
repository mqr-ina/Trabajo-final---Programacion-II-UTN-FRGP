
#include "class_Entradas.h"
#include "class_pelicula.h"
#include "class_Fecha.h"
#include "class_sala.h"
#include "GestorArchivos.h"
#include "GestorPelicula.h"
#include "rlutil.h"
#include <iostream>
#include <string>
#include <cstring>
#include <regex>
#include <iomanip>
#include "GestorSalas.h"

using namespace std;



//setters//
void Entradas::setCantVenEntre(int CantVentEntre){

_CantVenEntre=CantVentEntre;

}
void Entradas::setDNI(string DNI){

strcpy(_DNI,DNI.c_str());

}
void Entradas::setFecha(Fecha aFecha){

_fecha=aFecha;

}
void Entradas::setSala(int aSala){

 _sala = aSala;

}
void Entradas::setPelicula(string aPelicula){

strcpy(_pelicula,aPelicula.c_str());


}

void Entradas::setImpValor(float impValor){

    _impValor = impValor;

}

void Entradas::setIdVenta(string id){
 strcpy(_IDventa,id.c_str());
}




//getters//

int Entradas::getCantVenEntre(){

return _CantVenEntre;

}
string Entradas::getDNI(){

return _DNI;

}
Fecha Entradas::getFecha(){

return _fecha;

}
int Entradas::getSala(){

return _sala;

}
string Entradas::getPelicula(){

return _pelicula;

}

float Entradas::getImpValor(){

return _impValor;
}


string Entradas::getIdVenta(){
    return _IDventa;
}


bool Entradas::cargarEntrada(Fecha &_fecha){


string idVentas = generarIdVentas();

Fecha _FechaLimite;

float importes[3]={1000.00,2000.00,5000.00};
bool valid, valido;
float impValor, valorTotal;
string DNI,PeliculaN;
int cantVenEntr,SalaN, SalaImp, poss,posp, butacasActuales, butacasDisp, tEntr;
GestorArchivos gestorPelicula(1);
GestorArchivos gestorSala(2);
GestorArchivos gestorVentas(3);

gestorSala.ListarMenuDeSalas();
cout<<"Ingrese numero de sala"<<endl;
cin>>poss;
poss--;

GestorPelicula _peli;
_peli.ListarMenuDePeliculas();
cout<<"Ingrese numero de peli : "<<endl;
cin>>posp;
posp--;

SalaN = gestorSala.LlamadoDeSala(poss);
PeliculaN = gestorPelicula.LlamadoDePelicula(posp);

cout<<"INGRESE LA FECHA DE COMPRA "<<endl;
_fecha.cargar();

_FechaLimite = gestorPelicula.LLamadoDeFechaLimite(posp);

//VALIDAMOS FECHA DE COMPRA
if (_fecha > _FechaLimite) {
    cout << "ERROR === Esta pelicula ya no este disponible en esa fecha." << endl;
    cout << "Fecha límite de proyección: ";
    _FechaLimite.mostrar();
    system("pause");
    return false;
}

do{cout<<"INGRESAR DNI DE COMPRADOR: "<<endl;
getline(cin,DNI);
valid=ValidDNI(DNI);
}while(valid!=true);

if(gestorVentas.verificarVentaDuplicada(DNI,PeliculaN,_fecha)){
    cout<<"Ya existe una venta para este comprador, con la misma pelicula y fecha"<<endl;
    system("pause");
    return false;
}

cout<<"INGRESAR LA CANTIDAD DE ENTRADAS VENDIDAS: "<<endl;   ///MEPA QUE DEBERIAMOS CONTAR LO DE LA SALA PERO QUE MAMBO LOCO///
cin>>cantVenEntr;

SalaImp=cargarsalaimp(poss);
valorTotal = importes[SalaImp-1] * cantVenEntr;
cout<<"VALOR TOTAL \t" <<fixed<<setprecision(2)<<valorTotal<<endl;
system("pause");
impValor=importes[SalaImp-1];
if(!gestorSala.buscarCantButacasPos(SalaN,cantVenEntr)){
        valido=false;

}else {
gestorPelicula.Ventpeli(posp,cantVenEntr);
Entradas::setPelicula(PeliculaN);
Entradas::setCantVenEntre(cantVenEntr);
Entradas::setSala(SalaN);
Entradas::setDNI(DNI);
Entradas::setFecha(_fecha);
Entradas::setImpValor(impValor);
Entradas::setIdVenta(idVentas);


valido=true;
}

return valido;


/*gestorPelicula.Ventpeli(posp,cantVenEntr);
Entradas::setPelicula(PeliculaN);
Entradas::setCantVenEntre(cantVenEntr);
Entradas::setSala(SalaN);
Entradas::setDNI(DNI);
Entradas::setFecha(_fecha);
Entradas::setImpValor(impValor);
Entradas::setValorTotal(valorTotal);*/
}

void Entradas::mostrarEntrada(Fecha &_fecha){



cout<<"=========PELICULA SOLICITADA========="<<endl;
cout<<_pelicula<<endl;
cout<<"SALA DE LA PELICULA"<<endl;
cout<<_sala<<endl;
cout<<"FECHA DE PROYECCION"<<endl;
cout<<_fecha.getDia()<<"/"<<_fecha.getMes()<<"/"<<_fecha.getAnio()<<endl;
cout<<"DNI DE COMPRADOR"<<endl;
cout<<getDNI()<<endl;
cout<<"CANTIDAD DE ENTRADAS VENDIDAS"<<endl;
cout<<getCantVenEntre()<<endl;
cout<<"ID de la venta"<<endl;
cout<<fixed<<setprecision(2)<<getIdVenta()<<endl;

cout<<endl;
cout<<endl;
}

//VALIDACIONES//

bool Entradas::ValidDNI(string DNI){

regex Patron("^[0-9]{8,8}$");

if(regex_match(DNI,Patron)){

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

int Entradas::cargarsalaimp(int SalaN){
        Sala reg;
        GestorSalas _gesto;
        system("cls");
        reg = _gesto.LeerSala(SalaN);
        cin.ignore();
        SalaN=reg.getTipoSala();

return SalaN;


}

bool Entradas::verificarIdExistenteV(string Id){
    FILE *p;
    Entradas reg;
    p = fopen("Ventas.dat","rb+");
    if(p==NULL){
        exit(44);
    }

    bool existente = false;

    while(fread(&reg,sizeof(Entradas),1,p)){
        if(strcmp(reg.getIdVenta().c_str(),Id.c_str())==0){
            existente = true;
            break;
        }
    }
    fclose(p);
    return existente;
}


string Entradas::generarIdVentas(){
    string idVentas;
    const int LIMITE = 10;

    do {
        idVentas = "";
        for (int i = 0; i < 5; i++) {
            int num = rand() % LIMITE;   // genera número 0–9
            idVentas += to_string(num);
        }
    } while (verificarIdExistenteV(idVentas));  // repetir mientras exista

    return idVentas;
}

