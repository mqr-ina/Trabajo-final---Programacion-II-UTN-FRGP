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
#include "Detalle_Venta.h"
using namespace std;

void Detalle::DetalleDeVenta(string idVenta){



}

void Detalle::RecaudacionAnual(int Anio){
    Entradas ventas;
    Fecha fecha;
    FILE *p;

    float acumulador = 0;
    p=fopen("Ventas.dat","rb+");
    if(p==NULL){
        exit(808);
    }


    while(fread(&ventas,sizeof(Entradas),1,p)){
    fecha = ventas.getFecha();
    if(ventas.getFecha().getAnio()==Anio){
       acumulador += ventas.getImpValor()*ventas.getCantVenEntre();
    }
        }
    cout<<"======================================================"<<endl;
    cout<<endl;
    cout<<"LA RECAUDACION ANUAL PARA EL ANIO "<<Anio<<" ES DE: "<<acumulador<<endl;
    cout<<endl;
    cout<<"======================================================"<<endl;
    fclose(p);
}

void Detalle::RecaudacionPorMes(int Anio){
    Entradas ventas;
    Fecha fecha;

    float mes[12] = {};

    FILE *p;
    p = fopen("Ventas.dat","rb+");
     if(p==NULL){
        exit(202);
    }


    while(fread(&ventas,sizeof(Entradas),1,p)){
           if (ventas.getFecha().getAnio() == Anio) {
    int mesActual = ventas.getFecha().getMes();
    mes[mesActual - 1] += ventas.getImpValor() * ventas.getCantVenEntre();
}
    }


    fclose(p);

        cout << "RECAUDACIONES PARA EL ANIO: " << Anio << endl;
    cout << "MES  |  TOTAL RECAUDADO" << endl;
    cout << "-------------------------" << endl;

    for (int i = 0; i < 12; i++) {
        if (mes[i] > 0) {
            cout << setw(2) << setfill('0') << (i + 1)
                 << "   |  $" << fixed << setprecision(2) << mes[i] << endl;
        }
    }
}





