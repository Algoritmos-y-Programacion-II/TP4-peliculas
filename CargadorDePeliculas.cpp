#include "CargadorDePeliculas.h"

/*1)*/void CargadorDePeliculas::cargar(string camino, Lista<Pelicula*> &cartelera){
    Pelicula *peli;
    string lectura;
    int puntuacion;

    arch.abrirArchivo(camino);

    while(!arch.finalArchivo()){
        peli = new Pelicula;

        //Carga Titulo
        lectura=arch.leerLinea();
        peli->cargarTitulo(lectura);

        //Carga Genero
        lectura=arch.leerLinea();
        peli->cargarGenero(lectura);

        //Carga Puntuacion
        lectura=arch.leerLinea();
        puntuacion=atoi(lectura.c_str());
        peli->cargarPuntaje(puntuacion);

        //Carga en Director
        lectura=arch.leerLinea();
        peli->cargarDirector(lectura);

        //Carga Actores
        lectura=arch.leerLinea();
        cargarListaDeActores(lectura, peli);

        cartelera.agregarAlFinal(peli);
        
        lectura=arch.leerLinea();
     }
     arch.cerrarArchivo();
}

/*2)*/void CargadorDePeliculas::cargarListaDeActores(string actores,Pelicula *&peli){

    string actor;
    char caracter;

    for (unsigned int contador = 0; contador < actores.length(); contador++) {

        caracter = actores[contador];
        if ((caracter != ' ') && (caracter != '\000')) {
            actor+=caracter;
        }
        else {
            peli->cargarActor(actor);
            actor.erase(0,contador);
        }
    }

}

/*3)*/
bool CargadorDePeliculas::existeRuta(string ruta) {
    return arch.existeRuta(ruta);
}
