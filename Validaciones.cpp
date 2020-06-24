#include "Validaciones.h"
#include <regex>    // Se utiliza en validarEntero()
#include <iostream>

int Validaciones:: validarEntero(string num) {

    regex entero("^(\\+|-)?[[:digit:]]+");

    while (!regex_match(num, entero)) {
        cout << "\tError, el tipo de dato que ingreso no es valido.\n\tPor favor reingrese (solo numeros enteros): ";
        cin >> num;
    }
    return atoi(num.c_str());
}

void Validaciones:: validarRango(int &num, int min, int max) {
    string strPos;
    while (num < min || num > max) {
        cout << "\tEl numero que ingreso esta fuera de rango, por favor reingrese: ";
        cin >> strPos;
        num = validarEntero(strPos);
    }
}