#include <iostream>
#include "stdafx.h"
#include <string>
#include <fstream>
#include <sstream>
#include "NodoRojiNegro.h"

class ArbolRojiNegro{
  //private:
  //NodoRojiNegro *RaizRN;

  //protected:


  public:
    // Constructor
    ArbolRojiNegro() { RaizRN = NULL; }
    void insertarValorNodoRN(string pIdDestino, int data,
	string pIdTransporte, string pTipoTransporte, string pOrigen, string pDestino, string pFechaSalida,
                  string pHoraSalida, string pFechaLlegada, string pHoraLlegada, string pCompania, string pNumplazas,
                  string pPrecio, int pCantdeTransportes);

	pNodoRojiNegro InsertarNodoRN(pNodoRojiNegro RaizRN, pNodoRojiNegro pt);

    void rotarIzquierda(NodoRojiNegro *&, NodoRojiNegro *&);
    void rotarDerecha(NodoRojiNegro *&, NodoRojiNegro *&);
    void aplicarReglas(NodoRojiNegro *&, NodoRojiNegro *&);
	void inordenRN(NodoRojiNegro *RaizRN);
	void addMostrado(string pMendaje);
	string getMostrado();
	void borrarMostrado();

    void inorder();

    NodoRojiNegro *RaizRN;
	string mostradoArbol;

    friend class NodoRojiNegro;
};

void ArbolRojiNegro::inordenRN(NodoRojiNegro *RaizRN){
	string mostrado;

    if (RaizRN == NULL)
        return;

    inordenRN(RaizRN->izq);
	mostrado += "\nidTransporte: " + RaizRN->idTransporte;
	mostrado += "\ntipoTransporte: " + RaizRN->tipoTransporte;
	mostrado += "\nOrigen: " + RaizRN->origen;
	mostrado += "\nDestino: " + RaizRN->destino;
	mostrado += "\nFechaSalida: " + RaizRN->fechaSalida;
	mostrado += "\nHoraSalida: " + RaizRN->horaSalida;
	mostrado += "\nFechaLlegada: " + RaizRN->fechaLlegada;
	mostrado += "\nHoraLlegada: " + RaizRN->horaLlegada;
	mostrado += "\nCompania: " + RaizRN->compania;
	mostrado += "\nPlazas: " + RaizRN->numPlazas;
	mostrado += "\nPrecio: " + RaizRN->precio;

	int intCantDeTransportes = RaizRN->cantDeTransportes;
	string stringcantDeTransportes = to_string(intCantDeTransportes);

	mostradoArbol += "\nTransportes disponibles: " + stringcantDeTransportes;
	mostradoArbol += "\n";

	addMostrado(mostrado);
	mostrado = "";

    inordenRN(RaizRN->der);

}

void ArbolRojiNegro::addMostrado(string pMensaje) {
	mostradoArbol += pMensaje;
}

string ArbolRojiNegro::getMostrado() {
	return mostradoArbol;
}

void ArbolRojiNegro::borrarMostrado() {
	mostradoArbol = "";
}

pNodoRojiNegro ArbolRojiNegro::InsertarNodoRN(pNodoRojiNegro RaizRN, pNodoRojiNegro pt){

    if (RaizRN == NULL)
       return pt;

    if (pt->data < RaizRN->data){
        RaizRN->izq  = InsertarNodoRN(RaizRN->izq, pt);
        RaizRN->izq->padre = RaizRN;
    }
    else if (pt->data > RaizRN->data)
    {
        RaizRN->der = InsertarNodoRN(RaizRN->der, pt);
        RaizRN->der->padre = RaizRN;
    }

    return RaizRN;
}

void ArbolRojiNegro::rotarIzquierda(NodoRojiNegro *&RaizRN, NodoRojiNegro *&pt){
    NodoRojiNegro *pt_der = pt->der;

    pt->der = pt_der->izq;

    if (pt->der != NULL)
        pt->der->padre = pt;

    pt_der->padre = pt->padre;

    if (pt->padre == NULL)
        RaizRN = pt_der;

    else if (pt == pt->padre->izq)
        pt->padre->izq = pt_der;

    else
        pt->padre->der = pt_der;

    pt_der->izq = pt;
    pt->padre = pt_der;
}

void ArbolRojiNegro::rotarDerecha(NodoRojiNegro *&RaizRN, NodoRojiNegro *&pt){
    NodoRojiNegro *pt_izq = pt->izq;

    pt->izq = pt_izq->der;

    if (pt->izq != NULL)
        pt->izq->padre = pt;

    pt_izq->padre = pt->padre;

    if (pt->padre == NULL)
        RaizRN = pt_izq;

    else if (pt == pt->padre->izq)
        pt->padre->izq = pt_izq;

    else
        pt->padre->der = pt_izq;

    pt_izq->der = pt;
    pt->padre = pt_izq;
}


void ArbolRojiNegro::aplicarReglas(NodoRojiNegro *&RaizRN, NodoRojiNegro *&pt){
    NodoRojiNegro *padre_pt = NULL;
    NodoRojiNegro *abuelo_pt = NULL;

    while ((pt != RaizRN) && (pt->color != BLACK) &&
           (pt->padre->color == RED))
    {

        padre_pt = pt->padre;
        abuelo_pt = pt->padre->padre;

        /*  Case : A
            Parent of pt is left child of Grand-parent of pt */
        if (padre_pt == abuelo_pt->izq){
            NodoRojiNegro *tio_pt = abuelo_pt->der;

            /* Case : 1
               The uncle of pt is also red
               Only Recoloring required */
            if (tio_pt != NULL && tio_pt->color == RED){
                abuelo_pt->color = RED;
                padre_pt->color = BLACK;
                tio_pt->color = BLACK;
                pt = abuelo_pt;
            }

            else{
                /* Case : 2
                   pt is right child of its parent
                   Left-rotation required */
                if (pt == padre_pt->der)
                {
                    rotarIzquierda(RaizRN, padre_pt);
                    pt = padre_pt;
                    padre_pt = pt->padre;
                }

                /* Case : 3
                   pt is left child of its parent
                   Right-rotation required */
                rotarDerecha(RaizRN, abuelo_pt);
                swap(padre_pt->color, abuelo_pt->color);
                pt = padre_pt;
            }
        }

        /* Case : B
           Parent of pt is right child of Grand-parent of pt */
        else{
            NodoRojiNegro *tio_pt = abuelo_pt->izq;

            /*  Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((tio_pt != NULL) && (tio_pt->color == RED)){
                abuelo_pt->color = RED;
                padre_pt->color = BLACK;
                tio_pt->color = BLACK;
                pt = abuelo_pt;
            }
            else{
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == padre_pt->izq){
                    rotarDerecha(RaizRN, padre_pt);
                    pt = padre_pt;
                    padre_pt = pt->padre;
                }

                /* Case : 3
                   pt is right child of its parent
                   Left-rotation required */
                rotarIzquierda(RaizRN, abuelo_pt);
                swap(padre_pt->color, abuelo_pt->color);
                pt = padre_pt;
            }
        }
    }

    RaizRN->color = BLACK;
}

void ArbolRojiNegro::insertarValorNodoRN(string pIdDestino, int num, string pIdTransporte, string pTipoTransporte, string pOrigen, string pDestino, string pFechaSalida,
                  string pHoraSalida, string pFechaLlegada, string pHoraLlegada, string pCompania, string pNumplazas,
                  string pPrecio, int pCantdeTransportes){

    NodoRojiNegro *pt = new NodoRojiNegro(pIdDestino, num, pIdTransporte, pTipoTransporte, pOrigen, pDestino, pFechaSalida,
                   pHoraSalida, pFechaLlegada, pHoraLlegada, pCompania, pNumplazas,
                   pPrecio, pCantdeTransportes);

    RaizRN = InsertarNodoRN(RaizRN, pt);

    aplicarReglas(RaizRN, pt);
}

void ArbolRojiNegro::inorder(){
    inordenRN(RaizRN);
}


//-----------Pila-----------//

class PilaRN {
   public:
    PilaRN() : plistaRN(NULL) {}

    void PushRN(pnodoRN);
    //void Mostrar();
    bool VaciaRN() { return plistaRN == NULL; }
    pnodoRN PopRN();
    int SizeRN();

    pnodoRN plistaRN;
};

void PilaRN::PushRN(pnodoRN v)
{
   if(VaciaRN()) {
      plistaRN = v;
   }else{
    NodoRojiNegro *aux = plistaRN;
    while(aux->siguiente){
        aux = aux->siguiente;
    }
    aux->siguiente = v;
    v->anterior = aux;

   }
}

pnodoRN PilaRN::PopRN()
{
    NodoRojiNegro *borrar = NULL;
    NodoRojiNegro *salida = NULL;
    if(VaciaRN()){
        cout<<"Pila Vacia"<<endl;
    }else{
    borrar = plistaRN;
    while(borrar->siguiente){
        borrar=borrar->siguiente;
    }
    if(SizeRN()>1){
        salida = borrar;
        borrar->anterior->siguiente=NULL;
        borrar = NULL;
        delete borrar;
    }else{
        salida = plistaRN;
        plistaRN = NULL;
    }
    }
    return salida;
}

int PilaRN::SizeRN(){
    while(plistaRN && plistaRN->anterior) plistaRN = plistaRN->anterior;
    int cont=0;
    NodoRojiNegro *aux;
    aux = plistaRN;
    while(aux){
        cont++;
        aux = aux->siguiente;
    }
    return cont;
}


/*
int main(){
    ArbolRojiNegro RN;

    RN.insertarValorNodoRN(01, "01", "1", "Nicaragua", "Estados Unidos", "20/Enero", "15:00", "21/Enero", "12:00",
                             "Avianca", "24", "300000", 69);
    RN.insertarValorNodoRN(02, "02", "1", "China", "Dubai", "06/Junio", "9:00", "08/Junio", "16:00", "Despegar",
                              "56", "650000", 54);
    RN.insertarValorNodoRN(03, "03", "3", "Mexico", "Costa Rica", "26/Abril", "21:00", "28/Abril", "9:00",
                             "Turismauro","60","250000",12);
    RN.insertarValorNodoRN(24, "24", "3", "Mexisdsco", "Costa", "26/Abril", "21:30", "28/Mayo", "9:00",
                             "Turis323refmauro","60","25340000",212);
    RN.insertarValorNodoRN(15, "15", "2", "USA", "Unidos", "10/Enero", "15:00", "21/Diciembre", "12:00",
                             "AviancaCa", "23", "800100", 16);
    RN.insertarValorNodoRN(9, "9", "1", "Nicaraguita", "Costa Rica", "07/Enero", "5:00", "12/Enero", "2:00",
                             "Avianca", "24", "305000", 6);
    RN.insertarValorNodoRN(16, "01", "1", "China", "Chile", "30/Septiembre", "15:00", "12/Mayo", "1:00",
                             "Avianca", "74", "600000", 69);

    cout << "- Inorden: Arbol RojiNegro:\n";
    RN.inorder();

    //cout << "\n- Recorrido por niveles:\n";
    //RN.levelOrder();

    return 0;
}*/

