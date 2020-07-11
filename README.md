75.41/95.15: Algoritmos y Programacion II - Catedra Juarez - 1°C 2020
================
Trabajo Practico Grupal N4: Recomendación de Películas
------------
La finalidad de este proyecto es recomendarle al usuario qué película ver en base a las películas que vio y no vio.

Hecho por:

  - [Morgan Fossati](https://github.com/MorganIvan)
  - [Patricio Rodriguez](https://github.com/LHFPSystem)
  - [Kevin Meaca](https://github.com/root-MKevin)
  - [Valentina Varela Rodriguez](https://github.com/valva-ro)

UML
------------
Para ver el diagrama UML haga click [acá](https://app.lucidchart.com/documents/view/3449b957-8e6d-49e4-85ff-a5bf505d5faa/0_0)

Instalación
------------

- Instale algún compilador de C++ de su preferencia
    - Linux 
    
            sudo apt-get update
            sudo apt-get upgrade
            sudo apt-get install build-essential
            
    - Windows 
        - [MinGw](https://osdn.net/projects/mingw/releases/) 
        - [Cygwin](https://sourceware.org/cygwin/)
        - [CLang](https://releases.llvm.org/download.html)
        
- Instale Git
	- Linux 
	
	      sudo apt-get update
	      sudo apt-get install git
		  
	- Windows [Descargar Git](https://git-scm.com/downloads)

- Desde la terminal vaya a la ubicacion en donde desea tener el proyecto, y clonelo con 

    `git clone https://github.com/valva-ro/TP4-recomendacionPelicula` 

- Compile el programa con `g++ *.cpp -o ejecutable`

- Asegurese de tener en el mismo directorio donde tiene el ejecutable el archivo `peliculasNoVistas.txt`

- Corra el programa
    - Linux `./ejecutable`
    - Windows `ejecutable`
