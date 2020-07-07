
#include"Archivos.h"

Archivos::Archivos(){
    abierto = false;
}

Archivos::Archivos(string camino){
    abrirArchivo(camino);
}

Archivos::~Archivos(){
    if(this->abierto){
        this->cerrarArchivo();
    }
}

void Archivos::abrirArchivo(string camino){

    try{
        if(this->abierto){
            throw abierto;
        }
        archivo.open(camino);
        abierto = true;
        if(archivo.fail()){
            abierto = false;
            throw abierto;
        }
    }
    catch(bool &e){
        if(e){
            cout<<"\t-- AVISO -- Ya hay un archivo con ese nombre abierto! " << endl;
        }else{
            cout<<"\t-- AVISO -- No se pudo abrir el archivo \"" << camino << "\"" << endl;
        }
    }
}

void Archivos::cerrarArchivo(){
    archivo.close();
    abierto = false;
}

bool Archivos::estaAbierto(){
    return abierto;
}

bool Archivos::finalArchivo(){
    return archivo.eof();
}

bool Archivos::existeRuta(string ruta) {
    ifstream archivo(ruta);
    bool existe = archivo.good();
    archivo.close();
    return existe;
}

string Archivos::leerLinea(){
    string dato;
    getline(archivo,dato);
    return dato;
}
