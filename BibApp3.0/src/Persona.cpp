#include "Persona.h"

Persona::Persona()
{
    //ctor
}

Persona::Persona(string n, uint32_t d, Ubicacion u)
{
    nombre = n;
    Setdni(d);
    ubpers= u;
    nCatalogos={};
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

ostream& Persona::guardar (){

    ostream& os = ubpers.guardar();
    uint16_t i;
    os<<to_string(nCatalogos.size())<<endl;

    for (i=0; i<nCatalogos.size(); i++){
        os<<to_string(nCatalogos[i])<<endl;;
    }
    os<<to_string(dni)<<endl;
    os<<nombre.c_str()<<endl;

    return os;
}
