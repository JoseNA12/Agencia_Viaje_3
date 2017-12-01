//SOCKETS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")

#include <conio.h>
#include <WinSock2.h>
#include <stdio.h>

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "resource/ArbolBinario.cpp" // Viajes
#include "resource/AVL.cpp" // Hoteles
#include "resource/RojiNegro.cpp" // Transportes
#include "resource/B.cpp" // Clientes
#include "resource/AA.cpp" // Oferta Transporte
#include "resource/listaSimple.cpp" // Validaciones de ID's repetidos
#include "resource/listag.h"
#include "resource/Dijkstra.cpp"
#include "resource/Kruskal.cpp"





using namespace std;

//VARIABLES
SOCKET Connections[100];
int TotalConnections = 0;
//FIN VARIABLES


//----------SOCKETS----------//
string Respuesta(char *datos, int tamanio);
string DesconectarCliente();

void ClientHandlerThread(int index);
string funcionesServidor(string funcion, string informacion);

class TareaProgramada2 {

public:

	string tipoHab;
	string opcionHotel;
	bool escogioHab = false;

	string tieneOferta;
	string precioHab;
	string opcionOferta;


	void CargarArchivos();
	void leerArchivoDestinos();
	void leerArchivoConexiones();
	void leerArchivoViaje(); // Binario
	void leerArchivoHotel(); // AVL
	void leerArchivoTransporte(); // RN
	void leerArchivoOfertaHotel(); // AA
	void leerArchivoClientes(); // B

	pNodoBinarioBusqueda buscarViaje(string pIdViaje);
	pNodoAVL buscarHotel(string pIdHotel);
	pNodoRojiNegro buscarTransporte(string pIdTransporte);
	void buscarOfertaHotel(pnodoAA Raiz, string pIdOferta);
	void setAuxOfertaHotel(NodoArbolAA *auxOF);
	pnodoAA getAuxOfertaHotel();
	void buscarCliente(ApuntadorPagina Raiz, string pIdCliente);
	void setAuxCliente(NodoArbolB *aux);
	pNodoB getAuxCliente();

	pNodoBinarioReservarViaje buscarViajeReservacion(string pIdCliente);
	pNodoBinarioReservarHoteles buscarHotelReservacion(string pIdCliente);
	pNodoBinarioReservarTransporte buscarTransporteReservacion(string pIdCliente);

	void enlazarHotelAViaje(string pIdViaje, pNodoAVL auxHotel);
	void enlazarTranspAHotel(string pHotel, pNodoRojiNegro auxTransporte);
	void enlazarOfertaHotelAHotel(string pHotel, pnodoAA auxOfertaTransporte);

	void verReferenciasViaje(string pIdViaje);
	void verReferenciasHotel(string pIdHotel);

	//------OPERACION PRINCIPALES------//

	string ConsultarPrecioProducto(string info); // 0
	string MostrarArbol(string eleccion); // 1
	string ConsultarViajeHotelTransporteDeUnCliente(string info); // 2
	string ConsultarOrigenDestidoDeUnViaje(string opcionViaje); // 3
	string ConsultarInformacionDeUnCliente(string opcionCliente); // 4
	string ConsultarCategoriaDeUnHotel(string opcionHotel); // 5
	string ConsultarPrecioViajeHotelTransporteDeUnCliente(string opcionCliente); // 6

																				 //Viajes
	string RealizarReservacionViaje0(string opcionIDCliente);
	string RealizarReservacionViaje1(string opcionViaje);
	string RealizarReservacionViaje2(string info);

	//Transportes
	string RealizarReservacionTransp0(string opcionCliente);
	string RealizarReservacionTransp1(string info);

	//Hoteles
	string RealizarReservacionHotel0(string opcionCliente);
	string RealizarReservacionHotel1(string info);
	string RealizarReservacionHotel2(string info);
	string RealizarReservacionHotel3(string info);

	string ConsultarPaquetesDeUnViaje(string opcionViaje); // 8

	string buscarViajeDestino(string destino);

	void ejecutarDijkstra();
	string LlamarPrim();
	string LlamarDijkstra(string inicio);
	string LlamarKruskal();

	string anchuraGrafo();
	string profundidadGrafo();


	string SalirPrograma(); // 9


private:
	lista ListaIDViajes; // Listas: Unicamente para verificar repetidos
	lista ListaIDHoteles;
	lista ListaIDOfertaHoteles;
	lista ListaIDTransportes;
	lista ListaIDCliente;
	lista listaIDCliente_Reservacion;
	lista listaIDCliente_ReservacionHotel;
	lista listaIDCliente_ReservacionTransporte;
	lista lista_Origenes_Destinos;

	BinarioBusqueda arbolBinario;
	AVL arbolAVL;
	ArbolRojiNegro arbolRN;
	ArbolB arbolB;
	ArbolAA arbolAA;

	BinarioBusqueda arbolReserViajes;
	BinarioBusqueda arbolReserHoteles;
	BinarioBusqueda arbolResertTransporte;


	grafo Grafo;
	Dijkstra grafoDijkstra;
	Kruskal grafoKruskal;


	NodoArbolB *auxCliente = NULL;
	NodoArbolAA *auxOfertaTransporte = NULL;


	friend class BinarioBusqueda;
	friend class AVL;
	friend class ArbolB;
	friend class ArbolAA;
	friend class arbolRojiNegro;
	friend class lista;

};

TareaProgramada2 programa;


//----------------------BUSQUEDAS----------------------//

pNodoBinarioBusqueda TareaProgramada2::buscarViaje(string pIdViaje) {

	NodoBinarioBusqueda *Act = arbolBinario.raiz;
	Pila p;
	NodoBinarioBusqueda *Temp = NULL;

	while (p.Vacia() == false || (Act != NULL)) {
		if (Act != NULL) {
			if ((Act->idViaje) == pIdViaje) {
				Temp = Act;
			}

			p.Push(Act);
			Act = Act->Hizq;

		}
		else {
			Act = p.Pop();
			Act = Act->Hder;
		}
	}
	return Temp;
}

pNodoAVL TareaProgramada2::buscarHotel(string pIdHotel) {

	NodoAVL *Act = arbolAVL.raiz;
	PilaAVL p;
	NodoAVL *Temp = NULL;

	while (p.VaciaAVL() == false || (Act != NULL)) {
		if (Act != NULL) {
			if (Act->idHotel == pIdHotel) {
				Temp = Act;
			}

			p.PushAVL(Act);
			Act = Act->Hizq;

		}
		else {
			Act = p.PopAVL();
			Act = Act->Hder;
		}
	}
	return Temp;
}

pNodoRojiNegro TareaProgramada2::buscarTransporte(string pIdTransporte) {

	NodoRojiNegro *Act = arbolRN.RaizRN;
	PilaRN p;
	NodoRojiNegro *Temp = NULL;

	while (p.VaciaRN() == false || (Act != NULL)) {
		if (Act != NULL) {
			if (Act->idTransporte == pIdTransporte) {
				Temp = Act;
			}

			p.PushRN(Act);
			Act = Act->izq;

		}
		else {
			Act = p.PopRN();
			Act = Act->der;
		}
	}
	return Temp;
}

void TareaProgramada2::buscarOfertaHotel(pnodoAA pRaiz, string pIdOferta) {
	//pRaiz = arbolAA.raizAA;
	if (pRaiz == NULL) {
		return;
	}
	else {
		buscarOfertaHotel(pRaiz->hizq, pIdOferta);

		if (pRaiz->idOferta == pIdOferta) {
			setAuxOfertaHotel(pRaiz);
		}

		buscarOfertaHotel(pRaiz->hder, pIdOferta);
	}
}

void TareaProgramada2::setAuxOfertaHotel(NodoArbolAA *pAuxOF) {
	auxOfertaTransporte = pAuxOF;
}

pnodoAA TareaProgramada2::getAuxOfertaHotel() {
	return auxOfertaTransporte;
}

void TareaProgramada2::buscarCliente(ApuntadorPagina Raiz, string pIdCliente) {

	if (Raiz == NULL) {
		return;
	}
	else {
		buscarCliente(Raiz->Ramas->ObtenerRama(0), pIdCliente);
		int I = 1;
		while (I <= Raiz->cuenta) {
			pNodoB Recorrido = Raiz->Claves->ObtenerApuntadorClave(I);

			if (Recorrido->idCliente == pIdCliente) {
				setAuxCliente(Recorrido);
			}

			buscarCliente(Raiz->Ramas->ObtenerRama(I), pIdCliente);

			I++;
		}
	}

}

void TareaProgramada2::setAuxCliente(NodoArbolB *pAux) {
	auxCliente = pAux;
}

pNodoB TareaProgramada2::getAuxCliente() {
	return auxCliente;
}

//----------------------BUSQUEDAS RESERVACIONES----------------------//

pNodoBinarioReservarViaje TareaProgramada2::buscarViajeReservacion(string pIdCliente) {

	NodoBinarioReservarViaje *Act = arbolReserViajes.rv_raiz;
	PilaRV p;
	NodoBinarioReservarViaje *Temp = NULL;

	while (p.VaciaRV() == false || (Act != NULL)) {
		if (Act != NULL) {
			if (Act->rv_idCliente == pIdCliente) {

				Temp = Act;
			}

			p.PushRV(Act);
			Act = Act->Hizq;

		}
		else {
			Act = p.PopRV();
			Act = Act->Hder;
		}
	}
	return Temp;
}

pNodoBinarioReservarHoteles TareaProgramada2::buscarHotelReservacion(string pIdCliente) {

	NodoBinarioReservarHoteles *Act = arbolReserHoteles.rh_raiz;
	PilaRH p;
	NodoBinarioReservarHoteles *Temp = NULL;

	while (p.VaciaRH() == false || (Act != NULL)) {
		if (Act != NULL) {
			if (Act->rh_idCliente == pIdCliente) {

				Temp = Act;
			}

			p.PushRH(Act);
			Act = Act->Hizq;

		}
		else {
			Act = p.PopRH();
			Act = Act->Hder;
		}
	}
	return Temp;
}

pNodoBinarioReservarTransporte TareaProgramada2::buscarTransporteReservacion(string pIdCliente) {

	NodoBinarioReservarTransporte *Act = arbolResertTransporte.rt_raiz;
	PilaRT p;
	NodoBinarioReservarTransporte *Temp = NULL;

	while (p.VaciaRT() == false || (Act != NULL)) {
		if (Act != NULL) {
			if (Act->rt_idCliente == pIdCliente) {

				Temp = Act;
			}

			p.PushRT(Act);
			Act = Act->Hizq;

		}
		else {
			Act = p.PopRT();
			Act = Act->Hder;
		}
	}
	return Temp;
}



//----------------------GRAFOS----------------------//

string TareaProgramada2::anchuraGrafo() {

	cout << "Anchura" << endl;
	string resp= Grafo.RecorridoAnchura();
	return "true,"+resp;
}

string TareaProgramada2::profundidadGrafo() {

	cout << "Profundidad" << endl;
	string resp = Grafo.RecorridoProfundidad();
	return "true," + resp;

}




//----------------------REFERENCIAS----------------------//

void TareaProgramada2::enlazarHotelAViaje(string pIdViaje, pNodoAVL auxHotel) {

	NodoBinarioBusqueda *Act = arbolBinario.raiz;
	Pila p;

	while (p.Vacia() == false || (Act != NULL)) {
		if (Act != NULL) {
			if ((Act->idViaje) == pIdViaje) {

				if (Act->NodoAVLHotel == NULL) {
					Act->NodoAVLHotel = auxHotel;

				}
				else {/*
					  while(Act->NodoAVLHotel != NULL){
					  //Act = Act->NodoAVLHotel->siguiente;
					  }
					  Act->NodoAVLHotel = auxHotel;*/

					if (Act->NodoAVLHotel1 == NULL) {
						Act->NodoAVLHotel1 = auxHotel;
					}
					else {
						if (Act->NodoAVLHotel2 == NULL) {
							Act->NodoAVLHotel2 = auxHotel;
						}
						else {
							if (Act->NodoAVLHotel3 == NULL) {
								Act->NodoAVLHotel3 = auxHotel;
							}
							else {
								if (Act->NodoAVLHotel4 == NULL) {
									Act->NodoAVLHotel4 = auxHotel;
								}
								else {
									if (Act->NodoAVLHotel6 == NULL) {
										Act->NodoAVLHotel6 = auxHotel;
									}
									else {
										if (Act->NodoAVLHotel7 == NULL) {
											Act->NodoAVLHotel7 = auxHotel;
										}
										else {
											if (Act->NodoAVLHotel8 == NULL) {
												Act->NodoAVLHotel8 = auxHotel;
											}
											else {
												if (Act->NodoAVLHotel9 == NULL) {
													Act->NodoAVLHotel9 = auxHotel;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			p.Push(Act);
			Act = Act->Hizq;
		}
		else {
			Act = p.Pop();
			Act = Act->Hder;
		}
	}
}

void TareaProgramada2::enlazarTranspAHotel(string pHotel, pNodoRojiNegro auxTransporte) {

	NodoAVL *Act = arbolAVL.raiz;
	PilaAVL p;

	while (p.VaciaAVL() == false || (Act != NULL)) {
		if (Act != NULL) {
			if ((Act->idHotel) == pHotel) {

				if (Act->NodoRNTransp == NULL) {
					Act->NodoRNTransp = auxTransporte;
				}
				else {
					if (Act->NodoRNTransp1 == NULL) {
						Act->NodoRNTransp1 = auxTransporte;
					}
					else {
						if (Act->NodoRNTransp2 == NULL) {
							Act->NodoRNTransp2 = auxTransporte;
						}
						else {
							if (Act->NodoRNTransp3 == NULL) {
								Act->NodoRNTransp3 = auxTransporte;
							}
							else {
								if (Act->NodoRNTransp4 == NULL) {
									Act->NodoRNTransp4 = auxTransporte;
								}
								else {
									if (Act->NodoRNTransp6 == NULL) {
										Act->NodoRNTransp6 = auxTransporte;
									}
									else {
										if (Act->NodoRNTransp7 == NULL) {
											Act->NodoRNTransp7 = auxTransporte;
										}
										else {
											if (Act->NodoRNTransp8 == NULL) {
												Act->NodoRNTransp8 = auxTransporte;
											}
											else {
												if (Act->NodoRNTransp9 == NULL) {
													Act->NodoRNTransp9 = auxTransporte;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			p.PushAVL(Act);
			Act = Act->Hizq;
		}
		else {
			Act = p.PopAVL();
			Act = Act->Hder;
		}
	}
}

void TareaProgramada2::enlazarOfertaHotelAHotel(string pHotel, pnodoAA auxOfertaTransporte) {

	NodoAVL *Act = arbolAVL.raiz;
	PilaAVL p;

	while (p.VaciaAVL() == false || (Act != NULL)) {
		if (Act != NULL) {
			if ((Act->idHotel) == pHotel) {

				if (Act->NodoAAOferT == NULL) {
					Act->NodoAAOferT = auxOfertaTransporte;
				}
				else {
					if (Act->NodoAAOferT1 == NULL) {
						Act->NodoAAOferT1 = auxOfertaTransporte;
					}
					else {
						if (Act->NodoAAOferT2 == NULL) {
							Act->NodoAAOferT2 = auxOfertaTransporte;
						}
						else {
							if (Act->NodoAAOferT3 == NULL) {
								Act->NodoAAOferT3 = auxOfertaTransporte;
							}
							else {
								if (Act->NodoAAOferT4 == NULL) {
									Act->NodoAAOferT4 = auxOfertaTransporte;
								}
								else {
									if (Act->NodoAAOferT6 == NULL) {
										Act->NodoAAOferT6 = auxOfertaTransporte;
									}
									else {
										if (Act->NodoAAOferT7 == NULL) {
											Act->NodoAAOferT7 = auxOfertaTransporte;
										}
										else {
											if (Act->NodoAAOferT8 == NULL) {
												Act->NodoAAOferT8 = auxOfertaTransporte;
											}
											else {
												if (Act->NodoAAOferT9 == NULL) {
													Act->NodoAAOferT9 = auxOfertaTransporte;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			p.PushAVL(Act);
			Act = Act->Hizq;
		}
		else {
			Act = p.PopAVL();
			Act = Act->Hder;
		}
	}
}



//----------------------MOSTRADOS REFERENCIAS----------------------//

void TareaProgramada2::verReferenciasViaje(string pIdViaje) {

	NodoBinarioBusqueda *aux;
	aux = buscarViaje(pIdViaje);

	if (aux != NULL) {
		if (aux->NodoAVLHotel != NULL) {
			cout << "Hotel 1: " << aux->NodoAVLHotel->nombre << endl;
		}
		if (aux->NodoAVLHotel1 != NULL) {
			cout << "Hotel 2: " << aux->NodoAVLHotel1->nombre << endl;
		}
		if (aux->NodoAVLHotel2 != NULL) {
			cout << "Hotel 3: " << aux->NodoAVLHotel2->nombre << endl;
		}
		if (aux->NodoAVLHotel3 != NULL) {
			cout << "Hotel 4: " << aux->NodoAVLHotel3->nombre << endl;
		}
		if (aux->NodoAVLHotel4 != NULL) {
			cout << "Hotel 5: " << aux->NodoAVLHotel4->nombre << endl;
		}
		if (aux->NodoAVLHotel5 != NULL) {
			cout << "Hotel 6: " << aux->NodoAVLHotel5->nombre << endl;
		}
		if (aux->NodoAVLHotel6 != NULL) {
			cout << "Hotel 7: " << aux->NodoAVLHotel6->nombre << endl;
		}
		if (aux->NodoAVLHotel7 != NULL) {
			cout << "Hotel 8: " << aux->NodoAVLHotel7->nombre << endl;
		}
		if (aux->NodoAVLHotel8 != NULL) {
			cout << "Hotel 9: " << aux->NodoAVLHotel8->nombre << endl;
		}
		if (aux->NodoAVLHotel9 != NULL) {
			cout << "Hotel 10: " << aux->NodoAVLHotel9->nombre << endl;
		}
	}
}

void TareaProgramada2::verReferenciasHotel(string pIdHotel) {

	NodoAVL *aux;
	aux = buscarHotel(pIdHotel);

	if (aux != NULL) {
		if (aux->NodoRNTransp == NULL) {
			cout << "-- No hay transportes --" << endl;
		}
		if (aux->NodoRNTransp != NULL) {
			cout << "Transporte 1: " << aux->NodoRNTransp->compania << ", " << aux->NodoRNTransp->origen << "/" << aux->NodoRNTransp->destino << endl;
		}
		if (aux->NodoRNTransp1 != NULL) {
			cout << "Transporte 2: " << aux->NodoRNTransp1->compania << ", " << aux->NodoRNTransp1->origen << "/" << aux->NodoRNTransp1->destino << endl;
		}
		if (aux->NodoRNTransp2 != NULL) {
			cout << "Transporte 3: " << aux->NodoRNTransp2->compania << ", " << aux->NodoRNTransp2->origen << "/" << aux->NodoRNTransp2->destino << endl;
		}
		if (aux->NodoRNTransp3 != NULL) {
			cout << "Transporte 4: " << aux->NodoRNTransp3->compania << ", " << aux->NodoRNTransp3->origen << "/" << aux->NodoRNTransp3->destino << endl;
		}
		if (aux->NodoRNTransp4 != NULL) {
			cout << "Transporte 5: " << aux->NodoRNTransp4->compania << ", " << aux->NodoRNTransp4->origen << "/" << aux->NodoRNTransp4->destino << endl;
		}
		if (aux->NodoRNTransp5 != NULL) {
			cout << "Transporte 6: " << aux->NodoRNTransp5->compania << ", " << aux->NodoRNTransp5->origen << "/" << aux->NodoRNTransp5->destino << endl;
		}
		if (aux->NodoRNTransp6 != NULL) {
			cout << "Transporte 7: " << aux->NodoRNTransp6->compania << ", " << aux->NodoRNTransp6->origen << "/" << aux->NodoRNTransp6->destino << endl;
		}
		if (aux->NodoRNTransp7 != NULL) {
			cout << "Transporte 8: " << aux->NodoRNTransp7->compania << ", " << aux->NodoRNTransp7->origen << "/" << aux->NodoRNTransp7->destino << endl;
		}
		if (aux->NodoRNTransp8 != NULL) {
			cout << "Transporte 9: " << aux->NodoRNTransp8->compania << ", " << aux->NodoRNTransp8->origen << "/" << aux->NodoRNTransp8->destino << endl;
		}
		if (aux->NodoRNTransp9 != NULL) {
			cout << "Transporte 10: " << aux->NodoRNTransp9->compania << ", " << aux->NodoRNTransp9->origen << "/" << aux->NodoRNTransp9->destino << endl;
		}
		// --------------------------------------- //
		if (aux->NodoAAOferT == NULL) {
			cout << "-- No hay ofertas --" << endl;
		}
		if (aux->NodoAAOferT != NULL) {
			cout << "Oferta 1: " << aux->NodoAAOferT->idHotel << endl;
		}
		if (aux->NodoAAOferT1 != NULL) {
			cout << "Oferta 2: " << aux->NodoAAOferT1->idHotel << endl;
		}
		if (aux->NodoAAOferT2 != NULL) {
			cout << "Oferta 3: " << aux->NodoAAOferT2->idHotel << endl;
		}
		if (aux->NodoAAOferT3 != NULL) {
			cout << "Oferta 4: " << aux->NodoAAOferT3->idHotel << endl;
		}
		if (aux->NodoAAOferT4 != NULL) {
			cout << "Oferta 5: " << aux->NodoAAOferT4->idHotel << endl;
		}
		if (aux->NodoAAOferT5 != NULL) {
			cout << "Oferta 6: " << aux->NodoAAOferT5->idHotel << endl;
		}
		if (aux->NodoAAOferT6 != NULL) {
			cout << "Oferta 7: " << aux->NodoAAOferT6->idHotel << endl;
		}
		if (aux->NodoAAOferT7 != NULL) {
			cout << "Oferta 8: " << aux->NodoAAOferT7->idHotel << endl;
		}
		if (aux->NodoAAOferT8 != NULL) {
			cout << "Oferta 9: " << aux->NodoAAOferT8->idHotel << endl;
		}
		if (aux->NodoAAOferT9 != NULL) {
			cout << "Oferta 9: " << aux->NodoAAOferT9->idHotel << endl;
		}
	}
	else {
		cout << "ID invalido." << endl;
	}
}



//Recorridos Grafos

string TareaProgramada2::LlamarKruskal()
{
	string resultado = "true," + grafoKruskal.algoritmoKruskal(12);
	return resultado;
}

string TareaProgramada2::LlamarDijkstra(string inicio)
{
	int thevalue;
	istringstream ss(inicio);
	ss >> thevalue;

	string resultado = "true," + grafoDijkstra.algoritmoDijkstra(thevalue);
	return resultado;


}

string TareaProgramada2::LlamarPrim()
{
	string resultado = "true," + grafoDijkstra.algoritmoPrim(12);
	return resultado;
}




//----------------------LECTURAS----------------------//


void TareaProgramada2::ejecutarDijkstra() {
	int i = 0;
	int varTemp_Origen = 0 ;
	int varTemp_Destino = 0;

	ifstream archivoConexiones("files/Conexiones.txt");
	if (!archivoConexiones) {
		cout << "Archivo Conexiones.txt no encontrado!" << endl; // Solo por saber el error
	}

	while (!archivoConexiones.eof()) {
		string conexion; // Almacena cada linea del .txt
		string origen;
		string destino;
		string peso;

		getline(archivoConexiones, conexion);

		while (conexion[i] != ';') {
			origen += conexion[i];
			i++;
		}
		i += 1;

		while (conexion[i] != ';') {
			destino += conexion[i];
			i++;
		}
		i += 1;

		while (conexion[i] != false) {
			peso += conexion[i];
			i++;
		}

		int pesoNum = 0;
		int origenNum = 0;
		int destinoNum = 0;


		istringstream convertir(peso); // Conversion de String a int
		convertir >> pesoNum;

		istringstream convertir_1(origen); // Conversion de String a int
		convertir_1 >> origenNum;

		istringstream convertir_2(destino); // Conversion de String a int
		convertir_2 >> destinoNum;

		if (varTemp_Origen != destinoNum && varTemp_Destino != origenNum) { // Salta las lineas para ir de 2 en 2

			varTemp_Origen = origenNum;
			varTemp_Destino = destinoNum;

			if (lista_Origenes_Destinos.buscarElemento(origen) != true) {
				grafoDijkstra.crearVertice(origenNum);
				grafoKruskal.crearVertice_Kruskal(origenNum);
				lista_Origenes_Destinos.InsertarFinal(origen);
			}

			if (lista_Origenes_Destinos.buscarElemento(destino) != true) {
				grafoDijkstra.crearVertice(destinoNum);
				grafoKruskal.crearVertice_Kruskal(destinoNum);
				lista_Origenes_Destinos.InsertarFinal(destino);
			}

			//cout << "Anterior: " << origenNum << "/" << destinoNum << " - Entra: " << varTemp_Origen << "/" << varTemp_Destino << endl;

			grafoDijkstra.enlazarVertices(origenNum, destinoNum, pesoNum);
			grafoKruskal.enlazarVertices_Kruskal(origenNum, destinoNum, pesoNum);
		}


		i = 0;
	}

}

void TareaProgramada2::leerArchivoDestinos() {
	int i = 0;

	ifstream archivoConexiones("files/Destinos.txt");
	if (!archivoConexiones) {
		cout << "Archivo Destinos.txt no encontrado!" << endl; // Solo por saber el error
	}

	while (!archivoConexiones.eof()) {
		string destino; // Almacena cada linea del .txt
		string idDestino;
		string lugar;

		getline(archivoConexiones, destino);

		while (destino[i] != ';') {
			idDestino += destino[i];
			i++;
		}
		i += 1;
		
		while (destino[i] != false) {
			lugar += destino[i];
			i++;
		}
		
		int idDestinoNum = 0;

		istringstream convertir(idDestino); // Conversion de String a int
		convertir >> idDestinoNum;

		i = 0;

	}
}

void TareaProgramada2::leerArchivoConexiones(){
	int i = 0;
	int v = 0;
	int e = 0;
	ifstream archivoConexiones("files/Conexiones.txt");
	if (!archivoConexiones) {
		cout << "Archivo Conexiones.txt no encontrado!" << endl; // Solo por saber el error
	}

	while (!archivoConexiones.eof()) {
		string conexion; // Almacena cada linea del .txt
		string origen;
		string destino;
		string peso;
		
		getline(archivoConexiones, conexion);

		while (conexion[i] != ';') {
			origen += conexion[i];
			i++;
		}
		i += 1;

		while (conexion[i] != ';') {
			destino += conexion[i];
			i++;
		}
		i += 1;
	
		while (conexion[i] != false) {
			peso += conexion[i];
			i++;
		}

		int pesoNum = 0;
		int origenNum = 0;
		int destinoNum = 0;


		istringstream convertir(peso); // Conversion de String a int
		convertir >> pesoNum;

		istringstream convertir_1(origen); // Conversion de String a int
		convertir_1 >> origenNum;

		istringstream convertir_2(destino); // Conversion de String a int
		convertir_2 >> destinoNum;
		
		Grafo.Insertarv(origenNum);
		v++;
		Grafo.Insertarv(destinoNum);
		v++;
		Grafo.creararco(origenNum, destinoNum, pesoNum);
		e++;
	
		i = 0;
	}
	
}

void TareaProgramada2::leerArchivoViaje() {

	int i = 0;

	ifstream archivoViaje("files/Viajes.txt");
	if (!archivoViaje) {
		cout << "Archivo Viajes.txt no encontrado!" << endl; // Solo por saber el error

	}

	while (!archivoViaje.eof()) {
		string viaje; // Almacena cada linea del .txt

		string pIdDestino;
		int num = 0; // IDViaje de tipo entero
		string pIdViaje;
		string pOrigen;
		string pDestino;
		string pFechaSalida;
		string pFechaLlegada;
		string pPrecio;
		string pNumPlazas;
		string StringCantPaquetes;
		int cantPaquetes;

		getline(archivoViaje, viaje);

		while (viaje[i] != ';') {
			pIdDestino += viaje[i];
			i++;
		}
		i += 1;

		while (viaje[i] != ';') {
			pIdViaje += viaje[i];
			i++;
		}
		i += 1; // Omitir el ;

		while (viaje[i] != ';') {
			pOrigen += viaje[i];
			i++;
		}
		i += 1;

		while (viaje[i] != ';') {
			pDestino += viaje[i];
			i++;
		}
		i += 1;

		while (viaje[i] != ';') {
			pFechaSalida += viaje[i];
			i++;
		}
		i += 1;

		while (viaje[i] != ';') {
			pFechaLlegada += viaje[i];
			i++;
		}
		i += 1;

		while (viaje[i] != ';') {
			pPrecio += viaje[i];
			i++;
		}
		i += 1;

		while (viaje[i] != ';') {
			pNumPlazas += viaje[i];
			i++;
		}
		i += 1;

		while (viaje[i] != false) {
			StringCantPaquetes += viaje[i];
			i++;
		}

		istringstream convertir(pIdViaje); // Conversion de String a int
		convertir >> num;

		istringstream convertir2(StringCantPaquetes);
		convertir2 >> cantPaquetes;

		if (ListaIDViajes.buscarElemento(pIdViaje) != true) {
			ListaIDViajes.InsertarFinal(pIdViaje);
			arbolBinario.InsertaNodoBinarioBusqueda(pIdDestino, num, pIdViaje, pOrigen, pDestino, pFechaSalida, pFechaLlegada, pPrecio, pNumPlazas, cantPaquetes);
		}

		i = 0;
	}
}

void TareaProgramada2::leerArchivoHotel() {

	int i = 0;

	ifstream archivoHotel("files/Hoteles.txt");
	if (!archivoHotel) {
		cout << "Archivo Hoteles.txt no encontrado!" << endl;
	}

	while (!archivoHotel.eof()) {
		string hotel; // Almacena cada linea del .txt

		string pIdDestino;
		int num = 0;
		string pIdViaje; // No se inserta
		string pIdHotel;
		string pNombre;
		string pCategoria;
		string pCiudad;
		string pPrecioHabIndiv;
		string pPrecioHabDoble;
		string StringCantHabIndiv;
		string StringCantHabDoble;
		int pCantHabIndiv;
		int pCantHabDoble;

		getline(archivoHotel, hotel);

		while (hotel[i] != ';') {
			pIdDestino += hotel[i];
			i++;
		}
		i += 1;

		while (hotel[i] != ';') {
			pIdViaje += hotel[i];
			i++;
		}
		i += 1; // Omitir el ;

		while (hotel[i] != ';') {
			pIdHotel += hotel[i];
			i++;
		}
		i += 1;

		while (hotel[i] != ';') {
			pNombre += hotel[i];
			i++;
		}
		i += 1;

		while (hotel[i] != ';') {
			pCategoria += hotel[i];
			i++;
		}
		i += 1;

		while (hotel[i] != ';') {
			pCiudad += hotel[i];
			i++;
		}
		i += 1;

		while (hotel[i] != ';') {
			pPrecioHabIndiv += hotel[i];
			i++;
		}
		i += 1;

		while (hotel[i] != ';') {
			pPrecioHabDoble += hotel[i];
			i++;
		}
		i += 1;

		while (hotel[i] != ';') {
			StringCantHabIndiv += hotel[i];
			i++;
		}
		i += 1;

		while (hotel[i] != false) {
			StringCantHabDoble += hotel[i];
			i++;
		}

		istringstream convertir(pIdHotel); // Conversion de String a int
		convertir >> num;

		istringstream convertir1(StringCantHabIndiv); // Conversion de String a int
		convertir1 >> pCantHabIndiv;

		istringstream convertir2(StringCantHabDoble);
		convertir2 >> pCantHabDoble;

		if (ListaIDHoteles.buscarElemento(pIdHotel) != true) {
			ListaIDHoteles.InsertarFinal(pIdHotel);
			arbolAVL.InsertaNodoAVL(pIdDestino, num, pIdHotel, pNombre, pCategoria, pCiudad, pPrecioHabIndiv, pPrecioHabDoble,
				pCantHabIndiv, pCantHabDoble);

			NodoAVL *auxHotel;
			auxHotel = buscarHotel(pIdHotel); // retorna el nodo del hotel que se inserta

			enlazarHotelAViaje(pIdViaje, auxHotel); // Se envia el viaje del hotel (para buscar) y el ..
													// .. nodo de ese hotel para enlazarlo en caso de existir

		}
		i = 0;
	}
}

void TareaProgramada2::leerArchivoTransporte() {

	int i = 0;

	ifstream archivoTransporte("files/Transportes.txt");
	if (!archivoTransporte) {
		cout << "Archivo Transportes.txt no encontrado!" << endl;
	}

	while (!archivoTransporte.eof()) {
		string transporte; // Almacena cada linea del .txt

		string pIdDestino;
		int num = 0;
		string pIdViaje;
		string pIdHotel;
		string pIdTransporte;
		string pTipoTransporte;
		string pOrigen;
		string pDestino;
		string pFechaSalida;
		string pHoraSalida;
		string pFechaLlegada;
		string pHoraLlegada;
		string pCompania;
		string pPlazas;
		string pPrecio;
		string StringCantTransportes;
		int pCantDeTransportes;

		getline(archivoTransporte, transporte);

		while (transporte[i] != ';') {
			pIdDestino += transporte[i];
			i++;
		}
		i += 1;

		while (transporte[i] != ';') {
			pIdViaje += transporte[i];
			i++;
		}
		i += 1;

		while (transporte[i] != ';') {
			pIdHotel += transporte[i];
			i++;
		}
		i += 1;

		while (transporte[i] != ';') {
			pIdTransporte += transporte[i];
			i++;
		}
		i += 1;

		while (transporte[i] != ';') {
			pTipoTransporte += transporte[i];
			i++;
		}
		i += 1;

		while (transporte[i] != ';') {
			pOrigen += transporte[i];
			i++;
		}
		i += 1;

		while (transporte[i] != ';') {
			pDestino += transporte[i];
			i++;
		}
		i += 1;

		while (transporte[i] != ';') {
			pFechaSalida += transporte[i];
			i++;
		}
		i += 1;

		while (transporte[i] != ';') {
			pHoraSalida += transporte[i];
			i++;
		}
		i += 1;

		while (transporte[i] != ';') {
			pFechaLlegada += transporte[i];
			i++;
		}
		i += 1;

		while (transporte[i] != ';') {
			pHoraLlegada += transporte[i];
			i++;
		}
		i += 1;

		while (transporte[i] != ';') {
			pCompania += transporte[i];
			i++;
		}
		i += 1;

		while (transporte[i] != ';') {
			pPlazas += transporte[i];
			i++;
		}
		i += 1;

		while (transporte[i] != ';') {
			pPrecio += transporte[i];
			i++;
		}
		i += 1;

		while (transporte[i] != false) {
			StringCantTransportes += transporte[i];
			i++;
		}


		istringstream convertir(pIdTransporte);
		convertir >> num;

		istringstream convertir2(StringCantTransportes);
		convertir2 >> pCantDeTransportes;

		if (ListaIDTransportes.buscarElemento(pIdTransporte) != true) {
			ListaIDTransportes.InsertarFinal(pIdTransporte);
			arbolRN.insertarValorNodoRN(pIdDestino, num, pIdTransporte, pTipoTransporte, pOrigen, pDestino, pFechaSalida, pHoraSalida,
				pFechaLlegada, pHoraLlegada, pCompania, pPlazas, pPrecio, pCantDeTransportes);

			NodoRojiNegro *auxTrans;
			auxTrans = buscarTransporte(pIdTransporte);

			enlazarTranspAHotel(pIdHotel, auxTrans);

		}
		i = 0;
	}
}

void TareaProgramada2::leerArchivoClientes() {

	int i = 0;

	ifstream archivoCliente("files/Clientes.txt");
	if (!archivoCliente) {
		cout << "Archivo Clientes.txt no encontrado!" << endl;
	}

	while (!archivoCliente.eof()) {
		string cliente; // Almacena cada linea del .txt

		int num = 0;
		string pIdCliente;
		string pNombre;
		string pApellido;
		string pCiudad;
		string pTelefono;

		getline(archivoCliente, cliente);

		while (cliente[i] != ';') {
			pIdCliente += cliente[i];
			i++;
		}
		i += 1;

		while (cliente[i] != ';') {
			pNombre += cliente[i];
			i++;
		}
		i += 1;

		while (cliente[i] != ';') {
			pApellido += cliente[i];
			i++;
		}
		i += 1;

		while (cliente[i] != ';') {
			pCiudad += cliente[i];
			i++;
		}
		i += 1;

		while (cliente[i] != false) {
			pTelefono += cliente[i];
			i++;
		}

		istringstream convertir(pIdCliente);
		convertir >> num;


		if (ListaIDCliente.buscarElemento(pIdCliente) != true) {
			ListaIDCliente.InsertarFinal(pIdCliente);
			arbolB.IniciarInsercionB(num, pIdCliente, pNombre, pApellido, pCiudad, pTelefono);
		}
		i = 0;
	}
}

void TareaProgramada2::leerArchivoOfertaHotel() {

	int i = 0;

	ifstream archivoOfertaHoteles("files/OfertasHoteles.txt");
	if (!archivoOfertaHoteles) {
		cout << "Archivo OfertasHoteles.txt no encontrado!" << endl;
	}

	while (!archivoOfertaHoteles.eof()) {
		string ofertaHoteles; // Almacena cada linea del .txt

		string pIdDestino;
		int num = 0;
		string pIdViaje; // No se inserta
		string pIdHotel;
		string pIDoferta;
		string pPrecioHabIndiv;
		string pPrecioHabDoble;
		string StringCantOfertasIndivi;
		string StringCantOfertasDobles;
		int pCantOfertasIndivi;
		int pCantOfertasDobles;
		string llaveID; //Combinacion de idViaje e idHotel

		getline(archivoOfertaHoteles, ofertaHoteles);

		while (ofertaHoteles[i] != ';') {
			pIdDestino += ofertaHoteles[i];
			i++;
		}

		while (ofertaHoteles[i] != ';') {
			pIdViaje += ofertaHoteles[i];
			i++;
		}
		i += 1;

		while (ofertaHoteles[i] != ';') {
			pIdHotel += ofertaHoteles[i];
			i++;
		}
		i += 1;

		while (ofertaHoteles[i] != ';') {
			pIDoferta += ofertaHoteles[i];
			i++;
		}
		i += 1;

		while (ofertaHoteles[i] != ';') {
			pPrecioHabIndiv += ofertaHoteles[i];
			i++;
		}
		i += 1;

		while (ofertaHoteles[i] != ';') {
			pPrecioHabDoble += ofertaHoteles[i];
			i++;
		}
		i += 1;

		while (ofertaHoteles[i] != ';') {
			StringCantOfertasIndivi += ofertaHoteles[i];
			i++;
		}
		i += 1;


		while (ofertaHoteles[i] != false) {
			StringCantOfertasDobles += ofertaHoteles[i];
			i++;
		}

		llaveID += pIdViaje;
		llaveID += pIdHotel;

		istringstream convertirOF(pIDoferta);
		convertirOF >> num;

		istringstream convertir(StringCantOfertasIndivi);
		convertir >> pCantOfertasIndivi;

		istringstream convertir2(StringCantOfertasDobles);
		convertir2 >> pCantOfertasDobles;


		if (ListaIDOfertaHoteles.buscarElemento(llaveID) != true) {
			ListaIDOfertaHoteles.InsertarFinal(llaveID);
			arbolAA.IniciarInsercionAA(pIdDestino, num, pIdViaje, pIdHotel, pIDoferta, pPrecioHabIndiv, pPrecioHabDoble, pCantOfertasIndivi, pCantOfertasDobles);

			NodoArbolAA *Raiz = arbolAA.raizAA;
			buscarOfertaHotel(Raiz, pIDoferta);

			NodoArbolAA *auxOF;
			auxOF = getAuxOfertaHotel();

			enlazarOfertaHotelAHotel(pIdHotel, auxOF);

		}
		setAuxOfertaHotel(NULL);
		i = 0;
	}
}

//----------------------OPERACIONES PRINCIPALES----------------------//

string TareaProgramada2::ConsultarPrecioProducto(string info) {

	string eleccion = info.substr(0, 1);
	string opcion = info.substr(1, info.length() - 1);

	if (eleccion == "0") {


		NodoBinarioBusqueda *auxBinario;
		auxBinario = buscarViaje(opcion);

		if (auxBinario != NULL) {

			return "true,\nEl precio del viaje corresponde a: " + auxBinario->precio;

		}
		else {
			return "false,\nError!. El viaje no existe!. ";
		}
	}

	else {
		if (eleccion == "1") {


			NodoAVL *auxAVL;
			auxAVL = buscarHotel(opcion);

			if (auxAVL != NULL) {

				return "true,\nEl precio del hotel corresponde a : \n Habitacion individual: " + auxAVL->precioHabIndiv + "\n Habitacion doble: " + auxAVL->precioHabDoble;

			}
			else {

				return "false,\nError!. El hotel no existe!.";
			}
		}
		else {
			if (eleccion == "2") {


				NodoRojiNegro *auxRN;
				auxRN = buscarTransporte(opcion);

				if (auxRN != NULL) {

					return "true,\nEl precio del transporte correponde a: " + auxRN->precio;

				}
				else {

					return "false,\nError!. El transporte no existe!.";

				}
			}
		}
	}
}

string TareaProgramada2::MostrarArbol(string pEleccion) {

	string eleccion = pEleccion.substr(0, 1);
	string opcion = pEleccion.substr(1, pEleccion.length() - 1);

	if (eleccion == "0") {

		return "true," + arbolBinario.InordenI();

	}
	else {
		if (eleccion == "1") {

			return "true," + arbolAVL.InordenI();

		}
		else {
			if (eleccion == "2") {
				arbolRN.borrarMostrado();
				NodoRojiNegro *auxRaiz = arbolRN.RaizRN;
				arbolRN.inordenRN(auxRaiz);
				return "true," + arbolRN.getMostrado();
				

			}
			else {

				return "false,La opción dada no es válida";
			}
		}
	}
}

string TareaProgramada2::ConsultarViajeHotelTransporteDeUnCliente(string info) {

	string opcionConsulta = info.substr(0, 1);
	string opcionIdCliente = info.substr(1, info.length() - 1);


	if (opcionConsulta == "0") {


		NodoBinarioReservarViaje *auxCliente;
		auxCliente = buscarViajeReservacion(opcionIdCliente);

		if (auxCliente != NULL) {
			NodoBinarioBusqueda *auxBinario;
			auxBinario = buscarViaje(auxCliente->rv_idViaje);

			if (auxBinario != NULL) {

				return "true,\n- El viaje corresponde a:\nidViaje: " + auxBinario->idViaje + "\n Origen: " + auxBinario->origen + "\n Destino: " + auxBinario->destino + "\n FechaSalida: " + auxBinario->fechaSalida + "\n FechaLlegada: " + auxBinario->fechaLlegada + "\n Precio: " + auxBinario->precio;

			}
			else {

				return "false,nError inesperado!. El cliente ya reservo pero no tiene viaje asociado.";
			}
		}
		else {

			return "false,\nError!. El cliente no ha reservado un viaje o no exite.";
		}

	}
	else {
		if (opcionConsulta == "1") {


			NodoBinarioReservarHoteles *auxClienteH;
			auxClienteH = buscarHotelReservacion(opcionIdCliente);

			if (auxClienteH != NULL) {
				NodoAVL *auxAVL;
				auxAVL = buscarHotel(auxClienteH->rh_idHotel);

				if (auxAVL != NULL) {


					return "true,\n- El hotel corresponde a:\nidHotel: " + auxAVL->idHotel + "\nNombre: " + auxAVL->nombre + "\nCategoria: " + auxAVL->categoria + "\nCiudad: " + auxAVL->ciudad;

				}
				else {
					return "false,\nError inesperado!. El cliente ya reservo pero no tiene hotel asociado.";
				}

			}
			else {

				return "false,\nError!. El cliente no ha reservado un hotel o no existe.";
			}
		}
		else {
			if (opcionConsulta == "2") {

				NodoBinarioReservarTransporte *auxT;
				auxT = buscarTransporteReservacion(opcionIdCliente);

				if (auxT != NULL) {
					NodoRojiNegro *auxRN;
					auxRN = buscarTransporte(auxT->rt_idTransporte);

					if (auxRN != NULL) {

						return "true,\n- El transporte corresponde a:\n idTransporte: " + auxRN->idTransporte + "\ntipoTransporte: " + auxRN->tipoTransporte + "\nOrigen: " + auxRN->origen + "\nDestino: " + auxRN->destino + "\nFechaSalida: " + auxRN->fechaSalida + "\nHoraSalida: " + auxRN->horaSalida + "\nFechaLlegada: " + auxRN->fechaLlegada + "\nHoraLlegada: " + auxRN->horaLlegada + "\nCompania: " + auxRN->compania;

					}
					else {

						return "false,\nError inesperado!. El cliente ya reservo pero no tiene trasnporte asociado.";
					}
				}
				else {

					return "false,\nError!. El cliente no ha reservado un transporte o no existe.";
				}
			}
			else { return "false,Opción no válida"; }
		}

	}
}

string TareaProgramada2::ConsultarOrigenDestidoDeUnViaje(string opcionViaje) {


	NodoBinarioBusqueda *auxViaje;
	auxViaje = buscarViaje(opcionViaje);

	if (auxViaje != NULL) {

		return "true,\nLos lugares corresponde a:\n Origen: " + auxViaje->origen + "\n Destino: " + auxViaje->destino;

	}
	else {

		return "false,\nError!. El viaje no existe!.";
	}
}

string TareaProgramada2::ConsultarInformacionDeUnCliente(string opcionCliente) {

	int pCliente = 0;

	ApuntadorPagina Raiz = arbolB.raizB;

	buscarCliente(Raiz, opcionCliente);

	NodoArbolB *auxB;

	auxB = getAuxCliente();

	if (auxB != NULL) {

		setAuxCliente(NULL); //Se establece nulo en caso de realizar consultas seguidas	
		return "true,\n - Informacion correspondiente : \n Identificacion : " + auxB->idCliente + "\n Nombre : " + auxB->nombre + "\n Apellido : " + auxB->apellido + "\n Ciudad : " + auxB->ciudad + "\n Telefono : " + auxB->telefono;

	}
	else {

		return "false,\nError!. El cliente no existe.";
	}
}

string TareaProgramada2::ConsultarCategoriaDeUnHotel(string opcionHotel) {

	NodoAVL *auxAVL;
	auxAVL = buscarHotel(opcionHotel);

	if (auxAVL != NULL) {
		string categoria;

		if ((auxAVL->categoria) == "1") {
			categoria = " - Familiar";

		}
		else {
			if ((auxAVL->categoria) == "2") {
				categoria = " - Economico";
			}
		}

		return "true,\nLa categoria del hotel es: " + auxAVL->categoria + categoria;

	}
	else {

		return "false,\nError!. El hotel no existe!.";
	}
}

string TareaProgramada2::ConsultarPrecioViajeHotelTransporteDeUnCliente(string opcionCliente) {
	bool tieneViaje = false;
	string precioTemp; int precioViaje = 0; int precioHotel = 0; int precioTransporte = 0;


	//---------------- VIAJE ----------------//
	NodoBinarioReservarViaje *auxRV;
	auxRV = buscarViajeReservacion(opcionCliente);

	if (auxRV != NULL) {
		NodoBinarioBusqueda *auxViaje;
		auxViaje = buscarViaje(auxRV->rv_idViaje);

		if (auxViaje != NULL) {
			precioTemp = auxViaje->precio;

			istringstream convertir(precioTemp);
			convertir >> precioViaje;

			tieneViaje = true;

		}
		else {

			return "false,\nError inesperado!. No se ha encontrado el viaje.";
		}
	}
	else {

		return "false,\nError!. El cliente no ha reservado un viaje.";
	}

	if (tieneViaje) {

		//---------------- HOTEL ----------------//

		NodoBinarioReservarHoteles *auxRH;
		auxRH = buscarHotelReservacion(opcionCliente);

		if (auxRH != NULL) {
			precioTemp = auxRH->rh_precioHabitacion;

			istringstream convertir(precioTemp);
			convertir >> precioHotel;
		}
		else {
			cout << "\n*Sin Hotel." << endl;
		}

		//---------------- TRANSPORTE ----------------//

		NodoBinarioReservarTransporte *auxRT;
		auxRT = buscarTransporteReservacion(opcionCliente);

		if (auxRT != NULL) {
			NodoRojiNegro *auxRB;
			auxRB = buscarTransporte(auxRT->rt_idTransporte);

			if (auxRB != NULL) {
				precioTemp = auxRB->precio;

				istringstream convertir(precioTemp);
				convertir >> precioTransporte;
			}
			else {

				return "false,\nError inesperado!. No se ha encontrado el transporte.";
			}
		}
		else {
			cout << "*Sin Transporte" << endl;

		}
	}
	int precioTotal = precioViaje + precioHotel + precioTransporte;
	string s = to_string(precioTotal);
	return "true,\n- El precio a pagar es de: " + s;

}

//---------------------- Reservar Viaje ----------------------//

// 7
string TareaProgramada2::RealizarReservacionViaje0(string opcionIDCliente) {
	NodoArbolB *auxCliente;
	ApuntadorPagina Raiz = arbolB.raizB;

	buscarCliente(Raiz, opcionIDCliente); //Realiza el setAuxCliente, si no ..
										  //..se encuentra sigue en NULL
	auxCliente = getAuxCliente();
	setAuxCliente(NULL);

	if (auxCliente != NULL) {
		if (listaIDCliente_Reservacion.buscarElemento(opcionIDCliente) != true) {

			return "true," + arbolBinario.InordenI();

		}
		else {

			return "false,\nError!. El cliente ya a reservado un viaje.";
		}
	}
	else {

		return "false,\nError!. El cliente no existe.";
	}

}

//8
string TareaProgramada2::RealizarReservacionViaje1(string opcionViaje) {

	NodoBinarioBusqueda *auxViaje;
	auxViaje = buscarViaje(opcionViaje);
	string s;

	if (auxViaje != NULL) {

		if (auxViaje->cantPaquetes > 0) {
			s = std::to_string(auxViaje->cantPaquetes);
			return "true,\n *Viaje: " + auxViaje->idViaje + "\n " + auxViaje->origen + " \n " + auxViaje->destino + "\n*Plazas disponibles: " + auxViaje->numPlazas + "\n*Paquetes disponibles: " + s;
		}
		else { return "false,\nError!. El viaje no dispone de paquetes. "; }


	}
	else {
		return "false,\nError!. El viaje no existe.";
	}
}

//9
string TareaProgramada2::RealizarReservacionViaje2(string info) {

	string opcionPlazas;
	string opcionIDCliente;
	string opcionViaje;

	int i = 0;
	while (info[i] != ',') {
		opcionPlazas += info[i];
		i++;
	}

	i += 1;

	while (info[i] != ',') {
		opcionIDCliente += info[i];
		i++;
	}

	i += 1;

	while (info[i] != false) {
		opcionViaje += info[i];
		i++;
	}



	int int_opcionPlazas;
	int int_auxViajePlazas;
	int int_opcionIDCliente;


	NodoBinarioBusqueda *auxViaje;
	auxViaje = buscarViaje(opcionViaje);

	istringstream convertir(auxViaje->numPlazas);
	convertir >> int_auxViajePlazas;

	istringstream convertir2(opcionPlazas);
	convertir2 >> int_opcionPlazas;

	istringstream convertir3(opcionIDCliente);
	convertir3 >> int_opcionIDCliente;


	if (int_opcionPlazas > int_auxViajePlazas) {

		return "false,\nError!. El numero de plazas es mayor al disponible.";

	}
	else {

		listaIDCliente_Reservacion.InsertarFinal(opcionIDCliente);
		auxViaje->cantPaquetes = auxViaje->cantPaquetes - 1;
		arbolReserViajes.InsertarNodoReservacionViaje(int_opcionIDCliente, opcionIDCliente, auxViaje->idViaje, opcionPlazas);
		return "true,\nSe ha realizado la reservacion!";

	}

}


//---------------- Transporte ----------------------

//10
string TareaProgramada2::RealizarReservacionTransp0(string opcionCliente)
{
	NodoBinarioReservarViaje *auxCliente;
	auxCliente = buscarViajeReservacion(opcionCliente);

	if (auxCliente != NULL) {
		if (listaIDCliente_ReservacionTransporte.buscarElemento(opcionCliente) != true) {

			//arbolRN.borrarMostrado();
			NodoRojiNegro *auxRaiz = arbolRN.RaizRN;
			string k = arbolRN.getMostrado();
			return "true," + k;
		}
		else {

			return "false,\nError!. El cliente ya ha reservado un transporte.";
		}
	}
	else {

		return "false,\nError!. El cliente no existe o no ha reservado un viaje.";
	}


}

//11
string TareaProgramada2::RealizarReservacionTransp1(string info)
{
	string opcionTransporte;
	string opcionCliente;

	int i = 0;
	while (info[i] != ',') {
		opcionCliente += info[i];
		i++;
	}

	i += 1;

	while (info[i] != false) {
		opcionTransporte += info[i];
		i++;
	}


	NodoBinarioReservarViaje *auxCliente;
	auxCliente = buscarViajeReservacion(opcionCliente);

	NodoRojiNegro *auxTransporte;
	auxTransporte = buscarTransporte(opcionTransporte);

	NodoBinarioBusqueda *auxViaje;
	auxViaje = buscarViaje(auxCliente->rv_idViaje);

	NodoAVL *auxHotel;
	auxHotel = buscarHotel(auxViaje->NodoAVLHotel->idHotel);

	int num;

	istringstream convertir(opcionCliente);
	convertir >> num;

	if (auxTransporte != NULL) {
		bool reservo = false;

		if (auxHotel->NodoRNTransp != NULL) {
			if (auxHotel->NodoRNTransp->idTransporte == opcionTransporte) {
				reservo = true;
			}
		}
		else {
			if (auxHotel->NodoRNTransp1 != NULL) {
				if (auxHotel->NodoRNTransp1->idTransporte == opcionTransporte) {
					reservo = true;
				}

			}
			else {
				if (auxHotel->NodoRNTransp2 != NULL) {
					if (auxHotel->NodoRNTransp2->idTransporte == opcionTransporte) {
						reservo = true;
					}

				}
				else {
					if (auxHotel->NodoRNTransp3 != NULL) {
						if (auxHotel->NodoRNTransp3->idTransporte == opcionTransporte) {
							reservo = true;
						}
					}
					else {
						if (auxHotel->NodoRNTransp4 != NULL) {
							if (auxHotel->NodoRNTransp4->idTransporte == opcionTransporte) {
								reservo = true;
							}
							else {
								if (auxHotel->NodoRNTransp5 != NULL) {
									if (auxHotel->NodoRNTransp5->idTransporte == opcionTransporte) {
										reservo = true;
									}
								}
							}
						}
					}
				}
			}
		}


		if (reservo) {
			if (auxTransporte->cantDeTransportes > 0) {
				listaIDCliente_ReservacionTransporte.InsertarFinal(opcionCliente);
				auxTransporte->cantDeTransportes = auxTransporte->cantDeTransportes - 1;
				arbolResertTransporte.InsertarNodoReservacionTransporte(num, auxCliente->rv_idCliente, auxViaje->idViaje, opcionTransporte);
				return "true,\nSe realizado la reservacion!.";


			}
			else {
				return "false,\nError!. El transporte esta agotado.";
			}
		}
		else {
			return "false,\nError!. El transporte no esta disponible para su viaje.";
		}
	}
	else {

		return "false,\nError!. El transporte no existe.";
	}

}


//12

//---------------------- Hotel ----------------------

string TareaProgramada2::RealizarReservacionHotel0(string opcionCliente)
{
	NodoBinarioReservarViaje *auxCliente;
	auxCliente = buscarViajeReservacion(opcionCliente);

	if (auxCliente != NULL) {
		if (listaIDCliente_ReservacionHotel.buscarElemento(opcionCliente) != true) {
			string x = arbolAVL.InordenI();
			return "true,"+x;
		}
		else{
	
			return "false,\nError!. El cliente ya ha reservado un hotel.";
		}
	}
	else {
	
		return "false,\nError!. El cliente no existe o no ha reservado un viaje.";
	}
}

string TareaProgramada2::RealizarReservacionHotel1(string info)
{
	string opcionCliente;
	opcionHotel = "";
	
	int i = 0;
	while (info[i] != ',') {
		opcionCliente += info[i];
		i++;
	}

	i += 1;

	while (info[i] != false) {
		opcionHotel += info[i];
		i++;
	}
	

	NodoBinarioReservarViaje *auxCliente;
	auxCliente = buscarViajeReservacion(opcionCliente);

	NodoAVL *auxHotel;
	auxHotel = buscarHotel(opcionHotel);

	NodoBinarioBusqueda *auxViaje;
	auxViaje = buscarViaje(auxCliente->rv_idViaje);

	int num;

	istringstream convertir(opcionCliente);
	convertir >> num;

	if (auxHotel != NULL) {
		bool reservo = false;

		if (auxViaje->NodoAVLHotel != NULL) {
			if (auxViaje->NodoAVLHotel->idHotel == opcionHotel) {
				reservo = true;
			}
		}
		else {
			if (auxViaje->NodoAVLHotel1 != NULL) {
				if (auxViaje->NodoAVLHotel1->idHotel == opcionHotel) {
					reservo = true;
				}
			}
			else {
				if (auxViaje->NodoAVLHotel2 != NULL) {
					if (auxViaje->NodoAVLHotel2->idHotel == opcionHotel) {
						reservo = true;;
					}
				}
				else {
					if (auxViaje->NodoAVLHotel3 != NULL) {
						if (auxViaje->NodoAVLHotel3->idHotel == opcionHotel) {
							reservo = true;
						}
					}
					else {
						if (auxViaje->NodoAVLHotel4 != NULL) {
							if (auxViaje->NodoAVLHotel4->idHotel == opcionHotel) {
								reservo = true;
							}
						}
						else {
							if (auxViaje->NodoAVLHotel5 != NULL) {
								if (auxViaje->NodoAVLHotel5->idHotel == opcionHotel) {
									reservo = true;
								}
							}
							else {
								if (auxViaje->NodoAVLHotel6 != NULL) {
									if (auxViaje->NodoAVLHotel6->idHotel == opcionHotel) {
										reservo = true;
									}
								}
								else {
									if (auxViaje->NodoAVLHotel7 != NULL) {
										if (auxViaje->NodoAVLHotel7->idHotel == opcionHotel) {
											reservo = true;

										}
									}
								}
							}
						}
					}
				}
			}
		}

		if (reservo == true) {
			return "true,Continuando con la reservación...";


		}
		else {
			return "false,\nError!. El hotel no existe.";
		}
	}
	else {
		return "false,\nError!. El hotel no existe.";
	}
}

string TareaProgramada2::RealizarReservacionHotel2(string info)
{

	tipoHab=info;
	escogioHab = false;
	/*
	int i = 0;
	while (info[i] != ',') {
		opcionHotel += info[i];
		i++;
	}

	i += 1;

	while (info[i] != false) {
		tipoHab += info[i];
		i++;
	}
	*/

	

	NodoAVL *auxHotel;
	auxHotel = buscarHotel(opcionHotel);

	if (tipoHab == "0") {
		
	
		if (auxHotel->cantHabIndiv > 0) {
			auxHotel->cantHabIndiv = auxHotel->cantHabIndiv - 1;
			precioHab = auxHotel->precioHabIndiv; escogioHab = true;
		
		}
		else {
			return "false,\nError!. La habitacion individal esta agotada.";
		}
	}
	else {
		if (tipoHab == "1") {
			if (auxHotel->cantHabDoble > 0) {
				auxHotel->cantHabDoble = auxHotel->cantHabDoble - 1;
				precioHab = auxHotel->precioHabDoble; escogioHab = true;
			}
			else {
				return "false,\nError!. La habitacion doble esta agotada.";
			}
		}
	}


	if (escogioHab) {

		NodoAVL *aux;
		aux = buscarHotel(opcionHotel);
		bool tieneOfertaHotel = false;

		if (aux->NodoAAOferT != NULL) {
			tieneOfertaHotel = true;

		}
		else {
			if (aux->NodoAAOferT1 != NULL) {
				tieneOfertaHotel = true;

			}
			else {
				if (aux->NodoAAOferT2 != NULL) {
					tieneOfertaHotel = true;

				}
				else {
					if (aux->NodoAAOferT3 != NULL) {
						tieneOfertaHotel = true;

					}
				}
			}
			
		}



		if (tieneOfertaHotel == true) {

			return "true,\n- Su hotel tiene una oferta!. Aceptar?";
		}
		else {
			
			return "true,\n- Su hotel no tiene ofertas disponibles";
		}



	}
	else {
	
		return "false,\nError!. Opcion de la habitacion invalida.";
	}



}
							
string TareaProgramada2::RealizarReservacionHotel3(string info)
{
	string opcionOferta;
	string opcionCliente;

	int i = 0;
	while (info[i] != ',') {
		opcionCliente += info[i];
		i++;
	}

	i += 1;

	while (info[i] != false) {
		opcionOferta += info[i];
		i++;
	}

	int num;
	istringstream convertir(opcionCliente);
	convertir >> num;

	NodoBinarioReservarViaje *auxCliente;
	auxCliente = buscarViajeReservacion(opcionCliente);

	NodoBinarioBusqueda *auxViaje;
	auxViaje = buscarViaje(auxCliente->rv_idViaje);

	NodoAVL *aux;
	aux = buscarHotel(opcionHotel);

	if (tieneOferta == "true") {

		if (opcionOferta == "0") {
			if (tipoHab == "0") {

				if (aux->NodoAAOferT->cantOfertasIndivi > 0) {
					precioHab = aux->NodoAAOferT->precioHabIndiv;
					aux->NodoAAOferT->cantOfertasIndivi = aux->NodoAAOferT->cantOfertasIndivi - 1;
				}
				else {

					return "false,\nLo sentimos, se acabaron las oferta.";
				}

			}
			else {
				if (tipoHab == "1") {
					if (aux->NodoAAOferT->cantOfertasDobles > 0) {
						precioHab = aux->NodoAAOferT->precioHabDoble;
						aux->NodoAAOferT->cantOfertasDobles = aux->NodoAAOferT->cantOfertasDobles - 1;
					}
					else {

						return "false,\nLo sentimos, se acabaron las oferta.";

					}
				}
			}
		}

	}

	listaIDCliente_ReservacionHotel.InsertarFinal(opcionCliente);
	arbolReserHoteles.InsertarNodoReservacionHotel(num, opcionCliente, auxViaje->idViaje, opcionHotel, auxViaje->fechaSalida, auxViaje->fechaLlegada, precioHab);
	return "true,\nSe ha realizado la reservacion!.";



	
}


//--------------------------//

string TareaProgramada2::ConsultarPaquetesDeUnViaje(string opcionViaje) {


	NodoBinarioBusqueda *auxViaje;
	auxViaje = buscarViaje(opcionViaje);

	if (auxViaje != NULL) {
		string s = to_string(auxViaje->cantPaquetes);
		return "true,\nEl viaje dispone de " + s + " paquetes.";

	}
	else {

		return "false,\nError!. El viaje no existe!.";
	}
}

//--------------------------//

string TareaProgramada2::buscarViajeDestino(string destino) {
	string resultado = arbolBinario.BuscarDestinoViaje(destino);

	if (resultado != "") {
		return "true," + resultado;
	}
	else {
		return "false, Destino no encontrado.";
	}
}

string TareaProgramada2::SalirPrograma() {
	
	return "true,\n---Gracias por utilizar nuestro servicio :) ---";
}


// FUNCIONES DE SOCKETS

void ClientHandlerThread(int index) //Como tengo un arreglo de sockets, le paso uno en especifico para que el hilo como es unico sepa con cual de todos se tiene que comunicar
{
	int bufferlength; //variable en donde se va a guardar el largo del mensaje recibido del cliente
	while (true)
	{

		recv(Connections[index], (char*)&bufferlength, sizeof(int), NULL);								//atrapo y asigno el largo del mensaje que el cliente mando
		char * buffer = new char[bufferlength + 1];														//creo un char en del tamaño del mensaje que voy a recibir y en donde guardare el mensaje del cliente
		buffer[bufferlength] = '\0';																	//le indico en donde termina el char, pues sin esto meteria cosas de la memoria que no necesito
		recv(Connections[index], buffer, bufferlength, NULL);											//atrapo y asigno el mensaje enviado por el cliente

		string respuesta = Respuesta(buffer, bufferlength);												//convierto el mensaje recibido del cliente (char * ) a string 
		string funcion = respuesta.substr(0, 2);														//extraigo el codigo de la funcion que el cliente quiere ejecutar
		string informacion = respuesta.substr(2, respuesta.length() - 2);								//asigno en informacion el resto del mensaje que envio en cliente, quitandole el codigo de la funcion pues ya lo asigne en otro variable
		string retorno = funcionesServidor(funcion, informacion);										//aqui el servidor segun el codigo de la funcion ejecuta lo que tenga que hacer, y retorna un "true" o "false" si es una pregunta y sino retorna un string con la informacion de lo que se desea

		if (retorno == "exit") {
			SOCKET aux = Connections[index];
			closesocket(aux);
			break;
		}

		int size = retorno.size();																		//atrapo el largo del mensaje que se le va a contestar al cliente
		send(Connections[index], (char*)&size, sizeof(int), NULL);										//envio el largo del mensaje que el servidor va a enviar
		send(Connections[index], retorno.c_str(), retorno.size(), NULL);								//envio el mensaje o la respuesta 
		delete[] buffer;																				//Borro el buffer solo por limpiarlo y que no le quede basura *NO BORRAR
	}
}


// SWITCH DE OPCIONES SERVIDOR
string funcionesServidor(string funcion, string informacion) {
	
	int opcion = atoi(funcion.c_str());
	string resultado;
	switch (opcion)
	{
	case 0: resultado = programa.ConsultarPrecioProducto(informacion); break; // Listo
	case 1: resultado = programa.MostrarArbol(informacion); break; // Listo
	case 2: resultado = programa.ConsultarViajeHotelTransporteDeUnCliente(informacion); break;
	case 3: resultado = programa.ConsultarOrigenDestidoDeUnViaje(informacion); break; // Listo
	case 4: resultado = programa.ConsultarInformacionDeUnCliente(informacion); break; // Listo
	case 5: resultado = programa.ConsultarCategoriaDeUnHotel(informacion); break; // Listo
	case 6: resultado = programa.ConsultarPrecioViajeHotelTransporteDeUnCliente(informacion); break;
		//Reservar Viaje
	case 7: resultado = programa.RealizarReservacionViaje0(informacion); break;
	case 8: resultado = programa.RealizarReservacionViaje1(informacion); break;
	case 9: resultado = programa.RealizarReservacionViaje2(informacion); break;
		//Reservar Transporte
	case 10: resultado = programa.RealizarReservacionTransp0(informacion); break;
	case 11: resultado = programa.RealizarReservacionTransp1(informacion); break;

	case 12: resultado = programa.ConsultarPaquetesDeUnViaje(informacion); break; // Listo
	case 13: resultado = programa.SalirPrograma(); break;
		//Reservar Hoteles
	case 14: resultado = programa.RealizarReservacionHotel0(informacion); break;
	case 15: resultado = programa.RealizarReservacionHotel1(informacion); break;
	case 16: resultado = programa.RealizarReservacionHotel2(informacion); break;
	case 17: resultado = programa.RealizarReservacionHotel3(informacion); break;
	case 18: resultado = programa.buscarViajeDestino(informacion); break;
		//Grafos
	case 19: resultado = programa.anchuraGrafo(); break;
	case 20: resultado = programa.profundidadGrafo(); break;
	case 21: resultado = programa.LlamarPrim(); break;
	case 22: resultado = programa.LlamarDijkstra(informacion); break;
	case 23: resultado = programa.LlamarKruskal(); break;
	}
	cout << "\nRespuesta enviada: " << resultado << " ..enviado!";
	return resultado;
}


// Funcion que convierte a string el mensaje recibido del cliente
string Respuesta(char *datos, int tamanio) {
	string respuesta = "";
	for (int i = 0; i < tamanio; i++) {
		respuesta = respuesta + datos[i];
	}
	return respuesta;
}

string DesconectarCliente() {
	return "exit";
}


//----------------------OPERACIONES SECUNDARIAS----------------------//

void TareaProgramada2::CargarArchivos() {

	cout << "- CONEXIONES: ...";
	leerArchivoConexiones(); cout << "LISTO!" << endl;

	cout << "- VIAJES: ...";
	leerArchivoViaje(); cout << "LISTO!" << endl;

	cout << "- HOTELES: ...";
	leerArchivoHotel(); cout << "LISTO!" << endl;

	cout << "- TRANSPORTE: ...";
	leerArchivoTransporte(); cout << "LISTO!" << endl;

	cout << "- OFERTA HOTEL: ...";
	leerArchivoOfertaHotel(); cout << "LISTO!" << endl;

	cout << "- CLIENTES: ...";
	leerArchivoClientes(); cout << "LISTO!" << endl;

	
	cout << "- DESTINOS: ...";
	leerArchivoDestinos(); cout << "LISTO!" << endl;

	cout << "- DIJKSTRA: ...";
	ejecutarDijkstra();  cout << "LISTO!" << endl;

	
	

	

	// ----------------MOSTRADOS------------------ //

	//arbolBinario.InordenI(); // VIAJES
	//arbolAVL.InordenI();  // HOTELES
	//arbolRN.inorder(); //TRANSPORTES
	//arbolAA.IniciarRecorridoAA(); // OFERTA HOTELES
	//arbolB.IniciarRecorridoB(); // CLIENTES

	// ------------------------------------------- //
}





int main() {

	programa.CargarArchivos();

	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0)						//Pregunto si hay error al iniciar el servidor
	{
		cout << "Error al iniciar el servidor" << endl;
		return 0;
	}
	else {
		cout << "\n** Servidor conectado exitosamente **" << endl;
	}

	SOCKADDR_IN addr;												   //Direccion en la que el socket se quedara escuchando los clientes
	int addrlen = sizeof(addr);									       //largo de la direccion, necesario para aceptar los clientes
	addr.sin_addr.s_addr = inet_addr("172.18.175.224");					   //Ip del servidor
	addr.sin_port = htons(1111);									   //Puertos
	addr.sin_family = AF_INET;										   //tipo de socket IPv4Socket

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);				//Crear el socket del servidor, para las conexiones del cliente
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));						//Asignacion de la direccion del socket en donde va a estar escuchando
	listen(sListen, SOMAXCONN);											//Lugares en donde el socket se va a quedar esperando las conexiones. Nota:SOMAXCONN = Maxima cantidad de conexiones

	SOCKET newConnection;												//Socket que se crea para cada cliente
	int ConnectionCounter = 0;											//# de clientes conectados
	for (int i = 0; i < 100; i++)
	{
		newConnection = accept(sListen, (SOCKADDR*)&addr, &addrlen);		//Aceptar a un nuevo cliente
		if (newConnection == 0)												//Pregunto si el cliente se conecto bien
		{
			cout << "Fallo al conectar a un nuevo cliente " << endl;
		}
		else																//Sino hubo error al aceptar cliente
		{
			cout << "Cliente Conectado!" << endl;
			Connections[i] = newConnection;			//Agrego al arreglo de sockets la nueva conexion
			TotalConnections += 1;					//Incremento la cantidad de sockets conectados
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandlerThread, (LPVOID)(i), NULL, NULL); //Se crea un nuevo hilo para ese cliente... Sin esta linea no hay proyecto
			string buftest = "Te has conectado.";
			int size = buftest.size(); //tamaño del mensaje a enviar
			send(Connections[i], (char*)&size, sizeof(int), NULL); //envio el tamaño del mensaje de confirmacion de conexion al cliente
			send(Connections[i], buftest.c_str(), buftest.size(), NULL); //envio el mensaje
		}
	}

	system("pause");
	return 0;
}
