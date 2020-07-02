#include"Archivos.h"

/*1)*/Archivos::Archivos(){
    //ctor sin patamentros
        posicionLector=0;
        abierto=false;

}

/*2)*/Archivos::Archivos(string camino){
    //ctor
    abrirArchivo(string camino);
    if(this->good()){
        abirto=true;
        posicionLector=0;
    }else{
        abierto=false;
    }

}

/*3)*/Archivos::~Archivos(){
    //dtor
    if(this->abierto()){
        this->cerrarArchivo();
    }
}

/*4)*/void Archivos::abrirArchivo(string camino){
    if(this->abierto){
        this->cerrarArchivo();
    }
    try{
        archivo.open(camino);
        abierto=true;

        if(archivo.fail()){
            abierto=false;
            throw abierto;
        }
    }catch(bool &e){
        cout<<"Archivo invalido "<<endl;
    }
}

/*5)*/void Archivos::cerrarArchivo(){
    archivo.close();
    abierto=false;
}

/*6)*/void Archivos::estaAbierto(){
    return abierto;
}

/*7)*/void Archivos::finalArchivo(){
    return(archivo.eof());
}

/*8)*/string Archivos::leerLinea(){
    getline(dato,archivo);
    posicionLector++;
    return(dato);
}
