#ifndef DVD_H
#define DVD_H

#include <Ejemplar.h>


class Dvd : public Ejemplar
{
    public:
        Dvd();
        Dvd(string, uint16_t, string, string, uint32_t, string, Fecha, string, string);

        virtual ~Dvd();

        uint16_t Getduracion() { return duracion; }
        void Setduracion(uint16_t val) { duracion = val; }
        string Getgenero() { return genero; }
        void Setgenero(string val) { genero = val; }
        string Getsubtitulos() { return subtitulos; }
        void Setsubtitulos(string val) { subtitulos = val; }
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
        ostream& guardar();

    protected:

    private:

        uint16_t duracion;
        string genero;
        string subtitulos;
};

#endif // DVD_H
