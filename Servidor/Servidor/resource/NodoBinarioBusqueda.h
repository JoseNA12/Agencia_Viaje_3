#include <iostream>
#ifndef _NODOBINARIOBUSQUEDA_H
#define	_NODOBINARIOBUSQUEDA_H

#include "NodoAVL.h"


using namespace std;

class NodoBinarioBusqueda {
   public:

    NodoBinarioBusqueda(string pIdDestino, int num, string pIdViaje, string pOrigen, string pDestino, string pFechaSalida, string pFechaLlegada,
                        string pPrecio, string pNumPlazas, int pCantPaquetes,
                        NodoBinarioBusqueda *der = NULL, NodoBinarioBusqueda *izq = NULL, NodoBinarioBusqueda *sig=NULL,
                        NodoBinarioBusqueda *ant=NULL):
                        Hizq(izq), Hder(der), siguiente(sig), anterior(ant) {

		idDestino = pIdDestino;
        valor = num;
        idViaje = pIdViaje;
        origen = pOrigen;
        destino = pDestino;
        fechaSalida = pFechaSalida;
        fechaLlegada = pFechaLlegada;
        precio = pPrecio;
        numPlazas = pNumPlazas;
        cantPaquetes = pCantPaquetes;
        NodoAVLHotel = NULL;
        NodoAVLHotel1 = NULL;
        NodoAVLHotel2 = NULL;
        NodoAVLHotel3 = NULL;
        NodoAVLHotel4 = NULL;
        NodoAVLHotel5 = NULL;
        NodoAVLHotel6 = NULL;
        NodoAVLHotel7 = NULL;
        NodoAVLHotel8 = NULL;
        NodoAVLHotel9 = NULL;

        }

	string idDestino;
    int valor; // num
    string idViaje;
    string origen;
    string destino;
    string fechaSalida;
    string fechaLlegada;
    string precio;
    string numPlazas;
    int cantPaquetes;

	NodoBinarioBusqueda *Hizq, *Hder, *siguiente, *anterior;
	NodoAVL *NodoAVLHotel, *NodoAVLHotel1, *NodoAVLHotel2, *NodoAVLHotel3, *NodoAVLHotel4;
	NodoAVL *NodoAVLHotel5, *NodoAVLHotel6, *NodoAVLHotel7, *NodoAVLHotel8, *NodoAVLHotel9;
	
    void InsertaBinarioBusqueda(string pIdDestino, int num, string pIdViaje, string pOrigen, string pDestino, string pFechaSalida,
                                string pFechaLlegada, string pPrecio, string pNumPlazas, int pCantPaquetes);

    friend class BinarioBusqueda;
    friend class TareaProgramada2;
    friend class NodoAVL;

};

typedef NodoBinarioBusqueda *pNodoBinario;
typedef NodoBinarioBusqueda *pNodoBinarioBusqueda;


class NodoBinarioReservarViaje{
	public:
		NodoBinarioReservarViaje(int pRv_num, string pIdCliente, string pIdViaje, string pNumPlazas,
						NodoBinarioReservarViaje *der = NULL, NodoBinarioReservarViaje *izq = NULL, NodoBinarioReservarViaje *sig=NULL,
                        NodoBinarioReservarViaje *ant=NULL):
                        Hizq(izq), Hder(der), siguiente(sig), anterior(ant){
                
		pRv_num = rv_num;        	
    	rv_idCliente = pIdCliente;
    	rv_idViaje = pIdViaje;
    	rv_numPlazas = pNumPlazas;
	}
	
	int rv_num;
	string rv_idCliente;
    string rv_idViaje;
    string rv_numPlazas;
    
    NodoBinarioReservarViaje *Hizq, *Hder, *siguiente, *anterior;
    
    void InsertaBinarioReservacionViaje(int num, string pIdCliente, string pIdViaje, string pNumPlazas);
    
    friend class BinarioBusqueda;
    friend class TareaProgramada2;
		
};

typedef NodoBinarioReservarViaje* pNodoBinarioReservarViaje;


class NodoBinarioReservarHoteles{
	public:
		NodoBinarioReservarHoteles(int pRv_num, string pIdCliente, string pIdViaje, string pIdHotel, string pFechaInicial, string pFechasFinal, string pPrecioHab,
						NodoBinarioReservarHoteles *der = NULL, NodoBinarioReservarHoteles *izq = NULL, NodoBinarioReservarHoteles *sig=NULL,
                        NodoBinarioReservarHoteles *ant=NULL):
                        Hizq(izq), Hder(der), siguiente(sig), anterior(ant){
                
		rh_num = pRv_num;
		rh_idCliente = pIdCliente;
	    rh_idViaje = pIdViaje;
	    rh_idHotel = pIdHotel;
	    rh_fechaInicial = pFechaInicial;
	    rh_fechaFinal = pFechasFinal;
	    rh_precioHabitacion = pPrecioHab;
	}
	
	int rh_num;
	string rh_idCliente;
    string rh_idViaje;
    string rh_idHotel;
    string rh_fechaInicial;
    string rh_fechaFinal;
    string rh_precioHabitacion;
    
    NodoBinarioReservarHoteles *Hizq, *Hder, *siguiente, *anterior;
    
    void InsertaBinarioReservacionHotel(int pRv_num, string pIdCliente, string pIdViaje, string pIdHotel, string pFechaInicial, string pFechasFinal, string pPrecioHab);
    
    friend class BinarioBusqueda;
    friend class TareaProgramada2;
		
};

typedef NodoBinarioReservarHoteles* pNodoBinarioReservarHoteles;



class NodoBinarioReservarTransporte{
	public:
		NodoBinarioReservarTransporte(int num, string IdCliente, string IdViaje, string IdTransporte,
						NodoBinarioReservarTransporte *der = NULL, NodoBinarioReservarTransporte *izq = NULL, NodoBinarioReservarTransporte *sig=NULL,
                        NodoBinarioReservarTransporte *ant=NULL):
                        Hizq(izq), Hder(der), siguiente(sig), anterior(ant){
                
		rt_num = num;        	
    	rt_idCliente = IdCliente;
    	rt_idViaje = IdViaje;
    	rt_idTransporte = IdTransporte;
	}
	
	int rt_num;
	string rt_idCliente;
    string rt_idViaje;
    string rt_idTransporte;
    
    NodoBinarioReservarTransporte *Hizq, *Hder, *siguiente, *anterior;
    
   void InsertaBinarioReservacionTransporte(int num, string IdCliente, string IdViaje, string IdTransportes);
   
    
    friend class BinarioBusqueda;
    friend class TareaProgramada2;
    friend class Pila;
		
};

typedef NodoBinarioReservarTransporte* pNodoBinarioReservarTransporte;


#endif
