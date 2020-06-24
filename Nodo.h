#ifndef TP4_RECOMENDACIONPELICULA_NODO_H
#define TP4_RECOMENDACIONPELICULA_NODO_H

#include <iostream>

template <typename Tipo>
class Nodo {

private:
    Tipo dato;
    Nodo* pSig;

public:

    // PRE: datoExterno debe ser valido
    // POST: Construye un nodo con el dato recibido
    Nodo(Tipo datoExterno);

    // PRE: El nodo debe estar creado
    // POST: Libera la memoria del nodo
    ~Nodo();

    // PRE: pSigExterno debe ser valido
    // POST: Le asigna pSigExterno a pSig
    void asignarSiguiente(Nodo* pSigExterno);

    // PRE: datoExterno debe ser valido
    // POST: Le asigna datoExterno a dato
    void asignarDato(Tipo datoExterno);

    // PRE: -
    // POST: Devuelve dato
    Tipo obtenerDato();

    // PRE: -
    // POST: Devuelve pSig
    Nodo* obtenerSiguiente();

    // PRE: -
    // POST: Muestra los datos del nodo
    void mostrarNodo();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename Tipo>
Nodo<Tipo>:: Nodo(Tipo datoExterno) {
    dato = datoExterno;
    pSig = 0;
}

template <typename Tipo>
Nodo<Tipo>:: ~Nodo() {
    delete dato;
}

// <-------------------- Asignaciones
template <typename Tipo>
void Nodo<Tipo>:: asignarSiguiente(Nodo<Tipo>* pSigExterno) {
    pSig = pSigExterno;
}

template <typename Tipo>
Nodo<Tipo>* Nodo<Tipo>:: obtenerSiguiente() {
    return pSig;
}
// -------------------->

// <-------------------- Obtenciones
template <typename Tipo>
void Nodo<Tipo>:: asignarDato(Tipo datoExterno) {
    dato = datoExterno;
}

template <typename Tipo>
Tipo Nodo<Tipo>:: obtenerDato() {
    return dato;
}
// -------------------->

template <typename Tipo>
void Nodo<Tipo>:: mostrarNodo() {
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "Nodo ->   Dato: " << dato << "   Dirección: " << this << "   Siguiente: " << pSig << "\n";
    std::cout << "----------------------------------------------------------------\n\n";
}

#endif //TP4_RECOMENDACIONPELICULA_NODO_H
