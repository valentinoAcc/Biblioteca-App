#ifndef UBICACION_H
#define UBICACION_H
#include <iostream>
using namespace std;

class Ubicacion
{
    public:
        Ubicacion();
        Ubicacion(string , string , string , uint16_t );
        virtual ~Ubicacion();

        string Getdireccion() { return direccion; }
        void Setdireccion(string val) { direccion = val; }

        string Gettelefono() { return telefono; }
        void Settelefono(string val) { telefono = val; }

        string Getemail() { return email; }
        void Setemail(string val) { email = val; }

        uint16_t Getcodpos() { return codpostal; }
        void Setcodpos(uint16_t val) { codpostal = val; }

        friend ostream& operator<<(ostream& os, const Ubicacion& dt);
    protected:

    private:
        string direccion;
        string telefono;
        uint16_t codpostal;
        string email;
};

#endif // UBICACION_H
