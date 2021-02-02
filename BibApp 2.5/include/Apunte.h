#ifndef APUNTE_H
#define APUNTE_H

#include <Ejemplar.h>


class Apunte : public Ejemplar
{
    public:
        Apunte();
        Apunte(string, uint16_t, string autor, string, uint32_t, string, Fecha, string, string);
        virtual ~Apunte();

        uint16_t Getpaginas() { return paginas; }
        void Setpaginas(uint16_t val) { paginas = val; }
        string Getautor() { return autor; }
        void Setautor(string val) { autor = val; }
        string Getarea() { return area; }
        void Setarea(string val) { area = val; }
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
        uint16_t paginas;
        string autor;
        string area;
};

#endif // APUNTE_H
