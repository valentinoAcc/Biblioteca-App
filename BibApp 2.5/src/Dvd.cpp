#include "Dvd.h"

Dvd::Dvd()
{
    //ctor
}

Dvd::Dvd(string _genero, uint16_t _duracion, string _subtitulos, string _titulo, uint32_t _numCatalogo, string _editorial, Fecha _anioEdicion, string _idioma, string _tipo){

    genero = _genero;
    duracion = _duracion;
    subtitulos = _subtitulos;
    titulo = _titulo;
    numCatalogo = _numCatalogo;
    editorial = _editorial;
    anioEdicion = _anioEdicion;
    idioma = _idioma;
    tipo = _tipo;


}

Dvd::~Dvd()
{
    //dtor
}

void Dvd:: imprime()
{
    cout<<GetnumCatalogo() <<"       " <<Gettitulo()<< "          "<< Getgenero()<<endl;
}

void Dvd:: imprime(char completo)
{
    if (completo == 'c' || completo == 'C')
    {
        cout<< "Titulo: "<<Gettitulo()<<endl;
        cout<< "Genero: "<<Getgenero()<<endl;
        cout<< "Numero de catalogo: "<<GetnumCatalogo()<<endl;
        cout<< "Idioma: "<<Getidioma()<<endl;
        cout<< "Subtitulos: "<<Getsubtitulos()<<endl;
        cout<< "Duracion: "<< Getduracion()<<"min"<<endl;
    }
}
