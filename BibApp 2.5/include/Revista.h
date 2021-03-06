#ifndef REVISTA_H
#define REVISTA_H

#include <Ejemplar.h>


class Revista : public Ejemplar
{
    public:
        Revista();
        Revista(string, string, bool, string, uint32_t, string, Fecha, string, string);

        virtual ~Revista();

        string Getvolumen() { return volumen; }
        void Setvolumen(string val) { volumen = val; }
        string Getissn() { return issn; }
        void Setissn(string val) { issn = val; }
        bool Getreferato() { return referato; }
        void Setreferato(bool val) { referato = val; }
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

    protected:

    private:
        string volumen;
        string issn;
        bool referato;
};

#endif // REVISTA_H
