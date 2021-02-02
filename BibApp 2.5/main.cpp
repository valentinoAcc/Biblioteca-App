#include <iostream>
#include"Ejemplar.h"
#include"Libro.h"
#include "Biblioteca.h"
#include "Menu.h"
#include <cstdlib>
using namespace std;


int main()
{
    /*
    Libro *l1 = new Libro("Stephen King", "2394af532", 500, "EEUU", "Pegado", "Terror", "IT", 111, "penguin", Fecha(10,10,2001), "ESP", "Libro");
    Libro *l2 = new Libro("G. Orwell", "d3425235sg5", 250, "Inglarerra", "COSIDO", "Ciencia Ficcion", "1984", 112, "OTRA EDITORIAL", Fecha(10,10,2004), "ING", "Libro");
    Dvd *d1= new Dvd("Terror", 120, "español, frances", "The Thing", 444, "Universal", Fecha(4,5,1982),"ingles", "Dvd" );
    vector<Persona> enc;
    enc.push_back(Persona("Maxi", 33273886, Ubicacion("Ibiza 162", "2235918574", "Maxi@bib.com", 7609)));
    enc.push_back(Persona("Tino", 32345252, Ubicacion("salta 1218", "2235918544", "tino@bib.com", 7600)));

    bib.ingresarEjemplar(l1);
    bib.ingresarEjemplar(l2);
    bib.ingresarEjemplar(d1);
    bib.alquilerEjemplar(111,true,Fecha(10,10,2001),"VALEN", enc.back());
*/
    // levantatDatos("nombre del archivo.dat")
    vector<Persona> enc;
    enc.push_back(Persona("Maxi", 33273886, Ubicacion("Ibiza 162", "2235918574", "Maxi@bib.com", 7609)));
    enc.push_back(Persona("Tino", 32345252, Ubicacion("salta 1218", "2235918544", "tino@bib.com", 7600)));
    Biblioteca bib("Ing UNMDP", Ubicacion("JB justo 4300", "2235321654", "lib@unmdp.com", 7600),enc);
    Menu menu;
    menu.preMenu(bib);
    menu.menuPrincipal(bib);




    return 0;

}
