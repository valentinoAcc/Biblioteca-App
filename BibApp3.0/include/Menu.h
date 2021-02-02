#ifndef MENU_H
#define MENU_H
#include "Biblioteca.h"
#include "Persona.h"
#include "Fecha.h"
#include "Ubicacion.h"
#include "Ejemplar.h"
#include "Libro.h"
#include "Revista.h"
#include "Dvd.h"
#include "Apunte.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Menu
{
    public:
        /** Default constructor */
        Menu();
        Menu(Biblioteca *bib);
        /** Default destructor */
        virtual ~Menu();
        void limpiarPantalla();

        void preMenu();

        void menuPrincipal();

        void menuAlquileres();
        void alquilerEjemplar();
        void devolverEjemplar();
        void subMenuAlquileres1(uint32_t);
        void subMenuAlquileres2(uint32_t numCatalogoAux);
        void listadoAlquilados();

        void menuListado();

        void menuEjemplares();
        Ejemplar* ingresaEjemplar();
        Libro* ingresarLibro();
        Revista* ingresarRevista();
        Dvd* ingresarDvd();
        Apunte * ingresarApunte();

        void menuBiblioteca();
        void modificarNombre();
        void modificarUbicacion();
        void agregarEncargado();




    protected:

    private:
        Biblioteca *bib;
};

#endif // MENU_H
