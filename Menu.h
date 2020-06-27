#ifndef PELICULAS_MENU_H
#define PELICULAS_MENU_H

#include "Lista.h"
#include <fstream>
#include <sstream>

using namespace std;

class Menu{

private:

Lista<string> ListaPV;

Lista<string> ListaPNV;

Lista<string> ListaPR;

int opcion;

void iterarListaPeliculasVistas();

void iterarListaPeliculasNoVistas();

void iterarListaPeliculasRecomendadas();

public:

    //Constructor con parametro
    //Pre-Condicion: El archivo debe existir y ser del tipo string, y debe existir una lista
    //Post-Condicion: Se crea un objeto del tipo Menu

    Menu(Lista<string> ListaPV,Lista<string> ListaPNV,Lista<string> ListaPR);

    //Mostrar las opciones que el usuario puede elegir
    //Pre-Condicion: Debe instanciarse un menu y pasar las listas por parametro
    //Post-Condicion: Imprime por pantalla las decisiones que tiene el usuario

    void mostrarMenu();

    //Procesa la opcion del usuario
    //Pre-Condicion: Debe existir un objeto instanciado Menu y la opcion debe estar entre el rango 1 y el 3
    //Post-Condicion: procesa la opcion invocando las funciones correspondientes

    bool optionHandler();

};
#endif //PELICULAS_MENU_H