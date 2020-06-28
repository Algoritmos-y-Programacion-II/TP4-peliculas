//
// Created by root-MKevin on 28/6/20.
//
// Los atributos estan ordenados por tipo y alfabeticamente. Los metodos estan ordenados segun su
// "clasificacion" (Constructor, consultor, etc.) y dentro de cada clasificacion, tambien
// ordenados alfabeticamente.
// NOTA: Los parametros de un metodo podrian estar ordenados segun la forma del archivo peliculas.
//
//FORMA DE ARCHIVO PELICULA:
//Nombre_pelicula
//Género
//Puntaje
//Director/a
//actor/actriz_1  actor/actriz_2... actor/actriz_n

#ifndef PELICULA_H
#define PELICULA_H

#include "Lista.h"
#include "Persona.h"

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

        //PRE:
        //POST:
        void igualarListasActores(Lista<string> *actoresRecibidos);

    public:

        // METODOS

        // CONSTRUCTORES

        //PRE: NO RECIBE NADA.
        //POST: CONSTRUYE UNA PELICULA CON SUS ATRIBUTOS EN CERO Y VACIO SEGUN CORRESPONDA.
        Pelicula();

        //PRE:
        //POST:
        Pelicula(Pelicula otraPelicula);

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

        Pelicula operator=(Pelicula otraPelicula);

        // CONSULTORES

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
