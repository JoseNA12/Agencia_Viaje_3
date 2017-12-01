#include "Hilo.h"
#include <iostream>
#include <string>

using namespace std;

SocketT::SocketT()
{

}


SocketT::~SocketT()
{
}
void SocketT::enviar(SOCKET auxiliar, string mensaje) {
	socketConeccion = auxiliar;
	string userinput = mensaje;
	//getline(cin, userinput); //Get line if user presses enter and fill the buffer
	int bufferlength = userinput.size(); //Find buffer length
	send(socketConeccion, (char*)&bufferlength, sizeof(int), NULL); //Send length of buffer
	send(socketConeccion, userinput.c_str(), bufferlength, NULL); //Send buffer
}
string SocketT::recibir(SOCKET auxiliar) {
	socketConeccion = auxiliar;
	int bufferlength;
	recv(socketConeccion, (char*)&bufferlength, sizeof(int), NULL); //receive buffer
	char * buffer = new char[bufferlength + 1]; //Allocate buffer
	buffer[bufferlength] = '\0'; //Set last character of buffer to be a null terminator so we aren't printing memory that we shouldn't be looking at
	recv(socketConeccion, buffer, bufferlength, NULL);
	string respuesta = "";
	for (int i = 0; i < bufferlength; i++) {
		respuesta = respuesta + buffer[i];
	}
	delete[] buffer; //Deallocate buffer
	return respuesta;
}