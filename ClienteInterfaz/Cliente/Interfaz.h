#include <iostream>
#include <locale.h>
#include "Socket_Cliente.h"
#include <msclr\marshal_cppstd.h> //Convertir: string -> System::String


//Declaracion del socket como global
ClienteSocket * sockets;
int opcionEnviarRespuesta;
std::string IDPais_Origen = "";
std::string IDPais_Llegada = "";
//

//Declaracion del string mensaje
std::string mensaje = "";
std::string respuestaServer = "";


//FUNCIONES
std::string ConsultarPrecioProducto_Viaje(std::string opcionViaje);
std::string ConsultarPrecioProducto_Hotel(std::string opcionHotel);
std::string ConsultarPrecioProducto_Transporte(std::string opcionTransporte);
std::string MostrarViajes();
std::string MostrarHoteles();
std::string MostrarTransportes();
std::string ConsultarOrigenDestidoDeUnViaje(std::string opcionViaje);
std::string ConsultarPaquetesDeUnViaje(std::string opcionViaje);
std::string ConsultarCategoriaDeUnHotel(std::string opcionHotel);
std::string ConsultarInformacionDeUnCliente(std::string opcionCliente);
std::string ConsultarPaquetesDeUnViaje(std::string opcionViaje);
std::string ConsultarViaje_Cliente(std::string opcionIdCliente);
std::string ConsultarHotel_Cliente(std::string opcionIdCliente);
std::string ConsultarTransporte_Cliente(std::string opcionIdCliente);
std::string ConsultarPrecioViajeHotelTransporte_Cliente(std::string opcionCliente);

//FIN FUNCIONES


//----DEFINICION DE FUNCIONES----

// 0

std::string ConsultarPrecioProducto_Viaje(std::string opcionViaje) {

	//cout << "\n- Ingrese el ID-Viaje correspondiente:" << endl;
	//cin >> opcionViaje;

	mensaje = "000" + opcionViaje; // el 01 es el codigo de la funcion que quiero hacer en el servidor
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
		return respuesta;
	}

	else {
		return respuesta;
	}
}

std::string ConsultarPrecioProducto_Hotel(std::string opcionHotel) {

	//cout << "\n- Ingrese el ID-Viaje correspondiente:" << endl;
	//cin >> opcionViaje;

	mensaje = "001" + opcionHotel; // el 01 es el codigo de la funcion que quiero hacer en el servidor
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
		return respuesta;
	}

	else {
		return respuesta;
	}
}

std::string ConsultarPrecioProducto_Transporte(std::string opcionTransporte) {

	//cout << "\n- Ingrese el ID-Viaje correspondiente:" << endl;
	//cin >> opcionViaje;

	mensaje = "002" + opcionTransporte; // el 01 es el codigo de la funcion que quiero hacer en el servidor
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
		return respuesta;
	}

	else {
		return respuesta;
	}
}

// 1
std::string MostrarViajes() {

	mensaje = "010"; // el 01 es el codigo de la funcion que quiero hacer en el servidor
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

		return respuesta;
	}

	else {
		return respuesta;
	}
}

std::string MostrarHoteles() {

	mensaje = "011"; // el 01 es el codigo de la funcion que quiero hacer en el servidor
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

		return respuesta;
	}

	else {
		return respuesta;
	}
}

std::string MostrarTransportes() {

	mensaje = "012"; // el 01 es el codigo de la funcion que quiero hacer en el servidor
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

		return respuesta;
	}

	else {
		return respuesta;
	}
}

// 2
std::string ConsultarViaje_Cliente(std::string opcionIdCliente) {

	mensaje = "020" + opcionIdCliente; // el 01 es el codigo de la funcion que quiero hacer en el servidor
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
		return respuesta;
	}

	else {
		return respuesta;
	}
}

std::string ConsultarHotel_Cliente(std::string opcionIdCliente) {

	mensaje = "021" + opcionIdCliente; // el 01 es el codigo de la funcion que quiero hacer en el servidor
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
		return respuesta;
	}

	else {
		return respuesta;
	}
}

std::string ConsultarTransporte_Cliente(std::string opcionIdCliente) {

	mensaje = "022" + opcionIdCliente; // el 01 es el codigo de la funcion que quiero hacer en el servidor
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
		return respuesta;
	}

	else {
		return respuesta;
	}
}


// 3
std::string ConsultarOrigenDestidoDeUnViaje(std::string opcionViaje) {

	mensaje = "03" + opcionViaje;
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
		return respuesta;
	}

	else {
		return respuesta;
	}
}


// 4
std::string ConsultarInformacionDeUnCliente(std::string opcionCliente) {
	
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
		return respuesta;
	}

	else {
		return respuesta;
	}
}


//5
std::string ConsultarCategoriaDeUnHotel(std::string opcionHotel) {

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
		return respuesta;
	}

	else {
		return respuesta;
	}
}


//6
std::string ConsultarPrecioViajeHotelTransporte_Cliente(std::string opcionCliente) {

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
		return respuesta;
	}

	else {
		return respuesta;
	}
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

				mensaje = "15" + opcionCliente + "," + opcionHotel;
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
					mensaje = "16" + tipoHab;
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

						mensaje = "17" + opcionCliente + "," + opcionOferta;
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

	//menuPrincipal();
}

std::string ReservarViaje(std::string opcionIDCliente, std::string opcionViaje, std::string opcionPlazas) {

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

		//std::string opcionViaje;
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

			//std::string opcionPlazas;
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
				return respuesta;
			}

			else {
				return respuesta;
			}

		}

		else {
			return respuesta;
		}

	}

	else {
		return respuesta;
	}
}

std::string ReservarHotel(std::string opcionCliente, std::string opcionHotel, std::string tipoHab, std::string opcionOferta) {

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

		mensaje = "15" + opcionCliente + "," + opcionHotel;
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

			mensaje = "16" + tipoHab;
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

				mensaje = "17" + opcionCliente + "," + opcionOferta;
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

					return respuesta;
				}
				else {
					return respuesta;
				}
			}

			else {
				return respuesta;
			}
		}

		else {
			return respuesta;
		}
	}

	else {
		return respuesta;
	}
	
}

std::string ReservarTransporte(std::string opcionCliente, std::string opcionTransporte){

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
			return respuesta;
		}
		else {
			return respuesta;
		}
	}
	else {
		return respuesta;
	}

}

// 8
std::string ConsultarPaquetesDeUnViaje(std::string opcionViaje) {
	

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
		return respuesta;
	}

	else {
		return respuesta;
	}
}


std::string MarshalString(System::String ^ s, std::string& os) {
	using namespace System::Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(System::IntPtr((void*)chars));

	return os;
}


std::string ConsultarViajesDestinosDisponibles(std::string idDestino) {

	mensaje = "18" + idDestino;
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
		return respuesta;
	}

	else {
		return respuesta;
	}
}

//-----------------------------------------------INTERFAZ-----------------------------------------------//


#pragma once

namespace Cliente {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Interfaz
	/// </summary>
	public ref class Interfaz : public System::Windows::Forms::Form
	{
	public:
		Interfaz(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Interfaz()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  barraMenu;
	protected:

	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  ArchivoMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  InfoMenu;
	private: System::Windows::Forms::PictureBox^  LogoVentana;

	private: System::Windows::Forms::Label^  label1;



	private: System::Windows::Forms::ToolStripMenuItem^  toolProductos;
	private: System::Windows::Forms::ToolStripMenuItem^  Mostrar;
	private: System::Windows::Forms::ToolStripMenuItem^  toolViajesMostrar;
	private: System::Windows::Forms::ToolStripMenuItem^  toolHotelesMostrar;
	private: System::Windows::Forms::ToolStripMenuItem^  toolTransportesMostrar;

	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^  toolViajePrecio;
	private: System::Windows::Forms::ToolStripMenuItem^  toolHotelPrecio;
	private: System::Windows::Forms::ToolStripMenuItem^  toolTransportePrecio;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem6;
	private: System::Windows::Forms::ToolStripMenuItem^  toolViajeOrigenDestino;

	private: System::Windows::Forms::ToolStripMenuItem^  toolPaquetes;
	private: System::Windows::Forms::ToolStripMenuItem^  toolViajePaquetes;
	private: System::Windows::Forms::ToolStripMenuItem^  toolCategoria;
	private: System::Windows::Forms::ToolStripMenuItem^  toolHotelCategoria;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem7;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^  toolViajeReservado;
	private: System::Windows::Forms::ToolStripMenuItem^  toolHotelReservado;
	private: System::Windows::Forms::ToolStripMenuItem^  toolTransporteReservado;
	private: System::Windows::Forms::ToolStripMenuItem^  toolPrecioReservaciones;

	private: System::Windows::Forms::ToolStripMenuItem^  toolInfoCliente;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolSalir;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem9;
	private: System::Windows::Forms::ToolStripMenuItem^  toolReservarViaje;
	private: System::Windows::Forms::ToolStripMenuItem^  toolReservarHotel;
	private: System::Windows::Forms::ToolStripMenuItem^  toolReservarTransporte;

	private: System::Windows::Forms::Button^  botonEnviarRespuesta;
	private: System::Windows::Forms::TextBox^  boxEscribeUsuario;
	private: System::Windows::Forms::Label^  labelPreguntaTodo;
	private: System::Windows::Forms::RichTextBox^  cuadroActividades;
	private: System::Windows::Forms::Label^  labelTipoConsulta;

	private: System::Windows::Forms::GroupBox^  panelPreguntaIngresa;

	private: System::Windows::Forms::ToolStripMenuItem^  toolRealizarRecorridos;
	private: System::Windows::Forms::TabControl^  contenedorRecorridos;

	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  grupoContenedorRecorrido;

	private: System::Windows::Forms::Label^  labelPreguntaRecorrido;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;



	private: System::Windows::Forms::TabControl^  tabControl_Reservaciones;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::TabPage^  tabPage6;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::TextBox^  textBox_Plazas_Cliente;

private: System::Windows::Forms::TextBox^  textBox_Viaje_Viaje;

private: System::Windows::Forms::TextBox^  textBox_Cliente_Viaje;

private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label6;

private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::CheckBox^  checkBox_Hab_Doble;

private: System::Windows::Forms::CheckBox^  checkBox_Hab_Individual;

private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::TextBox^  textBox_Cliente_Hotel;

private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::TextBox^  textBox_Hotel_Hotel;
private: System::Windows::Forms::TextBox^  textBox_Transporte_Transporte;


private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::TextBox^  textBox_Cliente_Transporte;

private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::CheckBox^  checkBox_Oferta_Rechazar;

private: System::Windows::Forms::CheckBox^  checkBox_Oferta_Aceptar;

private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::Button^  button_Cuba;
private: System::Windows::Forms::Button^  button_China;


private: System::Windows::Forms::Button^  button_Dubai;

private: System::Windows::Forms::Button^  button_Italia;

private: System::Windows::Forms::Button^  button_Canada;
private: System::Windows::Forms::Button^  button_Alemania;


private: System::Windows::Forms::Button^  button_Camerun;
private: System::Windows::Forms::Button^  button_Finlandia;



private: System::Windows::Forms::Button^  button_Inglaterra;

private: System::Windows::Forms::Button^  button_Espania;
private: System::Windows::Forms::Button^  button_ElCongo;


private: System::Windows::Forms::Button^  button_Chile;
private: System::Windows::Forms::Button^  button_Egipto;


private: System::Windows::Forms::Button^  button_Francia;

private: System::Windows::Forms::Button^  button_Argentina;

private: System::Windows::Forms::Button^  button_USA;
private: System::Windows::Forms::Button^  button_ElSalvador;
private: System::Windows::Forms::Button^  button_Costa_Rica;



private: System::Windows::Forms::Button^  button_Nicaragua;

private: System::Windows::Forms::Button^  button_Mexico;
private: System::Windows::Forms::Button^  button_Panama;


private: System::Windows::Forms::TabControl^  tabControl1;
private: System::Windows::Forms::TabPage^  tabPage7;
private: System::Windows::Forms::TabPage^  tabPage8;
private: System::Windows::Forms::Button^  button_Belice;
private: System::Windows::Forms::Button^  button_Japon;


private: System::Windows::Forms::Button^  button_Rusia;

private: System::Windows::Forms::Button^  button_Portugal;
private: System::Windows::Forms::Button^  button_Eslovaquia;


private: System::Windows::Forms::Button^  button_Brasil;
private: System::Windows::Forms::Button^  button_Armenia;


private: System::Windows::Forms::Button^  button_Dinamarca;
private: System::Windows::Forms::Button^  button_Belgica;


private: System::Windows::Forms::Button^  button_Grecia;

private: System::Windows::Forms::Button^  button_Bulgaria;
private: System::Windows::Forms::Label^  label_InicioDijkstra;
private: System::Windows::Forms::ToolStripMenuItem^  consultarDestinosToolStripMenuItem;
private: System::Windows::Forms::Label^  label_LlegadaDijkstra;


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::Button^  button2;
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Interfaz::typeid));
			this->barraMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->ArchivoMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolProductos = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Mostrar = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolViajesMostrar = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolHotelesMostrar = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolTransportesMostrar = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolViajePrecio = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolHotelPrecio = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolTransportePrecio = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolViajeOrigenDestino = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolPaquetes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolViajePaquetes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolCategoria = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolHotelCategoria = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem7 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolViajeReservado = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolHotelReservado = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolTransporteReservado = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolPrecioReservaciones = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolInfoCliente = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolSalir = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem9 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolReservarViaje = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolReservarHotel = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolReservarTransporte = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolRealizarRecorridos = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->consultarDestinosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->InfoMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LogoVentana = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->botonEnviarRespuesta = (gcnew System::Windows::Forms::Button());
			this->boxEscribeUsuario = (gcnew System::Windows::Forms::TextBox());
			this->labelPreguntaTodo = (gcnew System::Windows::Forms::Label());
			this->cuadroActividades = (gcnew System::Windows::Forms::RichTextBox());
			this->labelTipoConsulta = (gcnew System::Windows::Forms::Label());
			this->panelPreguntaIngresa = (gcnew System::Windows::Forms::GroupBox());
			this->contenedorRecorridos = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label_LlegadaDijkstra = (gcnew System::Windows::Forms::Label());
			this->label_InicioDijkstra = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->grupoContenedorRecorrido = (gcnew System::Windows::Forms::GroupBox());
			this->labelPreguntaRecorrido = (gcnew System::Windows::Forms::Label());
			this->tabControl_Reservaciones = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->textBox_Plazas_Cliente = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Viaje_Viaje = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Cliente_Viaje = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->checkBox_Oferta_Rechazar = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_Oferta_Aceptar = (gcnew System::Windows::Forms::CheckBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox_Hotel_Hotel = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->checkBox_Hab_Doble = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_Hab_Individual = (gcnew System::Windows::Forms::CheckBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox_Cliente_Hotel = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->textBox_Transporte_Transporte = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox_Cliente_Transporte = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button_Cuba = (gcnew System::Windows::Forms::Button());
			this->button_China = (gcnew System::Windows::Forms::Button());
			this->button_Dubai = (gcnew System::Windows::Forms::Button());
			this->button_Italia = (gcnew System::Windows::Forms::Button());
			this->button_Canada = (gcnew System::Windows::Forms::Button());
			this->button_Alemania = (gcnew System::Windows::Forms::Button());
			this->button_Camerun = (gcnew System::Windows::Forms::Button());
			this->button_Finlandia = (gcnew System::Windows::Forms::Button());
			this->button_Inglaterra = (gcnew System::Windows::Forms::Button());
			this->button_Espania = (gcnew System::Windows::Forms::Button());
			this->button_ElCongo = (gcnew System::Windows::Forms::Button());
			this->button_Chile = (gcnew System::Windows::Forms::Button());
			this->button_Egipto = (gcnew System::Windows::Forms::Button());
			this->button_Francia = (gcnew System::Windows::Forms::Button());
			this->button_Argentina = (gcnew System::Windows::Forms::Button());
			this->button_USA = (gcnew System::Windows::Forms::Button());
			this->button_ElSalvador = (gcnew System::Windows::Forms::Button());
			this->button_Costa_Rica = (gcnew System::Windows::Forms::Button());
			this->button_Nicaragua = (gcnew System::Windows::Forms::Button());
			this->button_Mexico = (gcnew System::Windows::Forms::Button());
			this->button_Panama = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
			this->button_Belice = (gcnew System::Windows::Forms::Button());
			this->button_Japon = (gcnew System::Windows::Forms::Button());
			this->button_Rusia = (gcnew System::Windows::Forms::Button());
			this->button_Portugal = (gcnew System::Windows::Forms::Button());
			this->button_Eslovaquia = (gcnew System::Windows::Forms::Button());
			this->button_Brasil = (gcnew System::Windows::Forms::Button());
			this->button_Armenia = (gcnew System::Windows::Forms::Button());
			this->button_Dinamarca = (gcnew System::Windows::Forms::Button());
			this->button_Belgica = (gcnew System::Windows::Forms::Button());
			this->button_Grecia = (gcnew System::Windows::Forms::Button());
			this->button_Bulgaria = (gcnew System::Windows::Forms::Button());
			button2 = (gcnew System::Windows::Forms::Button());
			this->barraMenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoVentana))->BeginInit();
			this->panelPreguntaIngresa->SuspendLayout();
			this->contenedorRecorridos->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->grupoContenedorRecorrido->SuspendLayout();
			this->tabControl_Reservaciones->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->tabPage6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage7->SuspendLayout();
			this->tabPage8->SuspendLayout();
			this->SuspendLayout();
			// 
			// button2
			// 
			button2->Location = System::Drawing::Point(6, 62);
			button2->Name = L"button2";
			button2->Size = System::Drawing::Size(75, 23);
			button2->TabIndex = 1;
			button2->Text = L"Anchura";
			button2->UseVisualStyleBackColor = true;
			button2->Click += gcnew System::EventHandler(this, &Interfaz::button2_Click);
			// 
			// barraMenu
			// 
			this->barraMenu->BackColor = System::Drawing::Color::Transparent;
			this->barraMenu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->barraMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ArchivoMenu, this->toolStripMenuItem1,
					this->InfoMenu
			});
			this->barraMenu->Location = System::Drawing::Point(0, 0);
			this->barraMenu->Name = L"barraMenu";
			this->barraMenu->Size = System::Drawing::Size(1115, 24);
			this->barraMenu->TabIndex = 0;
			this->barraMenu->Text = L"menuStrip1";
			// 
			// ArchivoMenu
			// 
			this->ArchivoMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolProductos,
					this->toolStripMenuItem3, this->toolStripSeparator1, this->toolSalir
			});
			this->ArchivoMenu->Name = L"ArchivoMenu";
			this->ArchivoMenu->Size = System::Drawing::Size(60, 20);
			this->ArchivoMenu->Text = L"Archivo";
			// 
			// toolProductos
			// 
			this->toolProductos->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->Mostrar,
					this->toolStripMenuItem2
			});
			this->toolProductos->Name = L"toolProductos";
			this->toolProductos->Size = System::Drawing::Size(128, 22);
			this->toolProductos->Text = L"Productos";
			// 
			// Mostrar
			// 
			this->Mostrar->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolViajesMostrar,
					this->toolHotelesMostrar, this->toolTransportesMostrar
			});
			this->Mostrar->Name = L"Mostrar";
			this->Mostrar->Size = System::Drawing::Size(125, 22);
			this->Mostrar->Text = L"Mostrar";
			// 
			// toolViajesMostrar
			// 
			this->toolViajesMostrar->Name = L"toolViajesMostrar";
			this->toolViajesMostrar->Size = System::Drawing::Size(135, 22);
			this->toolViajesMostrar->Text = L"Viajes";
			this->toolViajesMostrar->Click += gcnew System::EventHandler(this, &Interfaz::toolViajesMostrar_Click);
			// 
			// toolHotelesMostrar
			// 
			this->toolHotelesMostrar->Name = L"toolHotelesMostrar";
			this->toolHotelesMostrar->Size = System::Drawing::Size(135, 22);
			this->toolHotelesMostrar->Text = L"Hoteles";
			this->toolHotelesMostrar->Click += gcnew System::EventHandler(this, &Interfaz::toolHotelesMostrar_Click);
			// 
			// toolTransportesMostrar
			// 
			this->toolTransportesMostrar->Name = L"toolTransportesMostrar";
			this->toolTransportesMostrar->Size = System::Drawing::Size(135, 22);
			this->toolTransportesMostrar->Text = L"Transportes";
			this->toolTransportesMostrar->Click += gcnew System::EventHandler(this, &Interfaz::toolTransportesMostrar_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripMenuItem5,
					this->toolStripMenuItem6, this->toolPaquetes, this->toolCategoria
			});
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(125, 22);
			this->toolStripMenuItem2->Text = L"Consultar";
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolViajePrecio,
					this->toolHotelPrecio, this->toolTransportePrecio
			});
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(186, 22);
			this->toolStripMenuItem5->Text = L"Precio";
			// 
			// toolViajePrecio
			// 
			this->toolViajePrecio->Name = L"toolViajePrecio";
			this->toolViajePrecio->Size = System::Drawing::Size(130, 22);
			this->toolViajePrecio->Text = L"Viaje";
			this->toolViajePrecio->Click += gcnew System::EventHandler(this, &Interfaz::toolViajePrecio_Click);
			// 
			// toolHotelPrecio
			// 
			this->toolHotelPrecio->Name = L"toolHotelPrecio";
			this->toolHotelPrecio->Size = System::Drawing::Size(130, 22);
			this->toolHotelPrecio->Text = L"Hotel";
			this->toolHotelPrecio->Click += gcnew System::EventHandler(this, &Interfaz::toolHotelPrecio_Click);
			// 
			// toolTransportePrecio
			// 
			this->toolTransportePrecio->Name = L"toolTransportePrecio";
			this->toolTransportePrecio->Size = System::Drawing::Size(130, 22);
			this->toolTransportePrecio->Text = L"Transporte";
			this->toolTransportePrecio->Click += gcnew System::EventHandler(this, &Interfaz::toolTransportePrecio_Click);
			// 
			// toolStripMenuItem6
			// 
			this->toolStripMenuItem6->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolViajeOrigenDestino });
			this->toolStripMenuItem6->Name = L"toolStripMenuItem6";
			this->toolStripMenuItem6->Size = System::Drawing::Size(186, 22);
			this->toolStripMenuItem6->Text = L"Origen y Destino";
			// 
			// toolViajeOrigenDestino
			// 
			this->toolViajeOrigenDestino->Name = L"toolViajeOrigenDestino";
			this->toolViajeOrigenDestino->Size = System::Drawing::Size(99, 22);
			this->toolViajeOrigenDestino->Text = L"Viaje";
			this->toolViajeOrigenDestino->Click += gcnew System::EventHandler(this, &Interfaz::toolViajeOrigenDestino_Click);
			// 
			// toolPaquetes
			// 
			this->toolPaquetes->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolViajePaquetes });
			this->toolPaquetes->Name = L"toolPaquetes";
			this->toolPaquetes->Size = System::Drawing::Size(186, 22);
			this->toolPaquetes->Text = L"Paquetes Disponibles";
			// 
			// toolViajePaquetes
			// 
			this->toolViajePaquetes->Name = L"toolViajePaquetes";
			this->toolViajePaquetes->Size = System::Drawing::Size(99, 22);
			this->toolViajePaquetes->Text = L"Viaje";
			this->toolViajePaquetes->Click += gcnew System::EventHandler(this, &Interfaz::toolViajePaquetes_Click);
			// 
			// toolCategoria
			// 
			this->toolCategoria->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolHotelCategoria });
			this->toolCategoria->Name = L"toolCategoria";
			this->toolCategoria->Size = System::Drawing::Size(186, 22);
			this->toolCategoria->Text = L"Categoria";
			// 
			// toolHotelCategoria
			// 
			this->toolHotelCategoria->Name = L"toolHotelCategoria";
			this->toolHotelCategoria->Size = System::Drawing::Size(103, 22);
			this->toolHotelCategoria->Text = L"Hotel";
			this->toolHotelCategoria->Click += gcnew System::EventHandler(this, &Interfaz::toolHotelCategoria_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripMenuItem7 });
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(128, 22);
			this->toolStripMenuItem3->Text = L"Cliente";
			// 
			// toolStripMenuItem7
			// 
			this->toolStripMenuItem7->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripMenuItem4,
					this->toolPrecioReservaciones, this->toolInfoCliente
			});
			this->toolStripMenuItem7->Name = L"toolStripMenuItem7";
			this->toolStripMenuItem7->Size = System::Drawing::Size(125, 22);
			this->toolStripMenuItem7->Text = L"Consultar";
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolViajeReservado,
					this->toolHotelReservado, this->toolTransporteReservado
			});
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(217, 22);
			this->toolStripMenuItem4->Text = L"Producto Reservado";
			// 
			// toolViajeReservado
			// 
			this->toolViajeReservado->Name = L"toolViajeReservado";
			this->toolViajeReservado->Size = System::Drawing::Size(130, 22);
			this->toolViajeReservado->Text = L"Viaje";
			this->toolViajeReservado->Click += gcnew System::EventHandler(this, &Interfaz::toolViajeReservado_Click);
			// 
			// toolHotelReservado
			// 
			this->toolHotelReservado->Name = L"toolHotelReservado";
			this->toolHotelReservado->Size = System::Drawing::Size(130, 22);
			this->toolHotelReservado->Text = L"Hotel";
			this->toolHotelReservado->Click += gcnew System::EventHandler(this, &Interfaz::toolHotelReservado_Click);
			// 
			// toolTransporteReservado
			// 
			this->toolTransporteReservado->Name = L"toolTransporteReservado";
			this->toolTransporteReservado->Size = System::Drawing::Size(130, 22);
			this->toolTransporteReservado->Text = L"Transporte";
			this->toolTransporteReservado->Click += gcnew System::EventHandler(this, &Interfaz::toolTransporteReservado_Click);
			// 
			// toolPrecioReservaciones
			// 
			this->toolPrecioReservaciones->Name = L"toolPrecioReservaciones";
			this->toolPrecioReservaciones->Size = System::Drawing::Size(217, 22);
			this->toolPrecioReservaciones->Text = L"Precio de las Reservaciones";
			this->toolPrecioReservaciones->Click += gcnew System::EventHandler(this, &Interfaz::toolPrecioReservaciones_Click);
			// 
			// toolInfoCliente
			// 
			this->toolInfoCliente->Name = L"toolInfoCliente";
			this->toolInfoCliente->Size = System::Drawing::Size(217, 22);
			this->toolInfoCliente->Text = L"Información";
			this->toolInfoCliente->Click += gcnew System::EventHandler(this, &Interfaz::toolInfoCliente_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(125, 6);
			// 
			// toolSalir
			// 
			this->toolSalir->Name = L"toolSalir";
			this->toolSalir->Size = System::Drawing::Size(128, 22);
			this->toolSalir->Text = L"Salir";
			this->toolSalir->Click += gcnew System::EventHandler(this, &Interfaz::toolSalir_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripMenuItem9,
					this->toolRealizarRecorridos, this->consultarDestinosToolStripMenuItem
			});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(49, 20);
			this->toolStripMenuItem1->Text = L"Editar";
			// 
			// toolStripMenuItem9
			// 
			this->toolStripMenuItem9->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolReservarViaje,
					this->toolReservarHotel, this->toolReservarTransporte
			});
			this->toolStripMenuItem9->Name = L"toolStripMenuItem9";
			this->toolStripMenuItem9->Size = System::Drawing::Size(174, 22);
			this->toolStripMenuItem9->Text = L"Reservar";
			// 
			// toolReservarViaje
			// 
			this->toolReservarViaje->Name = L"toolReservarViaje";
			this->toolReservarViaje->Size = System::Drawing::Size(130, 22);
			this->toolReservarViaje->Text = L"Viaje";
			this->toolReservarViaje->Click += gcnew System::EventHandler(this, &Interfaz::toolReservarViaje_Click);
			// 
			// toolReservarHotel
			// 
			this->toolReservarHotel->Name = L"toolReservarHotel";
			this->toolReservarHotel->Size = System::Drawing::Size(130, 22);
			this->toolReservarHotel->Text = L"Hotel";
			this->toolReservarHotel->Click += gcnew System::EventHandler(this, &Interfaz::toolReservarHotel_Click);
			// 
			// toolReservarTransporte
			// 
			this->toolReservarTransporte->Name = L"toolReservarTransporte";
			this->toolReservarTransporte->Size = System::Drawing::Size(130, 22);
			this->toolReservarTransporte->Text = L"Transporte";
			this->toolReservarTransporte->Click += gcnew System::EventHandler(this, &Interfaz::toolReservarTransporte_Click);
			// 
			// toolRealizarRecorridos
			// 
			this->toolRealizarRecorridos->Name = L"toolRealizarRecorridos";
			this->toolRealizarRecorridos->Size = System::Drawing::Size(174, 22);
			this->toolRealizarRecorridos->Text = L"Realizar recorrido...";
			this->toolRealizarRecorridos->Click += gcnew System::EventHandler(this, &Interfaz::toolRealizarRecorridos_Click);
			// 
			// consultarDestinosToolStripMenuItem
			// 
			this->consultarDestinosToolStripMenuItem->Name = L"consultarDestinosToolStripMenuItem";
			this->consultarDestinosToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->consultarDestinosToolStripMenuItem->Text = L"Consultar destinos";
			this->consultarDestinosToolStripMenuItem->Click += gcnew System::EventHandler(this, &Interfaz::consultarDestinosToolStripMenuItem_Click);
			// 
			// InfoMenu
			// 
			this->InfoMenu->Name = L"InfoMenu";
			this->InfoMenu->Size = System::Drawing::Size(40, 20);
			this->InfoMenu->Text = L"Info";
			this->InfoMenu->Click += gcnew System::EventHandler(this, &Interfaz::InfoMenu_Click);
			// 
			// LogoVentana
			// 
			this->LogoVentana->BackColor = System::Drawing::Color::Transparent;
			this->LogoVentana->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LogoVentana.Image")));
			this->LogoVentana->Location = System::Drawing::Point(39, 51);
			this->LogoVentana->Name = L"LogoVentana";
			this->LogoVentana->Size = System::Drawing::Size(54, 52);
			this->LogoVentana->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->LogoVentana->TabIndex = 1;
			this->LogoVentana->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 12.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(99, 70);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(224, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Sistema de Reservaciones";
			// 
			// botonEnviarRespuesta
			// 
			this->botonEnviarRespuesta->BackColor = System::Drawing::Color::Transparent;
			this->botonEnviarRespuesta->Location = System::Drawing::Point(907, 556);
			this->botonEnviarRespuesta->Name = L"botonEnviarRespuesta";
			this->botonEnviarRespuesta->Size = System::Drawing::Size(111, 23);
			this->botonEnviarRespuesta->TabIndex = 2;
			this->botonEnviarRespuesta->Text = L"Enviar Respuesta";
			this->botonEnviarRespuesta->UseVisualStyleBackColor = false;
			this->botonEnviarRespuesta->Click += gcnew System::EventHandler(this, &Interfaz::botonEnviarRespuesta_Click);
			// 
			// boxEscribeUsuario
			// 
			this->boxEscribeUsuario->Location = System::Drawing::Point(9, 45);
			this->boxEscribeUsuario->Name = L"boxEscribeUsuario";
			this->boxEscribeUsuario->Size = System::Drawing::Size(190, 20);
			this->boxEscribeUsuario->TabIndex = 1;
			// 
			// labelPreguntaTodo
			// 
			this->labelPreguntaTodo->AutoSize = true;
			this->labelPreguntaTodo->BackColor = System::Drawing::Color::Transparent;
			this->labelPreguntaTodo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPreguntaTodo->Location = System::Drawing::Point(6, 16);
			this->labelPreguntaTodo->Name = L"labelPreguntaTodo";
			this->labelPreguntaTodo->Size = System::Drawing::Size(37, 15);
			this->labelPreguntaTodo->TabIndex = 0;
			this->labelPreguntaTodo->Text = L"          ";
			// 
			// cuadroActividades
			// 
			this->cuadroActividades->BackColor = System::Drawing::Color::WhiteSmoke;
			this->cuadroActividades->Location = System::Drawing::Point(0, 0);
			this->cuadroActividades->Name = L"cuadroActividades";
			this->cuadroActividades->ReadOnly = true;
			this->cuadroActividades->Size = System::Drawing::Size(226, 350);
			this->cuadroActividades->TabIndex = 17;
			this->cuadroActividades->Text = L"";
			// 
			// labelTipoConsulta
			// 
			this->labelTipoConsulta->AutoSize = true;
			this->labelTipoConsulta->BackColor = System::Drawing::Color::Transparent;
			this->labelTipoConsulta->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 8.3F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTipoConsulta->Location = System::Drawing::Point(818, 77);
			this->labelTipoConsulta->Name = L"labelTipoConsulta";
			this->labelTipoConsulta->Size = System::Drawing::Size(40, 15);
			this->labelTipoConsulta->TabIndex = 18;
			this->labelTipoConsulta->Text = L"           ";
			// 
			// panelPreguntaIngresa
			// 
			this->panelPreguntaIngresa->BackColor = System::Drawing::Color::Transparent;
			this->panelPreguntaIngresa->Controls->Add(this->labelPreguntaTodo);
			this->panelPreguntaIngresa->Controls->Add(this->boxEscribeUsuario);
			this->panelPreguntaIngresa->Enabled = false;
			this->panelPreguntaIngresa->Location = System::Drawing::Point(31, 40);
			this->panelPreguntaIngresa->Name = L"panelPreguntaIngresa";
			this->panelPreguntaIngresa->Size = System::Drawing::Size(210, 78);
			this->panelPreguntaIngresa->TabIndex = 21;
			this->panelPreguntaIngresa->TabStop = false;
			// 
			// contenedorRecorridos
			// 
			this->contenedorRecorridos->Controls->Add(this->tabPage1);
			this->contenedorRecorridos->Controls->Add(this->tabPage2);
			this->contenedorRecorridos->Location = System::Drawing::Point(4, 51);
			this->contenedorRecorridos->Multiline = true;
			this->contenedorRecorridos->Name = L"contenedorRecorridos";
			this->contenedorRecorridos->SelectedIndex = 0;
			this->contenedorRecorridos->Size = System::Drawing::Size(203, 179);
			this->contenedorRecorridos->TabIndex = 22;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::Transparent;
			this->tabPage1->Controls->Add(this->button6);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(button2);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(195, 153);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Tipo recorrido";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(113, 111);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Articulación";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(113, 17);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Kruskal";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Interfaz::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(6, 111);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Prim";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Interfaz::button3_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 17);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Profundidad";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Interfaz::button1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::Transparent;
			this->tabPage2->Controls->Add(this->label_LlegadaDijkstra);
			this->tabPage2->Controls->Add(this->label_InicioDijkstra);
			this->tabPage2->Controls->Add(this->label5);
			this->tabPage2->Controls->Add(this->button5);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(195, 153);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Inicio/Llegada";
			// 
			// label_LlegadaDijkstra
			// 
			this->label_LlegadaDijkstra->AutoSize = true;
			this->label_LlegadaDijkstra->Location = System::Drawing::Point(60, 75);
			this->label_LlegadaDijkstra->Name = L"label_LlegadaDijkstra";
			this->label_LlegadaDijkstra->Size = System::Drawing::Size(25, 13);
			this->label_LlegadaDijkstra->TabIndex = 6;
			this->label_LlegadaDijkstra->Text = L"      ";
			// 
			// label_InicioDijkstra
			// 
			this->label_InicioDijkstra->AutoSize = true;
			this->label_InicioDijkstra->Location = System::Drawing::Point(49, 38);
			this->label_InicioDijkstra->Name = L"label_InicioDijkstra";
			this->label_InicioDijkstra->Size = System::Drawing::Size(25, 13);
			this->label_InicioDijkstra->TabIndex = 5;
			this->label_InicioDijkstra->Text = L"      ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(7, 75);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(48, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Llegada:";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(63, 115);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Dijkstra";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Interfaz::button5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 38);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Inicio:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(31, 143);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 17);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Recorridos:";
			// 
			// grupoContenedorRecorrido
			// 
			this->grupoContenedorRecorrido->BackColor = System::Drawing::Color::Transparent;
			this->grupoContenedorRecorrido->Controls->Add(this->labelPreguntaRecorrido);
			this->grupoContenedorRecorrido->Controls->Add(this->contenedorRecorridos);
			this->grupoContenedorRecorrido->Enabled = false;
			this->grupoContenedorRecorrido->Location = System::Drawing::Point(31, 169);
			this->grupoContenedorRecorrido->Name = L"grupoContenedorRecorrido";
			this->grupoContenedorRecorrido->Size = System::Drawing::Size(211, 236);
			this->grupoContenedorRecorrido->TabIndex = 24;
			this->grupoContenedorRecorrido->TabStop = false;
			// 
			// labelPreguntaRecorrido
			// 
			this->labelPreguntaRecorrido->AutoSize = true;
			this->labelPreguntaRecorrido->BackColor = System::Drawing::Color::Transparent;
			this->labelPreguntaRecorrido->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelPreguntaRecorrido->Location = System::Drawing::Point(4, 17);
			this->labelPreguntaRecorrido->Name = L"labelPreguntaRecorrido";
			this->labelPreguntaRecorrido->Size = System::Drawing::Size(28, 14);
			this->labelPreguntaRecorrido->TabIndex = 23;
			this->labelPreguntaRecorrido->Text = L"       ";
			// 
			// tabControl_Reservaciones
			// 
			this->tabControl_Reservaciones->Controls->Add(this->tabPage3);
			this->tabControl_Reservaciones->Controls->Add(this->tabPage4);
			this->tabControl_Reservaciones->Controls->Add(this->tabPage5);
			this->tabControl_Reservaciones->Controls->Add(this->tabPage6);
			this->tabControl_Reservaciones->Location = System::Drawing::Point(21, 15);
			this->tabControl_Reservaciones->Name = L"tabControl_Reservaciones";
			this->tabControl_Reservaciones->SelectedIndex = 0;
			this->tabControl_Reservaciones->Size = System::Drawing::Size(235, 378);
			this->tabControl_Reservaciones->TabIndex = 25;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->cuadroActividades);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(227, 352);
			this->tabPage3->TabIndex = 0;
			this->tabPage3->Text = L"Consultas";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::Color::Transparent;
			this->tabPage4->Controls->Add(this->textBox_Plazas_Cliente);
			this->tabPage4->Controls->Add(this->textBox_Viaje_Viaje);
			this->tabPage4->Controls->Add(this->textBox_Cliente_Viaje);
			this->tabPage4->Controls->Add(this->label7);
			this->tabPage4->Controls->Add(this->label6);
			this->tabPage4->Controls->Add(this->label2);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(227, 352);
			this->tabPage4->TabIndex = 1;
			this->tabPage4->Text = L"Viaje";
			// 
			// textBox_Plazas_Cliente
			// 
			this->textBox_Plazas_Cliente->Location = System::Drawing::Point(31, 199);
			this->textBox_Plazas_Cliente->Name = L"textBox_Plazas_Cliente";
			this->textBox_Plazas_Cliente->Size = System::Drawing::Size(165, 20);
			this->textBox_Plazas_Cliente->TabIndex = 5;
			// 
			// textBox_Viaje_Viaje
			// 
			this->textBox_Viaje_Viaje->Location = System::Drawing::Point(31, 127);
			this->textBox_Viaje_Viaje->Name = L"textBox_Viaje_Viaje";
			this->textBox_Viaje_Viaje->Size = System::Drawing::Size(165, 20);
			this->textBox_Viaje_Viaje->TabIndex = 4;
			// 
			// textBox_Cliente_Viaje
			// 
			this->textBox_Cliente_Viaje->Location = System::Drawing::Point(31, 52);
			this->textBox_Cliente_Viaje->Name = L"textBox_Cliente_Viaje";
			this->textBox_Cliente_Viaje->Size = System::Drawing::Size(162, 20);
			this->textBox_Cliente_Viaje->TabIndex = 3;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(28, 165);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(95, 13);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Número de plazas:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(28, 95);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(47, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"ID-Viaje:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"ID-Cliente:";
			// 
			// tabPage5
			// 
			this->tabPage5->BackColor = System::Drawing::Color::Transparent;
			this->tabPage5->Controls->Add(this->checkBox_Oferta_Rechazar);
			this->tabPage5->Controls->Add(this->checkBox_Oferta_Aceptar);
			this->tabPage5->Controls->Add(this->label13);
			this->tabPage5->Controls->Add(this->textBox_Hotel_Hotel);
			this->tabPage5->Controls->Add(this->label10);
			this->tabPage5->Controls->Add(this->checkBox_Hab_Doble);
			this->tabPage5->Controls->Add(this->checkBox_Hab_Individual);
			this->tabPage5->Controls->Add(this->label9);
			this->tabPage5->Controls->Add(this->textBox_Cliente_Hotel);
			this->tabPage5->Controls->Add(this->label8);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(227, 352);
			this->tabPage5->TabIndex = 2;
			this->tabPage5->Text = L"Hotel";
			// 
			// checkBox_Oferta_Rechazar
			// 
			this->checkBox_Oferta_Rechazar->AutoSize = true;
			this->checkBox_Oferta_Rechazar->Location = System::Drawing::Point(106, 305);
			this->checkBox_Oferta_Rechazar->Name = L"checkBox_Oferta_Rechazar";
			this->checkBox_Oferta_Rechazar->Size = System::Drawing::Size(72, 17);
			this->checkBox_Oferta_Rechazar->TabIndex = 10;
			this->checkBox_Oferta_Rechazar->Text = L"Rechazar";
			this->checkBox_Oferta_Rechazar->UseVisualStyleBackColor = true;
			// 
			// checkBox_Oferta_Aceptar
			// 
			this->checkBox_Oferta_Aceptar->AutoSize = true;
			this->checkBox_Oferta_Aceptar->Location = System::Drawing::Point(31, 305);
			this->checkBox_Oferta_Aceptar->Name = L"checkBox_Oferta_Aceptar";
			this->checkBox_Oferta_Aceptar->Size = System::Drawing::Size(63, 17);
			this->checkBox_Oferta_Aceptar->TabIndex = 9;
			this->checkBox_Oferta_Aceptar->Text = L"Aceptar";
			this->checkBox_Oferta_Aceptar->UseVisualStyleBackColor = true;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(31, 271);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(39, 13);
			this->label13->TabIndex = 8;
			this->label13->Text = L"Oferta:";
			// 
			// textBox_Hotel_Hotel
			// 
			this->textBox_Hotel_Hotel->Location = System::Drawing::Point(31, 126);
			this->textBox_Hotel_Hotel->Name = L"textBox_Hotel_Hotel";
			this->textBox_Hotel_Hotel->Size = System::Drawing::Size(161, 20);
			this->textBox_Hotel_Hotel->TabIndex = 7;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(28, 183);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(98, 13);
			this->label10->TabIndex = 5;
			this->label10->Text = L"Tipo de habitación:";
			// 
			// checkBox_Hab_Doble
			// 
			this->checkBox_Hab_Doble->AutoSize = true;
			this->checkBox_Hab_Doble->Location = System::Drawing::Point(106, 218);
			this->checkBox_Hab_Doble->Name = L"checkBox_Hab_Doble";
			this->checkBox_Hab_Doble->Size = System::Drawing::Size(54, 17);
			this->checkBox_Hab_Doble->TabIndex = 4;
			this->checkBox_Hab_Doble->Text = L"Doble";
			this->checkBox_Hab_Doble->UseVisualStyleBackColor = true;
			// 
			// checkBox_Hab_Individual
			// 
			this->checkBox_Hab_Individual->AutoSize = true;
			this->checkBox_Hab_Individual->Location = System::Drawing::Point(28, 218);
			this->checkBox_Hab_Individual->Name = L"checkBox_Hab_Individual";
			this->checkBox_Hab_Individual->Size = System::Drawing::Size(71, 17);
			this->checkBox_Hab_Individual->TabIndex = 3;
			this->checkBox_Hab_Individual->Text = L"Individual";
			this->checkBox_Hab_Individual->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(28, 97);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(49, 13);
			this->label9->TabIndex = 2;
			this->label9->Text = L"ID-Hotel:";
			// 
			// textBox_Cliente_Hotel
			// 
			this->textBox_Cliente_Hotel->Location = System::Drawing::Point(31, 52);
			this->textBox_Cliente_Hotel->Name = L"textBox_Cliente_Hotel";
			this->textBox_Cliente_Hotel->Size = System::Drawing::Size(161, 20);
			this->textBox_Cliente_Hotel->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(28, 22);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(56, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"ID-Cliente:";
			// 
			// tabPage6
			// 
			this->tabPage6->BackColor = System::Drawing::Color::Transparent;
			this->tabPage6->Controls->Add(this->textBox_Transporte_Transporte);
			this->tabPage6->Controls->Add(this->label12);
			this->tabPage6->Controls->Add(this->textBox_Cliente_Transporte);
			this->tabPage6->Controls->Add(this->label11);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(227, 352);
			this->tabPage6->TabIndex = 3;
			this->tabPage6->Text = L"Transportes";
			// 
			// textBox_Transporte_Transporte
			// 
			this->textBox_Transporte_Transporte->Location = System::Drawing::Point(32, 127);
			this->textBox_Transporte_Transporte->Name = L"textBox_Transporte_Transporte";
			this->textBox_Transporte_Transporte->Size = System::Drawing::Size(158, 20);
			this->textBox_Transporte_Transporte->TabIndex = 3;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(29, 98);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(75, 13);
			this->label12->TabIndex = 2;
			this->label12->Text = L"ID-Transporte:";
			// 
			// textBox_Cliente_Transporte
			// 
			this->textBox_Cliente_Transporte->Location = System::Drawing::Point(32, 52);
			this->textBox_Cliente_Transporte->Name = L"textBox_Cliente_Transporte";
			this->textBox_Cliente_Transporte->Size = System::Drawing::Size(161, 20);
			this->textBox_Cliente_Transporte->TabIndex = 1;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(29, 21);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(53, 13);
			this->label11->TabIndex = 0;
			this->label11->Text = L"ID-Cliente";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 129);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(815, 464);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 47;
			this->pictureBox1->TabStop = false;
			// 
			// button_Cuba
			// 
			this->button_Cuba->BackColor = System::Drawing::Color::Transparent;
			this->button_Cuba->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Cuba->Location = System::Drawing::Point(207, 314);
			this->button_Cuba->Name = L"button_Cuba";
			this->button_Cuba->Size = System::Drawing::Size(75, 23);
			this->button_Cuba->TabIndex = 68;
			this->button_Cuba->Text = L" Cuba";
			this->button_Cuba->UseVisualStyleBackColor = false;
			this->button_Cuba->Click += gcnew System::EventHandler(this, &Interfaz::button_Cuba_Click);
			// 
			// button_China
			// 
			this->button_China->BackColor = System::Drawing::Color::Transparent;
			this->button_China->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_China->Location = System::Drawing::Point(609, 294);
			this->button_China->Name = L"button_China";
			this->button_China->Size = System::Drawing::Size(75, 23);
			this->button_China->TabIndex = 67;
			this->button_China->Text = L" China";
			this->button_China->UseVisualStyleBackColor = false;
			this->button_China->Click += gcnew System::EventHandler(this, &Interfaz::button_China_Click);
			// 
			// button_Dubai
			// 
			this->button_Dubai->BackColor = System::Drawing::Color::Transparent;
			this->button_Dubai->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Dubai->Location = System::Drawing::Point(503, 334);
			this->button_Dubai->Name = L"button_Dubai";
			this->button_Dubai->Size = System::Drawing::Size(75, 23);
			this->button_Dubai->TabIndex = 66;
			this->button_Dubai->Text = L"Dubai";
			this->button_Dubai->UseVisualStyleBackColor = false;
			this->button_Dubai->Click += gcnew System::EventHandler(this, &Interfaz::button_Dubai_Click);
			// 
			// button_Italia
			// 
			this->button_Italia->BackColor = System::Drawing::Color::Transparent;
			this->button_Italia->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Italia->Location = System::Drawing::Point(419, 286);
			this->button_Italia->Name = L"button_Italia";
			this->button_Italia->Size = System::Drawing::Size(75, 23);
			this->button_Italia->TabIndex = 65;
			this->button_Italia->Text = L" Italia";
			this->button_Italia->UseVisualStyleBackColor = false;
			this->button_Italia->Click += gcnew System::EventHandler(this, &Interfaz::button_Italia_Click);
			// 
			// button_Canada
			// 
			this->button_Canada->BackColor = System::Drawing::Color::Transparent;
			this->button_Canada->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Canada->Location = System::Drawing::Point(116, 238);
			this->button_Canada->Name = L"button_Canada";
			this->button_Canada->Size = System::Drawing::Size(75, 23);
			this->button_Canada->TabIndex = 64;
			this->button_Canada->Text = L" Canada";
			this->button_Canada->UseVisualStyleBackColor = false;
			this->button_Canada->Click += gcnew System::EventHandler(this, &Interfaz::button_Canada_Click);
			// 
			// button_Alemania
			// 
			this->button_Alemania->BackColor = System::Drawing::Color::Transparent;
			this->button_Alemania->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Alemania->Location = System::Drawing::Point(446, 236);
			this->button_Alemania->Name = L"button_Alemania";
			this->button_Alemania->Size = System::Drawing::Size(75, 23);
			this->button_Alemania->TabIndex = 63;
			this->button_Alemania->Text = L" Alemania";
			this->button_Alemania->UseVisualStyleBackColor = false;
			this->button_Alemania->Click += gcnew System::EventHandler(this, &Interfaz::button_Alemania_Click);
			// 
			// button_Camerun
			// 
			this->button_Camerun->BackColor = System::Drawing::Color::Transparent;
			this->button_Camerun->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Camerun->Location = System::Drawing::Point(341, 385);
			this->button_Camerun->Name = L"button_Camerun";
			this->button_Camerun->Size = System::Drawing::Size(75, 23);
			this->button_Camerun->TabIndex = 62;
			this->button_Camerun->Text = L" Camerun";
			this->button_Camerun->UseVisualStyleBackColor = false;
			this->button_Camerun->Click += gcnew System::EventHandler(this, &Interfaz::button_Camerun_Click);
			// 
			// button_Finlandia
			// 
			this->button_Finlandia->BackColor = System::Drawing::Color::Transparent;
			this->button_Finlandia->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Finlandia->Location = System::Drawing::Point(421, 207);
			this->button_Finlandia->Name = L"button_Finlandia";
			this->button_Finlandia->Size = System::Drawing::Size(75, 23);
			this->button_Finlandia->TabIndex = 61;
			this->button_Finlandia->Text = L" Finlandia";
			this->button_Finlandia->UseVisualStyleBackColor = false;
			this->button_Finlandia->Click += gcnew System::EventHandler(this, &Interfaz::button_Finlandia_Click);
			// 
			// button_Inglaterra
			// 
			this->button_Inglaterra->BackColor = System::Drawing::Color::Transparent;
			this->button_Inglaterra->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Inglaterra->Location = System::Drawing::Point(362, 234);
			this->button_Inglaterra->Name = L"button_Inglaterra";
			this->button_Inglaterra->Size = System::Drawing::Size(75, 23);
			this->button_Inglaterra->TabIndex = 60;
			this->button_Inglaterra->Text = L" Inglaterra";
			this->button_Inglaterra->UseVisualStyleBackColor = false;
			this->button_Inglaterra->Click += gcnew System::EventHandler(this, &Interfaz::button_Inglaterra_Click);
			// 
			// button_Espania
			// 
			this->button_Espania->BackColor = System::Drawing::Color::Transparent;
			this->button_Espania->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Espania->Location = System::Drawing::Point(304, 259);
			this->button_Espania->Name = L"button_Espania";
			this->button_Espania->Size = System::Drawing::Size(75, 23);
			this->button_Espania->TabIndex = 59;
			this->button_Espania->Text = L" España";
			this->button_Espania->UseVisualStyleBackColor = false;
			this->button_Espania->Click += gcnew System::EventHandler(this, &Interfaz::button_Espania_Click);
			// 
			// button_ElCongo
			// 
			this->button_ElCongo->BackColor = System::Drawing::Color::Transparent;
			this->button_ElCongo->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_ElCongo->Location = System::Drawing::Point(401, 360);
			this->button_ElCongo->Name = L"button_ElCongo";
			this->button_ElCongo->Size = System::Drawing::Size(75, 23);
			this->button_ElCongo->TabIndex = 58;
			this->button_ElCongo->Text = L" El Congo";
			this->button_ElCongo->UseVisualStyleBackColor = false;
			this->button_ElCongo->Click += gcnew System::EventHandler(this, &Interfaz::button_ElCongo_Click);
			// 
			// button_Chile
			// 
			this->button_Chile->BackColor = System::Drawing::Color::Transparent;
			this->button_Chile->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Chile->Location = System::Drawing::Point(179, 437);
			this->button_Chile->Name = L"button_Chile";
			this->button_Chile->Size = System::Drawing::Size(75, 23);
			this->button_Chile->TabIndex = 57;
			this->button_Chile->Text = L" Chile";
			this->button_Chile->UseVisualStyleBackColor = false;
			this->button_Chile->Click += gcnew System::EventHandler(this, &Interfaz::button_Chile_Click);
			// 
			// button_Egipto
			// 
			this->button_Egipto->BackColor = System::Drawing::Color::Transparent;
			this->button_Egipto->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Egipto->Location = System::Drawing::Point(453, 310);
			this->button_Egipto->Name = L"button_Egipto";
			this->button_Egipto->Size = System::Drawing::Size(75, 23);
			this->button_Egipto->TabIndex = 56;
			this->button_Egipto->Text = L" Egipto";
			this->button_Egipto->UseVisualStyleBackColor = false;
			this->button_Egipto->Click += gcnew System::EventHandler(this, &Interfaz::button_Egipto_Click);
			// 
			// button_Francia
			// 
			this->button_Francia->BackColor = System::Drawing::Color::Transparent;
			this->button_Francia->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Francia->Location = System::Drawing::Point(398, 262);
			this->button_Francia->Name = L"button_Francia";
			this->button_Francia->Size = System::Drawing::Size(75, 23);
			this->button_Francia->TabIndex = 55;
			this->button_Francia->Text = L" Francia";
			this->button_Francia->UseVisualStyleBackColor = false;
			this->button_Francia->Click += gcnew System::EventHandler(this, &Interfaz::button_Francia_Click);
			// 
			// button_Argentina
			// 
			this->button_Argentina->BackColor = System::Drawing::Color::Transparent;
			this->button_Argentina->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Argentina->Location = System::Drawing::Point(215, 461);
			this->button_Argentina->Name = L"button_Argentina";
			this->button_Argentina->Size = System::Drawing::Size(75, 23);
			this->button_Argentina->TabIndex = 54;
			this->button_Argentina->Text = L" Argentina";
			this->button_Argentina->UseVisualStyleBackColor = false;
			this->button_Argentina->Click += gcnew System::EventHandler(this, &Interfaz::button_Argentina_Click);
			// 
			// button_USA
			// 
			this->button_USA->BackColor = System::Drawing::Color::Transparent;
			this->button_USA->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_USA->Location = System::Drawing::Point(123, 267);
			this->button_USA->Name = L"button_USA";
			this->button_USA->Size = System::Drawing::Size(92, 23);
			this->button_USA->TabIndex = 53;
			this->button_USA->Text = L" Estados Unidos";
			this->button_USA->UseVisualStyleBackColor = false;
			this->button_USA->Click += gcnew System::EventHandler(this, &Interfaz::button_USA_Click);
			// 
			// button_ElSalvador
			// 
			this->button_ElSalvador->BackColor = System::Drawing::Color::Transparent;
			this->button_ElSalvador->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_ElSalvador->Location = System::Drawing::Point(103, 327);
			this->button_ElSalvador->Name = L"button_ElSalvador";
			this->button_ElSalvador->Size = System::Drawing::Size(75, 23);
			this->button_ElSalvador->TabIndex = 52;
			this->button_ElSalvador->Text = L" El Salvador";
			this->button_ElSalvador->UseVisualStyleBackColor = false;
			this->button_ElSalvador->Click += gcnew System::EventHandler(this, &Interfaz::button_ElSalvador_Click);
			// 
			// button_Costa_Rica
			// 
			this->button_Costa_Rica->BackColor = System::Drawing::Color::Transparent;
			this->button_Costa_Rica->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Costa_Rica->Location = System::Drawing::Point(103, 352);
			this->button_Costa_Rica->Name = L"button_Costa_Rica";
			this->button_Costa_Rica->Size = System::Drawing::Size(75, 23);
			this->button_Costa_Rica->TabIndex = 51;
			this->button_Costa_Rica->Text = L" Costa Rica";
			this->button_Costa_Rica->UseVisualStyleBackColor = false;
			this->button_Costa_Rica->Click += gcnew System::EventHandler(this, &Interfaz::button_Costa_Rica_Click);
			// 
			// button_Nicaragua
			// 
			this->button_Nicaragua->BackColor = System::Drawing::Color::Transparent;
			this->button_Nicaragua->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Nicaragua->Location = System::Drawing::Point(180, 339);
			this->button_Nicaragua->Name = L"button_Nicaragua";
			this->button_Nicaragua->Size = System::Drawing::Size(75, 23);
			this->button_Nicaragua->TabIndex = 50;
			this->button_Nicaragua->Text = L" Nicaragua";
			this->button_Nicaragua->UseVisualStyleBackColor = false;
			this->button_Nicaragua->Click += gcnew System::EventHandler(this, &Interfaz::button_Nicaragua_Click);
			// 
			// button_Mexico
			// 
			this->button_Mexico->BackColor = System::Drawing::Color::Transparent;
			this->button_Mexico->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Mexico->Location = System::Drawing::Point(130, 300);
			this->button_Mexico->Name = L"button_Mexico";
			this->button_Mexico->Size = System::Drawing::Size(75, 23);
			this->button_Mexico->TabIndex = 49;
			this->button_Mexico->Text = L" Mexico";
			this->button_Mexico->UseVisualStyleBackColor = false;
			this->button_Mexico->Click += gcnew System::EventHandler(this, &Interfaz::button_Mexico_Click);
			// 
			// button_Panama
			// 
			this->button_Panama->BackColor = System::Drawing::Color::Transparent;
			this->button_Panama->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Panama->Location = System::Drawing::Point(180, 365);
			this->button_Panama->Name = L"button_Panama";
			this->button_Panama->Size = System::Drawing::Size(75, 23);
			this->button_Panama->TabIndex = 48;
			this->button_Panama->Text = L" Panama";
			this->button_Panama->UseVisualStyleBackColor = false;
			this->button_Panama->Click += gcnew System::EventHandler(this, &Interfaz::button_Panama_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage7);
			this->tabControl1->Controls->Add(this->tabPage8);
			this->tabControl1->Location = System::Drawing::Point(817, 107);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(282, 434);
			this->tabControl1->TabIndex = 69;
			// 
			// tabPage7
			// 
			this->tabPage7->BackColor = System::Drawing::Color::White;
			this->tabPage7->Controls->Add(this->panelPreguntaIngresa);
			this->tabPage7->Controls->Add(this->label3);
			this->tabPage7->Controls->Add(this->grupoContenedorRecorrido);
			this->tabPage7->Location = System::Drawing::Point(4, 22);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(274, 408);
			this->tabPage7->TabIndex = 0;
			this->tabPage7->Text = L"Operaciones";
			// 
			// tabPage8
			// 
			this->tabPage8->BackColor = System::Drawing::Color::White;
			this->tabPage8->Controls->Add(this->tabControl_Reservaciones);
			this->tabPage8->Location = System::Drawing::Point(4, 22);
			this->tabPage8->Name = L"tabPage8";
			this->tabPage8->Padding = System::Windows::Forms::Padding(3);
			this->tabPage8->Size = System::Drawing::Size(274, 408);
			this->tabPage8->TabIndex = 1;
			this->tabPage8->Text = L"Consultas";
			// 
			// button_Belice
			// 
			this->button_Belice->BackColor = System::Drawing::Color::Transparent;
			this->button_Belice->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Belice->Location = System::Drawing::Point(257, 338);
			this->button_Belice->Name = L"button_Belice";
			this->button_Belice->Size = System::Drawing::Size(75, 23);
			this->button_Belice->TabIndex = 70;
			this->button_Belice->Text = L"Belice";
			this->button_Belice->UseVisualStyleBackColor = false;
			this->button_Belice->Click += gcnew System::EventHandler(this, &Interfaz::button_Belice_Click);
			// 
			// button_Japon
			// 
			this->button_Japon->BackColor = System::Drawing::Color::Transparent;
			this->button_Japon->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Japon->Location = System::Drawing::Point(661, 268);
			this->button_Japon->Name = L"button_Japon";
			this->button_Japon->Size = System::Drawing::Size(75, 23);
			this->button_Japon->TabIndex = 71;
			this->button_Japon->Text = L"Japon";
			this->button_Japon->UseVisualStyleBackColor = false;
			this->button_Japon->Click += gcnew System::EventHandler(this, &Interfaz::button_Japon_Click);
			// 
			// button_Rusia
			// 
			this->button_Rusia->BackColor = System::Drawing::Color::Transparent;
			this->button_Rusia->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Rusia->Location = System::Drawing::Point(600, 224);
			this->button_Rusia->Name = L"button_Rusia";
			this->button_Rusia->Size = System::Drawing::Size(75, 23);
			this->button_Rusia->TabIndex = 72;
			this->button_Rusia->Text = L"Rusia";
			this->button_Rusia->UseVisualStyleBackColor = false;
			this->button_Rusia->Click += gcnew System::EventHandler(this, &Interfaz::button_Rusia_Click);
			// 
			// button_Portugal
			// 
			this->button_Portugal->BackColor = System::Drawing::Color::Transparent;
			this->button_Portugal->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Portugal->Location = System::Drawing::Point(320, 284);
			this->button_Portugal->Name = L"button_Portugal";
			this->button_Portugal->Size = System::Drawing::Size(75, 23);
			this->button_Portugal->TabIndex = 73;
			this->button_Portugal->Text = L"Portugal";
			this->button_Portugal->UseVisualStyleBackColor = false;
			this->button_Portugal->Click += gcnew System::EventHandler(this, &Interfaz::button_Portugal_Click);
			// 
			// button_Eslovaquia
			// 
			this->button_Eslovaquia->BackColor = System::Drawing::Color::Transparent;
			this->button_Eslovaquia->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Eslovaquia->Location = System::Drawing::Point(480, 262);
			this->button_Eslovaquia->Name = L"button_Eslovaquia";
			this->button_Eslovaquia->Size = System::Drawing::Size(75, 23);
			this->button_Eslovaquia->TabIndex = 74;
			this->button_Eslovaquia->Text = L"Eslovaquia";
			this->button_Eslovaquia->UseVisualStyleBackColor = false;
			this->button_Eslovaquia->Click += gcnew System::EventHandler(this, &Interfaz::button_Eslovaquia_Click);
			// 
			// button_Brasil
			// 
			this->button_Brasil->BackColor = System::Drawing::Color::Transparent;
			this->button_Brasil->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Brasil->Location = System::Drawing::Point(240, 413);
			this->button_Brasil->Name = L"button_Brasil";
			this->button_Brasil->Size = System::Drawing::Size(75, 23);
			this->button_Brasil->TabIndex = 75;
			this->button_Brasil->Text = L"Brasil";
			this->button_Brasil->UseVisualStyleBackColor = false;
			this->button_Brasil->Click += gcnew System::EventHandler(this, &Interfaz::button_Brasil_Click);
			// 
			// button_Armenia
			// 
			this->button_Armenia->BackColor = System::Drawing::Color::Transparent;
			this->button_Armenia->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Armenia->Location = System::Drawing::Point(530, 310);
			this->button_Armenia->Name = L"button_Armenia";
			this->button_Armenia->Size = System::Drawing::Size(75, 23);
			this->button_Armenia->TabIndex = 76;
			this->button_Armenia->Text = L"Armenia";
			this->button_Armenia->UseVisualStyleBackColor = false;
			this->button_Armenia->Click += gcnew System::EventHandler(this, &Interfaz::button_Armenia_Click);
			// 
			// button_Dinamarca
			// 
			this->button_Dinamarca->BackColor = System::Drawing::Color::Transparent;
			this->button_Dinamarca->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Dinamarca->Location = System::Drawing::Point(343, 209);
			this->button_Dinamarca->Name = L"button_Dinamarca";
			this->button_Dinamarca->Size = System::Drawing::Size(75, 23);
			this->button_Dinamarca->TabIndex = 77;
			this->button_Dinamarca->Text = L"Dinamarca";
			this->button_Dinamarca->UseVisualStyleBackColor = false;
			this->button_Dinamarca->Click += gcnew System::EventHandler(this, &Interfaz::button_Dinamarca_Click);
			// 
			// button_Belgica
			// 
			this->button_Belgica->BackColor = System::Drawing::Color::Transparent;
			this->button_Belgica->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Belgica->Location = System::Drawing::Point(523, 238);
			this->button_Belgica->Name = L"button_Belgica";
			this->button_Belgica->Size = System::Drawing::Size(75, 23);
			this->button_Belgica->TabIndex = 78;
			this->button_Belgica->Text = L"Belgica";
			this->button_Belgica->UseVisualStyleBackColor = false;
			this->button_Belgica->Click += gcnew System::EventHandler(this, &Interfaz::button_Belgica_Click);
			// 
			// button_Grecia
			// 
			this->button_Grecia->BackColor = System::Drawing::Color::Transparent;
			this->button_Grecia->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Grecia->Location = System::Drawing::Point(504, 287);
			this->button_Grecia->Name = L"button_Grecia";
			this->button_Grecia->Size = System::Drawing::Size(75, 23);
			this->button_Grecia->TabIndex = 79;
			this->button_Grecia->Text = L"Grecia";
			this->button_Grecia->UseVisualStyleBackColor = false;
			this->button_Grecia->Click += gcnew System::EventHandler(this, &Interfaz::button_Grecia_Click);
			// 
			// button_Bulgaria
			// 
			this->button_Bulgaria->BackColor = System::Drawing::Color::Transparent;
			this->button_Bulgaria->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Bulgaria->Location = System::Drawing::Point(284, 234);
			this->button_Bulgaria->Name = L"button_Bulgaria";
			this->button_Bulgaria->Size = System::Drawing::Size(75, 23);
			this->button_Bulgaria->TabIndex = 80;
			this->button_Bulgaria->Text = L"Bulgaria";
			this->button_Bulgaria->UseVisualStyleBackColor = false;
			this->button_Bulgaria->Click += gcnew System::EventHandler(this, &Interfaz::button_Bulgaria_Click);
			// 
			// Interfaz
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1115, 602);
			this->Controls->Add(this->button_Bulgaria);
			this->Controls->Add(this->botonEnviarRespuesta);
			this->Controls->Add(this->button_Grecia);
			this->Controls->Add(this->button_Belgica);
			this->Controls->Add(this->button_Dinamarca);
			this->Controls->Add(this->button_Armenia);
			this->Controls->Add(this->button_Brasil);
			this->Controls->Add(this->button_Eslovaquia);
			this->Controls->Add(this->button_Portugal);
			this->Controls->Add(this->button_Rusia);
			this->Controls->Add(this->button_Japon);
			this->Controls->Add(this->button_Belice);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->button_Cuba);
			this->Controls->Add(this->button_China);
			this->Controls->Add(this->button_Dubai);
			this->Controls->Add(this->button_Italia);
			this->Controls->Add(this->button_Canada);
			this->Controls->Add(this->button_Alemania);
			this->Controls->Add(this->button_Camerun);
			this->Controls->Add(this->button_Finlandia);
			this->Controls->Add(this->button_Inglaterra);
			this->Controls->Add(this->button_Espania);
			this->Controls->Add(this->button_ElCongo);
			this->Controls->Add(this->button_Chile);
			this->Controls->Add(this->button_Egipto);
			this->Controls->Add(this->button_Francia);
			this->Controls->Add(this->button_Argentina);
			this->Controls->Add(this->button_USA);
			this->Controls->Add(this->button_ElSalvador);
			this->Controls->Add(this->button_Costa_Rica);
			this->Controls->Add(this->button_Nicaragua);
			this->Controls->Add(this->button_Mexico);
			this->Controls->Add(this->button_Panama);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->labelTipoConsulta);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->LogoVentana);
			this->Controls->Add(this->barraMenu);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->barraMenu;
			this->MaximizeBox = false;
			this->Name = L"Interfaz";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Proyecto 3 - Estructuras de Datos";
			this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->barraMenu->ResumeLayout(false);
			this->barraMenu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoVentana))->EndInit();
			this->panelPreguntaIngresa->ResumeLayout(false);
			this->panelPreguntaIngresa->PerformLayout();
			this->contenedorRecorridos->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->grupoContenedorRecorrido->ResumeLayout(false);
			this->grupoContenedorRecorrido->PerformLayout();
			this->tabControl_Reservaciones->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage7->ResumeLayout(false);
			this->tabPage7->PerformLayout();
			this->tabPage8->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void InfoMenu_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("Instituto Tecnológico de Costa Rica\n\nEstructuras de Datos:\nJose Navarro Acuña\nJosué Suárez Campos\n\n2016", "Información", MessageBoxButtons::OK,
			MessageBoxIcon::Asterisk);
	}

	private: System::Void toolSalir_Click(System::Object^  sender, System::EventArgs^  e) {
		if (MessageBox::Show("Desea salir del programa?", "Atencion!", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::Yes) {
			Application::Exit();
		}

	}

	private: System::Void toolViajesMostrar_Click(System::Object^  sender, System::EventArgs^  e) {
		this->cuadroActividades->Text = L"Por favor, espere...";
		//Convierte string a stringSystem
		std::string stringSystem = MostrarViajes(); 
		System::String^ managedString = gcnew String(stringSystem.c_str());
		//-------------------------------
		this->cuadroActividades->Text = managedString;
	}
	private: System::Void toolHotelesMostrar_Click(System::Object^  sender, System::EventArgs^  e) {
		this->cuadroActividades->Text = L"Por favor, espere...";

		std::string stringSystem = MostrarHoteles();
		System::String^ managedString = gcnew String(stringSystem.c_str());

		this->cuadroActividades->Text = managedString;
	}
	private: System::Void toolTransportesMostrar_Click(System::Object^  sender, System::EventArgs^  e) {
		this->cuadroActividades->Text = L"Por favor, espere...";
		
		
		std::string stringSystem = MostrarTransportes();
		System::String^ managedString = gcnew String(stringSystem.c_str());

		this->cuadroActividades->Text = managedString;
	}
	private: System::Void toolViajePrecio_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panelPreguntaIngresa->Enabled = true;
		this->labelTipoConsulta->Text = L"Consultando precio de un viaje";
		this->labelPreguntaTodo->Text = L"- Ingrese el ID-Viaje:";
		opcionEnviarRespuesta = 1; // Medio por el cual se identifica el boton EnviarRespuesta
	}
	private: System::Void toolHotelPrecio_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panelPreguntaIngresa->Enabled = true;
		this->labelTipoConsulta->Text = L"Consultando precio de un hotel";
		this->labelPreguntaTodo->Text = L"- Ingrese el ID-Hotel:";
		opcionEnviarRespuesta = 2;
	}
	private: System::Void toolTransportePrecio_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panelPreguntaIngresa->Enabled = true;
		this->labelTipoConsulta->Text = L"Consultando precio de un transporte";
		this->labelPreguntaTodo->Text = L"- Ingrese el ID-Transporte:";
		opcionEnviarRespuesta = 3;
	}
	private: System::Void toolViajeOrigenDestino_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panelPreguntaIngresa->Enabled = true;
		this->labelTipoConsulta->Text = L"Consultando Origen/Destino de un viaje";
		this->labelPreguntaTodo->Text = L"- Ingrese el ID-Viaje:";
		opcionEnviarRespuesta = 4;
	}
	private: System::Void toolViajePaquetes_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panelPreguntaIngresa->Enabled = true;
		this->labelTipoConsulta->Text = L"Consultando paquetes de un viaje";
		this->labelPreguntaTodo->Text = L"- Ingrese el ID-Viaje:";
		opcionEnviarRespuesta = 5;
	}
	private: System::Void toolHotelCategoria_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panelPreguntaIngresa->Enabled = true;
		this->labelTipoConsulta->Text = L"Consultando categoria de un hotel";
		this->labelPreguntaTodo->Text = L"- Ingrese el ID-Hotel:";
		opcionEnviarRespuesta = 6;
	}
	private: System::Void toolViajeReservado_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panelPreguntaIngresa->Enabled = true;
		this->boxEscribeUsuario->Enabled = true;
		this->labelTipoConsulta->Text = L"Consultando viaje reservado";
		this->labelPreguntaTodo->Text = L"- Ingrese el ID-Cliente:";
		opcionEnviarRespuesta = 7;
	}
	private: System::Void toolHotelReservado_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panelPreguntaIngresa->Enabled = true;
		this->boxEscribeUsuario->Enabled = true;
		this->labelTipoConsulta->Text = L"Consultando hotel reservado";
		this->labelPreguntaTodo->Text = L"- Ingrese el ID-Cliente:";
		opcionEnviarRespuesta = 8;
	}
	private: System::Void toolTransporteReservado_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panelPreguntaIngresa->Enabled = true;
		this->boxEscribeUsuario->Enabled = true;
		this->labelTipoConsulta->Text = L"Consultando transporte reservado";
		this->labelPreguntaTodo->Text = L"- Ingrese el ID-Cliente:";
		opcionEnviarRespuesta = 9;
	}
	private: System::Void toolPrecioReservaciones_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panelPreguntaIngresa->Enabled = true;
		this->labelTipoConsulta->Text = L"Consultando precio de las reservaciones";
		this->labelPreguntaTodo->Text = L"- Ingrese el ID-Cliente:";
		opcionEnviarRespuesta = 10;
	}
	private: System::Void toolInfoCliente_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panelPreguntaIngresa->Enabled = true;
		this->boxEscribeUsuario->Enabled = true;
		this->labelTipoConsulta->Text = L"Consultando información de un cliente";
		this->labelPreguntaTodo->Text = L"- Ingrese el ID-Cliente:";
		opcionEnviarRespuesta = 11;
	}
	private: System::Void toolReservarViaje_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panelPreguntaIngresa->Enabled = true;
		this->labelTipoConsulta->Text = L"Reservando viaje";
		this->boxEscribeUsuario->Enabled = true;
		opcionEnviarRespuesta = 12;
	}
	private: System::Void toolReservarHotel_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panelPreguntaIngresa->Enabled = true;
		this->labelTipoConsulta->Text = L"Reservando hotel:";
		this->boxEscribeUsuario->Enabled = true;
		opcionEnviarRespuesta = 13;
	}
	private: System::Void toolReservarTransporte_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panelPreguntaIngresa->Enabled = true;
		this->labelTipoConsulta->Text = L"Reservando transporte:";
		this->boxEscribeUsuario->Enabled = true;
		opcionEnviarRespuesta = 14;
	}
	private: System::Void toolRealizarRecorridos_Click(System::Object^  sender, System::EventArgs^  e) {
		this->grupoContenedorRecorrido->Enabled = true;
		this->labelPreguntaRecorrido->Text = L"- Seleccione el tipo de recorrido:";

		opcionEnviarRespuesta = 15;
	}

	std::string textBox_obtenerRespuesta() {
		std::string inputUser;

		inputUser = MarshalString(this->boxEscribeUsuario->Text, inputUser);
	
		return inputUser;
	}

	private: System::Void botonEnviarRespuesta_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string escribeUsuario = textBox_obtenerRespuesta();
		std::string respServer;

		if (opcionEnviarRespuesta == 1) {
			respServer = ConsultarPrecioProducto_Viaje(textBox_obtenerRespuesta());
		}

		if (opcionEnviarRespuesta == 2) {
			respServer = ConsultarPrecioProducto_Hotel(textBox_obtenerRespuesta());
		}

		if (opcionEnviarRespuesta == 3) {
			respServer = ConsultarPrecioProducto_Transporte(textBox_obtenerRespuesta());
		}

		if (opcionEnviarRespuesta == 4) {
			respServer = ConsultarOrigenDestidoDeUnViaje(textBox_obtenerRespuesta());
		}

		if (opcionEnviarRespuesta == 5) {
			respServer = ConsultarPaquetesDeUnViaje(textBox_obtenerRespuesta());
		}

		if (opcionEnviarRespuesta == 6) {
			respServer = ConsultarCategoriaDeUnHotel(textBox_obtenerRespuesta());
		}

		if (opcionEnviarRespuesta == 7) {
			respServer = ConsultarViaje_Cliente(textBox_obtenerRespuesta());
		}

		if (opcionEnviarRespuesta == 8) {
			respServer = ConsultarHotel_Cliente(textBox_obtenerRespuesta());
		}

		if (opcionEnviarRespuesta == 9) {
			respServer = ConsultarTransporte_Cliente(textBox_obtenerRespuesta());
		}

		if (opcionEnviarRespuesta == 10) {
			respServer = ConsultarPrecioViajeHotelTransporte_Cliente(textBox_obtenerRespuesta());
		}

		if (opcionEnviarRespuesta == 11) {
			respServer = ConsultarInformacionDeUnCliente(textBox_obtenerRespuesta());
		}

		if (opcionEnviarRespuesta == 12) {

			std::string idCliente;
			idCliente = MarshalString(this->textBox_Cliente_Viaje->Text, idCliente);
			std::string idViaje;
			idViaje = MarshalString(this->textBox_Viaje_Viaje->Text, idViaje);
			std::string numPlazas;
			numPlazas = MarshalString(this->textBox_Plazas_Cliente->Text, numPlazas);

			if (idCliente == "" || idViaje == "" || numPlazas == "") {
				respServer = "Por favor, rellene todos los campos!";
			}
			else {
				respServer = ReservarViaje(idCliente, idViaje, numPlazas);
			}
		}

		if (opcionEnviarRespuesta == 13) {

			std::string idCliente;
			idCliente = MarshalString(this->textBox_Cliente_Hotel->Text, idCliente);
			std::string idHotel;
			idHotel = MarshalString(this->textBox_Hotel_Hotel->Text, idHotel);
			std::string habitacion;
			std::string oferta;

			if (idCliente == "" || idHotel == "") {
				respServer = "Por favor, rellene todos los campos!";
			}
			else {
				if (this->checkBox_Hab_Individual->Checked && this->checkBox_Hab_Doble->Checked) {
					respServer = "Por favor, escoja solo un tipo de habitacion!";
				}
				else {
					if (!this->checkBox_Hab_Individual->Checked && !this->checkBox_Hab_Doble->Checked) {
						respServer = "Por favor, escoja un tipo de habitacion!";
					}
					else {
						if (this->checkBox_Oferta_Aceptar->Checked && this->checkBox_Oferta_Rechazar->Checked) {
							respServer = "Por favor, escoja solo un tipo de oferta!";
						}
						else {
							if (!this->checkBox_Oferta_Aceptar->Checked && !this->checkBox_Oferta_Rechazar->Checked) {
								respServer = "Por favor, escoja una oferta!";
							}
							else {
								if (this->checkBox_Hab_Individual->Checked) {
									habitacion = "0";
								}
								else {
									if (this->checkBox_Hab_Doble->Checked) {
										habitacion = "1";
									}
								}
							}
						}
					}
				}

				if (this->checkBox_Oferta_Aceptar->Checked) {
					oferta = "0";
				}
				else {
					if (this->checkBox_Oferta_Rechazar->Checked) {
						oferta = "1";
					}
				}
			}
			if (habitacion != "" && oferta != "") {
				respServer = ReservarHotel(idCliente, idHotel, habitacion, oferta);
			}

		}

		if (opcionEnviarRespuesta == 14) {
			std::string idCliente;
			idCliente = MarshalString(this->textBox_Cliente_Transporte->Text, idCliente);
			std::string idTransporte;
			idTransporte = MarshalString(this->textBox_Transporte_Transporte->Text, idTransporte);

			if (idCliente == "" || idTransporte == "") {
				respServer = "Por favor, rellene todos los campos!";
			}
			else {
				respServer = ReservarTransporte(idCliente, idTransporte);
			}
		}
		System::String^ managedString = gcnew String(respServer.c_str());
		MessageBox::Show(managedString, "Atención", MessageBoxButtons::OK,
			MessageBoxIcon::Asterisk);
	
	}
	private: System::Void button_Canada_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Canada";
				IDPais_Origen = "12";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Canada";
				IDPais_Llegada = "12";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("12");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Canada", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}

	private: System::Void button_USA_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Estados Unidos";
				IDPais_Origen = "20";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Estados Unidos";
				IDPais_Llegada = "20";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("20");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Estados Unidos", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Mexico_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Mexico";
				IDPais_Origen = "86";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Mexico";
				IDPais_Llegada = "86";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("86");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Mexico", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Cuba_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Cuba";
				IDPais_Origen = "56";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Cuba";
				IDPais_Llegada = "56";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("56");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Cuba", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_ElSalvador_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "El Salvador";
				IDPais_Origen = "09";
			}
			else {
				this->label_LlegadaDijkstra->Text = "El Salvador";
				IDPais_Llegada = "09";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("09");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "El Salvador", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Nicaragua_Click(System::Object^  sender, System::EventArgs^  e) {
		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Nicaragua";
				IDPais_Origen = "70";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Nicaragua";
				IDPais_Llegada = "70";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("70");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Nicaragua", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Belice_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Belice";
				IDPais_Origen = "52";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Belice";
				IDPais_Llegada = "52";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("52");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Belice", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Costa_Rica_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Costa Rica";
				IDPais_Origen = "10";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Costa Rica";
				IDPais_Llegada = "10";
			}	
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("10");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Costa Rica", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Panama_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Panama";
				IDPais_Origen = "34";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Panama";
				IDPais_Llegada = "34";
			}

		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("34");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Panama", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Brasil_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Brasil";
				IDPais_Origen = "45";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Brasil";
				IDPais_Llegada = "45";
			}

		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("45");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Brasil", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Argentina_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Argentina";
				IDPais_Origen = "76";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Argentina";
				IDPais_Llegada = "76";
			}

		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("76");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Argentina", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Chile_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Chile";
				IDPais_Origen = "67";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Chile";
				IDPais_Llegada = "67";
			}
		}
		else {
			std::string respServer = ConsultarViajesDestinosDisponibles("67");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Chile", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Bulgaria_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Bulgaria";
				IDPais_Origen = "38";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Bulgaria";
				IDPais_Llegada = "38";
			}

		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("38");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Bulgaria", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Espania_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "España";
				IDPais_Origen = "80";
			}
			else {
				this->label_LlegadaDijkstra->Text = "España";
				IDPais_Llegada = "80";
			}

		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("80");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "España", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Portugal_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Portugal";
				IDPais_Origen = "31";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Portugal";
				IDPais_Llegada = "31";
			}

		}
		else {
			std::string respServer = ConsultarViajesDestinosDisponibles("31");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Portugal", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_ElCongo_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "El Congo";
				IDPais_Origen = "34";
			}
			else {
				this->label_LlegadaDijkstra->Text = "El Congo";
				IDPais_Llegada = "34";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("34");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "El Congo", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Camerun_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Camerun";
				IDPais_Origen = "18";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Camerun";
				IDPais_Llegada = "18";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("18");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Camerun", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Dinamarca_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Dinamarca";
				IDPais_Origen = "73";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Dinamarca";
				IDPais_Llegada = "73";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("73");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Dinamarca", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Francia_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Francia";
				IDPais_Origen = "23";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Francia";
				IDPais_Llegada = "23";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("23");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Francia", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Italia_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Italia";
				IDPais_Origen = "21";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Italia";
				IDPais_Llegada = "21";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("21");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Italia", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Egipto_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Egipto";
				IDPais_Origen = "20";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Egipto";
				IDPais_Llegada = "20";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("20");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Egipto", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Dubai_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Dubai";
				IDPais_Origen = "03";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Dubai";
				IDPais_Llegada = "03";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("03");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Dubai", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Finlandia_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Finlandia";
				IDPais_Origen = "27";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Finlandia";
				IDPais_Llegada = "27";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("27");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Finlandia", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Alemania_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Alemania";
				IDPais_Origen = "26";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Alemania";
				IDPais_Llegada = "26";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("26");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Alemania", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Eslovaquia_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Eslovaquia";
				IDPais_Origen = "86";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Eslovaquia";
				IDPais_Llegada = "86";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("86");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Eslovaquia", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Grecia_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Grecia";
				IDPais_Origen = "50";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Grecia";
				IDPais_Llegada = "50";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("50");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Grecia", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Armenia_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Armenia";
				IDPais_Origen = "65";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Francia";
				IDPais_Llegada = "65";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("65");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Armenia", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Belgica_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Belgica";
				IDPais_Origen = "52";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Belgica";
				IDPais_Llegada = "52";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("52");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Belgica", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Rusia_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Rusia";
				IDPais_Origen = "20";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Rusia";
				IDPais_Llegada = "20";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("20");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Rusia", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Japon_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Japón";
				IDPais_Origen = "13";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Japón";
				IDPais_Llegada = "13";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("13");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Japon", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_China_Click(System::Object^  sender, System::EventArgs^  e) {

		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "China";
				IDPais_Origen = "15";
			}
			else {
				this->label_LlegadaDijkstra->Text = "China";
				IDPais_Llegada = "15";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("15");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "China", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
	private: System::Void button_Inglaterra_Click(System::Object^  sender, System::EventArgs^  e) {
		if (opcionEnviarRespuesta == 15) {
			if (IDPais_Origen == "") {
				this->label_InicioDijkstra->Text = "Inglaterra";
				IDPais_Origen = "56";
			}
			else {
				this->label_LlegadaDijkstra->Text = "Inglaterra";
				IDPais_Llegada = "56";
			}
		}
		else {

			std::string respServer = ConsultarViajesDestinosDisponibles("56");

			System::String^ managedString = gcnew String(respServer.c_str());
			MessageBox::Show(managedString, "Inglaterra", MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
	}
			 //Anchura
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	mensaje = "19"; // el 19 es el codigo de la funcion que quiero hacer en el servidor
	sockets->enviar(mensaje);
	respuestaServer = sockets->respuesta();
	std::string resultadoBool = "";
	std::string respuesta = "";

	int i = 0;

	while (respuestaServer[i] != ',') {
		resultadoBool += respuestaServer[i];
		i++;
	}
	i++;
	while (respuestaServer[i] != false) {
		if (respuestaServer[i] == ';') {
			respuesta += "\n";
			i++;

		}
		else {
			respuesta += respuestaServer[i];
			i++;
		}
	}

	System::String^ managedString = gcnew String(respuesta.c_str());
	if (resultadoBool == "true") {
		MessageBox::Show(managedString, "Anchura", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

	else {
		MessageBox::Show(managedString, "No sirve la mierda", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

}
		 //Profundidad
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	mensaje = "20"; // el 19 es el codigo de la funcion que quiero hacer en el servidor
	sockets->enviar(mensaje);
	respuestaServer = sockets->respuesta();
	std::string resultadoBool = "";
	std::string respuesta = "";

	int i = 0;

	while (respuestaServer[i] != ',') {
		resultadoBool += respuestaServer[i];
		i++;
	}
	i++;
	while (respuestaServer[i] != false) {
		if (respuestaServer[i] == ';') {
			respuesta += "\n";
			i++;

		}
		else {
			respuesta += respuestaServer[i];
			i++;
		}
	}

	System::String^ managedString = gcnew String(respuesta.c_str());
	if (resultadoBool == "true") {
		MessageBox::Show(managedString, "Profundidad", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

	else {
		MessageBox::Show(managedString, "No sirve la mierda", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

}

		 //Prim
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	mensaje = "21"; // es el codigo de la funcion que quiero hacer en el servidor
	sockets->enviar(mensaje);
	respuestaServer = sockets->respuesta();
	std::string resultadoBool = "";
	std::string respuesta = "";

	int i = 0;

	while (respuestaServer[i] != ',') {
		resultadoBool += respuestaServer[i];
		i++;
	}
	i++;
	while (respuestaServer[i] != false) {
		if (respuestaServer[i] == ';') {
			respuesta += "\n";
			i++;

		}
		else {
			respuesta += respuestaServer[i];
			i++;
		}
	}

	System::String^ managedString = gcnew String(respuesta.c_str());
	if (resultadoBool == "true") {
		MessageBox::Show("El costo del recorrido es: " + managedString, "Prim", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

	else {
		MessageBox::Show(managedString, "No sirve la mierda", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
}
			 //Dijkstra
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

		if (IDPais_Origen == "" || IDPais_Llegada == "") {
			MessageBox::Show("Por favor, escoga un destino y una llegada!", "Atención!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {

			mensaje = "22" + IDPais_Origen; // es el codigo de la funcion que quiero hacer en el servidor
			sockets->enviar(mensaje);
			respuestaServer = sockets->respuesta();
			std::string resultadoBool = "";
			std::string respuesta = "";

			int i = 0;

			while (respuestaServer[i] != ',') {
				resultadoBool += respuestaServer[i];
				i++;
			}
			i++;
			while (respuestaServer[i] != false) {

				respuesta += respuestaServer[i];
				i++;
			}

			int k = 0; std::string nuevoResultado; std::string idViaje; std::string costoMomento; std::string ok;
			int size = respuesta.size();
			while (k < size) {

				if (idViaje == IDPais_Llegada) {
					break;
				}
				else {
					idViaje = "";
					costoMomento = "";
				}

				while (respuesta[k] != ',') {
					idViaje += respuesta[k];
					k++;
				}
				k += 1; // Saltar la coma

				while (respuesta[k] != ';') {
					costoMomento += respuesta[k];
					k++;
				}
				//k += 1;

				nuevoResultado += idViaje + ": " + costoMomento + "\n";

				k++;
			}

			nuevoResultado += "\nDe " + IDPais_Origen + " a " + IDPais_Llegada + ": " + costoMomento;

			System::String^ managedString = gcnew String(nuevoResultado.c_str());
			if (resultadoBool == "true") {
				MessageBox::Show(managedString, "Dijkstra", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}

			else {
				MessageBox::Show(managedString, "No sirve", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}

			this->label_InicioDijkstra->Text = "";
			this->label_LlegadaDijkstra->Text = "";

			IDPais_Origen = "";
			IDPais_Llegada = "";
		}
	}

		 //Kruskal
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	mensaje = "23"; // es el codigo de la funcion que quiero hacer en el servidor
	sockets->enviar(mensaje);
	respuestaServer = sockets->respuesta();
	std::string resultadoBool = "";
	std::string respuesta = "";

	int i = 0;

	while (respuestaServer[i] != ',') {
		resultadoBool += respuestaServer[i];
		i++;
	}
	i++;
	while (respuestaServer[i] != false) {
		if (respuestaServer[i] == ';') {
			respuesta += "\n";
			i++;

		}
		else {
			respuesta += respuestaServer[i];
			i++;
		}
	}

	System::String^ managedString = gcnew String(respuesta.c_str());
	if (resultadoBool == "true") {
		MessageBox::Show("El costo del recorrido es: " + managedString, "Kruskal", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

	else {
		MessageBox::Show(managedString, "No sirve la mierda", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
}
	private: System::Void consultarDestinosToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		opcionEnviarRespuesta = 666;
	}
};
}
