#ifndef ALQUILER_H
#define ALQUILER_H
#include "Fecha.h"
#include "Persona.h"
#include <vector>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

class Alquiler
{
    public:
        Alquiler();
        Alquiler (uint16_t, bool, Persona _encargado, Fecha _ultimaFecha);
        virtual ~Alquiler();

        uint16_t GetcontadorAlquiler() { return contadorAlquiler; }
        void SetcontadorAlquiler(uint16_t val) { contadorAlquiler = val; }

        Fecha GetultimaFecha() { return ultimaFecha; }
        void SetultimaFecha(Fecha val) { ultimaFecha = val; }

        Persona GetultimoEncargado() { return ultimoEncargado; }
        void SetultimoEncargado(Persona val) { ultimoEncargado = val; }

        vector<Persona*> GetClientes() { return clientes; }
        void SetClientes(vector<Persona*> val) { clientes = val; }

        bool Getalquilado() { return alquilado; }
        void Setalquilado(bool val) { alquilado = val; }
        bool verVenc();

        void infoAlquiler();

        friend ostream& operator<<(ostream& os, const Alquiler& a);
        ostream& guardar();

        void agregaCliente(Persona * _cliente) { clientes.push_back(_cliente);}

    protected:

    private:
        Persona ultimoEncargado;
        vector<Persona*> clientes={};
        Fecha ultimaFecha;
        uint16_t contadorAlquiler=0;
        bool alquilado;
};

#endif // ALQUILER_H
