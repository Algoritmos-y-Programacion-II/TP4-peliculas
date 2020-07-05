//Descripcion:Una clase pensada para cargar una Listas<*Peliculas>
// Tiene dos atributos. Los metodos estan ordenados segun
// un numero 'i)'.
//Nota:Los atributos estan al final


#ifndef CARGADORDEPELICULAS_H
#define CARGADORDEPELICULAS_H
#include "Archivos.h"
#include "Lista.h"
#include "Pelicula.h"

using namespace std;
class CargadorDePeliculas
{
    public:
        /*Metodos*/
        //1)
        // PRE: Deben proporcionarse un string y lista validos como argumentos
        // POST: Setea el numero de peliculas cargadas en 0 (numeroPelicula)
        void cargar(string camino,Lista<*Pelicula> &cartelera);
        //3)
        // PRE: -
        // POST: Si existe el archivo de peliculas no vistas devuelve true, de lo contrario false
        bool existePeliculasNoVistas();
        //4)
        //PRE: La lista debe estar cargada
        //POST: Vacia todas las listas de actores de cada elemento de la lista
        //void CargadorDePeliculas::vaciarActores(Lista<Pelicula*> &cartelera)

    private:

        //2)
        // PRE: Deben proporcionarse un string y puntero a pelicula validos como argumentos
        // POST: Carga la sublista de actores en la pelicula
        void cargarListaDeActores(string actores, Pelicula *&peli);

       /*Atributos*/
        Archivos arch;
};

#endif // CARGADORDEPELICULAS_H
