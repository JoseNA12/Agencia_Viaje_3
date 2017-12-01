#include "Interfaz.h"
#include <iostream>
#include <locale.h>

[System::STAThread]
void Main(array<System::String^>^ arg) {
	
	try {
		sockets = new ClienteSocket();			//Inicializacion del socket	
		sockets->respuesta();					//Inicializacion del socket

		System::Windows::Forms::Application::EnableVisualStyles();
		System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

		Cliente::Interfaz form;
		System::Windows::Forms::Application::Run(%form);
	
		system("pause");
	}

	catch(const std::exception e){
		System::Windows::Forms::MessageBox::Show("Verifique que el sevidor esté activo y que los puertos IP coincidan con el servidor.\nEl servidor y el cliente deben estar conectados a la misma red.", "Error al conectarse con el servidor", System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Error);
	}
}

