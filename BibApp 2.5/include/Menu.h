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
        /** Default destructor */
        virtual ~Menu();
        void limpiarPantalla();

        void preMenu(Biblioteca &bib);

        void menuPrincipal(Biblioteca  &bib);

        void menuAlquileres(Biblioteca &bib);
        void alquilerEjemplar(Biblioteca &bib);
        void devolverEjemplar(Biblioteca &bib);
        void subMenuAlquileres1(Biblioteca &bib,uint32_t);
        void subMenuAlquileres2(Biblioteca &bib, uint32_t numCatalogoAux);
        void listadoAlquilados(Biblioteca &bib);

        void menuListado(Biblioteca &bib);

        void menuEjemplares(Biblioteca  &bib);
        Ejemplar* ingresaEjemplar(Biblioteca &bib);
        Libro* ingresarLibro(Biblioteca &bib);
        Revista* ingresarRevista(Biblioteca &bib);
        Dvd* ingresarDvd(Biblioteca &bib);
        Apunte * ingresarApunte(Biblioteca &bib);

        void menuBiblioteca(Biblioteca &bib);
        void modificarNombre(Biblioteca &bib);
        void modificarUbicacion(Biblioteca &bib);
        void agregarEncargado(Biblioteca &bib);




    protected:

    private:
};

#endif // MENU_H
