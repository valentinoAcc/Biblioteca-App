#include "Persona.h"

Persona::Persona()
{
    //ctor
}

Persona::Persona(string n, uint32_t d, Ubicacion u)
{
    nombre = n;
    dni= d;
    ubpers= u;
}
Persona::~Persona()
{
    //dtor
}
ostream& operator<<(ostream& os, const Persona& p)
{
    os<< "Nombre: "<< p.nombre<<endl;
    os << "DNI: " << p.dni <<endl;
    os<< p.ubpers<<endl;
    return os;
}
