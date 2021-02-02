#ifndef ALQUILER_H
#define ALQUILER_H
#include "Fecha.h"
#include "Persona.h"
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Alquiler
{
    public:
        Alquiler();
        Alquiler (uint16_t, bool);
        virtual ~Alquiler();

        uint16_t GetcontadorAlquiler() { return contadorAlquiler; }
        void SetcontadorAlquiler(uint16_t val) { contadorAlquiler = val; }

        Fecha GetultimaFecha() { return ultimaFecha; }
        void SetultimaFecha(Fecha val) { ultimaFecha = val; }

        Persona GetultimoEncargado() { return ultimoEncargado; }
        void SetultimoEncargado(Persona val) { ultimoEncargado = val; }

        vector<string> GetClientes() { return clientes; }
        void SetClientes(vector<string> val) { clientes = val; }

        bool Getalquilado() { return alquilado; }
        void Setalquilado(bool val) { alquilado = val; }

        bool verVenc();

        void infoAlquiler();

        friend ostream& operator<<(ostream& os, const Alquiler& a);

    protected:

    private:
        vector<string> clientes;
        uint16_t contadorAlquiler=0;
        Fecha ultimaFecha;
        Persona ultimoEncargado;
        bool alquilado;
};

#endif // ALQUILER_H
