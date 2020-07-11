#ifndef PELICULAS_MENU_H
#define PELICULAS_MENU_H

#include "PeliculasRecomendadas.h"

using namespace std;

class Menu{

private:
    PeliculasRecomendadas peliculasRecomendadas;
    char opcion;

public:

    //Mostrar las opciones que el usuario puede elegir
    //Pre-Condicion: Debe instanciarse un menu y pasar las listas por parametro
    //Post-Condicion: Imprime por pantalla las decisiones que tiene el usuario
    void mostrarMenu();

    //Procesa la opcion del usuario
    //Pre-Condicion: Debe existir un objeto instanciado Menu y la opcion debe estar entre el rango 1 y el 3
    //Post-Condicion: procesa la opcion invocando las funciones correspondientes
    bool selectorDeOpciones();
};
#endif //PELICULAS_MENU_H