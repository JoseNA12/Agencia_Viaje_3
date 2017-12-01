#include <stdlib.h>
#include <iostream>
#ifndef _NODOROJINEGRO_H
#define	_NODOROJINEGRO_H

using namespace std;

enum Color {RED, BLACK};

class NodoRojiNegro{

  public:
	string idDestino;
    int data; //ID de tipo entero
    string idTransporte;
    string tipoTransporte;
    string origen;
    string destino;
    string fechaSalida;
    string horaSalida;
    string fechaLlegada;
    string horaLlegada;
    string compania;
    string numPlazas;
    string precio;
    int cantDeTransportes;

    bool color;
    NodoRojiNegro *izq;
    NodoRojiNegro *der;
    NodoRojiNegro *padre;
    NodoRojiNegro *siguiente;
    NodoRojiNegro *anterior;

    // Constructor
	NodoRojiNegro(string pIdDestino, int pData, string pIdTransporte, string pTipoTransporte, string pOrigen, string pDestino, string pFechaSalida,
		string pHoraSalida, string pFechaLlegada, string pHoraLlegada, string pCompania, string pNumplazas,
		string pPrecio, int pCantdeTransportes) {

		idDestino = pIdDestino;
		data = pData; // ID de tipo entero
		idTransporte = pIdTransporte;
		tipoTransporte = pTipoTransporte;
		origen = pOrigen;
		destino = pDestino;
		fechaSalida = pFechaSalida;
		horaSalida = pHoraSalida;
		fechaLlegada = pFechaLlegada;
		horaLlegada = pHoraLlegada;
		compania = pCompania;
		numPlazas = pNumplazas;
		precio = pPrecio;
		cantDeTransportes = pCantdeTransportes;
		siguiente = NULL;
		anterior = NULL;

		izq = NULL;
		der = NULL;
		padre = NULL;
	}

    friend class RojiNegro;
};

typedef NodoRojiNegro *pNodoRojiNegro;
typedef NodoRojiNegro *pnodoRN;

#endif
