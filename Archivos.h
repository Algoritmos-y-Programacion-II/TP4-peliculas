//Descripcion:Carga y manipula archivos
// Tiene como atributo el archivo "ifstream" y abierto "booleano".
// Los metodos estan ordenados segun un numero 'i)'.
//Nota:Los atributos estan al final


#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include<iostream>
#include<string>
#include<fstraem>

using namespace std;

class Archivos
{
    public:
        /*Funciones*/
         //1)
        // PRE : -
        // POST: Crea el objeto.
        Archivos();
         //2)
        // PRE : La ruta deve ser valida.
        // POST: Crea el objeto y carga el archivo señalado en la ruta.Marca abierto
        Archivos(string ruta);
         //3) "Destructor"
        // PRE : -
        // POST: Cierra el archivo abierto.
        ~Archivos();
        //4)
        // PRE : El archivo anterior debe estar cerrado
        // POST: abre un nuevo archivo
        void abrirArchivo(string ruta);
        //5)
        // PRE : El objeto debe estar cargado
        // POST: cierra el archivo que este abierto (si lo esta)
        void cerrarArchivo();
        //6)
        // PRE :-
        // POST: Revisa si el archivo sigue abierto
        bool estaAbierto();
        //7)
        // PRE : El objeto debe estar cargado
        // POST: revisa si se leyo la ultima linea del archivo
        bool finalArchivo();
        //8)
        // PRE : El objeto debe estar cargado
        // POST: Lee la sigiente linea del archivo
        string leerLinea();


    protected:

    private:
        /*Atributos*/
        ifstream archivo;
        bool abierto;      //Booleano que revisa si el archivo esta abiero

};
#endif // ARCHIVOS_H
