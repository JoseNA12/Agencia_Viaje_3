#ifndef NODODESTINO_H
#define NODODESTINO_H

class NodoDestino
{
    int idDestino;
    int Nombre;
public:
    NodoCliente(int _t, bool _leaf);
    void InsertaNodo(int k);
    void DividirNodo(int i, NodoCliente *y);

    void atravesar();
    NodoCliente *buscar(int k);

    friend class lista;
};

#endif // NODODESTINO_H
