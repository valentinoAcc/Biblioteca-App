#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include "Ubicacion.h"
#include <vector>
using namespace std;


class Persona
{
    public:
        Persona();
        Persona(string, uint32_t, Ubicacion);
        virtual ~Persona();

        string Getnombre() { return nombre; }
        void Setnombre(string val) { nombre = val; }

        uint32_t Getdni() { return dni; }
        void Setdni(uint32_t val) { dni = val; }

        Ubicacion Getubicacion() { return ubpers; }
        void Setubicacion(Ubicacion val) { ubpers = val; }
        friend ostream& operator<<(ostream& , const Persona& );
        vector<uint32_t> GetNcatalogos(){return nCatalogos;};
        void setNcatalogos(vector<uint32_t> val){nCatalogos = val;}
        ostream& guardar();


    protected:

    private:
        Ubicacion ubpers;
        vector<uint32_t> nCatalogos; //libros alquilados
        uint32_t dni;
        string nombre;

};

#endif // PERSONA_H
