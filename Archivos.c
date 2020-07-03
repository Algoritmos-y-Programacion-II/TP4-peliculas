#include"Archivos.h"

/*1)*/Archivos::Archivos(){
    //ctor sin patamentros
        abierto=false;

}

/*2)*/Archivos::Archivos(string camino){
    //ctor
    abrirArchivo(string camino);
    if(this->archivo.good()){
        abirto=true;
    }else{
        abierto=false;
    }

}

/*3)*/Archivos::~Archivos(){
    //dtor
    if(this->estaAbierto()){
        this->cerrarArchivo();
    }
}

/*4)*/void Archivos::abrirArchivo(string camino){

    try{
        archivo.open(camino);
        abierto=true;
        if(this->estaAbierto()){
            throw abierto;
        }
        if(archivo.fail()){
            abierto=false;
            throw abierto;
        }
    }catch(bool &e){

        if(e){
            cout<<"Ya hay un archivo abierto! "<<endl;
        }else{
            cout<<"Archivo invalido "<<endl;
        }
    }
}

/*5)*/void Archivos::cerrarArchivo(){
    archivo.close();
    abierto=false;
}

/*6)*/bool Archivos::estaAbierto(){
    return abierto;
}

/*7)*/void Archivos::finalArchivo(){
    return(archivo.eof());
}

/*8)*/string Archivos::leerLinea(){
    string dato;
    getline(archivo,dato);
    return(dato);
}
