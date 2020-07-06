#include "CargadorDePeliculas.h"

/*1)*/void CargadorDePeliculas::cargar(string camino, Lista<Pelicula*> &cartelera){
    /*
    Funciona creando uno a uno objetos Pelicula, alojados en memoria dinamica, y cargandolos desde un archivo,
    e introduciendo el puntero que los señalaal final de Lista<*Pelicula>
    */
    //NOTA: El metodo fue adaptado de otro que cargaba un objeto Pelicula en lugar de un puntero. keep an eye for gramar erros

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
        puntuacion=stoi(lectura);
        peli->cargarPuntaje(puntuacion);

        //Carga en Director
        lectura=arch.leerLinea();
        peli->cargarDirector(lectura);

        //Carga Actores
        lectura=arch.leerLinea();
        cargarListaDeActores(lectura, peli);

        cartelera.agregarAlFinal(peli);
     }
     cargas++;
}

/*2)*/void CargadorDePeliculas::cargarListaDeActores(string actores,Pelicula *&peli){
    /*
    Toma un string donde esta cargada la linea del archivo donde se nombra a todos los actores (nombre_apellido)
    separados por espacios, y la desarma caracter a caracter, guardando en "actor" todos los caracteres que no se corresponden
    con espacios. Finalmente, carga al actor en la lista
    */

    string actor;
    char caracter;

    for (int contador = 0; contador < lectura.length(); contador++) {

        caracter = actores[contador];
        if ((indice != ' ') && (indice != '\000')) {
            actor+=indice;
        }
        else {
            peli->cargarActor(actor);
            actor.erase(0,contador);
        }
    }

}

/*3)*/
bool CargadorDePeliculas::existePeliculasNoVistas() {
    return arch.existeRuta(PELICULAS_NO_VISTAS);
}

/*4)*//*
//Funcion opcional que libera las listas de actores dentro de cada *Pelicula de la lista
//IMPORTANTE: debe existir el Metodo:  vaciarListaDeActores en peliculas
void CargadorDePeliculas::vaciarCartelera(Lista<Pelicula*> &cartelera){
    Pelicula *peli;
    int cantidadDeElementos;
    cantidadDeElementos=cartelera.obtenerCantidadElementos();
    for(int i=0; i=< cantidadDeElementos;i++){
        peli=cartelera.obtenerDato(i);
        &peli.vaciarListaDeActores();
    }
}
*/
