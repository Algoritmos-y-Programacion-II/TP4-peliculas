#include "Menu.h"
#include "Lista.h"
#include <iostream>

void Menu::mostrarMenu(){

    cout << "\n\t1. Mostrar peliculas vistas\n";
    cout << "\t2. Mostrar peliculas no vistas\n";
    cout << "\t3. Mostrar peliculas recomendadas\n";
    cout << "\t4. Salir\n";
    cout << "\tIngrese el numero de la opcion que desea seleccionar: ";
    cin >> opcion;
}

bool Menu::selectorDeOpciones() {

    bool estado;

    switch (this->opcion) {

        case '1': {
            cout << "\n\t---------------------- PELICULAS VISTAS ----------------------\n";
            peliculasRecomendadas.mostrarPeliculasVistas();
            cout << "\n\t--------------------------------------------------------------\n";

            estado = true;
            break;
        }

        case '2': {
            cout << "\t--------------------- PELICULAS NO VISTAS --------------------\n";
            peliculasRecomendadas.mostrarPeliculasNoVistas();
            cout << "\n\t--------------------------------------------------------------\n";
            estado = true;
            break;
        }

        case '3': {
            cout << "\t-------------------- PELICULAS RECOMENDADAS ------------------\n";
            peliculasRecomendadas.mostrarPeliculasRecomendadas();
            cout << "\n\t--------------------------------------------------------------\n";
            estado = true;
            break;
        }

        case '4': {
            estado = false;
            break;
        }

        default: {
            cout << "\tOpcion no valida. Ingrese alguna de las opciones en el menu" << endl;
            estado = true;
            break;
        }
    }
    return estado;
}
