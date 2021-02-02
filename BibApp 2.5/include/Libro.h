#ifndef LIBRO_H
#define LIBRO_H

#include <Ejemplar.h>
#include"Persona.h"
#include <string>
#include "Fecha.h"



using namespace std;
class Libro : public Ejemplar
{
    public:

        Libro(); //el tipo y el num de catalogo se tienen que setear cuiando se crea
        Libro(string, string, uint16_t, string, string, string, string, uint32_t, string, Fecha, string, string);
        Libro(string);
        virtual ~Libro();

        string Getautor() { return autor; }
        void Setautor(string val) { autor = val; }

        string Getisbn() { return isbn; }
        void Setisbn(string val) { isbn = val; }

        uint16_t GetcantPaginas() { return cantPaginas; }
        void SetcantPaginas(uint16_t val) { cantPaginas = val; }

        string Getpais() { return pais; }
        void Setpais(string val) { pais = val; }

        string Getgenero() { return genero; }
        void Setgenero(string val) { genero = val; }
        /*! Method
        *   Imprime los datos basicos para listar (nro de catalogo, titulo, autor, genero, tipo, idioma)
        * @param: -
        * @retunr: -
        */
        void imprime();
        /*! Method
        *   Imprime todos los datos del libro pra una vista mas especifica
        * (todo)
        * @param: sentiodo, horizontal o verical
        * @retunr: -
        */
        void imprime (char sentido);

        void cargarDatos();

    protected:

    private:
        string autor; //!< Member variable "autor"
        string isbn; //!< Member variable "isbn"
        uint16_t cantPaginas; //!< Member variable "cantPaginas"
        string pais; //!< Member variable "pais"
        string genero; //!< Member variable "genero"
        string encuadernacion;
};

#endif // LIBRO_H
