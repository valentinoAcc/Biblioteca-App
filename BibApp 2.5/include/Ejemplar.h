#ifndef EJEMPLAR_H
#define EJEMPLAR_H
#include <string>
#include "Fecha.h"

using namespace::std;

class Ejemplar
{
    public:
        Ejemplar();
        virtual ~Ejemplar();
        //Setters y Getters
        string Gettitulo() { return titulo; }
        void Settitulo(string val) { titulo = val; }
        uint32_t GetnumCatalogo() { return numCatalogo; }
        void SetnumCatalogo(uint32_t val) { numCatalogo = val; }
        string Geteditorial() { return editorial; }
        void Seteditorial(string val) { editorial = val; }
        string Getidioma() { return idioma; }
        void Setidioma(string val) { idioma = val; }
        Fecha GetanioEdicion() { return anioEdicion; }
        void SetanioEdicion(Fecha val) { anioEdicion = val; }
        string getTipo(){ return tipo; }
        void setTipo (string val) {tipo = val; }

        virtual void imprime() = 0;
        virtual void imprime(char) = 0;

    protected:

        string titulo;
        uint32_t numCatalogo;
        string editorial;
        string idioma;
        Fecha anioEdicion;
        string tipo;

    private:

};

#endif // EJEMPLAR_H
