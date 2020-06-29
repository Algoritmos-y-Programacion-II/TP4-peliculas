//
// Created by daseos on 28/6/20.
//

#include "PeliculasRecomendadas.h"

bool PeliculasRecomendadas::actorEncontrado(Pelicula *peliculaNoVista, Lista<string> *actoresVistos){
    Lista<string> *listaAuxiliar = peliculaNoVista->obtenerActores();
    bool actorEnLista = false;
    int i = 0;
    while( (i < listaAuxiliar->obtenerCantidadElementos()) && !actorEnLista ){
        string actorLeido = listaAuxiliar->obtenerDato(i);
        if(actoresVistos->datoEnLista(actorLeido)){
            actorEnLista = true;
        }
        i++;
    }
    return actorEnLista;
}

void PeliculasRecomendadas::cargarActores(Pelicula *peliculaVista, Lista <string> *&actoresVistos){
    Lista <string> *listaAuxiliar;
    if(actoresVistos->obtenerCantidadElementos() == 0){
        listaAuxiliar = peliculaVista->obtenerActores();
        for(int i=0; listaAuxiliar->obtenerCantidadElementos(); i++){
            actoresVistos->agregarAlFinal(listaAuxiliar->obtenerDato(i));
        }
    }
    else{
        for(int i=0; listaAuxiliar->obtenerCantidadElementos(); i++){
            string actorLeido = listaAuxiliar->obtenerDato(i);
            if( !( actoresVistos->datoEnLista(actorLeido) ) ){
                actoresVistos->agregarAlFinal(actorLeido);
            }
        }
    }
}

void PeliculasRecomendadas::cargarDirector(Pelicula *peliculaVista, Lista<string> *&directoresVistos){

    string directorAuxiliar = peliculaVista->obtenerDirector();
    if( !( directoresVistos->datoEnLista(directorAuxiliar) ) ){
        directoresVistos->agregarAlFinal(directorAuxiliar);
    }
}

void PeliculasRecomendadas::cargarGenero(Pelicula *peliculaVista, Lista<string> *&generosVistos){

    string generoAuxiliar = peliculaVista->obtenerGenero();
    if( !( generosVistos->datoEnLinea(generoAuxiliar) ) ){
        generosVistos->agregarAlFinal(generoAuxiliar);
    }
}

void PeliculasRecomendadas::cargarListasAuxiliares(Lista<Pelicula> *peliculasVistas, Lista<string> *&generosVistos,
                                                   Lista<string> *&directoresVistos, Lista<string> *&actoresVistos){
    Pelicula peliculaAuxiliar;
    for(int i =0; peliculasVistas->obtenerCantidadElementos(); i++){
        peliculaAuxiliar = peliculasVistas->obtenerDato(i);
        if(i==0){
            generosVistos->agregarAlFinal(peliculaAuxiliar.obtenerGenero());
            directoresVistos->agregarAlFinal(peliculaAuxiliar.obtenerDirector());
            cargarActores(&peliculaAuxiliar, actoresVistos);
        }
        else{
            cargarGenero(&peliculaAuxiliar, generosVistos);
            cargarDirector(&peliculaAuxiliar, directoresVistos);
            cargarActores(&peliculaAuxiliar, actoresVistos);
        }
    }
}

void PeliculasRecomendadas::recomendarPeliculas(Lista<Pelicula> *peliculasNoVistas){
    int puntajePeliculaLeida;
    for(int i=0; peliculasNoVistas->obtenerCantidadElementos(); i++){
        puntajePeliculaLeida = (peliculasNoVistas->obtenerDato(i)).obtenerPuntaje();
        if(puntajePeliculaLeida >= PUNTAJE_VALIDO){
            listaPeliculasRecomendadas.agregarAlFinal(peliculasNoVistas->obtenerDato(i));
        }
    }
}

void PeliculasRecomendadas::recomendarPeliculas(Lista<Pelicula> *peliculasVistas, Lista<Pelicula> *peliculasNoVistas){
    Lista<string> *generosVistos;
    Lista<string> *directoresVistos;
    Lista<string> *actoresVistos;

    cargarListasAuxiliares(peliculasVistas, generosVistos, directoresVistos, actoresVistos);

    Pelicula peliculaLeida;
    for(int i=0; peliculasNoVistas->obtenerCantidadElementos(); i++){
        peliculaLeida = peliculasNoVistas->obtenerDato(i);
        string generoLeido = peliculaLeida.obtenerGenero();
        if( generosVistos->datoEnLista(generoLeido) ){
            string directorLeido = peliculaLeida.obtenerDirector();
            if( directoresVistos->datoEnLista(directorLeido) || actorEncontrado(&peliculaLeida, actoresVistos) ){
                listaPeliculasRecomendadas.agregarAlFinal(peliculaNoVista);
            }
        }
        else if(peliculaLeida.obtenerPuntaje() >= PUNTAJE_VALIDO){
            listaPeliculasRecomendadas.agregarAlFinal(peliculaNoVista);
        }
    }
}

Lista<Pelicula> *PeliculasRecomendadas::obtenerPeliculasRecomendadas(){
    return &listaPeliculasRecomendadas;
}
