#include "iostream"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Dijkstra {
	public:
       int nod;
       int marca;
	   class Dijkstra *sig;
	   class Dijkstra *arc;

	   class Dijkstra *ver;
       int marcaArc;
       int suma;
       int clave;
	   class Dijkstra *sigArc;

		void actualizarCampos ();
		void crearVertice(int vertice1);
		void enlazarVertices(int caca, int pedo, int pis);
		void enlazar(int peso);
		void listarAdyacencia();
		//void obtenerArcoMenor();
		void listarAdyacenciaPrim();
		string sumaCaminos();
		string algoritmoDijkstra(int i);
		void obtenerArcoMenor();
		void obtenerSumaMenor();
		void paso2();
		string paso2Dijkstra();
		string algoritmoPrim(int inicio);
		void liberarMemoria();


	friend class vertice;
	friend class arco;

};


class Dijkstra *pri, *nue, *aux, *ult, *aux2;
class Dijkstra *nueArc, *auxArc, *arcMen, *auxArc2, *antArc;
int auxNod, auxNod2, ban2, let;
int ban, enlace, ban3, ban4, numVer;


void Dijkstra::crearVertice(int vertice1) {
	//system ("cls");
	if (pri == NULL) {
		pri = new Dijkstra;
		//cout << "El Grafo no tiene vertices\nDigite la letra del Primer Nodo: ";
		//cin >>pri->nod;

		pri->nod = vertice1;

		pri->marca = 0;
		pri->arc = NULL;
		pri->sig = NULL;
		ult = pri;
		//cout << "\nNodo registrado correctamente.";
	}
	else {
		//cout << "Digite la letra del vertice: ";
		//cin >> let;

		let = vertice1;

		do {
			aux = pri;
			ban = 0;
			while (aux != NULL) {
				if (aux->nod == let) {
					ban = 1;
				}
				aux = aux->sig;
			}
			if (ban == 1) {
				//cout << "\nEsa letra clave ya fue usada:\n";
				aux = pri;
				while (aux != NULL) {
					//cout << aux->nod << " ";
					aux = aux->sig;
				}
				//cout << "\nDigita una letra diferente: ";
				//cin >> let;
			}
		} while (ban == 1);

		if (ban != 1) {
			nue = new Dijkstra;
			nue->nod = let;
			nue->marca = 0;
			nue->sig = NULL;
			nue->arc = NULL;
			ult->sig = nue;
			ult = nue;
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

void Dijkstra::enlazarVertices (int vertice1, int vertice2, int peso) {
     //system ("cls");
     if (pri != NULL){
        aux = pri;
        while (aux != NULL){
              //cout << aux->nod << "\n";
              aux = aux->sig;
        }
        //cout << "\nDigite la letra del nodo al cual desea enlazar: ";
        //cin >> auxNod;

		auxNod = vertice1;

        ban = 0;
        while (ban == 0){
              aux = pri;
              while (aux != NULL && ban == 0){
                   if (aux->nod == auxNod){
                      ban = 1;
                   }
                   aux = aux->sig;
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

		auxNod2 = vertice2;

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
        aux = pri;
        while (aux->nod != auxNod){
              aux = aux->sig;
        }
        auxArc = aux->arc;
        ban3 = 0;
        while (auxArc != NULL && ban3 == 0){
              if (auxArc->ver->nod == auxNod2){
                 ban3 = 1;
              }
              auxArc = auxArc->sigArc;
        }
        if (ban3 == 0){
           enlazar(peso);
           //cout << "\nEnlace creado correctamente.";
        }
        else {
             //cout << "\nEse enlace ya existe. Compruebe el enlace la proxima vez.";
        }
     }
}

void Dijkstra::enlazar(int peso) {
	aux = pri;
	while (aux->nod != auxNod) {
		aux = aux->sig;
	}
	aux2 = pri;
	while (aux2->nod != auxNod2) {
		aux2 = aux2->sig;
	}
	if (aux->arc == NULL) {
		nueArc = new Dijkstra;
		nueArc->ver = aux2;
		//cout << "\nDigite el valor del enlace: ";
		enlace = peso;

		/*while (nueArc->clave < 0) {		JOSESIN	
			cout << "\nEl valor debe ser positivo\nDigite el valor del enlace: ";
			cin >> enlace;
		}*/
		nueArc->clave = enlace;
		nueArc->marcaArc = 0;
		nueArc->suma = 0;
		nueArc->sigArc = NULL;
		aux->arc = nueArc;
		if (aux2->arc == NULL) {
			nueArc = new Dijkstra;
			nueArc->ver = aux;
			nueArc->clave = enlace;
			nueArc->marcaArc = 0;
			nueArc->suma = 0;
			nueArc->sigArc = NULL;
			aux2->arc = nueArc;
		}
		else {
			nueArc = new Dijkstra;
			nueArc->ver = aux;
			nueArc->clave = enlace;
			nueArc->marcaArc = 0;
			nueArc->suma = 0;
			nueArc->sigArc = NULL;
			auxArc = aux2->arc;
			while (auxArc->sigArc != NULL) {
				auxArc = auxArc->sigArc;
			}
			auxArc->sigArc = nueArc;
		}
	}
	else {
		nueArc = new Dijkstra;
		nueArc->ver = aux2;
		//cout << "\nDigite el valor del enlace: ";
		//cin >> enlace;

		enlace = peso;

		/*while (enlace < 0) {		JOSESIN
			cout << "\nEl valor debe ser positivo\nDigite el valor del enlace: ";
			cin >> enlace;
		}*/
		nueArc->clave = enlace;
		nueArc->marcaArc = 0;
		nueArc->suma = 0;
		nueArc->sigArc = NULL;
		auxArc = aux->arc;
		while (auxArc->sigArc != NULL) {
			auxArc = auxArc->sigArc;
		}
		auxArc->sigArc = nueArc;
		if (aux2->arc == NULL) {
			nueArc = new Dijkstra;
			nueArc->ver = aux;
			nueArc->clave = enlace;
			nueArc->marcaArc = 0;
			nueArc->suma = 0;
			nueArc->sigArc = NULL;
			aux2->arc = nueArc;
		}
		else {
			nueArc = new Dijkstra;
			nueArc->ver = aux;
			nueArc->clave = enlace;
			nueArc->marcaArc = 0;
			nueArc->suma = 0;
			nueArc->sigArc = NULL;
			auxArc = aux2->arc;
			while (auxArc->sigArc != NULL) {
				auxArc = auxArc->sigArc;
			}
			auxArc->sigArc = nueArc;
		}
	}
}

void Dijkstra::obtenerArcoMenor() {
	aux2 = pri;
	arcMen = NULL;
	while (aux2 != NULL) {
		if (aux2->marca == 1) {
			auxArc = aux2->arc;
			while (auxArc != NULL) {
				if (auxArc->marcaArc == 1) {
					if (arcMen == NULL) {
						arcMen = auxArc;
					}
					else {
						if (auxArc->clave < arcMen->clave) {
							arcMen = auxArc;
						}
					}
				}
				auxArc = auxArc->sigArc;
			}
		}
		aux2 = aux2->sig;
	}
	arcMen->marcaArc = 3;
	arcMen->ver->marca = 1;
}

void Dijkstra::obtenerSumaMenor() {
	aux2 = pri;
	arcMen = NULL;
	while (aux2 != NULL) {
		if (aux2->marca == 1) {
			auxArc = aux2->arc;
			while (auxArc != NULL) {
				if (auxArc->marcaArc == 1) {
					if (arcMen == NULL) {
						arcMen = auxArc;
					}
					else {
						if (auxArc->suma < arcMen->suma) {
							arcMen = auxArc;
						}
					}
				}
				auxArc = auxArc->sigArc;
			}
		}
		aux2 = aux2->sig;
	}
	arcMen->marcaArc = 3;
	arcMen->ver->marca = 1;
	auxArc = arcMen->ver->arc;
	while (auxArc != NULL) {
		auxArc->suma = arcMen->suma + auxArc->clave;
		auxArc = auxArc->sigArc;
	}
}

void Dijkstra::paso2() {
	obtenerArcoMenor();
	cout << "\nEl arco menor es: " << arcMen->ver->nod << " vale: " << arcMen->clave;
	//getch();
	aux = arcMen->ver;
	auxArc = aux->arc;
	while (auxArc != NULL) {
		if (auxArc->ver->marca == 0) {
			aux2 = pri;
			while (aux2 != NULL) {
				if (aux2 != aux && aux2->marca == 1) {
					auxArc2 = aux2->arc;
					while (auxArc2 != NULL) {
						if (auxArc->ver->nod == auxArc2->ver->nod) {
							if (auxArc->clave < auxArc2->clave) {
								auxArc2->marcaArc = 2;
								auxArc->marcaArc = 1;
							}
							else {
								auxArc->marcaArc = 2;
								auxArc2->marcaArc = 1;
							}
						}
						auxArc2 = auxArc2->sigArc;
					}
				}
				aux2 = aux2->sig;
			}
			if (auxArc->marcaArc == 0) {
				auxArc->marcaArc = 1;
			}
		}
		else {
			auxArc->marcaArc = 2;
		}
		auxArc = auxArc->sigArc;
	}
}


string Dijkstra::paso2Dijkstra() {
	obtenerSumaMenor();
	int a = arcMen->ver->nod;
	 stringstream convert_1;
	 convert_1 << a;
	 string string_1 = convert_1.str();
	
	 int b = arcMen->suma;
	 stringstream convert_2;
	 convert_2 << b;
	 string string_2 = convert_2.str();
	
	 string resultado = string_1 + ',' + string_2 + ";";
	//getch();
	aux = arcMen->ver;
	auxArc = aux->arc;
	while (auxArc != NULL) {
		if (auxArc->ver->marca == 0) {
			aux2 = pri;
			while (aux2 != NULL) {
				if (aux2 != aux && aux2->marca == 1) {
					auxArc2 = aux2->arc;
					while (auxArc2 != NULL) {
						if (auxArc->ver->nod == auxArc2->ver->nod) {
							if (auxArc->suma < auxArc2->suma) {
								auxArc2->marcaArc = 2;
								auxArc->marcaArc = 1;
							}
							else {
								auxArc->marcaArc = 2;
								auxArc2->marcaArc = 1;
							}
						}
						auxArc2 = auxArc2->sigArc;
					}
				}
				aux2 = aux2->sig;
			}
			if (auxArc->marcaArc == 0) {
				auxArc->marcaArc = 1;
				auxArc->suma = arcMen->suma + auxArc->clave;
			}
		}
		else {
			auxArc->marcaArc = 2;
		}
		auxArc = auxArc->sigArc;
	}
	return resultado;
}

string Dijkstra::algoritmoPrim(int inicio) {
	//system("cls");
	if (pri != NULL) {
		//actualizarCampos();
		//cout << "Digite el vertice inicial: ";
		//cin >> auxNod;

		auxNod = inicio;

		ban = 0;
		while (ban == 0) {
			aux = pri;
			while (aux != NULL) {
				if (aux->nod == auxNod) {
					ban = 1;
				}
				aux = aux->sig;
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
		aux = pri;
		while (aux->nod != auxNod) {
			aux = aux->sig;
		}
		aux->marca = 1;
		auxArc = aux->arc;
		while (auxArc != NULL) {
			auxArc->marcaArc = 1;
			auxArc = auxArc->sigArc;
		}
		cout << "\nSe han marcado todos los arcos para el vertice elegido.";
		ban2 = 1;
		while (ban2 == 1) {
			paso2();
			ban2 = 0;
			aux = pri;
			while (aux != NULL) {
				if (aux->marca == 0) {
					ban2 = 1;
				}
				aux = aux->sig;
			}
		}
	//	listarAdyacenciaPrim();
		string resultado= sumaCaminos();
		return resultado;
	}
	//getch();
	
}

void Dijkstra::listarAdyacencia() {
	//system("cls");
	if (pri != NULL) {
		aux = pri;
		cout << "---Lista de Adyacencia---\n";
		while (aux != NULL) {
			auxArc = aux->arc;
			cout << "\n|\n" << aux->nod << "->";
			while (auxArc != NULL) {
				cout << auxArc->ver->nod << " ";
				auxArc = auxArc->sigArc;
			}
			aux = aux->sig;
		}
		//getch();
	}
}


string Dijkstra::sumaCaminos() {
	aux = pri;
	int suma = 0;
	while (aux != NULL) {
		auxArc = aux->arc;
		while (auxArc != NULL) {
			if (auxArc->marcaArc == 3) {
				suma = suma + auxArc->clave;
			}
			auxArc = auxArc->sigArc;
		}
		aux = aux->sig;
	}
	stringstream convert;
 	convert << suma;
	string string2 = convert.str();
	return string2;
}

void Dijkstra::listarAdyacenciaPrim() {
	if (pri != NULL) {
		aux = pri;
	//	cout << "\n---Lista de Adyacencia---\n";
		while (aux != NULL) {
			auxArc = aux->arc;
			cout << "\n|\n" << aux->nod << "->";
			while (auxArc != NULL) {
				if (auxArc->marcaArc == 3)
					cout << auxArc->ver->nod << " ";
				auxArc = auxArc->sigArc;
			}
			aux = aux->sig;
		}
	}
}


void Dijkstra::liberarMemoria() {
	if (pri != NULL) {
		aux = pri;
		while (aux != NULL) {
			auxArc = aux->arc;
			while (auxArc != NULL) {
				aux->arc = aux->arc->sigArc;
				delete auxArc;
				auxArc = aux->arc;
			}
			pri = pri->sig;
			delete aux;
			aux = pri;
		}
	}
	cout << "Memoria Libre";
	//getch();
}


string Dijkstra::algoritmoDijkstra(int inicio) {
	//system("cls");
	if (pri != NULL) {
		actualizarCampos();
		//cout << "Digite el vertice inicial: ";
		//cin >> auxNod;
		
		auxNod = inicio; // EDITE AQUI
		
		ban = 0;
		while (ban == 0) {
			aux = pri;
			while (aux != NULL) {
				if (aux->nod == auxNod) {
					ban = 1;
				}
				aux = aux->sig;
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
		aux = pri;
		while (aux->nod != auxNod) {
			aux = aux->sig;
		}
		aux->marca = 1;
		auxArc = aux->arc;
		while (auxArc != NULL) {
			auxArc->marcaArc = 1;
			auxArc->suma = auxArc->clave;
			auxArc = auxArc->sigArc;
		}
		cout << "\nSe han trazado todos los arcos para el vertice elegido.";
		ban2 = 1;
		string resultado;
		while (ban2 == 1) {
			
			resultado+= paso2Dijkstra();
			ban2 = 0;
			aux = pri;
			while (aux != NULL) {
				if (aux->marca == 0) {
					ban2 = 1;
				}
				aux = aux->sig;
			}
		}
		//listarAdyacenciaPrim();
		return resultado;
	}
	//getch();
}


void Dijkstra::actualizarCampos () {
     aux = pri;
     while (aux != NULL){
           auxArc = aux->arc;
           while (auxArc != NULL){
                 auxArc->marcaArc = 0;
                 auxArc->suma = 0;
                 auxArc = auxArc->sigArc;
           }
           aux->marca = 0;
           aux = aux->sig;
     }
}
/*
int main (){
    int op = 0;
    do{
       //system("cls");
       cout<<"\n\n-----MENU-----";
       cout<<"\n1. Crear Vertices.";
       cout<<"\n2. Enlazar Vertices.";
       cout<<"\n3. Listar Vertices con su lista de adyacencia.";
       cout<<"\n4. Algoritmo de Prim.";
       cout<<"\n5. Algoritmo de Dijkstra.";
       cout<<"\n6. Liberar Memoria.";
       cout<<"\n7. Salir";
       cout<<"\n\nDigite la Opcion: ";
       cin>>op;

       while (op>7){
             cout << "Esa opcion no existe digite un numero del 1 al 7: ";
             cin >> op;
       }
       switch(op){
                  case 1: crearVertice(); break;
                  case 2: enlazarVertices(); getch(); break;
                  case 3: listarAdyacencia(); break;
                  case 4: algoritmoPrim(); break;
                  case 5: algoritmoDijkstra(); break;
                  case 6: liberarMemoria (); break;
                  case 7: exit (0);
       }
    }while(op<7);

	return 0;
}*/
