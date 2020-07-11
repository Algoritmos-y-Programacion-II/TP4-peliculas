// Los metodos se encuentran ordenados alfabeticamente sin distincion del tipo que sea.
// Si hubiese un constructor y/o un destructor se encuentran al principio y al final, respectivamente.

#include "PeliculasRecomendadas.h"

PeliculasRecomendadas::PeliculasRecomendadas(){
    if (!cargador.existeRuta(ARCHIVO_NO_VISTAS)) {
        std::cout << "\t-- AVISO -- No se pudo abrir el archivo \"" << ARCHIVO_NO_VISTAS << "\"" << std::endl;
        exit(1);
    }
    cargador.cargar(ARCHIVO_NO_VISTAS, peliculasNoVistas);
    cargador.cargar(ARCHIVO_VISTAS, peliculasVistas);
}

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

void PeliculasRecomendadas::cargarPelicula(Pelicula *&peliculaLeida){
    Pelicula *peliculaRecomendada = new Pelicula;
    cargarDatosPelicula(peliculaLeida,peliculaRecomendada);
    peliculasRecomendadas.agregarAlFinal(peliculaRecomendada);
}

void PeliculasRecomendadas::crearPeliculasRecomendadas(){
    if(peliculasRecomendadas.obtenerCantidadElementos() == 0) {
        if (peliculasVistas.obtenerCantidadElementos() != 0) {
            recomendarPeliculas();
        } else {
                recomendarPorPuntaje();
        }
    }
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
        peliculasVistas.obtenerDato(i)->imprimirDatosPelicula();
        cout << "\n";
    }
}

void PeliculasRecomendadas::mostrarPeliculasNoVistas(){
    for(int i = 0; i < peliculasNoVistas.obtenerCantidadElementos(); i++){
        peliculasNoVistas.obtenerDato(i)->imprimirDatosPelicula();
        cout << "\n";
    }
}

void PeliculasRecomendadas::mostrarPeliculasRecomendadas(){
    crearPeliculasRecomendadas();
    for(int i=0; i< peliculasRecomendadas.obtenerCantidadElementos(); i++){
        peliculasRecomendadas.obtenerDato(i)->imprimirDatosPelicula();
        cout << "\n";
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

PeliculasRecomendadas::~PeliculasRecomendadas(){
    liberarMemoria();
}