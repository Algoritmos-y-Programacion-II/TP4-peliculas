//Descripcion:Una clase pensada para cargar una Listas<*Peliculas>
// Tiene un unico atributo. Los metodos estan ordenados segun
// un numero 'i)'.
//Nota:Los atributos estan al final


#ifndef CARGADORDEPELICULAS_H
#define CARGADORDEPELICULAS_H
#include"Archivos.h"
#include"Lista.h"
#include"Pelicula.h"

using namespace std;

const string PELICULAS_NO_VISTAS = "peliculasNoVistas.txt";
const string PELICULAS_VISTAS = "peliculasVistas.txt";

class CargadorDePeliculas {
    public:
        /*Metodos*/
        //1)
        // PRE: -
        // POST: Crea el constructor. Setea el numero de peliculas cargadas en 0 (numeroPelicula)
        CargadorDePeliculas();

        //2)
        // PRE: Deben proporcionarse un string y lista validos como argumentos
        // POST: Carga los datos del archivo en la lista de peliculas
        void cargar(string camino, Lista<Pelicula*> &cartelera);

        //3)
        //PRE: la lista debe estar cargada
        //POST: Vacia todas las listas de actores de cada elemento de la lista
        //void CargadorDePeliculas::VaciarActores(Lista<*Pelicula> &cartelera)

    private:

        //4)
        // PRE: Deben proporcionarse un string y lista validos como argumentos
        // POST: Carga la lista de actores en la pelicula
        void cargarListaDeActores(string actores, Pelicula *&peli);

       /*Atributos*/
        Archivos archivo;
};

#endif // CARGADORDEPELICULAS_H
