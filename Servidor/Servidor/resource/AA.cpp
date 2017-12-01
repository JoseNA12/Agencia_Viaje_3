#include <iostream>
#include "stdafx.h"
#include <string>
#include <fstream>
#include <sstream>
#include "NodoAA.h"

class ArbolAA{
	public:

		ArbolAA(){raizAA = NULL;}
		bool AAVacio(){return raizAA == NULL;}
		void EstablecerRaizAA(pnodoAA Raiz);
		void IniciarInsercionAA(string pIdDestino, int Numero, string pIdViaje, string pIdHotel, string pIdOferta, string pPrecioHabIndiv,
                          string pPrecioHabDoble, int pCantOfertasIndivi, int pCantOfertasDobles);
		pnodoAA InsertarAA(string pIdDestino, int Numero, pnodoAA Raiz, string pIdViaje, string pIdHotel, string pIdOferta, string pPrecioHabIndiv,
                          string pPrecioHabDoble, int pCantOfertasIndivi, int pCantOfertasDobles);
		void RecorridoInordenAA(pnodoAA Raiz);
		void IniciarRecorridoAA();
		pnodoAA Skew(pnodoAA Raiz);
		pnodoAA Split(pnodoAA Raiz);
		pnodoAA RotacionHijoIzquierdoAA(pnodoAA Raiz);
		pnodoAA RotacionHijoDerechoAA(pnodoAA Raiz);
		pnodoAA BuscarElementoAA(int Numero,pnodoAA Raiz);
		void InicializarBusqueda(int Numero);


	//private:

		pnodoAA raizAA;

};

void ArbolAA::EstablecerRaizAA(pnodoAA Raiz)
{
	raizAA = Raiz;
}

void ArbolAA::IniciarInsercionAA(string pIdDestino, int Numero, string pIdViaje, string pIdHotel, string pIdOferta, string pPrecioHabIndiv,
                          string pPrecioHabDoble, int pCantOfertasIndivi, int pCantOfertasDobles)
{
	if(raizAA == NULL){
		raizAA = new NodoArbolAA(pIdDestino, Numero, pIdViaje, pIdHotel, pIdOferta, pPrecioHabIndiv,
                        pPrecioHabDoble, pCantOfertasIndivi, pCantOfertasDobles);
	}
	else{
		pnodoAA Raiz = raizAA;
		InsertarAA(pIdDestino, Numero, Raiz, pIdViaje, pIdHotel, pIdOferta, pPrecioHabIndiv,
                        pPrecioHabDoble, pCantOfertasIndivi, pCantOfertasDobles);
	}
}

pnodoAA ArbolAA::InsertarAA(string pIdDestino, int Numero, pnodoAA Raiz, string pIdViaje, string pIdHotel, string pIdOferta, string pPrecioHabIndiv,
                          string pPrecioHabDoble, int pCantOfertasIndivi, int pCantOfertasDobles)
{
	if(Raiz == NULL){
		Raiz = new NodoArbolAA(pIdDestino, Numero, pIdViaje, pIdHotel, pIdOferta, pPrecioHabIndiv,
                        pPrecioHabDoble, pCantOfertasIndivi, pCantOfertasDobles);
	}
	else if(Numero < Raiz->numero){
		Raiz->hizq = InsertarAA(pIdDestino, Numero, Raiz->hizq, pIdViaje, pIdHotel, pIdOferta, pPrecioHabIndiv,
                        pPrecioHabDoble, pCantOfertasIndivi, pCantOfertasDobles);
	}
	else if(Numero > Raiz->numero){
		Raiz->hder = InsertarAA(pIdDestino, Numero,Raiz->hder, pIdViaje, pIdHotel, pIdOferta, pPrecioHabIndiv,
                        pPrecioHabDoble, pCantOfertasIndivi, pCantOfertasDobles);
	}
	else{
		//cout << "El elemento esta repetido" << endl;
	}
	Raiz = Skew(Raiz);
	Raiz = Split(Raiz);
	raizAA = Raiz;
	return Raiz;
}

pnodoAA ArbolAA::Skew(pnodoAA Raiz)
{
	if(Raiz->hizq == NULL){
		return Raiz;
	}
	else if(Raiz->hizq->nivel == Raiz->nivel){
		Raiz = RotacionHijoIzquierdoAA(Raiz);
		return Raiz;
	}
	else{
		return Raiz;
	}
}

pnodoAA ArbolAA::Split(pnodoAA Raiz)
{
	if(Raiz->hder == NULL){
		return Raiz;
	}
	else if(Raiz->hder->hder == NULL){
		return Raiz;
	}

	else if(Raiz->hder->hder->nivel == Raiz->nivel){
		Raiz = RotacionHijoDerechoAA(Raiz);
		Raiz->nivel++;
		return Raiz;
	}
	else{
		return Raiz;
	}
}

pnodoAA ArbolAA::RotacionHijoIzquierdoAA(pnodoAA Raiz)
{
	//cout <<"Giro" << endl;
	pnodoAA k1 = Raiz->hizq;
    Raiz->hizq = k1->hder;
    k1->hder = Raiz;
    return k1;

}

pnodoAA ArbolAA::RotacionHijoDerechoAA(pnodoAA Raiz)
{
	//cout << "Reparto" << endl;
	pnodoAA k2 = Raiz->hder;
    Raiz->hder = k2->hizq;
    k2->hizq = Raiz;
    return k2;

}

void ArbolAA::RecorridoInordenAA(pnodoAA Raiz)
{
	if(Raiz == NULL){
        return;
    }else{
        RecorridoInordenAA(Raiz->hizq);
        cout << "idOferta: " << Raiz->numero << endl;
        cout << "PrecioHabIndiv: " << Raiz->precioHabIndiv << endl;
        cout << "PrecioHabDoble : " << Raiz->precioHabDoble << endl;
        cout << "CantOfertasIndivi: " << Raiz->cantOfertasIndivi << endl;
        cout << "CantOfertasDobles: " << Raiz->cantOfertasDobles << endl;
        cout << "\n" << endl;
        RecorridoInordenAA(Raiz->hder);
    }
}

void ArbolAA::IniciarRecorridoAA()
{
	pnodoAA Raiz = raizAA;
	RecorridoInordenAA(Raiz);
}
/*
pnodoAA ArbolAA::BuscarElementoAA(int Numero, pnodoAA Raiz)
{
	if(Raiz == NULL){
		cout << "No se encontro el elemento "<< Numero <<  endl;
		return NULL;
	}
	else if(Numero == Raiz->numero){
		cout << "Se encontro el elemento "<< Numero << endl;
		return Raiz;
	}

	else if(Numero < Raiz->numero){
		BuscarElementoAA(Numero, Raiz->hizq);
	}
	else{
		BuscarElementoAA(Numero,Raiz->hder);
	}
	if (1 == 2) {
		return Raiz;
	}
}

void ArbolAA::InicializarBusqueda(int Numero)
{
	pnodoAA Raiz = raizAA;
	BuscarElementoAA(Numero,Raiz);
}*/
/*
int main()
{
	ArbolAA Arbol;
	Arbol.IniciarInsercionAA(100, "25", "89", "100", "50000", "80000", 30, 12);
	Arbol.IniciarInsercionAA(50);
	Arbol.IniciarInsercionAA(40);
	Arbol.IniciarInsercionAA(60);
	Arbol.IniciarInsercionAA(20);
	Arbol.IniciarInsercionAA(45);
	Arbol.IniciarInsercionAA(110);
	Arbol.IniciarInsercionAA(55);
	Arbol.IniciarInsercionAA(19);
	Arbol.IniciarRecorridoAA();
//	Arbol.InicializarBusqueda(110);
	//cin.get();
	return 0;

}*/
