#include <iostream>
#include "class_sala.h"
#include "class_pelicula.h"
#include "class_Fecha.h"
#include "class_Entradas.h"
#include "GestorArchivos.h"
#include "GestorPelicula.h"
#include "GestorSalas.h"
#include "rlutil.h"
#include <iomanip>

using namespace std;



//Manipulacion de archivos//
GestorArchivos::GestorArchivos(int a){

if(a==1){
_rutadire = "Peliculas.dat";

}else if(a==2) {

_rutadire = "Salas.dat";

}
else{
    _rutadire = "Ventas.dat";
}

}

void GestorArchivos::ArrancanDatos(){

FILE *p;
    p= fopen(_rutadire.c_str(), "rb");

    if(p==NULL){

        p= fopen(_rutadire.c_str(), "wb");
        if(p!=NULL){

        fclose(p);

    }else{

        exit(1);
    }
    }else{

    fclose(p);
    }
}











bool GestorArchivos::GuardarenDiscoVenta(Entradas obj){
    FILE *p;
    p = fopen(_rutadire.c_str(),"ab+");
    if(p==NULL){
        exit(8);
    }

    bool grabo = fwrite(&obj,sizeof(Entradas),1,p);
    fclose(p);
    return grabo;
}



 void GestorArchivos::ListarTodasLasVentas(){
    Entradas _Ventas;
    Fecha _fecha;
    FILE *p;
    p = fopen(_rutadire.c_str(),"rb+");
    if(p==NULL){
        exit(333);
    }

    while(fread(&_Ventas,sizeof(Entradas),1,p)){
            _fecha=_Ventas.getFecha();
            _Ventas.mostrarEntrada(_fecha);
    }
 fclose(p);
 }








string GestorArchivos::LlamadoDePelicula(int posp){
    string PeliculaN;
 pelicula obj;
        GestorPelicula _gestor;
        system("cls");
        //localizar la pelicula por su posicion
        //GestorArchivos _peli(1);
        //_peli.ListarMenuDePeliculas();

        //cout<<"Ingrese Numero Pelicula (1-10): \t";
        //int pos;
        //cin>>pos;
        //pos--;

        if(posp<0){
            cout<<"NO EXISTE ESA PELICULA "<<endl;
        }

        ///copiamos el registro en una variable en memoria
        obj = _gestor.LeerPelicula(posp);
        //RETORNAMOS PELI
            //cin.ignore();
        PeliculaN=obj.getNombrepeli();


   return PeliculaN;
}

Fecha GestorArchivos::LLamadoDeFechaLimite(int posp){
    Fecha _FechaLimite;
     pelicula obj;
        GestorPelicula _gestor;
        system("cls");

        if(posp<0){
            cout<<"NO EXISTE ESA PELICULA "<<endl;
        }

        ///copiamos el registro en una variable en memoria
        obj = _gestor.LeerPelicula(posp);
        //RETORNAMOS PELI
            //cin.ignore();
        _FechaLimite=obj.getFechaLimiteProyeccion();


   return _FechaLimite;

}


int GestorArchivos::LlamadoDeSala(int poss){
    int SalaN;
        Sala reg;
        GestorSalas _gesto;
        system("cls");
        //localizar la pelicula por su posicion
        //cout<<"Ingrese Numero salas (0-8): \t";
        //int poss;
        //cin>>poss;

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


void GestorArchivos::ListarMenuDeSalas(){
    Sala reg;

    FILE *p;
    p= fopen(_rutadire.c_str(), "rb+");
    if(p==NULL){
        exit(11);
    }
    int i=0;
    while(fread(&reg, sizeof(Sala),1, p)){
        i++;
        cout<<i<<" Sala: "<<reg.getNumSala()<<reg.getNombre()<<" Tipo: ";

        switch(reg.getTipoSala()){

    case 1:
        cout<<"ESTANDAR";
        break;
    case 2:
        cout<<"PREMIUM";
        break;
    case 3:
        cout<<"CONFORT PLUS";
        break;

        }

cout<<endl;

    }

}



//void GestorArchivos::RecaudacionAnual(Entradas _ventas){
//
//    FILE *p;
//    p = fopen(_rutadire.c_str(),"rb+");
//    if(p==NULL){
//        exit(9);
//    }
//
//    float acumulador = 0;
//    while(fread(&_ventas,sizeof(Entradas),1,p)){
//        acumulador += _ventas.getValorTotal();
//    }
//
//    fclose(p);
//
//    cout<<"Recaudacion total hasta el momento: "<<acumulador<<endl;
//}

bool GestorArchivos::buscarCantButacasPos(int idsal, int Cantv){
        int cantButacas;
        GestorArchivos _gesto(2);
        system("cls");

        cantButacas= _gesto.conseguimeDisp(idsal);

        if((cantButacas-Cantv)<0){

            cout<<"NO HAY ESPACIO EN SALA, ASIENTOS DISPONIBLES: "<<cantButacas<<endl;
            return false;

        }else{


        return true;
        }

}

void GestorArchivos::BuscarPeliculaPorGenero(Fecha _fecha, Fecha _FechaLimite){
    FILE *p;
    int a;
    string genero;
    p = fopen(_rutadire.c_str(),"rb+");
    if(p==NULL){
        exit(909);
    }
    pelicula reg;

     cout << "GENEROS DISPONIBLES A BUSCAR:" << endl;
    cout << "1. AVENTURA" << endl;
    cout << "2. DRAMA" << endl;
    cout << "3. COMEDIA" << endl;
    cout << "4. ACCION" << endl;
    cout << "5. TERROR" << endl;
    cout << "-------------------------------------" << endl;
    cout << "INGRESE EL NUMERO DE GENERO: ";
    cin >> a;
    cin.ignore();

    if (a == 1) {
        genero = "AVENTURA";
    }
    else if (a == 2) {
        genero = "DRAMA";
    }
    else if (a == 3) {
        genero = "COMEDIA";
    }
    else if (a == 4) {
        genero = "ACCION";
    }
    else if (a == 5) {
        genero = "TERROR";
    }
    else {
        cout << "Opción no válida. Por defecto vamos a mostrar aventura" << endl;
        genero = "AVENTURA";
    }

    rewind(p);

    bool encontrado = false;
    cout << endl;
    cout << "=== PELICULAS DEL GENERO: " << genero << " ===" << endl;

    while(fread(&reg, sizeof(pelicula), 1, p)){
        if (strcmp(genero.c_str(), reg.getGeneropeli().c_str()) == 0) {
            _fecha = reg.getFechaEstreno();
            _FechaLimite = reg.getFechaLimiteProyeccion();    // traemos la fecha ya sea de estreno o proyección, hacerlo siempre q haya un listado
            reg.MostrarPeli(_fecha, _FechaLimite);        // porque sino tira cualq valor ojo!
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron peliculas del genero " << genero << endl;
    }

    fclose(p);
}



void GestorArchivos::MostrarPeliculasActivas(){
    pelicula reg;
    FILE *p;
    p = fopen(_rutadire.c_str(),"rb+");
    if(p==NULL){
        exit(2504);
    }

    int y = 12;
            rlutil::locate(30,10);
            cout<<"PELICULA \t" <<"   ESTADO "<<endl;
            rlutil::locate(30,11);
            cout<<"========================"<<endl;
    while(fread(&reg,sizeof(pelicula),1,p)){
          if(reg.getEstadopeli()==0){
                rlutil::locate(30,y);
            cout<<reg.getNombrepeli()<<" \t ||"<<(reg.getEstadopeli() ? "Activo" : "Inactivo")<<endl;
          y++;
          }
          cout<<endl;
}

fclose(p);
}

//int GestorArchivos::obtenerCantRegistros(){
//    int cantidad;
//    FILE *p;
//    p = fopen(_rutadire.c_str(), "rb");
//    if(p==NULL){
//        exit(21);
//    }
//    fseek(p,0,SEEK_END);
//    cantidad = ftell(p);
//
//    return cantidad/sizeof(Viajes);
//}



void GestorArchivos::MostrarCantidadButacasVendidas(){
    Sala _salita;
    GestorArchivos gestor(2);
    GestorArchivos _gestor(3);


    FILE *p;
    p = fopen(_rutadire.c_str(),"rb+");
    if(p==NULL){
        exit(9999);
    }

   cout << left << setw(8) << "SALA N"
     << setw(16) << "CAPACIDAD"
     << setw(20) << "ACTUALES"
     << setw(18) << "VENDIDAS" << endl;
    cout << "----------------------------------------------------------" << endl;

  while (fread(&_salita, sizeof(Sala), 1, p)) {
        int butacasMax = _salita.getMaxButacas();
        int butacasActual = _gestor.conseguimeDisp(_salita.getNumSala());
        int butacasVendidas = butacasMax - butacasActual;

        cout << left << setw(8) << _salita.getNumSala()
             << setw(16) << butacasMax
             << setw(20) << butacasActual
             << setw(18) << butacasVendidas << endl;
    }

    fclose(p);

}


void GestorArchivos::MostrarPeliMVendida(){
    pelicula _peli;
    int Max;
    string peli_;
    bool Pr=false;
    GestorArchivos gestor(1);


    FILE *p;
    p = fopen(_rutadire.c_str(),"rb+");
    if(p==NULL){
        exit(9999);
    }
    while (fread(&_peli, sizeof(pelicula), 1, p)) {

       if(Pr==false){
        Pr=true;
        Max=_peli.getEntradaVen();
        peli_=_peli.getNombrepeli();
       }else if(Max<(_peli.getEntradaVen())){

       Max=_peli.getEntradaVen();
        peli_=_peli.getNombrepeli();

       }
    }

    cout<<"=================================================================="<<endl;

    cout<< right << setw(16)<<"PELICULA MAS VENDIDA: "<<setw(24)<<peli_<<endl;

    cout << right << setw(16) <<"TOTAL :" << setw(24) << Max<< endl;
    cout<<"=================================================================="<<endl;


    fclose(p);

}

void GestorArchivos::Ventpeli(int poss, int Cantv){
        int  EntraV;
        pelicula reg;
        GestorPelicula _gesto;
        system("cls");

        if(poss<0){
            cout<<"NO EXISTE ESA SALA "<<endl;
        }

        reg = _gesto.LeerPelicula(poss);
        //RETORNAMOS PELI
        int Pelii=reg.getEntradaVen();
        EntraV=Pelii+Cantv;
        reg.setEntradaVen(EntraV);
   bool grabo = _gesto.guardarEnDiscoUNApelicula(reg,poss,reg.getFechaEstreno(),reg.getFechaLimiteProyeccion());

}

 void GestorArchivos::ConsultaDeSalaPorNombre(string SalaNombre){
    Sala _salita;
    GestorArchivos gestor(2);
    FILE *p;
    p = fopen(_rutadire.c_str(),"rb+");
    if(p==NULL){
        exit(9090);
    }


    bool encontrado=false;
    int i=0;

    while(fread(&_salita, sizeof(Sala),1, p)){

        string nombre = _salita.getNombre();       ///Pasa siempre los char a string pa todo mambo de find///

        if(nombre.find(SalaNombre) != string::npos){ ///relacionalo siempre a ::string sino no te lo toma///

           _salita.mostrarSala();
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



void GestorArchivos::ConsultaDeVentaPorDNI(string DNI){
    Entradas ventas;
    Fecha _fecha;

    FILE *p;
    p = fopen(_rutadire.c_str(),"rb");
    if(p==NULL){
        exit(32);
    }

   bool encontrado = false;

   system("cls");
   cout<< left << setw(8) <<"DNI"
    <<right<< setw(14) <<"PELICULA"
    << setw(10) <<"SALA"
    << setw(14) <<"IMPORTE"
    << setw(17) <<"FECHA" <<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
   while(fread(&ventas,sizeof(Entradas),1,p)){

        string _dni = ventas.getDNI();
        _fecha = ventas.getFecha();
     if(_dni.find(DNI)!= string::npos){

        cout<<left<< setw(8) <<DNI;
       cout <<right<< setw(14) << ventas.getPelicula();
       cout << setw(10) << ventas.getSala();
      // cout << setw(14) << ventas.getValorTotal();
       cout << setw(14) << _fecha.getDia()<<"/"<<_fecha.getMes()<<"/"<<_fecha.getAnio()<< endl;

        encontrado = true;
     }
   }

   if(!encontrado){
        rlutil::setColor(rlutil::BLUE);
    cout<<"NO SE ENCONTRARON COINCIDENCIAS CON ESE DNI "<<endl;
   system("pause");
   }

system("pause");
fclose(p);
}

void GestorArchivos::ConsultaPorButacasVendidas(int cantVenEntr){
    Entradas ventas;
    FILE *p;
    p = fopen(_rutadire.c_str(),"rb");
    if(p==NULL){
        exit(101);
    }

    cout <<  left << setw(8) <<"BUTACAS VENDIDAS"
         << right<<setw(16) <<"SALA" <<endl;

bool encontrado = false;
    while(fread(&ventas,sizeof(Entradas),1,p)){
        if(cantVenEntr==ventas.getCantVenEntre()){
            cout <<  left << setw(8) <<cantVenEntr;
            cout <<right<< setw(20) <<ventas.getSala()<<endl;
            encontrado = true;
        }
    }
    if(!encontrado){
        cout<<"NO SE ENCONTRARON SALAS CON ESA CANTIDAD DE BUTACAS VENDIDAS " <<endl;
        system("pause");
    }
    system("pause");
    fclose(p);
}


bool GestorArchivos::verificarVentaDuplicada(string dni,string pelicula,Fecha _fecha){
    Entradas ventas;
    FILE *p;
    p = fopen(_rutadire.c_str(),"rb");
    if(p==NULL){
        exit(3312);
    }

    while(fread(&ventas,sizeof(Entradas),1,p)){
     if (ventas.getDNI() == dni &&
            ventas.getPelicula() == pelicula &&
            ventas.getFecha().getDia() == _fecha.getDia() &&
            ventas.getFecha().getMes() == _fecha.getMes() &&
            ventas.getFecha().getAnio() == _fecha.getAnio()) {
            fclose(p);
            return true;
        }
    }

fclose(p);
return false;
}

   int GestorArchivos::conseguimeDisp(int sala){

     int Entradasvent=0;
     Entradas _entrada;
     GestorArchivos _gesto(3);
     int maxs=conseguimeMax(sala);
     int disp_entra=0;

    FILE *p;
    p = fopen(_rutadire.c_str(),"rb+");
    if(p==NULL){
        exit(333);
    }

    while(fread(&_entrada,sizeof(Entradas),1,p)){

    if(sala==_entrada.getSala()){

    Entradasvent+=_entrada.getCantVenEntre();

    }


    }

     disp_entra=maxs-Entradasvent;


 fclose(p);
 return disp_entra;
    }

GestorArchivos::conseguimeMax(int salab){


    Sala _sala;
    int maxsala=0;

    FILE *pp;
    pp = fopen("Salas.dat","rb+");
    if(pp==NULL){
        exit(333);
    }

    while(fread(&_sala,sizeof(Sala),1,pp)){

        if(salab==_sala.getNumSala()){

            maxsala=_sala.getMaxButacas();
                break;

        }
    }
 fclose(pp);
 return maxsala;
 }




// bool GestorArchivos::ReiniciarSala(int IDsala){
//
//Entradas Reg;
//FILE *p;//archivo viejo//
//FILE *PP;//archivo nuevo//
//p= fopen(_rutadire.c_str(),"rb");
//PP=fopen("VentaN.dat","wb+");
//
//while(fread(&Reg,sizeof(Entradas),1,p)){
//
//    if(Reg.getSala()!=IDsala){
//
//        fwrite(&Reg,sizeof(Entradas),1,PP);
//    }
//
//}
//
//fclose(p);
//fclose(PP);
//
//remove(_rutadire.c_str());
//if(rename("VentaN.dat",_rutadire.c_str())!=0){
//    return true;
//}
//}
