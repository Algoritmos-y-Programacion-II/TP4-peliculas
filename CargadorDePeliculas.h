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
class CargadorDePeliculas
{
    public:
        /*Funciones*/
        //1)
        // PRE: -
        // POST: Crea el constructor. Setea el numero de peliculas cargadas en 0 (numeroPelicula)
        CargadorDePeliculas();
        //2)
        // PRE: -
        // POST: Es una mera formalidad
        ~CargadorDePeliculas();
        //3)
        // PRE: Deven Proporcionarse un archivo y Lista validos como argumentos
        // POST: Setea el numero de peliculas cargadas en 0 (numeroPelicula)
        void cargar(string camino,Lista<Pelicula> &cartelera);
        //5)
        //PRE: la lista debe estar cargada
        //POST: Vacia todas las listas de actores de cada elemento de la lista
        //void CargadorDePeliculas::VaciarActores(Lista<*Pelicula> &cartelera)

    protected:

    private:

        //4)
        // PRE: Deven Proporcionarse un archivo y Lista validos como argumentos
        // POST: Carga La sublista "Actores" dentro de peli a partir de un unico string
        void cargarListaDeActores(string lectura,Pelicula *peli);


       /*Atributos*/
       //Cuenta la cantidad de objetos cargados
        Archivos arch;
}

#endif // CARGADORDEPELICULAS_H
