
#include "class_sala.h"
#include "class_pelicula.h"
#include "class_Fecha.h"
#include "class_Entradas.h"
#include "GestorArchivos.h"
#include "GestorPelicula.h"
#include "rlutil.h"
#include <iomanip>
#include <iostream>
#include "GestorSalas.h"


using namespace std;


bool GestorSalas::GuardarenDiscoSala(Sala obj){

 FILE *p;
    p = fopen("Salas.dat" , "ab+");
    if(p==NULL){
        exit(1);
    }
    bool grabo = fwrite(&obj, sizeof(Sala),1, p);
    fclose(p);
    return grabo;

}

Sala GestorSalas::LeerSala(int pos){
    Sala reg;
    FILE *p;
    ///
    p = fopen(_rutadireS.c_str(),"rb");
    if(p==NULL){
       exit(50);
    }
    /// ME POSICIONO EL CURSOR EN EL REGISTRO EXACTO
    fseek(p,sizeof(Sala)*pos,SEEK_SET);
    fread(&reg,sizeof(Sala),1,p);
    /// CIERRO ARCHIVO
    fclose(p);
    return reg;
}

 void GestorSalas::ListarTodasLasSalas(){
    Sala _sala;

    FILE *p;
    p = fopen(_rutadireS.c_str(),"rb+");
    if(p==NULL){
        exit(333);
    }

    while(fread(&_sala,sizeof(Sala),1,p)){

        _sala.mostrarSala();
    }
 fclose(p);
 }

  bool GestorSalas::ListarTodasLasSalasSPELI(){
    Sala _sala;
    bool Existe=false;

    FILE *p;
    p = fopen(_rutadireS.c_str(),"rb+");
    if(p==NULL){
        exit(333);
    }

    while(fread(&_sala,sizeof(Sala),1,p)){
    if(_sala.getPeliculaSala()=="NO_PELI"){

     cout<<_sala.getNombre()<<endl;
        Existe=true;
    }
    }
 fclose(p);
 return Existe;
 }



bool GestorSalas::guardarEnDiscoUNASala(Sala reg,int pos){
    FILE *p;
    p = fopen(_rutadireS.c_str(),"rb+");
    if(p==NULL){
        exit(520);
    }

    fseek(p,pos*sizeof(Sala),SEEK_SET);
   bool grabo = fwrite(&reg,sizeof(Sala),1,p);

fclose(p);
return grabo;
}

int GestorSalas::LlamadoDeSala(int poss){
    int SalaN;
        Sala reg;
        GestorSalas _gesto;
        system("cls");

        if(poss<0){
            cout<<"NO EXISTE ESA SALA "<<endl;
        }

        ///copiamos el registro en una variable en memoria
        reg = _gesto.LeerSala(poss);
        //RETORNAMOS SALA
            //cin.ignore();
        SalaN=reg.getNumSala();

return SalaN;
}

bool GestorSalas::validSalaExistente(int SalaN){
    Sala reg;
    FILE *p;
    p = fopen(_rutadireS.c_str(),"rb+");

    if(p==NULL){
        exit(8);
    }
    bool existente = false;

    while(fread(&reg,sizeof(Sala),1,p)){
        if(reg.getNumSala()==SalaN){
            existente = true;
            cout<<"ESA SALA YA EXISTE, INGRESE OTRO NUMERO "<<endl;
            break;
        }
    }




    fclose(p);
    return existente;
}









///id peli, ventas, tipo de sala, "precio uni", fk, total dato calculabre

