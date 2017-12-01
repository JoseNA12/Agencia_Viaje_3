#pragma once
#include <winsock.h>
#include <string>
#include <iostream>

//using namespace std;
class SocketT
{
public:
	SocketT();
	~SocketT();

	void enviar(SOCKET auxiliar, std::string mensaje);
	std::string recibir(SOCKET auxiliar);

	SOCKET socketConeccion;

};
