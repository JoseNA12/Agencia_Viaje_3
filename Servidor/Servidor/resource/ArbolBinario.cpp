#include <iostream>
#include "stdafx.h"
#include <string>
#include <fstream>
#include <sstream>
#include "NodoBinarioBusqueda.h"

class Pila {
   public:
    Pila() : plista(NULL) {}

    void Push(pNodoBinario);
    void Mostrar();
    bool Vacia() { return plista == NULL; }
    pNodoBinario Pop();
    int Size();

    pNodoBinario plista;
};

void Pila::Push(pNodoBinario v)
{
   if(Vacia()) {
      plista = v;
   }else{
    NodoBinarioBusqueda *aux=plista;
    while(aux->siguiente){
        aux=aux->siguiente;
    }
    aux->siguiente=v;
    v->anterior=aux;

   }
}

pNodoBinario Pila::Pop()
{
    NodoBinarioBusqueda *borrar = NULL;
    NodoBinarioBusqueda *salida = NULL;
    if(Vacia()){
        cout<<"Pila Vacia"<<endl;
    }else{
    borrar=plista;
    while(borrar->siguiente){
        borrar=borrar->siguiente;
    }
    if(Size()>1){
        salida=borrar;
        borrar->anterior->siguiente=NULL;
        borrar=NULL;
        delete borrar;
    }else{
        salida =plista;
        plista = NULL;
    }
    }
    return salida;
}

int Pila::Size(){
    while(plista && plista->anterior) plista = plista->anterior;
    int cont=0;
    NodoBinarioBusqueda *aux;
    aux=plista;
    while(aux){
        cont++;
        aux=aux->siguiente;
    }
    return cont;
}

void Pila::Mostrar(){
    if(Vacia()){
        cout<<"Vacia";
    }
    NodoBinarioBusqueda *aux = plista;
    while(aux){
        cout<< aux->valor<<" - ";
        aux=aux->siguiente;
    }
}

//---Pila reserva VIAJE---//

class PilaRV {
   public:
    PilaRV() : plistaRV(NULL) {}

    void PushRV(pNodoBinarioReservarViaje);
    void MostrarRV();
    bool VaciaRV() { return plistaRV == NULL; }
    pNodoBinarioReservarViaje PopRV();
    int SizeRV();

    pNodoBinarioReservarViaje plistaRV;
};

void PilaRV::PushRV(pNodoBinarioReservarViaje v)
{
   if(VaciaRV()) {
      plistaRV = v;
   }else{
    NodoBinarioReservarViaje *aux=plistaRV;
    while(aux->siguiente){
        aux=aux->siguiente;
    }
    aux->siguiente=v;
    v->anterior=aux;

   }
}

pNodoBinarioReservarViaje PilaRV::PopRV()
{
    NodoBinarioReservarViaje *borrar = NULL;
    NodoBinarioReservarViaje *salida = NULL;
    if(VaciaRV()){
        cout<<"Pila Vacia"<<endl;
    }else{
    borrar=plistaRV;
    while(borrar->siguiente){
        borrar=borrar->siguiente;
    }
    if(SizeRV()>1){
        salida=borrar;
        borrar->anterior->siguiente=NULL;
        borrar=NULL;
        delete borrar;
    }else{
        salida =plistaRV;
        plistaRV = NULL;
    }
    }
    return salida;
}

int PilaRV::SizeRV(){
    while(plistaRV && plistaRV->anterior) plistaRV = plistaRV->anterior;
    int cont=0;
    NodoBinarioReservarViaje *aux;
    aux=plistaRV;
    while(aux){
        cont++;
        aux=aux->siguiente;
    }
    return cont;
}

void PilaRV::MostrarRV(){
    if(VaciaRV()){
        cout<<"Vacia";
    }
    NodoBinarioReservarViaje *aux = plistaRV;
    while(aux){
        cout<< aux->rv_idCliente<<" - ";
        aux=aux->siguiente;
    }
}

//---Pila reserva Hotel---//

class PilaRH {
   public:
    PilaRH() : plistaRH(NULL) {}

    void PushRH(pNodoBinarioReservarHoteles);
    void MostrarRH();
    bool VaciaRH() { return plistaRH == NULL; }
    pNodoBinarioReservarHoteles PopRH();
    int SizeRH();

    pNodoBinarioReservarHoteles plistaRH;
};

void PilaRH::PushRH(pNodoBinarioReservarHoteles v)
{
   if(VaciaRH()) {
      plistaRH = v;
   }else{
    NodoBinarioReservarHoteles *aux=plistaRH;
    while(aux->siguiente){
        aux=aux->siguiente;
    }
    aux->siguiente=v;
    v->anterior=aux;

   }
}

pNodoBinarioReservarHoteles PilaRH::PopRH()
{
    NodoBinarioReservarHoteles *borrar = NULL;
    NodoBinarioReservarHoteles *salida = NULL;
    if(VaciaRH()){
        cout<<"Pila Vacia"<<endl;
    }else{
    borrar=plistaRH;
    while(borrar->siguiente){
        borrar=borrar->siguiente;
    }
    if(SizeRH()>1){
        salida=borrar;
        borrar->anterior->siguiente=NULL;
        borrar=NULL;
        delete borrar;
    }else{
        salida =plistaRH;
        plistaRH = NULL;
    }
    }
    return salida;
}

int PilaRH::SizeRH(){
    while(plistaRH && plistaRH->anterior) plistaRH = plistaRH->anterior;
    int cont=0;
    NodoBinarioReservarHoteles *aux;
    aux=plistaRH;
    while(aux){
        cont++;
        aux=aux->siguiente;
    }
    return cont;
}

void PilaRH::MostrarRH(){
    if(VaciaRH()){
        cout<<"Vacia";
    }
    NodoBinarioReservarHoteles *aux = plistaRH;
    while(aux){
        cout<< aux->rh_idCliente<<" - ";
        aux=aux->siguiente;
    }

}
//---Pila reserva Transporte---//

class PilaRT {
   public:
    PilaRT() : plistaRT(NULL) {}

    void PushRT(pNodoBinarioReservarTransporte);
    void MostrarRT();
    bool VaciaRT() { return plistaRT == NULL; }
    pNodoBinarioReservarTransporte PopRT();
    int SizeRT();

    pNodoBinarioReservarTransporte plistaRT;
};

void PilaRT::PushRT(pNodoBinarioReservarTransporte v)
{
   if(VaciaRT()) {
      plistaRT = v;
   }else{
    NodoBinarioReservarTransporte *aux=plistaRT;
    while(aux->siguiente){
        aux=aux->siguiente;
    }
    aux->siguiente=v;
    v->anterior=aux;

   }
}

pNodoBinarioReservarTransporte PilaRT::PopRT()
{
    NodoBinarioReservarTransporte *borrar = NULL;
    NodoBinarioReservarTransporte *salida = NULL;
    if(VaciaRT()){
        cout<<"Pila Vacia"<<endl;
    }else{
    borrar=plistaRT;
    while(borrar->siguiente){
        borrar=borrar->siguiente;
    }
    if(SizeRT()>1){
        salida=borrar;
        borrar->anterior->siguiente=NULL;
        borrar=NULL;
        delete borrar;
    }else{
        salida =plistaRT;
        plistaRT = NULL;
    }
    }
    return salida;
}

int PilaRT::SizeRT(){
    while(plistaRT && plistaRT->anterior) plistaRT = plistaRT->anterior;
    int cont=0;
    NodoBinarioReservarTransporte *aux;
    aux=plistaRT;
    while(aux){
        cont++;
        aux=aux->siguiente;
    }
    return cont;
}

void PilaRT::MostrarRT(){
    if(VaciaRT()){
        cout<<"Vacia";
    }
    NodoBinarioReservarTransporte *aux = plistaRT;
    while(aux){
        cout<< aux->rt_idCliente<<" - ";
        aux=aux->siguiente;
    }
}



//---------------------------------------//

class BinarioBusqueda{
  public:
    pNodoBinarioBusqueda raiz;
    pNodoBinarioReservarViaje rv_raiz = NULL;
    pNodoBinarioReservarHoteles rh_raiz = NULL;
    pNodoBinarioReservarTransporte rt_raiz = NULL;

    BinarioBusqueda():raiz(NULL){}

    void InsertaNodoBinarioBusqueda(string pIdDestino, int num, string pIdViaje, string pOrigen, string pDestino, string pFechaSalida,
                                string pFechaLlegada, string pPrecio, string pNumPlazas, int pCantPaquetes);
    
    void InsertarNodoReservacionViaje(int num, string pIdCliente, string pIdViaje, string pNumPlazas);
    
    void InsertarNodoReservacionHotel(int pRv_num, string pIdCliente, string pIdViaje, string pIdHotel, string pFechaInicial, string pFechasFinal, string pPrecioHab);
    
    void InsertarNodoReservacionTransporte(int num, string IdCliente, string IdViaje, string IdTransporte);
    
    void PreordenI();
    string InordenI();
    void PostordenI();
    
    void InordenI_RV();
    void InordenI_RH();
    void InordenI_RT();

    void BuscarViaje();
    string BuscarDestinoViaje(string destino);

    //void Borrar(NodoBinarioBusqueda *nodoB, bool);
    //void BorrarBalanceado(NodoBinarioBusqueda *r, bool, int eliminar);

    friend class TareaProgramada2;

};


void NodoBinarioBusqueda::InsertaBinarioBusqueda(string pIdDestino, int num, string pIdViaje, string pOrigen, string pDestino, string pFechaSalida,
                                string pFechaLlegada, string pPrecio, string pNumPlazas, int pCantPaquetes)
{
    if(num<valor){
        if(Hizq==NULL){
            Hizq = new NodoBinarioBusqueda(pIdDestino, num, pIdViaje, pOrigen, pDestino, pFechaSalida, pFechaLlegada, pPrecio,
                                           pNumPlazas, pCantPaquetes);
        }else{
            Hizq->InsertaBinarioBusqueda(pIdDestino, num, pIdViaje, pOrigen, pDestino, pFechaSalida, pFechaLlegada, pPrecio,
                                           pNumPlazas, pCantPaquetes);
        }
    }else{
        if(Hder==NULL){
            Hder = new NodoBinarioBusqueda(pIdDestino, num, pIdViaje, pOrigen, pDestino, pFechaSalida, pFechaLlegada, pPrecio,
                                           pNumPlazas, pCantPaquetes);
        }else{
            Hder->InsertaBinarioBusqueda(pIdDestino, num, pIdViaje, pOrigen, pDestino, pFechaSalida, pFechaLlegada, pPrecio,
                                           pNumPlazas, pCantPaquetes);
        }
    }
}

void BinarioBusqueda::InsertaNodoBinarioBusqueda(string pIdDestino, int num, string pIdViaje, string pOrigen, string pDestino, string pFechaSalida,
                                string pFechaLlegada, string pPrecio, string pNumPlazas, int pCantPaquetes)
{
    if(raiz==NULL){
        raiz = new NodoBinarioBusqueda(pIdDestino, num, pIdViaje, pOrigen, pDestino, pFechaSalida, pFechaLlegada, pPrecio,
                                           pNumPlazas, pCantPaquetes);
    }else{
        raiz->InsertaBinarioBusqueda(pIdDestino, num, pIdViaje, pOrigen, pDestino, pFechaSalida, pFechaLlegada, pPrecio,
                                           pNumPlazas, pCantPaquetes);
    }
}

//---Reservar Viaje---//

void BinarioBusqueda::InsertarNodoReservacionViaje(int num, string pIdCliente, string pIdViaje, string pNumPlazas){
	
    if(rv_raiz==NULL){
        rv_raiz = new NodoBinarioReservarViaje(num, pIdCliente, pIdViaje, pNumPlazas);
    }else{
        rv_raiz->InsertaBinarioReservacionViaje(num, pIdCliente, pIdViaje, pNumPlazas);
    }
}

void NodoBinarioReservarViaje::InsertaBinarioReservacionViaje(int num, string pIdCliente, string pIdViaje, string pNumPlazas){
    
    if(num < rv_num){
        if(Hizq==NULL){
            Hizq = new NodoBinarioReservarViaje(num, pIdCliente, pIdViaje, pNumPlazas);
        }else{
            Hizq->InsertaBinarioReservacionViaje(num, pIdCliente, pIdViaje, pNumPlazas);
        }
    }else{
        if(Hder==NULL){
            Hder = new NodoBinarioReservarViaje(num, pIdCliente, pIdViaje, pNumPlazas);
        }else{
            Hder->InsertaBinarioReservacionViaje(num, pIdCliente, pIdViaje, pNumPlazas);
        }
    }
}

//---Reservar Hotel---//

void BinarioBusqueda::InsertarNodoReservacionHotel(int pRv_num, string pIdCliente, string pIdViaje, string pIdHotel, string pFechaInicial, string pFechasFinal, string pPrecioHab){

    if(rh_raiz==NULL){
        rh_raiz = new NodoBinarioReservarHoteles(pRv_num, pIdCliente, pIdViaje, pIdHotel, pFechaInicial, pFechasFinal, pPrecioHab);
    }else{
        rh_raiz->InsertaBinarioReservacionHotel(pRv_num, pIdCliente, pIdViaje, pIdHotel, pFechaInicial, pFechasFinal, pPrecioHab);
    }
}

void NodoBinarioReservarHoteles::InsertaBinarioReservacionHotel(int pRv_num, string pIdCliente, string pIdViaje, string pIdHotel, string pFechaInicial, string pFechasFinal, string pPrecioHab){
	
	if(pRv_num < rh_num){
        if(Hizq==NULL){
            Hizq = new NodoBinarioReservarHoteles(pRv_num, pIdCliente, pIdViaje, pIdHotel, pFechaInicial, pFechasFinal, pPrecioHab);
        }else{
            Hizq->InsertaBinarioReservacionHotel(pRv_num, pIdCliente, pIdViaje, pIdHotel, pFechaInicial, pFechasFinal, pPrecioHab);
        }
    }else{
        if(Hder==NULL){
            Hder = new NodoBinarioReservarHoteles(pRv_num, pIdCliente, pIdViaje, pIdHotel, pFechaInicial, pFechasFinal, pPrecioHab);
        }else{
            Hder->InsertaBinarioReservacionHotel(pRv_num, pIdCliente, pIdViaje, pIdHotel, pFechaInicial, pFechasFinal, pPrecioHab);
        }
    }
}


//Reserva transporte

void BinarioBusqueda::InsertarNodoReservacionTransporte(int num, string IdCliente, string IdViaje, string IdTransporte){
	

    if(rt_raiz==NULL){
        rt_raiz = new NodoBinarioReservarTransporte( num, IdCliente, IdViaje, IdTransporte);
    }else{
        rt_raiz->InsertaBinarioReservacionTransporte( num, IdCliente, IdViaje, IdTransporte);
    }
}

void NodoBinarioReservarTransporte::InsertaBinarioReservacionTransporte(int num, string IdCliente, string IdViaje, string IdTransportes){
    
    if(num < rt_num){
        if(Hizq==NULL){
            Hizq = new NodoBinarioReservarTransporte( num, IdCliente, IdViaje, IdTransportes);
        }else{
            Hizq->InsertaBinarioReservacionTransporte( num, IdCliente, IdViaje, IdTransportes);
        }
    }else{
        if(Hder==NULL){
            Hder = new NodoBinarioReservarTransporte( num, IdCliente, IdViaje, IdTransportes);
        }else{
            Hder->InsertaBinarioReservacionTransporte( num, IdCliente, IdViaje, IdTransportes);
        }
    }
}


void BinarioBusqueda::InordenI_RT(){
    NodoBinarioReservarTransporte *Act = rt_raiz;
    PilaRT p;
    bool band=true;
    while(band){

        while(Act!=NULL){
            p.PushRT(Act);
            Act = Act->Hizq;
        }

        if(!p.VaciaRT()){
            Act = p.PopRT();
            cout << "idViaje: " << Act->rt_idCliente << endl;

            cout << "\n" << endl;

            Act = Act->Hder;
        }
        if(p.VaciaRT() && Act == NULL){
            break;
        }
    }
}


void BinarioBusqueda::PreordenI(){
    NodoBinarioBusqueda *Act = raiz;
    Pila p;
    while(p.Vacia()==false || (Act!=NULL)){
        if(Act!=NULL){
            cout << "idViaje: " << Act->valor << endl;
            cout << "Origen: " << Act->origen << endl;
            cout << "Destino: " << Act->destino << endl;
            cout << "FechaSalida: " << Act->fechaSalida << endl;
            cout << "FechaLlegada: " << Act->fechaLlegada << endl;
            cout << "Precio: " << Act->precio << endl;
            cout << "Plazas: " << Act->numPlazas << endl;
            cout << "Paquetes disponibles: " << Act->cantPaquetes << endl;

            cout << "\n" << endl;
            p.Push(Act);
            Act = Act->Hizq;
        }else{
            Act=p.Pop();
            Act=Act->Hder;
        }
    }
}

string BinarioBusqueda::InordenI(){
    NodoBinarioBusqueda *Act = raiz;
    Pila p;
    bool band=true;
    string mostrado;
    while(band){

        while(Act!=NULL){
            p.Push(Act);
            Act = Act->Hizq;
        }

        if(!p.Vacia()){
            Act = p.Pop();
             mostrado += "\nidViaje: " + Act->idViaje;
			mostrado += "\nOrigen: " + Act->origen;
			mostrado += "\nDestino: " + Act->destino;
			mostrado += "\nFechaSalida: " + Act->fechaSalida;
			mostrado += "\nFechaSalida: " + Act->fechaSalida;
			mostrado += "\nFechaLlegada: " + Act->fechaLlegada;
		 	mostrado += "\nPrecio: " + Act->precio;
			mostrado += "\nPlazas: " + Act->numPlazas;
			
			   string stringPaquetes;
			   int paquetes = Act->cantPaquetes;
			   stringPaquetes = to_string(paquetes);
			
			   mostrado += "\nPaquetes: " + stringPaquetes;
			   mostrado += "\n";
            Act = Act->Hder;
        }
        if(p.Vacia() && Act == NULL){
            break;
        }
    }
    return mostrado;
}

void BinarioBusqueda::PostordenI(){
    NodoBinarioBusqueda *Act = raiz;
    Pila p;
    Pila p2;
    while(!p.Vacia() || Act!=NULL){
        if(Act!=NULL){
            p2.Push(new NodoBinarioBusqueda(Act->idDestino, Act->valor, Act->idViaje, Act->origen, Act->destino, Act->fechaSalida,
                                            Act->fechaLlegada, Act->precio, Act->numPlazas, Act->cantPaquetes));
            p.Push(Act);
            Act = Act->Hder;
        }else{
            Act=p.Pop();
            Act = Act->Hizq;
        }
    }
    while(!p2.Vacia()){
        NodoBinarioBusqueda *salida=p2.Pop();
        cout << "idViaje: " << salida->valor << endl;
		cout << "Destino: " << salida->idDestino << endl;
        cout << "Origen: " << salida->origen << endl;
        cout << "Destino: " << salida->destino << endl;
        cout << "FechaSalida: " << salida->fechaSalida << endl;
        cout << "FechaLlegada: " << salida->fechaLlegada << endl;
        cout << "Precio: " << salida->precio << endl;
        cout << "Plazas: " << salida->numPlazas << endl;
        cout << "Paquetes: " << salida->cantPaquetes << endl;
        cout << "\n" << endl;
    }
}

void BinarioBusqueda::InordenI_RV(){
    NodoBinarioReservarViaje *Act = rv_raiz;
    PilaRV p;
    bool band=true;
    while(band){

        while(Act!=NULL){
            p.PushRV(Act);
            Act = Act->Hizq;
        }

        if(!p.VaciaRV()){
            Act = p.PopRV();
            cout << "idViaje: " << Act->rv_idCliente << endl;

            cout << "\n" << endl;

            Act = Act->Hder;
        }
        if(p.VaciaRV() && Act == NULL){
            break;
        }
    }
}


void BinarioBusqueda::InordenI_RH(){
    NodoBinarioReservarHoteles *Act = rh_raiz;
    PilaRH p;
    bool band=true;
    while(band){

        while(Act!=NULL){
            p.PushRH(Act);
            Act = Act->Hizq;
        }

        if(!p.VaciaRH()){
            Act = p.PopRH();
            cout << "idViaje: " << Act->rh_idCliente << endl;

            cout << "\n" << endl;

            Act = Act->Hder;
        }
        if(p.VaciaRH() && Act == NULL){
            break;
        }
    }
}
void BinarioBusqueda::BuscarViaje(){
    NodoBinarioBusqueda *Act = raiz;
    Pila p;
    bool band=true;
    while(band){

        while(Act!=NULL){
            p.Push(Act);
            Act = Act->Hizq;
        }

        if(!p.Vacia()){
            Act = p.Pop();
            cout << "idViaje: " << Act->valor << endl;
            cout << "Origen: " << Act->origen << endl;
            cout << "Destino: " << Act->destino << endl;
            cout << "FechaSalida: " << Act->fechaSalida << endl;
            cout << "FechaLlegada: " << Act->fechaLlegada << endl;
            cout << "Precio: " << Act->precio << endl;
            cout << "Plazas: " << Act->numPlazas << endl;
            cout << "Paquetes: " << Act->cantPaquetes << endl;
            cout << "\n" << endl;

            Act = Act->Hder;
        }
        if(p.Vacia() && Act == NULL){
            break;
        }
    }
}

string BinarioBusqueda::BuscarDestinoViaje(string destino){
    NodoBinarioBusqueda *Act = raiz;
    Pila p;
	string caca = ""; bool encontro = false;
    bool band=true;
    while(band){

        while(Act!=NULL){
            p.Push(Act);
            Act = Act->Hizq;
        }

        if(!p.Vacia()){
            Act = p.Pop();

            if (destino==Act->idDestino){
				string s = std::to_string(Act->cantPaquetes);
				caca += "ID-Viaje: "+Act->idViaje + "\nOrigen: " + Act->origen + "\nFechaSalida: " + Act->fechaSalida + "\nFechaLlegada: " +
					Act->fechaLlegada + "\nPrecio: " + Act->precio + "\nPlazas: " + Act->numPlazas + "\nPaquetes: " + s + "\n\n";
				encontro = true;
			}
			
			Act = Act->Hder;
		 
        }

        if(p.Vacia() && Act == NULL){
        	return caca;
            break;
        }
    }
}

/*
int main(){
	BinarioBusqueda B;
    B.InsertaNodoBinarioBusqueda(12);
    B.InsertaNodoBinarioBusqueda(10);
    B.InsertaNodoBinarioBusqueda(9);
    B.InsertaNodoBinarioBusqueda(8);
    B.InsertaNodoBinarioBusqueda(7);
    B.InsertaNodoBinarioBuNodoAVLHotelsqueda(4);
    B.InsertaNodoBinarioBusqueda(5);
    B.InsertaNodoBinarioBusqueda(1);
    B.InsertaNodoBinarioBusqueda(3);

    B.InordenI();

B.InsertarNodoReservacionViaje(12, "12", "25", "60");

}*/

