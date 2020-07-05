#include "CargadorDePeliculas.h"

/*1)*/bool CargadorDePeliculas::existePeliculasNoVistas() {
    return archivo.existeRuta(PELICULAS_NO_VISTAS))
}

/*2)*/void CargadorDePeliculas::cargar(string camino, Lista<*Pelicula> &cartelera){

    Pelicula *peli;
    string lectura;
    int puntuacion;

    arch.abrirArchivo(camino);

    while(!arch.finalArchivo()){
        peli = new Pelicula;

        //Carga Titulo
        lectura = archivo.leerLinea();
        peli->cargarTitulo(lectura);

        //Carga Genero
        lectura = archivo.leerLinea();
        peli->cargarGenero(lectura);

        //Carga Puntuacion
        lectura = archivo.leerLinea();//Lee
        puntuacion = atoi(lectura.c_str());
        peli->cargarPuntaje(puntuacion);

        //Carga Director
        lectura = archivo.leerLinea();
        peli->cargarDirector(lectura);

        //Carga Actores
        lectura = archivo.leerLinea();
        cargarListaDeActores(lectura, peli);

        //Agrega peli al final de la lista
        cartelera.agregarAlFinal(peli);
     }
}

/*3)*/void CargadorDePeliculas::cargarListaDeActores(string actores, Pelicula *&peli){

    string actor;
    char caracter;

    for(int contador = 0; contador < lectura.length(); contador++){

        incice = actores[contador];
        if((indice != ' ')&&(indice != '\000'))
            actor=+indice;

        else{
            peli->cargarActor(actor);
            actor.erase(0,contador);
        }
    }
}

/*
//Funcion opcional que libera las listas de actores dentro decada *Pelicula de la lista
//IMPORTANTE: debe existir el Metodo:  vaciarListaDeActores en peliculas
void CargadorDePeliculas::VaciarCartelera(Lista<*Pelicula> &cartelera){
    Pelicula *peli;
    int cantidadDeElementos;
    cantidadDeElementos=cartelera.obtenerCantidadElementos();
    for(int i=0; i=< cantidadDeElementos;i++){
        peli=cartelera.obtenerDato(i);
        &peli.vaciarListaDeActores();
    }
}
*/
