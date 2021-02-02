#include <iostream>
#include"Ejemplar.h"
#include"Libro.h"
#include "Biblioteca.h"
#include "Menu.h"
#include <cstdlib>
using namespace std;


int main()
{

    cout<<endl;
    Biblioteca bib("Ing UNMDP", Ubicacion("JB justo 4300", "2235321654", "lib@unmdp.com", 7600));
    Menu menu(&bib);
    try{
        menu.preMenu();
        menu.menuPrincipal();
    }catch (const char* e){
        cout<<e<<endl;
    }
    return 0;

}
