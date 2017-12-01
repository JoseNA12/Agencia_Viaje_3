#include <iostream>
#include "stdafx.h"
#include <string>
#include <fstream>

using namespace std;

class nodo {
   public:
    nodo(string v)
    {
       valor = v;
       siguiente = NULL;
    }

	nodo(string v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    string valor;
    nodo *siguiente;

   friend class lista;
   friend class TareaProgramada2;
};

typedef nodo *pnodoLista;

class lista {
   public:
    lista() { primero = actual = NULL; }
    ~lista();

    void InsertarFinal(string v);
    bool ListaVacia() { return primero == NULL; }
    //void Imprimir();
    void Mostrar();
    void Siguiente();
    void Primero();
    void Ultimo();
    void BorrarFinal();
    int largoLista();
    bool buscarElemento(string v);

   private:
    pnodoLista primero;
    pnodoLista actual;

    friend class TareaProgramada2;
};

lista::~lista()
{
   pnodoLista aux;

   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}

int lista::largoLista(){
    int cont=0;

    pnodoLista aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }

}

void lista::InsertarFinal(string v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     { pnodoLista aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
      }
}


void lista::BorrarFinal()
{
    if (ListaVacia()){
//     cout << "No hay elementos en la lista:" << endl;

   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                pnodoLista aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }

              pnodoLista temp = aux->siguiente;
              aux->siguiente= NULL;


                delete temp;
            }
        }
}

void lista::Mostrar()
{
   nodo *aux;

   aux = primero;
   while(aux) {
      //cout << aux->valor << "-> " << endl;
      aux = aux->siguiente;
   }

}

void lista::Siguiente()
{
   if(actual) actual = actual->siguiente;
}

void lista::Primero()
{
   actual = primero;
}

void lista::Ultimo()
{
   actual = primero;
   if(!ListaVacia())
      while(actual->siguiente) Siguiente();
}

bool lista::buscarElemento(string v){
	pnodoLista aux;

	aux = primero;

	if(ListaVacia())
		return false;

	else{
		while(aux != NULL){
			if(aux -> valor == v){
				return true;
			}
			else
				aux = aux -> siguiente;
		}
		return false;
	}
}
