#ifndef APUNTES_H
#define APUNTES_H

#include <Ejemplar.h>


class Apuntes : public Ejemplar
{
    public:
        Apuntes();
        Apuntes
        virtual ~Apuntes();

        uint16_t Getpaginas() { return paginas; }
        void Setpaginas(uint16_t val) { paginas = val; }
        string Getautor() { return autor; }
        void Setautor(string val) { autor = val; }
        string Getarea() { return area; }
        void Setarea(string val) { area = val; }

    protected:

    private:
        uint16_t paginas;
        string autor;
        string area;
};

#endif // APUNTES_H
