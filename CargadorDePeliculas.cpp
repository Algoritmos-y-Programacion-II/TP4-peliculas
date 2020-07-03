#include "CargadorDePeliculas.h"

/*1)*/CargadorDePeliculas::CargadorDePeliculas()
{
    //ctor
}

/*2)*/CargadorDePeliculas::~CargadorDePeliculas()
{
    //dtor
}

/*3)*/void CargadorDePeliculas::cargar(string camino, Lista<*Pelicula> &cartelera){
    /*
    Funciona creando uno a uno objetos Pelicula, alojados en memoria dinamica, y cargandolos desde un archivo,
    e introduciendo el puntero que los señalaal final de Lista<*Pelicula>
    */
    //NOTA: El metodo fue adaptado de otro que cargaba un objeto Pelicula en lugar de un puntero. keep an eye for gramar erros

    //Variables auxiliares de carga
    Pelicula *peli;
    string lectura;
    int puntuacion;

    //Abre el archivo
    arch.abrirArchivo(camino);
    numeroPelicula=0;

    while(!arch.finalArchivo()){
        //Crea un nuevo objeto en la memoria dinamica
        peli = new Pelicula;

        //Carga Titulo
        lectura=arch.leerLinea();//Lee el archivo
        peli->cargarTitulo(lectura);//carga en peli

        //Carga Genero          igual al primero
        lectura=arch.leerLinea();
        peli->cargarGenero(lectura);

        //Carga Puntuacion
        lectura=arch.leerLinea();//Lee
        puntuacion=stoi(lectura);//"castea" de string a int
        peli->cargarPuntaje(puntuacion);//carga en peli

        //carga en Director     igual al primero
        lectura=arch.leerLinea();
        peli->cargarDirector(lectura);

        //carga en la Lista de Actores
        lectura=arch.leerLinea();
        cargarListaDeActores(lectura, peli);//Metodo especialmente crado para adaptarse al formato del texto

        //Agrega peli al final de la lista
        cartelera.agregarAlFinal(peli);
        numeroPelicula++;

     }
}

/*4)*/void CargadorDePeliculas::cargarListaDeActores(string lectura,Pelicula *&peli){
    /*
    Toma un string donde esta cargada la linea del archivo donde se nombra a todos los actores (nombre_apellido)
    separados por espacios, y la desarma caracter a caracter, guardando en "actor" todos los caracteres que no se corresponden
    con espacios. Finalmente, carga al actor en la lista
    */

    //Variables auxiliares de carga

    string actor;//donde aislo a cada actor
    char indice;//aloja cada uno de los caracteres antes de cargalo en actores
    int contador;

    lectura+='/';//coloco una "marca de fin" al final del string

    for(contador=0 ,contador<lectura.length(),contador++){//Recorre el string #

        incice=peli[contador];//#
        if((indice!=' ')&&(indice!='/')){//Corta la carga de cada actor.

            actor=+indice;
            }else{

            peli->cargarActor(actor);//Cargo el contenido de actor al final de la lista;
            actor.erase(0,contador);//Limpo a la variable actor
        }
    }

}

/*5)*//*
//Funcion opcional que livera las listas de actores dentro decada *Pelicula de la lista
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
