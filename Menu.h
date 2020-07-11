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
    //Pre-Condicion: -
    //Post-Condicion: Imprime por pantalla las decisiones que tiene el usuario
    void mostrarMenu();

    //Procesa la opcion del usuario
    //Pre-Condicion: -
    //Post-Condicion: Procesa la opcion invocando las funciones correspondientes
    bool selectorDeOpciones();
};
#endif //PELICULAS_MENU_H