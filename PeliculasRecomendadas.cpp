//
// Created by root-MKevin on 28/6/20.
// Los metodos se encuentran ordenados alfabeticamente sin distincion del tipo que sea.

#include "PeliculasRecomendadas.h"

bool PeliculasRecomendadas::actorEncontrado(Pelicula *peliculaLeida, Lista<string> *actoresVistos){
    Lista<string> *listaAuxiliar = peliculaLeida->obtenerActores();
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

void PeliculasRecomendadas::cargarActoresLista(Pelicula *peliculaVista, Lista <string> *actoresVistos){

    if(actoresVistos->obtenerCantidadElementos() == 0){
        for(int i=0; i < peliculaVista->obtenerActores()->obtenerCantidadElementos(); i++){
            actoresVistos->agregarAlFinal(peliculaVista->obtenerActores()->obtenerDato(i));
        }
    }
    else{
        for(int i=0; i < peliculaVista->obtenerActores()->obtenerCantidadElementos(); i++){
            string actorLeido = peliculaVista->obtenerActores()->obtenerDato(i);
            if( !( actoresVistos->datoEnLista(actorLeido) ) ){
                actoresVistos->agregarAlFinal(actorLeido);
            }
        }
    }
}

void PeliculasRecomendadas::cargarActoresPelicula(Pelicula *&peliculaLeida, Pelicula *&peliculaRecomendada){
    Lista<string> *listaAux = peliculaLeida->obtenerActores();
    for(int i =0; i< listaAux->obtenerCantidadElementos(); i++){
        peliculaRecomendada->cargarActor(listaAux->obtenerDato(i));
    }
}


void PeliculasRecomendadas::cargarDatosPelicula(Pelicula *&peliculaLeida, Pelicula *&peliculaRecomendada){

    peliculaRecomendada->cargarTitulo(peliculaLeida->obtenerTitulo());
    peliculaRecomendada->cargarGenero(peliculaLeida->obtenerGenero());
    peliculaRecomendada->cargarDirector(peliculaLeida->obtenerDirector());
    peliculaRecomendada->cargarPuntaje(peliculaLeida->obtenerPuntaje());
    cargarActoresPelicula(peliculaLeida, peliculaRecomendada);

}


void PeliculasRecomendadas::cargarDirector(Pelicula *peliculaVista, Lista<string> *directoresVistos){

    string directorAuxiliar = peliculaVista->obtenerDirector();
    if( !( directoresVistos->datoEnLista(directorAuxiliar) ) ){
        directoresVistos->agregarAlFinal(directorAuxiliar);
    }
}

void PeliculasRecomendadas::cargarGenero(Pelicula *peliculaVista, Lista<string> *generosVistos){

    string generoAuxiliar = peliculaVista->obtenerGenero();
    if( !( generosVistos->datoEnLista(generoAuxiliar) ) ){
        generosVistos->agregarAlFinal(generoAuxiliar);
    }
}

void PeliculasRecomendadas::cargarListasAuxiliares(Lista<string> *generosVistos, Lista<string> *directoresVistos,
        Lista<string> *actoresVistos){

    for(int i =0; i < peliculasVistas.obtenerCantidadElementos(); i++){
        Pelicula *peliculaAuxiliar = peliculasVistas.obtenerDato(i);
        if(i==0){
            generosVistos->agregarAlFinal(peliculaAuxiliar->obtenerGenero());
            directoresVistos->agregarAlFinal(peliculaAuxiliar->obtenerDirector());
            cargarActoresLista(peliculaAuxiliar, actoresVistos);
        }
        else{
            cargarGenero(peliculaAuxiliar, generosVistos);
            cargarDirector(peliculaAuxiliar, directoresVistos);
            cargarActoresLista(peliculaAuxiliar, actoresVistos);
        }
    }
}

void PeliculasRecomendadas::cargarListasDePeliculas(){
    cargador.cargar(ARCHIVO_VISTAS, peliculasVistas);
    cargador.cargar(ARCHIVO_NO_VISTAS, peliculasNoVistas);
}

void PeliculasRecomendadas::cargarPelicula(Pelicula *&peliculaLeida){
    Pelicula *peliculaRecomendada = new Pelicula;
    cargarDatosPelicula(peliculaLeida,peliculaRecomendada);
    peliculasRecomendadas.agregarAlFinal(peliculaRecomendada);
}

void PeliculasRecomendadas::imprimirActores(Lista<string> *actores){
    std::cout << "REPARTO: ";
    for(int i=0; i < actores->obtenerCantidadElementos(); i++){
        std::cout << actores->obtenerDato(i) << " ";
    }
}

void PeliculasRecomendadas::imprimirDatosPelicula(Pelicula *peliculaLeida){
    std::cout << "\nTITULO: " << peliculaLeida->obtenerTitulo() << std::endl;
    std::cout << "GENERO: " << peliculaLeida->obtenerGenero() << std::endl;
    std::cout << "PUNTAJE: " << peliculaLeida->obtenerPuntaje() << std::endl;
    std::cout << "DIRECTOR: " << peliculaLeida->obtenerDirector() << std::endl;
    imprimirActores(peliculaLeida->obtenerActores());
}

void PeliculasRecomendadas::liberarMemoria(){
    if(peliculasVistas.obtenerCantidadElementos() != 0) {
        for (int i = 0; i < peliculasVistas.obtenerCantidadElementos(); i++) {
            delete peliculasVistas.obtenerDato(i);
        }
    }
    if(peliculasNoVistas.obtenerCantidadElementos() != 0) {
        for (int j = 0; j < peliculasNoVistas.obtenerCantidadElementos(); j++) {
            delete peliculasNoVistas.obtenerDato(j);
        }
    }
    if(peliculasRecomendadas.obtenerCantidadElementos() !=0 ){
        for (int k = 0; k < peliculasRecomendadas.obtenerCantidadElementos(); k++) {
            delete peliculasRecomendadas.obtenerDato(k);
        }
    }
}


void PeliculasRecomendadas::mostrarPeliculasVistas(){
    for(int i=0; i < peliculasVistas.obtenerCantidadElementos(); i++){
        imprimirDatosPelicula(peliculasVistas.obtenerDato(i));
    }
}

void PeliculasRecomendadas::mostrarPeliculasNoVistas(){
    for(int i = 0; i < peliculasNoVistas.obtenerCantidadElementos(); i++){
        imprimirDatosPelicula(peliculasNoVistas.obtenerDato(i));
    }
}


void PeliculasRecomendadas::mostrarPeliculasRecomendadas(){
    for(int i=0; i< peliculasRecomendadas.obtenerCantidadElementos(); i++){
        imprimirDatosPelicula(peliculasRecomendadas.obtenerDato(i));
    }
}

void PeliculasRecomendadas::recomendarPeliculas(){
    Lista<string> generosVistos;
    Lista<string> directoresVistos;
    Lista<string> actoresVistos;

    cargarListasAuxiliares(&generosVistos, &directoresVistos, &actoresVistos);

    for(int i=0; i < peliculasNoVistas.obtenerCantidadElementos(); i++){
        Pelicula *peliculaLeida = peliculasNoVistas.obtenerDato(i);
        string generoLeido = peliculaLeida->obtenerGenero();
        if( generosVistos.datoEnLista(generoLeido) ){
            string directorLeido = peliculaLeida->obtenerDirector();
            if( directoresVistos.datoEnLista(directorLeido) || actorEncontrado(peliculaLeida, &actoresVistos) ){
                cargarPelicula(peliculaLeida);
            }
        }
        else if(peliculaLeida->obtenerPuntaje() >= PUNTAJE_VALIDO){
            cargarPelicula(peliculaLeida);
        }
    }
}

void PeliculasRecomendadas::recomendarPorPuntaje(){
    for(int i=0; i < peliculasNoVistas.obtenerCantidadElementos(); i++){
        Pelicula *peliculaLeida = peliculasNoVistas.obtenerDato(i);
        if(peliculaLeida->obtenerPuntaje() >= PUNTAJE_VALIDO){
            cargarPelicula(peliculaLeida);
        }
    }
}

void PeliculasRecomendadas::verPeliculasRecomendadas(){
    if(peliculasVistas.obtenerCantidadElementos() != 0){
        recomendarPeliculas();
    }
    else{
        if(peliculasNoVistas.obtenerCantidadElementos() != 0) {
            recomendarPorPuntaje();
        }
    }
    mostrarPeliculasRecomendadas();
}

PeliculasRecomendadas::~PeliculasRecomendadas(){
    liberarMemoria();
}
