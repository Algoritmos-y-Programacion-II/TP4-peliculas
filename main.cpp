/*
  75.41/95.15: Algoritmos y Programacion II - Catedra Juarez - 1°C 2020
  Trabajo Practico Grupal N4: Recomendacion de Peliculas
  Hecho por
            Morgan Fossati
            Patricio Rodriguez
            Kevin Meaca
            Valentina Varela Rodriguez
*/

#include "Menu.h"

int main() {

    Menu menu;
    menu.mostrarMenu();
    while (menu.selectorDeOpciones()) {
        menu.mostrarMenu();
    }

    return 0;
}