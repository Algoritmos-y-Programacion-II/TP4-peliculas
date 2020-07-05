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
        // POST: Si existe el archivo de peliculas no vistas devuelve true, de lo contrario false
        bool existePeliculasNoVistas();

        //2)
        // PRE: Deben proporcionarse un string y lista validos como argumentos
        // POST: Carga los datos del archivo en la lista de peliculas
        void cargar(string camino, Lista<Pelicula*> &cartelera);

    private:

        //3)
        // PRE: Deben proporcionarse un string y lista validos como argumentos
        // POST: Carga la lista de actores en la pelicula
        void cargarListaDeActores(string actores, Pelicula *&peli);

       /*Atributos*/
        Archivos archivo;
};

#endif // CARGADORDEPELICULAS_H
