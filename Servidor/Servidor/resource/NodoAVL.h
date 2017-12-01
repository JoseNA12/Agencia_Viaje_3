#include <stdlib.h>
#include <iostream>
#ifndef _NODOAVL_H
#define	_NODOAVL_H

#include "NodoRojiNegro.h"
#include "NodoAA.h"

using namespace std;

class NodoAVL {
   public:

    NodoAVL(string pIdDestino, int num, string pIdHotel, string pNombre, string pCategoria, string pCiudad, string pPrecioHabIndiv,
            string pPrecioHabDoble, int pCantHabIndiv, int pCantHabDoble, NodoAVL *der = NULL, NodoAVL *izq = NULL,
            NodoAVL *sig=NULL, NodoAVL *ant=NULL):
            Hizq(izq), Hder(der), siguiente(sig), anterior(ant), FB(0) {

		idDestino = pIdDestino;
        valor = num;
        idHotel = pIdHotel;
        nombre = pNombre;
        categoria = pCategoria;
        ciudad = pCiudad;
        precioHabIndiv = pPrecioHabIndiv;
        precioHabDoble = pPrecioHabDoble;
        cantHabIndiv = pCantHabIndiv;
        cantHabDoble = pCantHabDoble;
        NodoRNTransp = NULL;
        NodoRNTransp1 = NULL;
        NodoRNTransp2 = NULL;
        NodoRNTransp3 = NULL;
        NodoRNTransp4 = NULL;
        NodoRNTransp5 = NULL;
        NodoRNTransp6 = NULL;
        NodoRNTransp7 = NULL;
        NodoRNTransp8 = NULL;
        NodoRNTransp9 = NULL;
        NodoAAOferT = NULL;
        NodoAAOferT1 = NULL;
        NodoAAOferT2 = NULL;
        NodoAAOferT3 = NULL;
        NodoAAOferT4 = NULL;
        NodoAAOferT5 = NULL;
        NodoAAOferT6 = NULL;
        NodoAAOferT7 = NULL;
        NodoAAOferT8 = NULL;
        NodoAAOferT9 = NULL;

        }

	string idDestino;
    int valor;
    string idHotel;
    string nombre;
    string categoria;
    string ciudad;
    string precioHabIndiv;
    string precioHabDoble;
    int cantHabIndiv;
    int cantHabDoble;
    int FB;

    NodoAVL *Hizq, *Hder, *siguiente, *anterior;
    
    NodoRojiNegro *NodoRNTransp, *NodoRNTransp1, *NodoRNTransp2, *NodoRNTransp3, *NodoRNTransp4;
    NodoRojiNegro *NodoRNTransp5, *NodoRNTransp6, *NodoRNTransp7, *NodoRNTransp8, *NodoRNTransp9;
    
	NodoArbolAA *NodoAAOferT, *NodoAAOferT1, *NodoAAOferT2, *NodoAAOferT3, *NodoAAOferT4;
	NodoArbolAA *NodoAAOferT5, *NodoAAOferT6, *NodoAAOferT7, *NodoAAOferT8, *NodoAAOferT9;
    

    void InsertaAVL(string pIdDestino, int num, string pIdHotel, string pNombre, string pCategoria, string pCiudad, string pPrecioHabIndiv,
            string pPrecioHabDoble, int pCantHabIndiv, int pCantHabDoble);


    friend class AVL;
    friend class TareaProgramada2;
    friend class NodoBinarioBusqueda;

};

typedef NodoAVL *pnodoAVL;
typedef NodoAVL *pNodoAVL;

#endif
