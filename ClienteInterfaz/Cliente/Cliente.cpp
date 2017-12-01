#include "Socket_Cliente.h"
#include <iostream>
#include <locale.h>

//using namespace std;
//Declaracion del socket como global
ClienteSocket * sockets;
//

//Declaracion del string mensaje
std::string mensaje = "";
std::string respuestaServer = "";
//

//FUNCIONES
void menuPrincipal();
void gotoFuncion(std::string seleccion);
void ConsultarPrecioProducto();
void MostrarArbol();
void ConsultarViajeHotelTransporteDeUnCliente();
void ConsultarOrigenDestidoDeUnViaje();
void ConsultarInformacionDeUnCliente();
void ConsultarCategoriaDeUnHotel();
void ConsultarPrecioViajeHotelTransporteDeUnCliente();
void RealizarReservacion(); // Viaje
void ConsultarPaquetesDeUnViaje();
void salir();
//FIN FUNCIONES




void gotoFuncion(std::string seleccion) {
	setlocale(LC_ALL, "spanish");
	int opcion = atoi(seleccion.c_str());
	//cout << "Opcion: " << opcion << endl;
	switch (opcion)
	{
	case 0: ConsultarPrecioProducto(); break;
	case 1: MostrarArbol(); break;
	case 2: ConsultarViajeHotelTransporteDeUnCliente(); break;
	case 3: ConsultarOrigenDestidoDeUnViaje(); break;
	case 4: ConsultarInformacionDeUnCliente(); break;
	case 5: ConsultarCategoriaDeUnHotel(); break;
	case 6: ConsultarPrecioViajeHotelTransporteDeUnCliente(); break;
	case 7: RealizarReservacion(); break; //Viajes
	case 8: ConsultarPaquetesDeUnViaje(); break;
	case 9: salir(); break;
	default:
		//cout << "Error en la seleccion. Intentelo" << endl;
		//menuPrincipal();
		break;

	}
	
}









//FUNCIONES
// 0

void ConsultarPrecioProducto() {

	std::string eleccion= "";
	/*
	cout << "\n- Indique el tipo del producto:" << endl;
	cout << " [0] - Viaje." << endl;
	cout << " [1] - Hotel." << endl;
	cout << " [2] - Transporte." << endl;
	cin >> eleccion;
	*/

	if (eleccion == "0") {
		std::string opcionViaje;

		//cout << "\n- Ingrese el ID-Viaje correspondiente:" << endl;
		//cin >> opcionViaje;

		//Primer 0 es del menu para ingresar a ConsultarPrecioProducto.El segundo 0 es el menu interno


		mensaje = "000" + opcionViaje; // el 01 es el codigo de la funcion que quiero hacer en el servidor
		sockets->enviar(mensaje);
		respuestaServer = sockets->respuesta();


		std::string resultadoBool= "";
		std::string respuesta= "";

		int i = 0;
		while(respuestaServer[i] != ','){
			resultadoBool += respuestaServer[i];
			i++;
		}

		i += 1;
	
		while(respuestaServer[i] != false){
			respuesta += respuestaServer[i];
			i++;
		}
	
	


		if (resultadoBool == "true") {

			//cout << respuesta << endl;
		}

		else {
			//cout << respuesta << endl;
		}
	}
	else {
		if (eleccion == "1") {
			std::string opcionHotel;

			//cout << "\n- Ingrese el ID-Hotel correspondiente:" << endl;
			//cin >> opcionHotel;

			mensaje = "001"+opcionHotel; // el 01 es el codigo de la funcion que quiero hacer en el servidor
			sockets->enviar(mensaje);
			respuestaServer = sockets->respuesta();

			std::string resultadoBool= "";
			std::string respuesta= "";

			int i = 0;
			while(respuestaServer[i] != ','){
				resultadoBool += respuestaServer[i];
				i++;
			}

			i += 1;
	
			while(respuestaServer[i] != false){
				respuesta += respuestaServer[i];
				i++;
			}
			

			if (resultadoBool == "true") {

				//cout << respuesta << endl;
			}

			else {
				//cout << respuesta << endl;
			}
		}
		else {
			if (eleccion == "2") {
				std::string opcionTransporte;

				//cout << "\n- Ingrese el ID-Transporte correspondiente: " << endl;
				//cin >> opcionTransporte;

				mensaje = "002" + opcionTransporte; // el 01 es el codigo de la funcion que quiero hacer en el servidor
				sockets->enviar(mensaje);
				respuestaServer = sockets->respuesta();

				std::string resultadoBool = "";
				std::string respuesta = "";

				int i = 0;
				while (respuestaServer[i] != ',') { //True or False
					resultadoBool += respuestaServer[i];
					i++;
				}

				i += 1;

				while (respuestaServer[i] != false) {
					respuesta += respuestaServer[i];
					i++;
				}

				if (resultadoBool == "true") {

					//cout << respuesta << endl;
				}

				else {
					//cout << respuesta << endl;
				}

			}else { //cout << "Opcion no valida" << endl; 
			
			}
		
		}
		
		}
	//menuPrincipal();

	}

		

// 1
void MostrarArbol() {
	std::string eleccion;
	/*
	cout << "\n- Ingrese el tipo de producto para mostrar:" << endl;
	cout << " [0] - Viajes." << endl;
	cout << " [1] - Hoteles." << endl;
	cout << " [2] - Transportes." << endl;
	cin >> eleccion;
	*/
	if (eleccion == "0") {
		mensaje = "01"+eleccion; // el 01 es el codigo de la funcion que quiero hacer en el servidor
		sockets->enviar(mensaje);
		respuestaServer = sockets->respuesta();
		std::string resultadoBool = "";
		std::string respuesta = "";

		int i = 0;
		while (respuestaServer[i] != ',') {
			resultadoBool += respuestaServer[i];
			i++;
		}

		i += 1;

		while (respuestaServer[i] != false) {
			respuesta += respuestaServer[i];
			i++;
		}

		if (resultadoBool == "true") {

			//cout << respuesta << endl;
		}

		else {
			//cout << respuesta << endl;
		}
		

	}
	else {
		if (eleccion == "1") {

			mensaje = "01"+ eleccion; // el 01 es el codigo de la funcion que quiero hacer en el servidor
			sockets->enviar(mensaje);
			respuestaServer = sockets->respuesta();

			std::string resultadoBool = "";
			std::string respuesta = "";

			int i = 0;
			while (respuestaServer[i] != ',') {
				resultadoBool += respuestaServer[i];
				i++;
			}

			i += 1;

			while (respuestaServer[i] != false) {
				respuesta += respuestaServer[i];
				i++;
			}

			if (resultadoBool == "true") {

				//cout << respuesta << endl;
			}

			else {
				//cout << respuesta << endl;
			}

		}
		else {
			if (eleccion == "2") {

				mensaje = "01"+eleccion; // el 01 es el codigo de la funcion que quiero hacer en el servidor
				sockets->enviar(mensaje);
				respuestaServer = sockets->respuesta();

				std::string resultadoBool = "";
				std::string respuesta = "";

				int i = 0;
				while (respuestaServer[i] != ',') {
					resultadoBool += respuestaServer[i];
					i++;
				}

				i += 1;

				while (respuestaServer[i] != false) {
					respuesta += respuestaServer[i];
					i++;
				}

				if (resultadoBool == "true") {

					//cout << respuesta << endl;
				}

				else {
					//cout << respuesta << endl;
				}

			}
			else { //cout << "Opción inválida" << endl;
			
			}

				
			
		}
	}
	menuPrincipal();
}


// 2
void ConsultarViajeHotelTransporteDeUnCliente() {
	std::string opcionConsulta;
	/*
	cout << "\n- Tipo de consulta ?" << endl;
	cout << " [0] - Viaje." << endl;
	cout << " [1] - Hotel." << endl;
	cout << " [2] - Transporte." << endl;

	cin >> opcionConsulta;
	*/
	if (opcionConsulta == "0") {
		std::string opcionIdCliente;

		//cout << "\n- Ingrese el ID-Cliente correspondiente:" << endl;
		//cin >> opcionIdCliente;

		mensaje = "020" + opcionIdCliente; // el 01 es el codigo de la funcion que quiero hacer en el servidor
		sockets->enviar(mensaje);
		respuestaServer = sockets->respuesta();


		std::string resultadoBool= "";
		std::string respuesta= "";

		int i = 0;
		while(respuestaServer[i] != ','){
			resultadoBool += respuestaServer[i];
			i++;
		}

		i += 1;
	
		while(respuestaServer[i] != false){
			respuesta += respuestaServer[i];
			i++;
		}


		if (resultadoBool == "true") {

			//cout <<  respuesta << endl;
		}

		else {
			//cout << respuesta << endl;
		}

		
	}
	else {
		if (opcionConsulta == "1") {
			std::string opcionIdCliente;
			//cout << "\n- Ingrese el ID-Cliente correspondiente:" << endl;
			//cin >> opcionIdCliente;

			mensaje = "021" + opcionIdCliente; // el 01 es el codigo de la funcion que quiero hacer en el servidor
			sockets->enviar(mensaje);
			respuestaServer = sockets->respuesta();


			std::string resultadoBool= "";
			std::string respuesta= "";

			int i = 0;
			while(respuestaServer[i] != ','){
				resultadoBool += respuestaServer[i];
				i++;
			}

			i += 1;
	
			while(respuestaServer[i] != false){
				respuesta += respuestaServer[i];
				i++;
			}
	
	


			if (resultadoBool == "true") {

				//cout <<  respuesta << endl;
			}

			else {
				//cout << respuesta << endl;
			}
		}

		else {
			if (opcionConsulta == "2") {
				std::string opcionPCliente;
				//cout << "\n- Ingrese el ID-Cliente correspondiente:" << endl;
				//cin >> opcionPCliente;

				mensaje = "022" +opcionPCliente; 
				sockets->enviar(mensaje);
				respuestaServer = sockets->respuesta();


				std::string resultadoBool = "";
				std::string respuesta = "";

				int i = 0;
				while (respuestaServer[i] != ',') {
					resultadoBool += respuestaServer[i];
					i++;
				}

				i += 1;

				while (respuestaServer[i] != false) {
					respuesta += respuestaServer[i];
					i++;
				}




				if (resultadoBool == "true") {

					//cout << respuesta << endl;
				}

				else {
					//cout << respuesta << endl;
				}
			}
			else {
				//cout << "\n- Opción inválida" << endl;
			
			}
		}

	}
	menuPrincipal();
}


// 3
void ConsultarOrigenDestidoDeUnViaje() {
	std::string opcionViaje;

	//cout << "\n- Ingrese el ID-Viaje correspondiente:" << endl;
	//cin >> opcionViaje;

	mensaje = "03"+ opcionViaje;
	sockets->enviar(mensaje);
	respuestaServer = sockets->respuesta();

	std::string resultadoBool = "";
	std::string respuesta = "";

	int i = 0;
	while (respuestaServer[i] != ',') {
		resultadoBool += respuestaServer[i];
		i++;
	}

	i += 1;

	while (respuestaServer[i] != false) {
		respuesta += respuestaServer[i];
		i++;
	}

	if (resultadoBool == "true") {

		//cout << respuesta << endl;
	}

	else {
		//cout << respuesta << endl;
	}
	menuPrincipal();

}


// 4
void ConsultarInformacionDeUnCliente() {
	std::string opcionCliente;
	int pCliente = 0;

	//cout << "\n- Ingrese el ID-Cliente correspondiente: " << endl;
	//cin >> opcionCliente;
	mensaje = "04" + opcionCliente;
	sockets->enviar(mensaje);
	respuestaServer = sockets->respuesta();

	std::string resultadoBool = "";
	std::string respuesta = "";

	int i = 0;
	while (respuestaServer[i] != ',') {
		resultadoBool += respuestaServer[i];
		i++;
	}

	i += 1;

	while (respuestaServer[i] != false) {
		respuesta += respuestaServer[i];
		i++;
	}

	if (resultadoBool == "true") {

		//cout << respuesta << endl;
	}

	else {
		//cout << respuesta << endl;
	}

	menuPrincipal();
	
}


//5
void ConsultarCategoriaDeUnHotel() {
	std::string opcionHotel;

	//cout << "\n- Ingrese el ID-Hotel correspondiente:" << endl;
	//cin >> opcionHotel;

	mensaje = "05" + opcionHotel;
	sockets->enviar(mensaje);
	respuestaServer = sockets->respuesta();

	std::string resultadoBool = "";
	std::string respuesta = "";

	int i = 0;
	while (respuestaServer[i] != ',') {
		resultadoBool += respuestaServer[i];
		i++;
	}

	i += 1;

	while (respuestaServer[i] != false) {
		respuesta += respuestaServer[i];
		i++;
	}

	if (resultadoBool == "true") {

		//cout << respuesta << endl;
	}

	else {
		//cout << respuesta << endl;
	}

	menuPrincipal();
}


//6
void ConsultarPrecioViajeHotelTransporteDeUnCliente() {
	bool tieneViaje = false;
	std::string precioTemp; int precioViaje = 0; int precioHotel = 0; int precioTransporte = 0;
	std::string opcionCliente;

	//cout << "\n- Ingrese el ID-Cliente: " << endl;
	//cin >> opcionCliente;

	mensaje = "06" + opcionCliente;
	sockets->enviar(mensaje);
	respuestaServer = sockets->respuesta();

	std::string resultadoBool = "";
	std::string respuesta = "";

	int i = 0;
	while (respuestaServer[i] != ',') {
		resultadoBool += respuestaServer[i];
		i++;
	}

	i += 1;

	while (respuestaServer[i] != false) {
		respuesta += respuestaServer[i];
		i++;
	}

	if (resultadoBool == "true") {

		//cout << respuesta << endl;
	}

	else {
		//cout << respuesta << endl;
	}

	menuPrincipal();
}

// 7
void RealizarReservacion() {

	std::string opcionReservacion;/*
	cout << "\n- Indique el tipo de reservacion:\n" << endl;
	cout << "[0] - Viaje." << endl;
	cout << "[1] - Hotel." << endl;
	cout << "[2] - Transporte." << endl;
	cin >> opcionReservacion;
	*/
	//---------Viaje-----------
	if (opcionReservacion == "0") {
		std::string opcionIDCliente;
		//cout << "\n- Ingrese el ID-Cliente:" << endl;
		//cin >> opcionIDCliente;

		mensaje = "07" + opcionIDCliente;
		sockets->enviar(mensaje);
		respuestaServer = sockets->respuesta();

		std::string resultadoBool = "";
		std::string respuesta = "";

		int i = 0;
		while (respuestaServer[i] != ',') {
			resultadoBool += respuestaServer[i];
			i++;
		}

		i += 1;

		while (respuestaServer[i] != false) {
			respuesta += respuestaServer[i];
			i++;
		}

		if (resultadoBool == "true") {

			//cout << respuesta << endl;

			std::string opcionViaje;
			//cout << "\n- Ingrese el ID-Viaje que desea reservar:" << endl;
			//cin >> opcionViaje;

			mensaje = "08" + opcionViaje;
			sockets->enviar(mensaje);
			respuestaServer = sockets->respuesta();

			resultadoBool = "";
			respuesta = "";

			int i = 0;
			while (respuestaServer[i] != ',') {
				resultadoBool += respuestaServer[i];
				i++;
			}

			i += 1;

			while (respuestaServer[i] != false) {
				respuesta += respuestaServer[i];
				i++;
			}

			if (resultadoBool == "true") {

				//cout << respuesta << endl;
				std::string opcionPlazas;
				//cout << "\n- Ingrese la cantidad de plazas a reservar:" << endl;
				//cin >> opcionPlazas;
				mensaje = "09" + opcionPlazas + "," + opcionIDCliente + "," + opcionViaje;
				sockets->enviar(mensaje);
				respuestaServer = sockets->respuesta();

				std::string resultadoBool = "";
				std::string respuesta = "";

				int i = 0;
				while (respuestaServer[i] != ',') {
					resultadoBool += respuestaServer[i];
					i++;
				}

				i += 1;

				while (respuestaServer[i] != false) {
					respuesta += respuestaServer[i];
					i++;
				}

				if (resultadoBool == "true") {

					//cout << respuesta << endl;
				}

				else {
					//cout << respuesta << endl;
				}

			}

			else {
				//cout << respuesta << endl;
			}

		}

		else {
			//cout << respuesta << endl;
		}

	}
	else {

		if (opcionReservacion == "1") {

			std::string opcionCliente;
			//cout << "\n- Ingrese el ID-Cliente:" << endl;
			//cin >> opcionCliente;

			mensaje = "14" + opcionCliente;
			sockets->enviar(mensaje);
			respuestaServer = sockets->respuesta();

			std::string resultadoBool = "";
			std::string respuesta = "";

			int i = 0;
			while (respuestaServer[i] != ',') {
				resultadoBool += respuestaServer[i];
				i++;
			}

			i += 1;

			while (respuestaServer[i] != false) {
				respuesta += respuestaServer[i];
				i++;
			}

			if (resultadoBool == "true") {

				//cout << respuesta << endl;
				std::string opcionHotel;
				//cout << "\n- Ingrese el ID-Hotel que se desea reservar:" << endl;
				//cin >> opcionHotel;

				mensaje = "15" +opcionCliente +"," + opcionHotel;
				sockets->enviar(mensaje);
				respuestaServer = sockets->respuesta();

				std::string resultadoBool = "";
				std::string respuesta = "";

				int i = 0;
				while (respuestaServer[i] != ',') {
					resultadoBool += respuestaServer[i];
					i++;
				}

				i += 1;

				while (respuestaServer[i] != false) {
					respuesta += respuestaServer[i];
					i++;
				}

				if (resultadoBool == "true") {

					//cout << respuesta << endl;
					std::string tipoHab;/*
					cout << "\n- Tipo de habitacion:" << endl;
					cout << " [0] - Habitacion individual." << endl;
					cout << " [1] - Habitacion doble." << endl;
					cin >> tipoHab;
					*/
					mensaje = "16" +tipoHab;
					sockets->enviar(mensaje);
					respuestaServer = sockets->respuesta();

					std::string resultadoBool = "";
					std::string respuesta = "";

					int i = 0;
					while (respuestaServer[i] != ',') {
						resultadoBool += respuestaServer[i];
						i++;
					}

					i += 1;

					while (respuestaServer[i] != false) {
						respuesta += respuestaServer[i];
						i++;
					}

					if (resultadoBool == "true") {


						//cout << respuesta << endl;
						std::string opcionOferta;
						
						//cout << " [0] - Si." << endl;
						//cout << " [1] - No." << endl;
						//cin >> opcionOferta;

						mensaje = "17"+opcionCliente+","+opcionOferta;
						sockets->enviar(mensaje);
						respuestaServer = sockets->respuesta();

						std::string resultadoBool = "";
						std::string respuesta = "";

						int i = 0;
						while (respuestaServer[i] != ',') {
							resultadoBool += respuestaServer[i];
							i++;
						}

						i += 1;

						while (respuestaServer[i] != false) {
							respuesta += respuestaServer[i];
							i++;
						}

						if (resultadoBool == "true") {

							//cout << respuesta << endl;




						}
						else {
							//cout << respuesta << endl;
						}

				

					}

					else {
						//cout << respuesta << endl;
					}

				}

				else {
					//cout << respuesta << endl;
				}

			}

			else {
				//cout << respuesta << endl;
			}

		
		}
		else {
			if (opcionReservacion == "2") {
				std::string opcionCliente;
				//cout << "\n- Ingrese el ID-Cliente:" << endl;
				//cin >> opcionCliente;


				mensaje = "10" + opcionCliente;
				sockets->enviar(mensaje);
				respuestaServer = sockets->respuesta();

				std::string resultadoBool = "";
				std::string respuesta = "";

				int i = 0;
				while (respuestaServer[i] != ',') {
					resultadoBool += respuestaServer[i];
					i++;
				}

				i += 1;

				while (respuestaServer[i] != false) {
					respuesta += respuestaServer[i];
					i++;
				}

				if (resultadoBool == "true") {

					//cout << respuesta << endl;
					std::string opcionTransporte;
					//cout << "\n- Ingrese el ID-Transporte que se desea reservar:" << endl;
					//cin >> opcionTransporte;



					mensaje = "11" + opcionCliente + "," + opcionTransporte;
					sockets->enviar(mensaje);
					respuestaServer = sockets->respuesta();

					std::string resultadoBool = "";
					std::string respuesta = "";

					int i = 0;
					while (respuestaServer[i] != ',') {
						resultadoBool += respuestaServer[i];
						i++;
					}

					i += 1;

					while (respuestaServer[i] != false) {
						respuesta += respuestaServer[i];
						i++;
					}

					if (resultadoBool == "true") {
						//cout << respuesta << endl;
					}
					else {
						//cout << respuesta << endl;
					}



				}
				else {
					//cout << respuesta << endl;
				}

			}
			else {
				//cout << "La opción dada no es válida" << endl;

			}
		}
		

	}

	menuPrincipal();
}
















// 8
void ConsultarPaquetesDeUnViaje() {
	std::string opcionViaje;

	//cout << "\n- Ingrese el ID-Viaje correspondente:" << endl;
	//cin >> opcionViaje;

	mensaje = "12" + opcionViaje; 
	sockets->enviar(mensaje);
	respuestaServer = sockets->respuesta();

	std::string resultadoBool = "";
	std::string respuesta = "";

	int i = 0;
	while (respuestaServer[i] != ',') {
		resultadoBool += respuestaServer[i];
		i++;
	}

	i += 1;

	while (respuestaServer[i] != false) {
		respuesta += respuestaServer[i];
		i++;
	}

	if (resultadoBool == "true") {

		//cout << respuesta << endl;
	}

	else {
		//cout << respuesta << endl;
	}
	menuPrincipal();
}



// 9
void salir() {
	mensaje = "13";
	sockets->enviar(mensaje);
	respuestaServer = sockets->respuesta();
	std::string respuesta;

	int i = 0;
	while (respuestaServer[i] != ',') {
		i++;
	}
	i += 1;

	while (respuestaServer[i] != ',') {
		respuesta += respuestaServer[i];
		i++;
	}

	//cout << respuesta << endl;
}




void menuPrincipal() {
	/*
	setlocale(LC_ALL, "spanish");
	cout << "\n-------------------Bienvenido al Sistema de Reservaciones!-------------------\n" << endl;

	cout << "[0] - Consultar precio de un producto." << endl; //Viaje, Hotel o Transporte
	cout << "[1] - Mostrar hoteles, viajes o transportes." << endl; //Mostrar los arboles
	cout << "[2] - Consultar el viaje de un cliente, su transporte o su hotel." << endl; //Ver descripcion
	cout << "[3] - Consultar el origen y el destino de un viaje." << endl;
	cout << "[4] - Consultar la informacion de un cliente." << endl;
	cout << "[5] - Consultar la categoria de un hotel." << endl;
	cout << "[6] - Precio a pagar por el viaje." << endl;
	cout << "[7] - Realizar reservacion." << endl;  //Viaje, hotel y transporte
	cout << "[8] - Paquetes disponibles de un viaje." << endl;
	cout << "[9] - Salir del sistema." << endl;
	cout << "\n- Que desea realizar?" << endl;
	string seleccion = "";
	cin >> seleccion;
	gotoFuncion(seleccion);
	*/
}


int main() {
	sockets = new ClienteSocket();			//Inicializacion del socket	
	sockets->respuesta();			//Inicializacion del socket
	menuPrincipal();
	system("pause");
	return 0;
}