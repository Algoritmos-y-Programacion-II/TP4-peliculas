//
// Created by root-MKevin on 28/6/20.
// Los metodos se encuentran ordenados por el tipo (Modificador, Consultor, etc.)
// y ademas, dentro de cada tipo, ordenados alfabeticamente.

#ifndef PELICULASRECOMENDADAS_H
#define PELICULASRECOMENDADAS_H

#include "Lista.h"
#include "Pelicula.h"
#include "CargadorDePeliculas.h"

const string ARCHIVO_VISTAS = "peliculasVistas.txt";
const string ARCHIVO_NO_VISTAS = "peliculasNoVistas.txt";

const int PUNTAJE_VALIDO = 7;

class PeliculasRecomendadas {

    private:
        // ATRIBUTOS
        Lista<Pelicula*> peliculasVistas;
        Lista<Pelicula*> peliculasNoVistas;
        Lista<Pelicula*> peliculasRecomendadas;
        CargadorDePeliculas cargador;

        // METODOS

        // MODIFICADORES

        //PRE: RECIBE UN PUNTERO DE TIPO PELICULA Y UNA LISTA DE STRINGS (PUEDE TENER O NO TENER DATOS).
        //POST: NO DEVUELVE NADA. SI LA LISTA ESTA VACIA, CARGA TODOS LOS ACTORES. SI YA TIENE DATOS CARGADOS
        //      COMPARA LOS DATOS PARA NO CARGAR UN DATO EXISTENTE.
        void cargarActoresLista(Pelicula *peliculaVista, Lista<string> *actoresVistos);

        //PRE:
        //POST:
        void cargarActoresPelicula(Pelicula *&peliculaLeida, Pelicula *&peliculaRecomendada);

        //PRE:
        //POST:
        void cargarDatosPelicula(Pelicula *&peliculaLeida, Pelicula *&peliculaRecomendada);


        //PRE: RECIBE UN PUNTERO DE TIPO PELICULA Y UNA LISTA DE STRINGS PREVIAMENTE CARGADA.
        //POST: NO DEVUELVE NADA. SI EL DIRECTOR DE LA PELICULA ESTA EN LA LISTA NO HACE NADA,
        //      DE LO CONTRARIO, LO CARGA.
        void cargarDirector(Pelicula *peliculaVista, Lista<string> *directoresVistos);

        //PRE: RECIBE UN PUNTERO DE TIPO PELICULA Y UNA LISTA DE STRINGS PREVIAMENTE CARGADA.
        //POST: NO DEVUELVE NADA. SI EL GENERO DE LA PELICULA ESTA EN LA LISTA NO HACE NADA,
        //      DE LO CONTRARIO, LO CARGA.
        void cargarGenero(Pelicula *peliculaVista, Lista<string> *generosVistos);

        //PRE: RECIBE UN PUNTERO DE TIPO LISTA, DE TIPO PELICULA, Y TRES PUNTEROS DE TIPO LISTA, DE TIPO STRING.
        //     LA LISTA DE TIPO PELICULAS DEBE ESTAR PREVIAMENTE CARGADA. LAS OTRAS DEBEN ESTAR VACIAS.
        //POST: NO DEVUELVE NADA. CARGA LOS DATOS CORRESPONDIENTES EN CADA UNA DE LAS LISTAS.
        void cargarListasAuxiliares(Lista<string> *generosVistos, Lista<string> *directoresVistos,
                Lista<string> *actoresVistos);

        //PRE:
        //POST:
        void cargarListasDePeliculas();

        //PRE:
        //POST:
        void cargarPelicula(Pelicula *&peliculaLeida);

        //PRE:
        //POST:
        void liberarMemoria();

        //PRE: RECIBE UN PUNTERO DE TIPO LISTA DE PELICULA, EN PARTICULAR LAS NO VISTAS, PREVIAMENTE CARGADA.
        //POST: GENERA UNA NUEVA LISTA DE PELICULAS RECOMENDADAS A PARTIR DE PELICULAS CON PUNTAJE MAYOR O IGUAL A 7.
        void recomendarPorPuntaje();

        //PRE: RECIBE DOS PUNTERO DE TIPO LISTA DE PELICULA, PREVIAMENTE CARGADAS.
        //POST: GENERA UNA NUEVA LISTA DE PELICULAS RECOMENDADAS, EN FUNCION DEL GENERO Y DIRECTOR/ACTORES QUE
        //      PARTICIPAN O DE UN PUNTAJE MAYOR O IGUAL A 7.
        void recomendarPeliculas();

        // CONSULTORES

        //PRE: RECIBE UNA PUNTERO DE TIPO PELICULA Y UNA LISTA DE STRING PREVIAMENTE CARGADA.
        //POST: DEVUELVE TRUE SI EL ACTOR ESTA EN LA LISTA, FALSE DE LO CONTRARIO.
        bool actorEncontrado(Pelicula *peliculaLeida, Lista<string> *actoresVistos);

        //PRE:
        //POST:
        void imprimirActores(Lista<string> *actores);

        //PRE:
        //POST:
        void imprimirDatosPelicula(Pelicula* peliculaLeida);

        //PRE:
        //POST:
        void mostrarPeliculasRecomendadas();
    public:

        // METODOS

        // CONSULTORES

        //PRE:
        //POST:
        void mostrarPeliculasVistas();

        //PRE:
        //POST:
        void mostrarPeliculasNoVistas();

        //PRE:
        //POST:
        void verPeliculasRecomendadas();

        // DESTRUCTOR

        //PRE:
        //POST:
        ~PeliculasRecomendadas();
};


#endif //PELICULASRECOMENDADAS_H
