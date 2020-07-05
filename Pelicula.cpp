//
// Created by root-MKevin on 28/6/20.
//
// Los metodos estan ordenados alfabeticamente sin distincion de su "clasificacion".
// NOTA: Si hubiese algun constructor, este aparecera primero. Si hubiese algun destructor,
//       estara al final.


#include "Pelicula.h"

Pelicula::Pelicula(){
    titulo = "";
    genero = "";
    director = "";
    puntaje = 0;
}

Pelicula::Pelicula(Pelicula otraPelicula){
    titulo = otraPelicula.titulo;
    genero = otraPelicula.genero;
    director = otraPelicula.director;
    puntaje = otraPelicula.puntaje;
    igualarListasActores(otraPelicula.actores);
}

void Pelicula::cargarActor(string actorRecibido){
    actores.agregarAlFinal(actorRecibido);
}

void Pelicula::cargarDirector(string directorRecibido){
    director = directorRecibido;
}

void Pelicula::cargarGenero(string generoRecibido){
    genero = generoRecibido;
}

void Pelicula::cargarPuntaje(int puntajeRecibido){
    puntaje = puntajeRecibido;
}

void Pelicula::cargarTitulo(string tituloRecibido){
    titulo = tituloRecibido;
}

void igualarListasActores(Lista<string> *actoresRecibidos){
    string actorAuxiliar;
    for(int i = 0; actoresRecibidos->obtenerCantidadElementos; i++){
        actorAuxiliar = actoresRecibidos->obtenerDato(i);
        actores.agregarAlFinal(actorAuxiliar);
    }
}

Lista* Pelicula::obtenerActores(){
    return &actores;
}

string Pelicula::obtenerGenero(){
    return genero;
}

string Pelicula::obtenerDirector(){
    return director;
}

int Pelicula::obtenerPuntaje(){
    return puntaje;
}

string Pelicula::obtenerTitulo(){
    return titulo;
}

Pelicula Pelicula::operator=(Pelicula otraPelicula){
    titulo = otraPelicula.titulo;
    genero = otraPelicula.genero;
    director = otraPelicula.director;
    puntaje = otraPelicula.puntaje;
    igualarListasActores(otraPelicula.actores);
}