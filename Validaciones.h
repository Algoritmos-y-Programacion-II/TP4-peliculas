#ifndef TP4_RECOMENDACIONPELICULA_VALIDACIONES_H
#define TP4_RECOMENDACIONPELICULA_VALIDACIONES_H

#include <string>

using namespace std;

class Validaciones {

public:

    // PRE: num es un string valido
    // POST: Si num no es un entero, pide el reingreso hasta que lo sea y luego lo devuelve
    int validarEntero(string num);

    // PRE: Todos los enteros deben ser validos
    // POST: Si no se cumple que min <= num <= max le pide al usuario que reingrese el valor
    void validarRango(int &num, int min, int max);
};


#endif //TP4_RECOMENDACIONPELICULA_VALIDACIONES_H
