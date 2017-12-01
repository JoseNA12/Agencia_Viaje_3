#include<iostream>
#ifndef _NODOARBOLAA_H
#define	_NODOARBOLAA_H

using namespace std;

class NodoArbolAA{
	public:

		NodoArbolAA(string pIdDestino, int Numero, string pIdViaje, string pIdHotel, string pIdOferta, string pPrecioHabIndiv,
                          string pPrecioHabDoble, int pCantOfertasIndivi, int pCantOfertasDobles){

			idDestino = pIdDestino;
			numero = Numero;
			idViaje = pIdViaje;
            idHotel = pIdHotel;
            idOferta = pIdOferta;
            precioHabIndiv = pPrecioHabIndiv;
            precioHabDoble = pPrecioHabDoble;
            cantOfertasIndivi = pCantOfertasIndivi;
            cantOfertasDobles = pCantOfertasDobles;
			nivel = 0;
			hizq = NULL;
			hder = NULL;
		}

		NodoArbolAA(int Numero, NodoArbolAA *Hizq, NodoArbolAA * Hder){
			numero = Numero;
			nivel = 0;
			hizq = Hizq;
			hder = Hder;
		}


	//private:
		string idDestino;
		int numero;
		int nivel;
		string idViaje;
		string idHotel;
		string idOferta;
		string precioHabIndiv;
        string precioHabDoble;
        int cantOfertasIndivi;
        int cantOfertasDobles;

		NodoArbolAA *hizq;
		NodoArbolAA *hder;

	friend class ArbolAA;

};

typedef NodoArbolAA *pnodoAA;

#endif
