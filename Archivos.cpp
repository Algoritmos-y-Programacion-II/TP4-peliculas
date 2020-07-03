#include"Archivos.h"

Archivos::Archivos(){
    abierto = false;
}

Archivos::Archivos(string camino){
    abrirArchivo(string camino);
    if(this->archivo.good())
        abierto = true;

    else
        abierto = false;
}

Archivos::~Archivos(){
    if(abierto)
        this->cerrarArchivo();
}

void Archivos::abrirArchivo(string camino){

    try{
        // Primero me fijo ya esta abierto, y en ese caso lanzo la excepcion
        if(this->abierto)
            throw abierto;

        // Si no esta abierto, lo abro
        archivo.open(camino);
        abierto = true;

        // Si no se pudo abrir, lanzo la excepcion
        if(archivo.fail()){
            abierto = false;
            throw abierto;
        }
    }
    catch(bool &e){
        if(e)
            cout<<"\t-- AVISO -- Ya hay un archivo abierto\n";
        else
            cout<<"\t -- AVISO-- No se pudo abrir la ruta del archivo\n";
    }
}

void Archivos::cerrarArchivo(){
    archivo.close();
    abierto = false;
}

bool Archivos::estaAbierto(){
    return abierto;
}

void Archivos::finalArchivo(){
    return(archivo.eof());
}

string Archivos::leerLinea(){
    string dato;
    getline(archivo,dato);
    return(dato);
}