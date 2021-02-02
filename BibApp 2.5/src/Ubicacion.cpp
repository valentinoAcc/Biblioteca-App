#include "Ubicacion.h"

Ubicacion::Ubicacion()
{
    //ctor
}

Ubicacion::Ubicacion(string d, string t, string e, uint16_t c)
{
    direccion= d;
    telefono =t;
    email= e;
    codpostal= c;
}
Ubicacion::~Ubicacion()
{
    //dtor
}

ostream& operator<<(ostream& os, const Ubicacion& dt)
{
    os << dt.direccion <<" Telefono: " << dt.telefono<< endl;
    os<< dt.email<< " Codigo postal: " << dt.codpostal<<endl;
    return os;
}
