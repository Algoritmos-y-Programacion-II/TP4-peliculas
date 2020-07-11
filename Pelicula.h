#ifndef PELICULA_H
#define PELICULA_H

#include "Lista.h"

using namespace std;

class Pelicula {
    private:

        // ATRIBUTOS

        string genero;
        string titulo;
        string director;
        int puntaje;
        Lista<string> actores;

        // METODOS

        // CONSULTORES

        //PRE: NO RECIBE NADA.
        //POST: NO DEVUELVE NADA. ITERA SOBRE LA LISTA E IMPRIME LOS DATOS.
        void imprimirActores();

    public:

        // METODOS

        // CONSTRUCTORES

        //PRE: -
        //POST: CONSTRUYE UNA PELICULA CON SUS ATRIBUTOS EN CERO Y VACIO SEGUN CORRESPONDA.
        Pelicula();

        // MODIFICADORES

        //PRE: -.
        //POST: NO DEVUELVE NADA. LO CARGA EN LA LISTA DE ACTORES.
        void cargarActor(string actorRecibido);

        //PRE: -
        //POST: NO DEVUELVE NADA. LE ASIGNA EL VALOR AL ATRIBUTO DIRECTOR.
        void cargarDirector(string directorRecibido);

        //PRE: -
        //POST: NO DEVUELVE NADA. LE ASIGNA EL VALOR AL ATRIBUTO GENERO.
        void cargarGenero(string generoRecibido);

        //PRE: 0 <= puntajeRecibido <= 10;
        //POST: NO DEVUELVE NADA. LE ASIGNA EL VALOR AL ATRIBUTO PUNTAJE.
        void cargarPuntaje(int puntajeRecibido);

        //PRE: -
        //POST: NO DEVUELVE NADA. LE ASIGNA EL VALOR AL ATRIBUTO TITULO.
        void cargarTitulo(string tituloRecibido);

        // CONSULTORES

        //PRE: -
        //POST: IMPRIME LOS ATRIBUTOS DE LA PELICULA.
        void imprimirDatosPelicula();

        //PRE: -
        //POST: DEVUELVE UN PUNTERO DE TIPO LISTA, ESPECIFICAMENTE, DIRECCIONADO A LA LISTA ACTORES.
        Lista<string> *obtenerActores();

        //PRE: -
        //POST: DEVUELVE EL STRING ALMACENADO EN EL ATRIBUTO GENERO.
        string obtenerGenero();

        //PRE: -
        //POST: DEVUELVE EL STRING ALMACENADO EN EL ATRIBUTO DIRECTOR.
        string obtenerDirector();

        //PRE: -
        //POST: DEVUELVE EL STRING ALMACENADO EN EL ATRIBUTO PUNTAJE.
        int obtenerPuntaje();

        //PRE: -
        //POST: DEVUELVE EL STRING ALMACENADO EN EL ATRIBUTO TITULO.
        string obtenerTitulo();
};


#endif //PELICULA_H
