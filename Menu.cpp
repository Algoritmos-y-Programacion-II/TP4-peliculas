#include <iostream>
#include "Menu.h"

Menu::Menu(Lista<Pelicula> peliculasVistas, Lista<Pelicula> peliculasNoVistas, Lista<Pelicula> peliculasRecomendadas) {
    
    this->peliculasVistas = peliculasVistas;
    this->peliculasNoVistas = peliculasNoVistas;
    this->peliculasRecomendadas = peliculasRecomendadas;
    
}

void Menu::mostrarMenu(){

    int opcion;

    cout << "1.Mostrar peliculas vistas." <<endl;

    cout << "2.Mostrar peliculas no vistas." <<endl;

    cout << "3.Mostrar peliculas recomendadas." <<endl;

    cout << "4.Salir." <<endl;

    cout << "Ingrese el numero de la opcion que desea seleccionar: " <<endl;

    cin >> opcion;

    this->opcion = opcion;

}

bool Menu::optionHandler() {
    
    switch (this->opcion) {
        case 1:{

            iterarListaPeliculasVistas();
            return true;
            break;
        }

        case 2:{

            iterarListaPeliculasNoVistas();
            return true;
            break;

        }

        case 3:{

            iterarListaPeliculasRecomendadas();
            return true;
            break;
        }

        case 4:{

            return false;
            break;
        }

        default:{
            cout << "Opcion no valida. Ingrese alguna de las opciones en el menu" << endl;
            return true;
            break;

        }

    }
}

void Menu::iterarListaPeliculasVistas(){
    cout << "Placeholder"<< endl;
}

void Menu::iterarListaPeliculasNoVistas(){
    cout << "Placeholder"<< endl;
}

void Menu::iterarListaPeliculasRecomendadas(){
    cout << "Placeholder"<< endl;
}