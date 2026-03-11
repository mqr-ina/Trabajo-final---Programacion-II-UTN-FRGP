

#include "class_sala.h"
#include "class_pelicula.h"
#include "class_Fecha.h"
#include "class_Entradas.h"
#include "GestorArchivos.h"
#include "GestorPelicula.h"
#include "rlutil.h"
#include <iomanip>

using namespace std;

bool GestorPelicula::GuardarenDiscoPelicula(pelicula obj, Fecha _fecha, Fecha _FechaLimite){

 FILE *p;
    p = fopen(_rutadireP.c_str(), "ab+");
    if(p==NULL){
        exit(1);
    }
    bool grabo = fwrite(&obj, sizeof(pelicula),1, p);
    fclose(p);
    return grabo;

}

void GestorPelicula::LeerDeDiscoTODASPeliculas(){

pelicula obj;
Fecha _fecha;
Fecha _fechaLimite;
FILE *p;
    p = fopen(_rutadireP.c_str(), "rb+");
    if(p==NULL){
        exit(10);
    }
    while(fread(&obj, sizeof(pelicula),1, p)){
            _fecha = obj.getFechaEstreno();
            _fechaLimite = obj.getFechaLimiteProyeccion();
        obj.MostrarPeli(_fecha,_fechaLimite);
    }
    fclose(p);


}

bool GestorPelicula::guardarEnDiscoUNApelicula(pelicula reg,int pos, Fecha _fecha, Fecha _fechaLimite){
    FILE *p;
    p = fopen(_rutadireP.c_str(),"rb+");
    if(p==NULL){
        exit(500);
    }

    fseek(p,pos*sizeof(pelicula),SEEK_SET);
   bool grabo = fwrite(&reg,sizeof(pelicula),1,p);

fclose(p);
return grabo;
}

pelicula GestorPelicula::LeerPelicula(int pos){
    pelicula reg;
    FILE *p;
    ///
    p = fopen(_rutadireP.c_str(),"rb");
    if(p==NULL){
       exit(50);
    }
    /// ME POSICIONO EL CURSOR EN EL REGISTRO EXACTO
    fseek(p,sizeof(pelicula)*pos,SEEK_SET);
    fread(&reg,sizeof(pelicula),1,p);
    /// CIERRO ARCHIVO
    fclose(p);
    return reg;
}

void GestorPelicula::MostrarUnaPelicula(int pos, pelicula reg, Fecha _fecha, Fecha _fechaLimite){

        FILE *p;
        p = fopen(_rutadireP.c_str(),"rb");
        if(p==NULL){
            exit(8);
        }
        _fecha = reg.getFechaEstreno();
        _fechaLimite = reg.getFechaLimiteProyeccion();
        fseek(p,sizeof(pelicula)*pos,SEEK_SET);
        fread(&reg,sizeof(pelicula),1,p);
        reg.MostrarPeli(_fecha,_fechaLimite);
        fclose(p);

}

void GestorPelicula::ListarMenuDePeliculas(){
    pelicula reg;

    FILE *p;
    p = fopen(_rutadireP.c_str(), "rb+");
    if(p==NULL){
        exit(10);
    }
    int i=0;
    while(fread(&reg, sizeof(pelicula),1, p)){
         i++;
         cout<<i<<" Pelicula: "<<reg.getNombrepeli()<<endl;
    }
    fclose(p);
}






