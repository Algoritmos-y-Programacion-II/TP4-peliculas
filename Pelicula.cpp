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

Lista<string>* Pelicula::obtenerActores(){
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

void Pelicula::imprimirActores(){
    std::cout << "\tREPARTO: ";
    for(int i=0; i < actores.obtenerCantidadElementos(); i++){
        std::cout << actores.obtenerDato(i) << " ";
    }
}

void Pelicula::imprimirDatosPelicula(){
    std::cout << "\n\tTITULO: " << titulo << std::endl;
    std::cout << "\tGENERO: " << genero << std::endl;
    std::cout << "\tPUNTAJE: " << puntaje << std::endl;
    std::cout << "\tDIRECTOR: " << director << std::endl;
    imprimirActores();
}