//
// Created by root-MKevin on 28/6/20.
//
// Los atributos estan ordenados por tipo y alfabeticamente. Los metodos estan ordenados segun su
// "clasificacion" (Constructor, consultor, etc.) y dentro de cada clasificacion, tambien
// ordenados alfabeticamente.
// NOTA: Los parametros de un metodo podrian estar ordenados segun la forma del archivo peliculas.


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

        // MODIFICADORES

        //PRE: RECIBE UN PUNTERO DE TIPO LISTA DE STRING.
        //POST: NO DEVUELVE NADA. LE ASIGNA LOS VALORES DE LA LISTA RECIBIDA AL ATRIBUTO ACTORES
        void igualarListasActores(Lista<string> actoresRecibidos);

        // CONSULTORES

        //PRE: NO RECIBE NADA.
        //POST: NO DEVUELVE NADA. ITERA SOBRE LA LISTA E IMPRIME LOS DATOS.
        void imprimirActores();

    public:

        // METODOS

        // CONSTRUCTORES

        //PRE: NO RECIBE NADA.
        //POST: CONSTRUYE UNA PELICULA CON SUS ATRIBUTOS EN CERO Y VACIO SEGUN CORRESPONDA.
        Pelicula();

        // MODIFICADORES

        //PRE: RECIBE UN STRING.
        //POST: NO DEVUELVE NADA. LO CARGA EN LA LISTA DE ACTORES.
        void cargarActor(string actorRecibido);

        //PRE: RECIBE UN STRING.
        //POST: NO DEVUELVE NADA. LE ASIGNA EL VALOR AL ATRIBUTO DIRECTOR.
        void cargarDirector(string directorRecibido);

        //PRE: RECIBE UN STRING.
        //POST: NO DEVUELVE NADA. LE ASIGNA EL VALOR AL ATRIBUTO GENERO.
        void cargarGenero(string generoRecibido);

        //PRE: RECIBE UN ENTERO VALIDO. 0 <= puntajeRecibido <= 10;
        //POST: NO DEVUELVE NADA. LE ASIGNA EL VALOR AL ATRIBUTO PUNTAJE.
        void cargarPuntaje(int puntajeRecibido);

        //PRE: RECIBE UN STRING.
        //POST: NO DEVUELVE NADA. LE ASIGNA EL VALOR AL ATRIBUTO TITULO.
        void cargarTitulo(string tituloRecibido);

        // CONSULTORES

        //PRE: NO RECIBE NADA.
        //POST: IMPRIME LOS ATRIBUTOS DE LA PELICULA.
        void imprimirDatosPelicula();

        //PRE: NO RECIBE NADA.
        //POST: DEVUELVE UN PUNTERO DE TIPO LISTA, ESPECIFICAMENTE, DIRECCIONADO A LA LISTA ACTORES.
        Lista<string> *obtenerActores();

        //PRE: NO RECIBE NADA.
        //POST: DEVUELVE EL STRING ALMACENADO EN EL ATRIBUTO GENERO.
        string obtenerGenero();

        //PRE: NO RECIBE NADA.
        //POST: DEVUELVE EL STRING ALMACENADO EN EL ATRIBUTO DIRECTOR.
        string obtenerDirector();

        //PRE: NO RECIBE NADA.
        //POST: DEVUELVE EL STRING ALMACENADO EN EL ATRIBUTO PUNTAJE.
        int obtenerPuntaje();

        //PRE: NO RECIBE NADA.
        //POST: DEVUELVE EL STRING ALMACENADO EN EL ATRIBUTO TITULO.
        string obtenerTitulo();
};


#endif //PELICULA_H
