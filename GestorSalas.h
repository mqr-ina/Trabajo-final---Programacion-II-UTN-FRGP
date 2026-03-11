#ifndef GESTORSALAS_H_INCLUDED
#define GESTORSALAS_H_INCLUDED

class GestorSalas{

private:
    string _rutadireS="Salas.dat";

public:
    bool GuardarenDiscoSala(Sala);
   void ListarTodasLasSalas();

    bool guardarEnDiscoUNASala(Sala,int);
    int LlamadoDeSala(int);
    Sala LeerSala(int pos);
    int sacaDisp();

    ///
    bool validSalaExistente(int);
    bool ListarTodasLasSalasSPELI();


};


#endif // GESTORSALAS_H_INCLUDED
