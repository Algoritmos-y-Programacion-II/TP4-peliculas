//
// Created by daseos on 28/6/20.
//

#include "PeliculasRecomendadas.h"

PeliculasRecomendadas(){
    listaPeliculasRecomendadas = 0;
}

bool PeliculasRecomendadas::actorEncontrado(Pelicula *peliculaNoVista, Lista<string> *actoresVistos){
    Lista<string> *listaAuxiliar = peliculaNoVista->obtenerActores;
    bool actorEnLista = false;
    int i = 0;
    while( (i < listaAuxiliar->obtenerCantidadElementos) && !actorEnLista ){
        string actorLeido = listaAuxiliar->obtenerDato(i);
        if(datoEnLista(actorLeido, actoresVistos)){
            actorEnLista = true;
        }
        i++;
    }
    return actorEnLista;
}

void PeliculasRecomendadas::cargarActores(Pelicula *peliculaVista, Lista <string> *&actoresVistos){
    Lista <string> *listaAuxiliar;
    if(actoresVistos->obtenerCantidadElementos == 0){
        listaAuxiliar = peliculaVista->obtenerActores;
        for(int i=0; listaAuxiliar->obtenerCantidadElementos; i++){
            actoresVistos->agregarAlFinal(listaAuxiliar->obtenerDato(i));
        }
    }
    else{
        for(int i=0; listaAuxiliar->obtenerCantidadElementos; i++){
            string actorVisto = listaAuxiliar->obtenerDato(i);
            if( !datoEnLista(actorVisto, actoresVistos) ){
                actoresVistos->agregarAlFinal(actorVisto);
            }
        }
    }
}

void PeliculasRecomendadas::cargarDirector(Pelicula *peliculaVista, Lista<string> *&directoresVistos){

    string directorAuxiliar = peliculaVista->obtenerDirector;
    if( !datoEnLista(directorAuxiliar, directoresVistos) ){
        directoresVistos->agregarAlFinal(directorAuxiliar);
    }
}

void PeliculasRecomendadoas::cargarGenero(Pelicula *peliculaVista, Lista<string> *&generosVistos){

    string generoAuxiliar = peliculaVista->obtenerGenero;
    if( !datoEnLista(generoAuxiliar, generosVistos) ){
        generosVistos->agregarAlFinal(generoAuxiliar);
    }
}

void PeliculasRecomendadas::cargarListasAuxiliares(Lista<Pelicula> *peliculasVistas, Lista<string> *&generosVistos,
                                                   Lista<string> *&directoresVistos, Lista<string> *&actoresVistos){
    Pelicula peliculaAuxiliar;
    for(int i =0; peliculasVistas->obtenerCantidadElementos; i++){
        peliculaAuxiliar = peliculasVistas->obtenerDato(i);
        if(i==0){
            generosVistos->agregarAlFinal(peliculaAuxiliar.obtenerGenero);
            directoresVistos->agregarAlFinal(peliculaAuxiliar.obtenerDirector);
            cargarActores(&peliculaAuxiliar, actoresVistos);
        }
        else{
            cargarGenero(&peliculaAuxiliar, generosVistos);
            cargarDirector(&peliculaAuxiliar, directoresVistos);
            cargarActores(&peliculaAuxiliar, actoresVistos);
        }
    }
}

bool Pelicula::datoEnLista(string dato, Lista<string> *listaAuxiliar){
    bool datoEncontrado = false;
    int i = 0;
    while( (i < listaAuxiiliar->obtenerCantidadElementos) && !datoEncontrado){
        if(dato == listaAuxiliar->obtenerDato(i)){
            datoEncontrado = true;
        }
        i++;
    }
    return datoEncontrado;
}

void PeliculasRecomendadas::recomendarPeliculas(Lista<Pelicula> *peliculasNoVistas){
    int puntajePeliculaLeida;
    for(int i=0; peliculasNoVistas->obtenerCantidadElementos; i++){
        puntajePeliculaLeida = (peliculasNoVistas->obtenerDato(i)).obtenerPuntaje;
        if(puntajePeliculaLeida >= puntajeValido){
            listaPeliculasRecomendadas.agregarAlFinal(peliculasNoVistas->obtenerDato(i));
        }
    }
}

void PeliculasRecomendadas::recomendarPeliculas(Lista<Pelicula> *peliculasVistas, Lista<Pelicula> *peliculasNoVistas){
    Lista<string> *generosVistos;
    Lista<string> *directoresVistos;
    Lista<string> *actoresVistos;

    cargarListasAuxiliares(peliculasVistas, generosVistos, directoresVistos, actoresVistos);

    Pelicula peliculaNoVista;
    for(int i=0; peliculasNoVistas->obtenerCantidadElementos; i++){
        peliculaNoVista = peliculasNoVistas->obtenerDato(i);
        string generoLeido = peliculaNoVista.obtenerGenero;
        if( datoEnLista(generoLeido, generosVistos) ){
            string directorLeido = peliculaNoVista.obtenerDirector;
            if( (datoEnLista(directorLeido,directoresVistos)) || (actorEncontrado(&peliculaNoVista, actoresVistos)) ){
                listaPeliculasRecomendadas.agregarAlFinal(peliculaNoVista);
            }
        }
        else if(peliculaNoVista.obtenerPuntaje >= puntajeValido){
            listaPeliculasRecomendadas.agregarAlFinal(peliculaNoVista);
        }
    }
}

Lista<Pelicula> *PeliculasRecomendadas::obtenerPeliculasRecomendadas(){
    return &listaPeliculasRecomendadas;
}
