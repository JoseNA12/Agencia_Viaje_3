#include<iostream>
#include<string>

using namespace std;

class NodoArbolB
{
	public:
		
		NodoArbolB(int Numero, string pIdCliente, string pNombre, string pApellido, string pCiudad, string pTelefono){
			numero = Numero;
			idCliente = pIdCliente;
			nombre = pNombre;
			apellido = pApellido;
			ciudad = pCiudad;
			telefono = pTelefono;
			siguiente = NULL;
			anterior = NULL;
			
			izq = NULL;
			der = NULL;
		}
		
	//private:
		
		int numero;
		string idCliente;
		string nombre;
		string apellido;
		string ciudad;
		string telefono;
		
		NodoArbolB *siguiente;
		NodoArbolB *anterior;
		NodoArbolB *izq;
		NodoArbolB *der;
		
	friend class Pagina;
	friend class ArregloClaves;	
	friend class ArbolB;
};

typedef NodoArbolB *pNodoB;
