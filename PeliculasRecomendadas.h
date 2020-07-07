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

        //PRE: AMBOS PARAMETROS TIENEN QUE SER PUNTEROS DE TIPO PELICULA VALIDOS
        //POST: CARGA LA LISTA DE ACTORES DE LA PELICULA LEIDA, EN LA RECOMENDADA
        void cargarActoresPelicula(Pelicula *&peliculaLeida, Pelicula *&peliculaRecomendada);

        //PRE: AMBOS PARAMETROS TIENEN QUE SER PUNTEROS DE TIPO PELICULA VALIDOS
        //POST: CARGA LOS DATOS DE LA PELICULA LEIDA, EN LA RECOMENDADA
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

        //PRE: RECIBE LA REFERENCIA DE UN PUNTERO DE TIPO PELICULA VALIDO
        //POST: CARGA LA PELICULA EN LA LISTA DE RECOMENDADAS
        void cargarPelicula(Pelicula *&peliculaLeida);

        //PRE: -
        //POST: SI LA LISTA DE RECOMENDADAS ESTA VACIA LLAMA A LOS METODOS QUE REALIZAN LA CARGA DE DATOS
        //      DE LO CONTRARIO NO HACE NADA.
        void crearPeliculasRecomendadas();

        //PRE: -
        //POST: LIBERA LOS RECURSOS UTILIZADOS
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

        //PRE: LA LISTA DE ACTORES TIENE QUE ESTAR CARGADA
        //POST: MUESTRA POR PANTALLA LOS ACTORES
        void imprimirActores(Lista<string> *actores);

        //PRE: LA PELICULA TIENE QUE SER VALIDA
        //POST: MUESTRA POR PANTALLA LA INFORMACION DE LA PELICULA
        void imprimirDatosPelicula(Pelicula* peliculaLeida);

    public:

        // METODOS

        // CONSTRUCTOR
        //PRE: -
        //POST: Si peliculasNoVistas.txt existe, carga las listas de peliculas vistas y no vistas
        //      De lo contrario finaliza la ejecucion del programa
        PeliculasRecomendadas();

        // CONSULTORES

        //PRE: -
        //POST: MUESTRA LAS PELICULAS VISTAS
        void mostrarPeliculasVistas();

        //PRE: -
        //POST: MUESTRA LAS PELICULAS NO VISTAS
        void mostrarPeliculasNoVistas();

        //PRE: -
        //POST: MUESTRA POR PANTALLA LAS PELICULAS RECOMENDADAS
        void mostrarPeliculasRecomendadas();

        // DESTRUCTOR

        //PRE: -
        //POST: LIBERA LOS RECURSOS UTILIZADOS
        ~PeliculasRecomendadas();
};


#endif //PELICULASRECOMENDADAS_H
