//
// Created by root-MKevin on 28/6/20.
//

#ifndef PELICULASRECOMENDADAS_H
#define PELICULASRECOMENDADAS_H

#include "Lista.h"
#include "Pelicula.h"

const int PUNTAJE_VALIDO = 7;

class PeliculasRecomendadas {

    private:
        // ATRIBUTOS
        Lista<Pelicula> listaPeliculasRecomendadas;

        // METODOS

        // MODIFICADORES

        //PRE: RECIBE UN PUNTERO DE TIPO PELICULA Y UNA LISTA DE STRINGS (PUEDE TENER O NO TENER DATOS).
        //POST: NO DEVUELVE NADA. SI LA LISTA ESTA VACIA, CARGA TODOS LOS ACTORES. SI YA TIENE DATOS CARGADOS
        //      COMPARA LOS DATOS PARA NO CARGAR UN DATO EXISTENTE.
        void cargarActores(Pelicula *peliculaVista, Lista<string> *&actoresVistos);

        //PRE: RECIBE UN PUNTERO DE TIPO PELICULA Y UNA LISTA DE STRINGS PREVIAMENTE CARGADA.
        //POST: NO DEVUELVE NADA. SI EL GENERO DE LA PELICULA ESTA EN LA LISTA NO HACE NADA,
        //      DE LO CONTRARIO, LO CARGA.
        void cargarGenero(Pelicula *peliculaVista, Lista<string> *&generosVistos);

        //PRE: RECIBE UN PUNTERO DE TIPO PELICULA Y UNA LISTA DE STRINGS PREVIAMENTE CARGADA.
        //POST: NO DEVUELVE NADA. SI EL DIRECTOR DE LA PELICULA ESTA EN LA LISTA NO HACE NADA,
        //      DE LO CONTRARIO, LO CARGA.
        void cargarDirector(Pelicula *peliculaVista, Lista<string> *&directoresVistos);

        //PRE: RECIBE UN PUNTERO DE TIPO LISTA, DE TIPO PELICULA, Y TRES PUNTEROS DE TIPO LISTA, DE TIPO STRING.
        //     LA LISTA DE TIPO PELICULAS DEBE ESTAR PREVIAMENTE CARGADA. LAS OTRAS DEBEN ESTAR VACIAS.
        //POST: NO DEVUELVE NADA. CARGA LOS DATOS CORRESPONDIENTES EN CADA UNA DE LAS LISTAS.
        void cargarListasAuxiliares(Lista<Pelicula> *peliculasVistas, Lista<string> *&generosVistos,
                                Lista<string> *&directoresVistos, Lista<string> *&actoresVistos);

        // CONSULTORES

        //PRE: RECIBE UNA PUNTERO DE TIPO PELICULA Y UNA LISTA DE STRING PREVIAMENTE CARGADA.
        //POST: DEVUELVE TRUE SI EL ACTOR ESTA EN LA LISTA, FALSE DE LO CONTRARIO.
        bool actorEncontrado(Pelicula *peliculaNoVista, Lista<string> *actoresVistos);

    public:

        // METODOS

        // CONSTRUCTOR

        //PRE: NO RECIBE NADA.
        //POST: CREA UN OBJETO DE TIPO PeliculasRecomendadas.

        PeliculasRecomendadas();

        // MODIFICADOR

        //PRE: RECIBE UN PUNTERO DE TIPO LISTA DE PELICULA, EN PARTICULAR LAS NO VISTAS, PREVIAMENTE CARGADA.
        //POST: GENERA UNA NUEVA LISTA DE PELICULAS RECOMENDADAS A PARTIR DE PELICULAS CON PUNTAJE MAYOR O IGUAL A 7.
        void recomendarPeliculas(Lista<Pelicula> *peliculasNoVistas);

        //PRE: RECIBE DOS PUNTERO DE TIPO LISTA DE PELICULA, PREVIAMENTE CARGADAS.
        //POST: GENERA UNA NUEVA LISTA DE PELICULAS RECOMENDADAS, EN FUNCION DEL GENERO Y DIRECTOR/ACTORES QUE
        //      PARTICIPAN O DE UN PUNTAJE MAYOR O IGUAL A 7.
        void recomendarPeliculas(Lista<Pelicula> *peliculasVistas, Lista<Pelicula> *peliculasNoVistas);

        // CONSULTORES

        //PRE: NO RECIBE NADA.
        //POST: DEVUELVE UN PUNTERO DE TIPO LISTA DE PELICULA, DIRECCIONADO AL ATRIBUTO listaPeliculasRecomendadas.
        Lista<Pelicula> *obtenerPeliculasRecomendadas();

};


#endif //PELICULASRECOMENDADAS_H
