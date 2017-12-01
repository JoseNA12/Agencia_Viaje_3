#include "iostream"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Kruskal {
	public:
       int nod_k;
       int marca_k;
	   class Kruskal *sig_k;
	   class Kruskal *arc_k;

	   class Kruskal *ver_k;
       int marcaArc_k;
       int suma_k;
       int clave_k;
	   class Kruskal *sigArc_k;

		void actualizarCampos_Kruskal();
		void crearVertice_Kruskal(int vertice1);
		void enlazarVertices_Kruskal(int c, int p, int k);
		void enlazar_Kruskal(int peso);
		void listarAdyacencia_Kruskal();
		//void obtenerArcoMenor();
		void listarAdyacenciaKruskal();
		string sumaCaminos_Kruskal();
		string algoritmoKruskal(int i);
		void obtenerArcoMenor_Kruskal();
		void obtenerSumaMenor_Kruskal();
		void paso2();
		void paso2Kruskal();
		void liberarMemoria_Kruskal();


	friend class vertice;
	friend class arco;

};


class Kruskal *pri_k, *nue_k, *aux_k, *ult_k, *aux2_k;
class Kruskal *nueArc_k, *auxArc_k, *arcMen_k, *auxArc2_k, *antArc_k;
int auxNod_k, auxNod2_k, ban2_k, let_k;
int ban_k, enlace_k, ban3_k, ban4_k, numVer_k;


void Kruskal::crearVertice_Kruskal(int vertice1) {
	//system ("cls");
	if (pri_k == NULL) {
		pri_k = new Kruskal;
		//cout << "El Grafo no tiene vertices\nDigite la letra del Primer Nodo: ";
		//cin >>pri->nod;

		pri_k->nod_k = vertice1;

		pri_k->marca_k = 0;
		pri_k->arc_k = NULL;
		pri_k->sig_k = NULL;
		ult_k = pri_k;
		//cout << "\nNodo registrado correctamente.";
	}
	else {
		//cout << "Digite la letra del vertice: ";
		//cin >> let;

		let_k = vertice1;

		do {
			aux_k = pri_k;
			ban_k = 0;
			while (aux_k != NULL) {
				if (aux_k->nod_k == let_k) {
					ban_k = 1;
				}
				aux_k = aux_k->sig_k;
			}
			if (ban_k == 1) {
				//cout << "\nEsa letra clave ya fue usada:\n";
				aux_k = pri_k;
				while (aux_k != NULL) {
					//cout << aux->nod << " ";
					aux_k = aux_k->sig_k;
				}
				//cout << "\nDigita una letra diferente: ";
				//cin >> let;
			}
		} while (ban_k == 1);

		if (ban_k != 1) {
			nue_k = new Kruskal;
			nue_k->nod_k = let_k;
			nue_k->marca_k = 0;
			nue_k->sig_k = NULL;
			nue_k->arc_k = NULL;
			ult_k->sig_k = nue_k;
			ult_k = nue_k;
			//cout << "\nNodo registrado correctamente.";
		}

		/*cout << "\nAhora que existe un nuevo vertice desea crear enlaces? s/n: ";
		cin >> ban2;
		while (ban2 == 's'){
			  enlazarVertices();
			  cout << "\n¿Desea crear otro enlace? s/n: ";
			  cin >> ban2;
		} */
	}

	//getch();
}

void Kruskal::enlazarVertices_Kruskal(int vertice1, int vertice2, int peso) {
     //system ("cls");
     if (pri_k != NULL){
        aux_k = pri_k;
        while (aux_k != NULL){
              //cout << aux->nod << "\n";
              aux_k = aux_k->sig_k;
        }
        //cout << "\nDigite la letra del nodo al cual desea enlazar: ";
        //cin >> auxNod;

		auxNod_k = vertice1;

        ban_k = 0;
        while (ban_k == 0){
              aux_k = pri_k;
              while (aux_k != NULL && ban_k == 0){
                   if (aux_k->nod_k == auxNod_k){
                      ban_k = 1;
                   }
                   aux_k = aux_k->sig_k;
              }
              /*if (ban == 0){  JOSESIN
                 cout << "\nEl nodo no existe\nPor favor digite uno de los listados anteriormente: ";
                 cin >> auxNod;
              }*/
        }
        /*cout << "\nEstos son los nodos disponibles para hacer el respectivo enlace:\n";
        aux = pri;
        aux2 = pri;
        while (aux2->nod != auxNod){           JOSESIN
              aux2 = aux2->sig;
        }
        while (aux != NULL){
              if (aux->nod != auxNod){
                  auxArc = aux2->arc;
                  ban4 = 0;
                  while (auxArc != NULL && ban4 == 0){
                        if (aux->nod == auxArc->ver->nod){
                           ban4 = 1;
                        }
                        auxArc = auxArc->sig;
                  }
                  if (ban4 == 0){
                     cout << aux->nod << "\n";
                  }
              }

              aux = aux->sig;
        }*/
        //cout << "\nDigite la letra del nodo al cual desea enlazar el nodo elegido: ";
        //cin >> auxNod2;

		auxNod2_k = vertice2;

        /*ban = 0;
        while (ban == 0){
              aux = pri;
              /*while (auxNod2 == auxNod){    JOSESIN
                    cout << "\nNo se puede hacer ese enlace\nDigite otro nodo disponible: ";
                    cin >> auxNod2;
              }
              while (aux != NULL && ban == 0){
                   if (aux->nod == auxNod2){
                      ban = 1;
                   }
                   aux = aux->sig;
              }
              if (ban == 0){
                 cout << "\nEl nodo no existe\nPor favor digite uno de los listados anteriormente: ";
                 cin >> auxNod2;
              }
        }*/
        aux_k = pri_k;
        while (aux_k->nod_k != auxNod_k){
              aux_k = aux_k->sig_k;
        }
        auxArc_k = aux_k->arc_k;
        ban3_k = 0;
        while (auxArc_k != NULL && ban3_k == 0){
              if (auxArc_k->ver_k->nod_k == auxNod2_k){
                 ban3_k = 1;
              }
              auxArc_k = auxArc_k->sigArc_k;
        }
        if (ban3_k == 0){
           enlazar_Kruskal(peso);
           //cout << "\nEnlace creado correctamente.";
        }
        else {
             //cout << "\nEse enlace ya existe. Compruebe el enlace la proxima vez.";
        }
     }
}

void Kruskal::enlazar_Kruskal(int peso) {
	aux_k = pri_k;
	while (aux_k->nod_k != auxNod_k) {
		aux_k = aux_k->sig_k;
	}
	aux2_k = pri_k;
	while (aux2_k->nod_k != auxNod2_k) {
		aux2_k = aux2_k->sig_k;
	}
	if (aux_k->arc_k == NULL) {
		nueArc_k = new Kruskal;
		nueArc_k->ver_k = aux2_k;
		//cout << "\nDigite el valor del enlace: ";
		enlace_k = peso;

		/*while (nueArc->clave < 0) {		JOSESIN
			cout << "\nEl valor debe ser positivo\nDigite el valor del enlace: ";
			cin >> enlace;
		}*/
		nueArc_k->clave_k = enlace_k;
		nueArc_k->marcaArc_k = 0;
		nueArc_k->suma_k = 0;
		nueArc_k->sigArc_k = NULL;
		aux_k->arc_k = nueArc_k;
		if (aux2_k->arc_k == NULL) {
			nueArc_k = new Kruskal;
			nueArc_k->ver_k = aux_k;
			nueArc_k->clave_k = enlace_k;
			nueArc_k->marcaArc_k = 0;
			nueArc_k->suma_k = 0;
			nueArc_k->sigArc_k = NULL;
			aux2_k->arc_k = nueArc_k;
		}
		else {
			nueArc_k = new Kruskal;
			nueArc_k->ver_k = aux_k;
			nueArc_k->clave_k = enlace_k;
			nueArc_k->marcaArc_k = 0;
			nueArc_k->suma_k = 0;
			nueArc_k->sigArc_k = NULL;
			auxArc_k = aux2_k->arc_k;
			while (auxArc_k->sigArc_k != NULL) {
				auxArc_k = auxArc_k->sigArc_k;
			}
			auxArc_k->sigArc_k = nueArc_k;
		}
	}
	else {
		nueArc_k = new Kruskal;
		nueArc_k->ver_k = aux2_k;
		//cout << "\nDigite el valor del enlace: ";
		//cin >> enlace;

		enlace_k = peso;

		/*while (enlace < 0) {		JOSESIN
			cout << "\nEl valor debe ser positivo\nDigite el valor del enlace: ";
			cin >> enlace;
		}*/
		nueArc_k->clave_k = enlace_k;
		nueArc_k->marcaArc_k = 0;
		nueArc_k->suma_k = 0;
		nueArc_k->sigArc_k = NULL;
		auxArc_k = aux_k->arc_k;
		while (auxArc_k->sigArc_k != NULL) {
			auxArc_k = auxArc_k->sigArc_k;
		}
		auxArc_k->sigArc_k = nueArc_k;
		if (aux2_k->arc_k == NULL) {
			nueArc_k = new Kruskal;
			nueArc_k->ver_k = aux_k;
			nueArc_k->clave_k = enlace_k;
			nueArc_k->marcaArc_k = 0;
			nueArc_k->suma_k = 0;
			nueArc_k->sigArc_k = NULL;
			aux2_k->arc_k = nueArc_k;
		}
		else {
			nueArc_k = new Kruskal;
			nueArc_k->ver_k = aux_k;
			nueArc_k->clave_k = enlace_k;
			nueArc_k->marcaArc_k = 0;
			nueArc_k->suma_k = 0;
			nueArc_k->sigArc_k = NULL;
			auxArc_k = aux2_k->arc_k;
			while (auxArc_k->sigArc_k != NULL) {
				auxArc_k = auxArc_k->sigArc_k;
			}
			auxArc_k->sigArc_k = nueArc_k;
		}
	}
}

void Kruskal::obtenerArcoMenor_Kruskal() {
	aux2_k = pri_k;
	arcMen_k = NULL;
	while (aux2_k != NULL) {
		if (aux2_k->marca_k == 1) {
			auxArc_k = aux2_k->arc_k;
			while (auxArc_k != NULL) {
				if (auxArc_k->marcaArc_k == 1) {
					if (arcMen_k == NULL) {
						arcMen_k = auxArc_k;
					}
					else {
						if (auxArc_k->clave_k < arcMen_k->clave_k) {
							arcMen_k = auxArc_k;
						}
					}
				}
				auxArc_k = auxArc_k->sigArc_k;
			}
		}
		aux2_k = aux2_k->sig_k;
	}
	arcMen_k->marcaArc_k = 3;
	arcMen_k->ver_k->marca_k = 1;
}

void Kruskal::obtenerSumaMenor_Kruskal() {
	aux2_k = pri_k;
	arcMen_k = NULL;
	while (aux2_k != NULL) {
		if (aux2_k->marca_k == 1) {
			auxArc_k = aux2_k->arc_k;
			while (auxArc_k != NULL) {
				if (auxArc_k->marcaArc_k == 1) {
					if (arcMen_k == NULL) {
						arcMen_k = auxArc_k;
					}
					else {
						if (auxArc_k->suma_k < arcMen_k->suma_k) {
							arcMen_k = auxArc_k;
						}
					}
				}
				auxArc_k = auxArc_k->sigArc_k;
			}
		}
		aux2_k = aux2_k->sig_k;
	}
	arcMen_k->marcaArc_k = 3;
	arcMen_k->ver_k->marca_k = 1;
	auxArc_k = arcMen_k->ver_k->arc_k;
	while (auxArc_k != NULL) {
		auxArc_k->suma_k = arcMen_k->suma_k + auxArc_k->clave_k;
		auxArc_k = auxArc_k->sigArc_k;
	}
}

void Kruskal::paso2() {
	obtenerArcoMenor_Kruskal();
	cout << "\nEl arco menor es: " << arcMen_k->ver_k->nod_k << " vale: " << arcMen_k->clave_k;
	//getch();
	aux_k = arcMen_k->ver_k;
	auxArc_k = aux_k->arc_k;
	while (auxArc_k != NULL) {
		if (auxArc_k->ver_k->marca_k == 0) {
			aux2_k = pri_k;
			while (aux2_k != NULL) {
				if (aux2_k != aux_k && aux2_k->marca_k == 1) {
					auxArc2_k = aux2_k->arc_k;
					while (auxArc2_k != NULL) {
						if (auxArc_k->ver_k->nod_k == auxArc2_k->ver_k->nod_k) {
							if (auxArc_k->clave_k < auxArc2_k->clave_k) {
								auxArc2_k->marcaArc_k = 2;
								auxArc_k->marcaArc_k = 1;
							}
							else {
								auxArc_k->marcaArc_k = 2;
								auxArc2_k->marcaArc_k = 1;
							}
						}
						auxArc2_k = auxArc2_k->sigArc_k;
					}
				}
				aux2_k = aux2_k->sig_k;
			}
			if (auxArc_k->marcaArc_k == 0) {
				auxArc_k->marcaArc_k = 1;
			}
		}
		else {
			auxArc_k->marcaArc_k = 2;
		}
		auxArc_k = auxArc_k->sigArc_k;
	}
}


void Kruskal::paso2Kruskal() {
	obtenerSumaMenor_Kruskal();
	cout << "\nLa sumatoria hasta el arco " << arcMen_k->ver_k->nod_k << " es: " << arcMen_k->suma_k;
	//getch();
	aux_k = arcMen_k->ver_k;
	auxArc_k = aux_k->arc_k;
	while (auxArc_k != NULL) {
		if (auxArc_k->ver_k->marca_k == 0) {
			aux2_k = pri_k;
			while (aux2_k != NULL) {
				if (aux2_k != aux_k && aux2_k->marca_k == 1) {
					auxArc2_k = aux2_k->arc_k;
					while (auxArc2_k != NULL) {
						if (auxArc_k->ver_k->nod_k == auxArc2_k->ver_k->nod_k) {
							if (auxArc_k->suma_k < auxArc2_k->suma_k) {
								auxArc2_k->marcaArc_k = 2;
								auxArc_k->marcaArc_k = 1;
							}
							else {
								auxArc_k->marcaArc_k = 2;
								auxArc2_k->marcaArc_k = 1;
							}
						}
						auxArc2_k = auxArc2_k->sigArc_k;
					}
				}
				aux2_k = aux2_k->sig_k;
			}
			if (auxArc_k->marcaArc_k == 0) {
				auxArc_k->marcaArc_k = 1;
				auxArc_k->suma_k = arcMen_k->suma_k + auxArc_k->clave_k;
			}
		}
		else {
			auxArc_k->marcaArc_k = 2;
		}
		auxArc_k = auxArc_k->sigArc_k;
	}
}

string Kruskal::algoritmoKruskal(int inicio) {
	//system("cls");
	if (pri_k != NULL) {
		//actualizarCampos();
		//cout << "Digite el vertice inicial: ";
		//cin >> auxNod;

		auxNod_k = inicio;

		ban_k = 0;
		while (ban_k == 0) {
			aux_k = pri_k;
			while (aux_k != NULL) {
				if (aux_k->nod_k == auxNod_k) {
					ban_k = 1;
				}
				aux_k = aux_k->sig_k;
			}/*
			if (ban == 0) {
				cout << "\nNo existe un nodo con esa letra.";
				aux = pri;
				cout << "\n---Lista de Nodos---\n";
				while (aux != NULL) {
					cout << aux->nod << " ";
					aux = aux->sig;
				}
				cout << "\nDigite uno de los anteriores nodos: ";
				cin >> auxNod;
			}*/
		}
		aux_k = pri_k;
		while (aux_k->nod_k != auxNod_k) {
			aux_k = aux_k->sig_k;
		}
		aux_k->marca_k = 1;
		auxArc_k = aux_k->arc_k;
		while (auxArc_k != NULL) {
			auxArc_k->marcaArc_k = 1;
			auxArc_k = auxArc_k->sigArc_k;
		}
		cout << "\nSe han marcado todos los arcos para el vertice elegido.";
		ban2_k = 1;
		while (ban2_k == 1) {
			paso2();
			ban2_k = 0;
			aux_k = pri_k;
			while (aux_k!= NULL) {
				if (aux_k->marca_k == 0) {
					ban2_k = 1;
				}
				aux_k = aux_k->sig_k;
			}
		}
	//	listarAdyacenciaKruskal();
		string resultado= sumaCaminos_Kruskal();
		return resultado;
	}
	//getch();
}

void Kruskal::listarAdyacencia_Kruskal() {
	//system("cls");
	if (pri_k != NULL) {
		aux_k = pri_k;
		cout << "---Lista de Adyacencia---\n";
		while (aux_k != NULL) {
			auxArc_k = aux_k->arc_k;
			cout << "\n|\n" << aux_k->nod_k << "->";
			while (auxArc_k != NULL) {
				cout << auxArc_k->ver_k->nod_k << " ";
				auxArc_k = auxArc_k->sigArc_k;
			}
			aux_k = aux_k->sig_k;
		}
		//getch();
	}
}

string Kruskal::sumaCaminos_Kruskal() {
	aux_k = pri_k;
	int suma_k = 0;
	while (aux_k != NULL) {
		auxArc_k = aux_k->arc_k;
		while (auxArc_k != NULL) {
			if (auxArc_k->marcaArc_k == 3) {
				suma_k = suma_k + auxArc_k->clave_k;
			}
			auxArc_k = auxArc_k->sigArc_k;
		}
		aux_k = aux_k->sig_k;
	}
	stringstream convert;
 	convert << suma_k;
	string string2 = convert.str();
	return string2;
}

void Kruskal::listarAdyacenciaKruskal() {
	if (pri_k != NULL) {
		aux_k = pri_k;
		cout << "\n---Lista de Adyacencia---\n";
		while (aux_k != NULL) {
			auxArc_k = aux_k->arc_k;
			cout << "\n|\n" << aux_k->nod_k << "->";
			while (auxArc_k != NULL) {
				if (auxArc_k->marcaArc_k == 3)
					cout << auxArc_k->ver_k->nod_k << " ";
				auxArc_k = auxArc_k->sigArc_k;
			}
			aux_k = aux_k->sig_k;
		}
	}
}


void Kruskal::liberarMemoria_Kruskal() {
	if (pri_k != NULL) {
		aux_k = pri_k;
		while (aux_k != NULL) {
			auxArc_k = aux_k->arc_k;
			while (auxArc_k != NULL) {
				aux_k->arc_k = aux_k->arc_k->sigArc_k;
				delete auxArc_k;
				auxArc_k = aux_k->arc_k;
			}
			pri_k = pri_k->sig_k;
			delete aux_k;
			aux_k = pri_k;
		}
	}
	cout << "Memoria Libre";
	//getch();
}

void Kruskal::actualizarCampos_Kruskal() {
     aux_k = pri_k;
     while (aux_k != NULL){
           auxArc_k = aux_k->arc_k;
           while (auxArc_k != NULL){
                 auxArc_k->marcaArc_k = 0;
                 auxArc_k->suma_k = 0;
                 auxArc_k = auxArc_k->sigArc_k;
           }
           aux_k->marca_k = 0;
           aux_k = aux_k->sig_k;
     }
}
/*
int main (){

    Kruskal K;

    int op = 0;
    do{
       //system("cls");
       cout<<"\n\n-----MENU-----";
       cout<<"\n1. Crear Vertices.";
       cout<<"\n2. Enlazar Vertices.";
       cout<<"\n3. Listar Vertices con su lista de adyacencia.";
       cout<<"\n4. Algoritmo de Prim.";
       cout<<"\n5. Algoritmo de Kruskal.";
       cout<<"\n6. Liberar Memoria.";
       cout<<"\n7. Salir";
       cout<<"\n\nDigite la Opcion: ";
       cin>>op;

       while (op>7){
             cout << "Esa opcion no existe digite un numero del 1 al 7: ";
             cin >> op;
       }
       switch(op){
                  case 1: K.crearVertice_Kruskal(); break;
                  case 2: K.enlazarVertices_Kruskal(); getch(); break;
                  case 3: K.listarAdyacencia_Kruskal(); break;
                  case 4: K.algoritmoKruskal(); break;
                  //case 5: K.algoritmoKruskal_Kruskal(); break;
                  case 6: K.liberarMemoria_Kruskal(); break;
                  case 7: exit (0);
       }
    }while(op<7);

	return 0;
}*/
