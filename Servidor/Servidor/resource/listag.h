#include<time.h>
#include<windows.h>
#include"lista.h"
#include"Colas.h"
#include"Pila.h"
#include<fstream>
#include <sstream>
#define Max 100
#define INF 999



using namespace std;
// funcion gotoxy
void gotoxy(short x, short y);
//funcion para cambiar el color del texto
void text_color( int col );
//matriz de adyacencia
int MatrizAdyacente[Max][Max];
//matriz de caminos o valorada
int MatrizCaminos[Max][Max];
//matriz de floyd y de warshall
int mat_floyd_warshall[Max][Max];
int visitado[Max];
int marcado[Max];

int transformar(string palabra){
    stringstream stream;

    int numero1;

    stringstream convert(palabra);
    convert>> numero1;
    return numero1;
}
class nodoGrafo {
   
   public:
    int vertice;
	nodoa *puntero;
	nodoGrafo *siguiente;
	//constructor
	nodoGrafo(int v, nodoGrafo *sig = NULL,nodoa *punt=NULL)
    {
       vertice = v;
       siguiente = sig;
	   puntero=punt;
    }
  // friend class listaa;
    friend class grafo;
};

typedef nodoGrafo *pnodoGrafo;

class grafo {      
   public:
	  
	   	   //listaa ad;
	   
	pnodoGrafo primero;
    //constructor
	grafo() { primero =  NULL; }// crea la lista vacia
	//metodos
	void Insertarv(int v); // insert
    void Borrarv(int v);// delete
    bool ListavVacia();  //empty
    void Mostrarv();// recorrer	 
	pnodoGrafo Buscarv( int v);// seek
    void BorrarListav(); //clear
    bool listavexiste(int i,int f); 
	void creararco(int i,int f,int peso);
	void CrearMatrizAdyacencia();
	int CantidadVertices();
	int ExisteArco(int i,int f);
	void mostrarmatriz();
	bool BuscarAdy(pnodoGrafo aux,int ad);
	void CrearMatrizCaminos();
	void MostrarMatrizCaminos();
	string RecorridoAnchura();
	int NodoVisitado(int v, int t);
	string RecorridoProfundidad();
	void Floyd();
	void Warshall();
	void copiarMatrizCaminos();
	void mostrar_mat_floyd_warshall();
	int Posicion(int v);
	bool marca(int ady ,int ident[Max],int i);
    void recorrer();
    void Conexiones();
    void Destinos();
	bool BuscarvVertice(int valor);
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void grafo::recorrer() {
	pnodoGrafo aux;
	aux = primero;
	while (aux != NULL) {
		cout << aux->vertice << endl;
		aux = aux->siguiente;
	}

}

void grafo::creararco(int i, int f, int peso) {
	pnodoGrafo pos;
	pos = primero;
	if (listavexiste(i, f)) {
		while (pos != NULL) { // se recorre la lista  hasta encontrar el valor buscado
			if (i == pos->vertice) {

				if (pos->puntero == NULL) {
					pos->puntero = new nodoa(f, peso);
				}
				else {
					nodoa *temp = pos->puntero;
					while (temp->siguiente != NULL) {
						temp = temp->siguiente;
					}
					temp->siguiente = new nodoa(f, peso);
					temp = NULL;
					delete temp;
				}
			}
			pos = pos->siguiente;
		}
		//cout << "Arco creado: " << i << "->" << f << " peso: " << peso << endl;
	}
	/*else {
		cout << "No se puede crear arco" << endl;
	}*/
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool grafo::listavexiste(int i, int f) {
	if (Buscarv(i) != NULL && Buscarv(f) != NULL) { return true; }
	else { return false; }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void grafo::Insertarv(int v)
{
	pnodoGrafo  anterior;
	if (ListavVacia()) // Si la lista esta vacia 
	{
		primero = new nodoGrafo(v, primero);
	}
	else {
		if (v <= primero->vertice) { //si el valor a insertar es menor que el  
			primero = new nodoGrafo(v, primero);            //se inserta el nodo antes del primer dato de la lista
		}
		else {
			//en caso contrario se busca el nodo que tenga un dato menor a valor 
			anterior = primero; // Avanzamos hasta que el siguiente tenga un valor mayor que valor 
			while ((anterior->siguiente) && (anterior->siguiente->vertice <= v)) {
				anterior = anterior->siguiente;
			}
			// Creamos un nuevo nodo despu�s del nodo anterior, y cuyo siguiente
			// es el siguiente del anterior
			anterior->siguiente = new nodoGrafo(v, anterior->siguiente);
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void grafo::Borrarv(int v)
{
	pnodoGrafo anterior, nodo;
	nodo = primero;
	anterior = NULL;
	if (primero) {  // si la lista tiene  datos se busca el nodo a borrar

		while ((nodo) && nodo->vertice != v) {// busca el dato igual al valor 
			anterior = nodo;
			nodo = nodo->siguiente;
		}
		if (!nodo) {// en este caso el valor buscado no esta en la lista   
			cout << "\n no exite en la lista";
		}
		else { // Borrar el nodo 
			if (anterior == NULL) //* Primer elemento
				primero = primero->siguiente;
			else  //* un elemento cualquiera 
				anterior->siguiente = nodo->siguiente;
			delete nodo; // se libera el nodo es decir se borra 
		}
	}
	else cout << "\n no hay elementos para borrar";
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void grafo::Mostrarv()
{
	pnodoGrafo nodo = primero;

	if (ListavVacia()) cout << "\nLista vac�a" << '\n'; // si hay datos para mostrar
	else {
		while (nodo) { // mientras tenga datos la lista
			cout << " vertice:\t"; text_color(8); cout << nodo->vertice; text_color(7); cout << "\tadyacentes";
			nodoa *temp = nodo->puntero;
			while (temp) {
				text_color(11); cout << "\t" << temp->ady/*<<"peso: "<<temp->peso*/;
				temp = temp->siguiente;

			}cout << endl << endl;
			nodo = nodo->siguiente; text_color(7);
		}
		cout << '\n';
	}
	text_color(7);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
pnodoGrafo grafo::Buscarv(int valor) {
	pnodoGrafo indice, n = NULL;
	indice = primero;
	while (indice != NULL) { // se recorre la lista  hasta encontrar el valor buscado
		if (valor == indice->vertice) {
			return indice; // al encontar el valor  lo retorna
		}
		indice = indice->siguiente;
	}
	//cout << "\nNo esta en la lista";
	return n; // si el valor buscado no esta en la lista retorna nulo
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool grafo::BuscarvVertice(int valor) {
	pnodoGrafo indice, n = NULL;
	indice = primero;
	while (indice != NULL) { // se recorre la lista  hasta encontrar el valor buscado
		if (valor == indice->vertice) {
			//cout << "Vertice repetido - No insertado" << endl;
			return true;//indice; // al encontar el valor  lo retorna
		}
		indice = indice->siguiente;
	}
	//cout << "\nNo esta en la lista";
	return false; // si el valor buscado no esta en la lista retorna nulo
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void grafo::BorrarListav() {
	pnodoGrafo nodo;
	while (primero) { //mientras la lista tenda datos los borra
		nodo = primero;
		primero = nodo->siguiente;
		delete nodo; // se libera la memoria de  cada nodo
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool grafo::ListavVacia() {
	return primero == NULL;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int grafo::CantidadVertices() {
	pnodoGrafo nodo = primero;
	int i = 0;
	while (nodo != NULL) {
		i++;
		nodo = nodo->siguiente;
	}
	return i;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void grafo::CrearMatrizAdyacencia() {
	pnodoGrafo nodo = primero, nodotemp;
	int i, j;// inicio, fin;
	int cant = CantidadVertices();
	for (i = 0; i < cant; i++) {
		nodotemp = primero;
		for (j = 0; j < cant; j++) {
			MatrizAdyacente[i][j] = ExisteArco(nodo->vertice, nodotemp->vertice);
			nodotemp = nodotemp->siguiente;
		}
		nodo = nodo->siguiente;
	}
	delete nodo;
	delete nodotemp;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int grafo::ExisteArco(int i, int f) {
	pnodoGrafo nodo;

	int a = 1;
	nodo = Buscarv(i);
	if (nodo) {
		if (BuscarAdy(nodo, f)) { return a; }
		else { return a = 0; }
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool grafo::BuscarAdy(pnodoGrafo aux, int ad) {
	nodoa *temp = aux->puntero;
	bool a;
	while (temp) {
		if (ad == temp->ady) {
			return a = true;
		}
		temp = temp->siguiente;
	} 
	return a = false;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void grafo::mostrarmatriz() {
	int i, j, cant;
	//char x = 236;
	pnodoGrafo nodo = primero;
	cant = CantidadVertices(); cout << "   ";
	for (i = 0; i < cant; i++) { text_color(11); cout << "\t" << nodo->vertice << " "; nodo = nodo->siguiente; }
	nodo = primero; cout << "\n\n";
	for (i = 0; i < cant; i++) {
		text_color(11); cout << nodo->vertice;
		for (j = 0; j < cant; j++) {
			text_color(7); cout << "\t" << MatrizAdyacente[i][j] << " ";
		}
		nodo = nodo->siguiente;
		cout << "\n";
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void grafo::CrearMatrizCaminos() {
	pnodoGrafo nodo = primero, nodotemp, nodoaux;
	nodoa *auxiliar;
	int i, j;// inicio, fin;
	int cant = CantidadVertices();
	for (i = 0; i < cant; i++) {
		nodotemp = primero;
		for (j = 0; j < cant; j++) {
			if (nodo->vertice == nodotemp->vertice) {
				MatrizCaminos[i][j] = 0;
			}
			else {
				if (ExisteArco(nodo->vertice, nodotemp->vertice) == 1) {
					nodoaux = Buscarv(nodo->vertice);
					auxiliar = nodoaux->puntero;
					while (auxiliar) {
						if (nodotemp->vertice == auxiliar->ady) {
							MatrizCaminos[i][j] = auxiliar->peso;
						}
						auxiliar = auxiliar->siguiente;
					}

				}
				else {
					MatrizCaminos[i][j] = INF;
				}
			}

			nodotemp = nodotemp->siguiente;
		}
		nodo = nodo->siguiente;
	}
	delete nodo;
	delete nodotemp;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void grafo::MostrarMatrizCaminos() {
	int i, j, cant;
	char x = 236;
	pnodoGrafo nodo = primero;
	cant = CantidadVertices(); cout << "   ";
	for (i = 0; i < cant; i++) { text_color(11); cout << "\t" << nodo->vertice << " "; nodo = nodo->siguiente; }
	nodo = primero; cout << "\n\n";
	for (i = 0; i < cant; i++) {
		text_color(11); cout << nodo->vertice << "  ";
		for (j = 0; j < cant; j++) {
			if (MatrizCaminos[i][j] == INF) {
				text_color(7); cout << "\t" << x << " ";
			}
			else {
				text_color(7); cout << "\t" << MatrizCaminos[i][j] << " ";
			}
		}
		nodo = nodo->siguiente;
		cout << "\n";
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
string grafo::RecorridoAnchura() {
	pnodoGrafo v;
	v = primero;
	cola c;
	string respuesta;
	nodoa *ady;
	ady = v->puntero;
	int i = 0, l;
	
	int marcado[10000];
	c.ingresar(v->vertice);

	//cout << v->vertice << endl;
	//respuesta+= v->vertice; //////
	marcado[i] = v->vertice;
	while (!c.colavacia()) {
		l = c.leer();


		//string s = to_string(l);
		//respuesta += ";"+ s + "\t"; 
	

		v = primero;
		while (v) {
			if (l == v->vertice) {
				ady = v->puntero;
				while (ady) {
					if (marca(ady->ady, marcado, i)) {
						c.ingresar(ady->ady);
		
						string y = to_string(ady->ady);
						cout << y << endl;
						respuesta +=  y+";"; ////
						marcado[i++] = ady->ady;
					}
					ady = ady->siguiente;

				}
			}
			v = v->siguiente;
		}
	}
	return respuesta;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int grafo::NodoVisitado(int v, int t){
  int i;
  for(i=0;i<t;i++){
     if(v==marcado[i]||v==visitado[i]){
        return 0;                  
     }               
  }
  return 1;    
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
string grafo::RecorridoProfundidad() {
	pnodoGrafo v;
	v = primero;
	pila pil;
	nodoa *ady;
	ady = v->puntero;
	int i = 0, l;
	string respuesta;
	
	int marcado[100];
	pil.push(v->vertice);
 
	cout << v->vertice;
	marcado[i] = v->vertice;
	while (!pil.pilavacia()) {
		l = pil.pop();

		
		v = primero;
		while (v) {
			if (l == v->vertice) {
				ady = v->puntero;
				while (ady) {
					if (marca(ady->ady, marcado, i)) {
						pil.push(ady->ady);
						string y = to_string(ady->ady);
						cout << y << endl;
						respuesta += y + ";"; ////
						marcado[i++] = ady->ady;
					}ady = ady->siguiente;

				}
			}
			v = v->siguiente;
		}

	}
	return respuesta;

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void grafo::Floyd() {
	int k, i, j, cant = CantidadVertices();
	copiarMatrizCaminos();
	for (k = 0; k < cant; k++) {
		for (i = 0; i < cant; i++) {
			for (j = 0; j < cant; j++) {
				if (mat_floyd_warshall[i][j] > mat_floyd_warshall[i][k] + mat_floyd_warshall[k][j]) {
					mat_floyd_warshall[i][j] = mat_floyd_warshall[i][k] + mat_floyd_warshall[k][j];
				}//fin si
			}//fin for j
		}//fin for i
	}//fin for k
	mostrar_mat_floyd_warshall();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void grafo::Warshall() {
	int k, i, j, cant = CantidadVertices();
	copiarMatrizCaminos();
	for (k = 0; k < cant; k++) {
		for (i = 0; i < cant; i++) {
			for (j = 0; j < cant; j++) {
				if (!mat_floyd_warshall[i][j] && (mat_floyd_warshall[i][k] && mat_floyd_warshall[k][j])) {
					mat_floyd_warshall[i][j] = mat_floyd_warshall[i][j] || (mat_floyd_warshall[i][k] && mat_floyd_warshall[k][j]);
				}//fin si
			}//fin for j
		}//fin for i
	}//fin for k
	mostrar_mat_floyd_warshall();

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void grafo::copiarMatrizCaminos() {
	int i, j, cant = CantidadVertices();
	CrearMatrizCaminos();
	for (i = 0; i < cant; i++) {
		for (j = 0; j < cant; j++) {
			mat_floyd_warshall[i][j] = MatrizCaminos[i][j];
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void grafo::mostrar_mat_floyd_warshall() {
	int i, j, cant = CantidadVertices();
	pnodoGrafo nodo = primero;
	char x = 236;
	for (i = 0; i < cant; i++) { text_color(8); cout << "\t" << nodo->vertice << " "; nodo = nodo->siguiente; }
	nodo = primero; cout << "\n\n";
	for (i = 0; i < cant; i++) {
		text_color(8); cout << nodo->vertice;
		for (j = 0; j < cant; j++) {
			if (mat_floyd_warshall[i][j] == INF) {
				text_color(7); cout << "\t" << x;
			}
			else {
				text_color(7); cout << "\t" << mat_floyd_warshall[i][j];
			}
		}cout << "\n";
		nodo = nodo->siguiente;
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// funcion gotoxy
void gotoxy(short x, short y) {
	HANDLE hConsoleOutput;
	COORD Cursor_Pos = { x, y };

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void text_color( int col ){
     HANDLE hOutput = NULL;
    if( hOutput == NULL )
        hOutput = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOutput, (WORD) col );
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int grafo::Posicion(int v) {
	pnodoGrafo nodo = primero;
	int i = 0;
	while (nodo) {
		if (nodo->vertice == v) {
			return i - 1;
		}
		i++;
		nodo = nodo->siguiente;
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool grafo::marca(int ady, int ident[Max], int i) {
	bool s;

	for (int f = 0; f < i; f++) {
		if (ady == ident[f]) {
			return s = false;
		}

	}
	return s = true;
}

void grafo::Destinos() {

	fstream ficheroEntrada;
	string frase;
	string caracter;
	string palabra;
	int idDestino;
	string nombre;
	int cont = 1;

	ficheroEntrada.open("C:/Users/carlo/Desktop/Proyectos y Tareas C++/Proyecto_3/Destinos_2.txt", ios::in);
	if (ficheroEntrada.is_open()) {
		while (!ficheroEntrada.eof()) {
			getline(ficheroEntrada, frase);
			int largo = frase.size();
			for (int i = 0; i <= largo; i++) {
				caracter = frase[i];
				if (caracter != ";") {
					palabra += caracter;
				}
				else {
					switch (cont) {
					case 1:
						idDestino = transformar(palabra);
						break;

					}
					cont++;
					palabra = "";
				}
			}
			cont = 1;
			nombre = palabra;
			palabra = "";
			if (Buscarv(idDestino) == NULL)
				Insertarv(idDestino);

		}
		ficheroEntrada.close();
	}
}




