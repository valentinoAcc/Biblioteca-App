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

        uint16_t Getdni() { return dni; }
        void Setdni(uint16_t val) { dni = val; }

        Ubicacion Getubicacion() { return ubpers; }
        void Setnombre(Ubicacion val) { ubpers = val; }

        friend ostream& operator<<(ostream& , const Persona& );

        string nombre;
    protected:

    private:
        vector<uint32_t> nCatalogos; //libros alquilados

        uint32_t dni;
        Ubicacion ubpers;
};

#endif // PERSONA_H
