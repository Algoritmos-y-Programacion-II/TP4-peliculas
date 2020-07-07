#include "Menu.h"
#include "Lista.h"
#include <iostream>

void Menu::mostrarMenu(){

    cout << "\t1. Mostrar peliculas vistas\n";
    cout << "\t2. Mostrar peliculas no vistas\n";
    cout << "\t3. Mostrar peliculas recomendadas\n";
    cout << "\t4. Salir\n";
    cout << "\tIngrese el numero de la opcion que desea seleccionar: ";
    cin >> opcion;
    //sin una validacion de la variable opcion, por como esta implementado en el main, si el 
    //usuario ingresa por error o negligencia un caracter distinto de un numero, el metodo selector de opciones
    //nunca corta la iteración.

}

bool Menu::selectorDeOpciones() {

    bool estado;
    Lista<Pelicula*>* lista;

    switch (this->opcion) {

        case 1: {
            cout << "\n\t---------------------- PELICULAS VISTAS ----------------------\n";
            peliculasRecomendadas.mostrarPeliculasVistas();
            cout << "\n\t--------------------------------------------------------------\n";

            estado = true;
            break;
        }

        case 2: {
            cout << "\t--------------------- PELICULAS NO VISTAS --------------------\n";
            peliculasRecomendadas.mostrarPeliculasNoVistas();
            cout << "\n\t--------------------------------------------------------------\n";
            estado = true;
            break;
        }

        case 3: {
            cout << "\t-------------------- PELICULAS RECOMENDADAS ------------------\n";
            peliculasRecomendadas.mostrarPeliculasRecomendadas();
            cout << "\n\t--------------------------------------------------------------\n";
            estado = true;
            break;
        }

        case 4: {
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
