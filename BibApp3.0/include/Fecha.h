#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <ctime>
using namespace std;

class Fecha
{
    public:
        Fecha();
        Fecha(uint16_t, uint16_t, uint16_t);
        virtual ~Fecha();

        time_t t = time(0);   // get time now
        tm* now = localtime(&t);

        uint16_t Getdia() { return dia; }
        void Setdia(uint16_t val) { dia = val; }
        uint16_t Getmes() { return mes; }
        void Setmes(uint16_t val) { mes = val; }
        uint16_t Getanio() { return anio; }
        void Setanio(uint16_t val) { anio = val; }

        bool confFechaValida();
        bool confFechaFuturo();

        friend ostream& operator<<(ostream& os, const Fecha& dt);
        friend istream& operator >>(istream& is,Fecha& f);
        ostream& guardar();
    protected:

    private:
        uint16_t dia;
        uint16_t mes;
        uint16_t anio;
};

#endif // FECHA_H
