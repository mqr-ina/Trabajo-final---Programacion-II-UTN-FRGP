#include <iostream>
#include <string>
#include <cstring>
#include "class_sala.h"
#include "class_pelicula.h"
#include "class_Fecha.h"
#include "class_Entradas.h"
#include "GestorArchivos.h"
#include "GestorPelicula.h"
#include "GestorSalas.h"
#include "Detalle_Venta.h"
#include "menu.h"
#include "rlutil.h"
#include <iomanip>
#include <regex>
#include <ctime>

using namespace std;

void Menu::mostrarMenu(){
    rlutil::setConsoleTitle("Multicine GESTION");
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::RED);
    system("cls");
    rlutil::locate(30,10);
    cout << "|====MENU DE OPCIONES======|" << endl;
    cout << endl;
     rlutil::locate(30,11);
    cout << "|1- MENU DE PELICULAS      |" << endl;
     rlutil::locate(30,12);
    cout << "|2- MENU DE SALAS          |" << endl;
     rlutil::locate(30,13);
    cout << "|3- MENU VENTA DE ENTRADAS |" << endl;
    rlutil::locate(30,14);
    cout<<"|--------------------------|"<<endl;
    rlutil::locate(30,15);
    cout<< "|4- INFORMES               |"<<endl;
    rlutil::locate(30,16);
    cout << "|5- CONSULTAS              |" <<endl;
    cout << endl;
     rlutil::locate(30,17);
    cout<<"|==========================|" <<endl;
    cout << endl;
     rlutil::locate(30,18);
    cout << "|9- SALIR                  |" <<endl;
     rlutil::locate(30,19);
    cout<<"|==========================|" <<endl;
    cout<<endl;
}

void Menu::obtenerOpcion(){
     rlutil::locate(30,20);
    cout<<"INGRESE UNA OPCION: \t"<<endl;
    cin>>_opcion;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
    }
}

void Menu::MenuPeli(){

do{system("cls");
    rlutil::locate(30,10);
    cout << "====MENU DE PELICULAS====" << endl;
    cout << endl;
    rlutil::locate(30,11);
    cout << "1- CARGAR PELICULA" << endl;
    rlutil::locate(30,12);
    cout << "2- MOSTRAR PELICULAS CARGADAS " << endl;
    rlutil::locate(30,13);
    cout << "3- BUSCAR PELICULA POR NOMBRE " << endl;
    rlutil::locate(30,14);
    cout << "4- MODIFICAR ESTADO DE PELICULA " << endl;
    cout << endl;
    cout << endl;

    rlutil::locate(30,15);
    cout << "9- VOLVER  " <<endl;

 obtenerOpcion();


switch(_opcion){

case 1:{
    system("cls");
    cout<<"====CARGANDO PELICULA====="<<endl;
    cin.ignore();
    pelicula obj;
    Fecha _fecha;
    Fecha _FechaLimite;
    obj.CargarPeli(_fecha,_FechaLimite);
    GestorPelicula gestor;
    if(gestor.GuardarenDiscoPelicula(obj,_fecha,_FechaLimite)){
   cout<<"Se guardo exitosamente "<<endl;
   break;
   }
    system("pause");
    break;}

case 2:{
    system("cls");
    GestorPelicula gestor;
    gestor.LeerDeDiscoTODASPeliculas();
    system("pause");
    break;}


    case 3:{
    system("cls");
    GestorArchivos gestor(1);
    pelicula obj;
    string Busqueda;
    cout<<"BUSQUE NOMBRE DE PELICULA: "<<endl;
    cin>> Busqueda;
    obj.BuscarPeliPorNombre(Busqueda);

    break;
}

case 4:{
        system("cls");
        pelicula reg;
        Fecha _fecha;
        Fecha _FechaLimite;
        GestorPelicula _gestor;
        system("cls");
        cout<<"---------MODIFICAR ESTADO DE PELICULA----------"<<endl;
        //localizar la pelicula por su posicion
        _gestor.ListarMenuDePeliculas();

        cout<<"INGRESE NUMERO DE PELICULA: \t";
        int pos;
        cin>>pos;

        if(pos<0){
            cout<<"NO EXISTE ESA POSICION "<<endl;
        }

        ///copiamos el registro en una variable en memoria
        reg = _gestor.LeerPelicula(pos-1);
        //mostramos pelicula
        _gestor.MostrarUnaPelicula(pos-1,reg,_fecha,_FechaLimite);

        ///ASIGNAR NUEVO NOMBRE
        cin.ignore();
        bool estado;
        bool grabo;


        do{
        cin.ignore();
        cout<<"Ingrese nuevo estado (1=ACTIVO, 0=INACTIVO) " <<endl;
        cin>>estado;

        }while(estado!=0 && estado!=1);

        reg.setEstadopeli(estado);



        grabo = _gestor.guardarEnDiscoUNApelicula(reg,pos-1,_fecha,_FechaLimite);
        if(grabo){
            cout<<"SE MODIFICO EXITOSAMENTE "<<endl;
        }
        else{ cout<<"ERROR AL MODIFICAR "<<endl;
        }
    system("pause");
    break;}

case 9:{
    break;
}

    default:
        rlutil::setColor(rlutil::BLACK);//Opcion Incorrecta mano remarcado por boludo
        std::cout << "ERROR, OPCION INCORRECTA!!!" << std::endl;
        rlutil::setColor(rlutil::WHITE);//proba otra vez                                    ///Capaz deberiamos hacer una funcion error, que reciba int y que funque igual que el gestor///

        system("pause");

        break;
}

}
while(_opcion!=9);}


void Menu::MenuSalas(){

do{system("cls");
    rlutil::locate(30,10);
    cout << "====MENU DE SALAS====" << endl;
    cout << endl;
    rlutil::locate(30,11);
    cout << "1- CARGAR SALAS" << endl;
    rlutil::locate(30,12);
    cout << "2- LISTAR TODAS LAS SALAS " << endl;
    cout << endl;
    cout <<"3- CARGAR PELICULA EN SALA" << endl;
    cout << endl;
    cout << endl;
    rlutil::locate(30,14);
    cout << "9- VOLVER  " <<endl;

obtenerOpcion();

switch(_opcion){

        case 1:  {
                system("cls");
                cout<<"====CARGANDO SALA====="<<endl;
                  GestorSalas gestor;
                  Sala _sala;
                  cin.ignore();
                  _sala.cargarSala();
                  if(gestor.GuardarenDiscoSala(_sala)){
                    cout<<"SALA CARGADA CON EXITO"<<endl;
                  }
                  system("pause");
                    break;}

        case 2:{
                system("cls");
                  cout<<"==========SALAS=========="<<endl;
                  GestorSalas gestor;
                  Sala _sala;
                  cin.ignore();
                  gestor.ListarTodasLasSalas();
                  system("pause");
                  break;}

    case 3:{
                system("cls");
                cout<<"=======MODIFICAR========="<<endl;
                GestorSalas _sala;
                if(_sala.ListarTodasLasSalasSPELI()){
                   system("pause");
                }else{
                cout<<"NO HAY SALAS SIN PELICULAS"<<endl;
                system("pause");

                }





    break;}

        case 9:{
           break;
    }


        default:

        rlutil::setColor(rlutil::BLACK);//Opcion Incorrecta mano remarcado por boludo
        std::cout << "ERROR, OPCION INCORRECTA!!!" << std::endl;
        rlutil::setColor(rlutil::WHITE);//proba otra vez
        system("pause");
        break;
        }

}while(_opcion!=9);

}

void Menu::MenuVentas(){
do{
system("cls");
    rlutil::locate(30,10);
    cout << "===========VENTAS==============" << endl;
    cout << endl;
    rlutil::locate(30,11);
    cout << "1- REGISTRAR VENTA" << endl;
    rlutil::locate(30,12);
    cout << "2- LISTAR TODAS LAS VENTAS" << endl;
    rlutil::locate(30,13);
    cout << "------------------------------- " << endl;
    cout << endl;
    cout << endl;
    rlutil::locate(30,14);
    cout << "9- VOLVER  " <<endl;

obtenerOpcion();

switch(_opcion){

case 1:{
    system("cls");

    Entradas venta;
    Fecha _fecha;
    GestorArchivos gestor(3);

        if(venta.cargarEntrada(_fecha)){
        gestor.GuardarenDiscoVenta(venta);
            cout<<"SE GUARDO EXITOSAMENTE LA VENTA "<<endl;

//        if(gestor.conseguimeDisp(venta.getSala())<=0){
//        gestor.ReiniciarSala(venta.getSala());}
        system("pause");
        }else{
        cout<<"NO SE GUARDO NINGUNA VENTA, puede ser por venta duplicada o algun error "<<endl;
        system("pause");
        }
        break;}
case 2:
    {
    system("cls");
    Entradas venta;
    Fecha _fecha;
    GestorArchivos gestor(3);
    gestor.ListarTodasLasVentas();
    system("pause");
    break;
    }


case 9:
    break;

default:
        rlutil::setColor(rlutil::BLACK);//Opcion Incorrecta mano remarcado por boludo
        std::cout << "ERROR, OPCION INCORRECTA!!!" << std::endl;
        rlutil::setColor(rlutil::WHITE);//proba otra vez
        system("pause");
        break;


}

}while(_opcion !=9);}

void Menu::MenuInformes(){
do{
    system("cls");
    rlutil::locate(30,10);
    cout<<"=============INFORMES============"<<endl;
    rlutil::locate(30,11);
    cout<<"1- INFORME DE RECAUDACION TOTAL ANUAL"<<endl;
    rlutil::locate(30,12);
    cout<<"2- CANTIDAD DE BUTACAS ACTUALES POR SALAS " <<endl;
    rlutil::locate(30,13);
    cout<<"3- PELICULA MAS VENDIDA " <<endl;
    rlutil::locate(30,14);
    cout<<"4- INFORME MENSUAL " <<endl;

    cout<<endl;
    cout<<endl;
    rlutil::locate(30,17);
    cout<<"9- VOLVER"<<endl;

    obtenerOpcion();

switch(_opcion){
    case 1: {
    system("cls");
    int anio;
    Detalle detalle;
    cout<<"Ingrese anio a presentar informe"<<endl;
    cin>>anio;
    detalle.RecaudacionAnual(anio);

   // gestor.RecaudacionAnual(venta);
    system("pause");
    break;
}
    case 2:{
        system("cls");
        Sala _sala;
        GestorArchivos gestor(2);
        gestor.MostrarCantidadButacasVendidas();
        system("pause");
        break;
    }

    case 3:{
        system("cls");
        pelicula _peli;
        GestorArchivos gesto(1);
        gesto.MostrarPeliMVendida();
        system("pause");
        break;

    }

    case 4:{
        system("cls");
        int anio;
        Detalle detalle;
        cout<<"Ingrese el anio de su recaudacion mensual"<<endl;
        cin>>anio;
        detalle.RecaudacionPorMes(anio);

        system("pause");
        break;
    }


case 9:
    break;

}

}while(_opcion!=9);

}

void Menu::MenuConsultas(){
do{
    system("cls");
    rlutil::locate(30,10);
    cout<<"=============CONSULTAS============"<<endl;
    rlutil::locate(30,11);
    cout<<"1- BUSCAR PELICULA POR GENERO "<<endl;
    rlutil::locate(30,12);
    cout<<"2- LISTADO DE PELICULAS INACTIVAS " <<endl;
    rlutil::locate(30,13);
    cout<<"3- BUSCAR SALA POR NOMBRE "<<endl;
    rlutil::locate(30,14);
    cout<<"4- BUSCAR VENTA POR DNI " <<endl;
    rlutil::locate(30,15);
    cout<<"5- BUSCAR ENTRADA POR CANTIDAD DE BUTACAS VENDIDAS " <<endl;


    cout<<endl;
    cout<<endl;
    rlutil::locate(30,16);
    cout<<"9- VOLVER"<<endl;

    obtenerOpcion();

switch(_opcion){
    case 1: {
    system("cls");
    pelicula reg;
    Fecha _fecha;
    Fecha FechaLimite;
    GestorArchivos gestor(1);

    gestor.BuscarPeliculaPorGenero(_fecha,FechaLimite);

    system("pause");
    break;
}
    case 2:{
        system("cls");
        pelicula reg;
        GestorArchivos gestor(1);
        gestor.MostrarPeliculasActivas();
        system("pause");
        break;
    }

    case 3:{
        system("cls");
        Sala _salita;
        GestorArchivos gestor(2);
        string salaNombre;
        cin.ignore();

        gestor.ListarMenuDeSalas();
        cout<<"INGRESE EL NOMBRE DE LA SALA A BUSCAR "<<endl;
        cin>>salaNombre;


        gestor.ConsultaDeSalaPorNombre(salaNombre);
        system("pause");
        break;
    }

    case 4: {
            system("cls");
            Entradas ventas;
            Fecha _fecha;
            Fecha FechaLimite;
            GestorArchivos gestor(3);
            string DNI;
            cin.ignore();
            cout<<"INGRESE EL DNI DE LA VENTA A BUSCAR " <<endl;
            cin>>DNI;

            gestor.ConsultaDeVentaPorDNI(DNI);

            break;
    }

    case 5:{
        system("cls");
        Entradas ventas;
        GestorArchivos gestor(3);
        int cantVentEntr;
        cout<<"INGRESE LA CANTIDAD DE BUTACAS A BUSCAR "<<endl;
        cin>>cantVentEntr;

        gestor.ConsultaPorButacasVendidas(cantVentEntr);
        break;
    }



case 9:
    break;

}

}while(_opcion!=9);

}





void Menu::opcionesMenu(){
    switch(_opcion){
    obtenerOpcion();

    case 1: MenuPeli();
            break;
    case 2: MenuSalas();
            break;
    case 3: MenuVentas();
            break;
    case 4: MenuInformes();
            break;
    case 5: MenuConsultas();
            break;
    case 9:
    {
        _salir=true;
        std::cout << "SALIMOS DEL SISTEMA" << std::endl;
        system("pause");
        exit(00);
    break;
    }
    default:
        rlutil::setColor(rlutil::BLACK);//Opcion Incorrecta mano, remarcado por boludo
        std::cout << "ERROR, OPCION INCORRECTA!!!" << std::endl;
        rlutil::setColor(rlutil::WHITE);//proba otra vez
        system("pause");
        break;
    }}


void Menu::ejecutarMenu()
{
    GestorArchivos _gcomp1(1);
    GestorArchivos _gcomp2(2);     ///Comprueban si los archivos .dat existen, caso contrario los crea///
    GestorArchivos _gcomp3(3);
    _gcomp1.ArrancanDatos();
    _gcomp2.ArrancanDatos();
    _gcomp3.ArrancanDatos();

    while(!_salir)
    {
        mostrarMenu();
        obtenerOpcion();
        opcionesMenu();
    }
}

Menu::Menu()
{
    _salir=false;
}


bool Menu::validGene(string ge){

regex patron("^[A-Z]$");  // ^inicio del string, $fin del string,+no vacio,{min,max}//

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




