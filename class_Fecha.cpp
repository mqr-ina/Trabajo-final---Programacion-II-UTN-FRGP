
#include "class_Fecha.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


    void Fecha::setAnio(int anio){
        _anio = anio;
    }
    void Fecha::setMes(int mes){
        _mes = mes;
    }
    void Fecha::setDia(int dia){
        _dia = dia;
    }

    int Fecha::getAnio(){
        return _anio;
    }
    int Fecha::getMes(){
        return _mes;
    }
    int Fecha::getDia(){
        return _dia;
    }

    void Fecha::cargar(){
        Fecha _fecha;
        bool validd;
        int anio, mes, dia;

  do{  cout<<" Y EL ANIO \t";
    cin>>anio;
    }while(anio<1900 || anio>2100);

    do{cout << " EL MES \t";
    cin >> mes;
    }while(mes<1 || mes>12);

   do{ cout << "INGRESE EL DIA \t";
    cin >> dia;
    validd=validacionDias(dia,mes,anio);
   }while(validd!=true);
   cin.ignore();


    Fecha::setAnio(anio);
    Fecha::setDia(dia);
    Fecha::setMes(mes);
    }

    void Fecha::mostrar(){
    cout<<"FECHA: " <<getDia()<<"/"<<getMes()<<"/"<<getAnio()<<endl;
    }

bool Fecha::validacionDias(int dia,int mes,int anio){
   int Mdias[12]={31,28,31,30,31,30,31,31,30,31,30,31};


    if((anio %4==0 && anio % 100 !=0)||(anio % 400==0)){
        Mdias[1]=29;
    }
    if(dia<1 || dia>Mdias[mes-1]){

        return false;
    }else{


    return true;
    }

}

bool Fecha::operator>(const Fecha&f)const{
if (_anio > f._anio) return true;       //compara el anio de x fecha(1ra) con la 2da fecha que llamamos nosotros.
    if (_anio < f._anio) return false;

    if (_mes > f._mes) return true;
    if (_mes < f._mes) return false;

    return _dia > f._dia;
}


