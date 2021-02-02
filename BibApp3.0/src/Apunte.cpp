#include "Apunte.h"

Apunte::Apunte()
{
    //ctor
}

Apunte::Apunte(string ar, uint16_t pag, string aut, string tit, uint32_t numC, string ed, Fecha anio, string id, string _tipo){

    area = ar;
    paginas = pag;
    autor = aut;
    titulo = tit;
    numCatalogo = numC;
    editorial = ed;
    anioEdicion = anio;
    idioma = id;
    tipo = _tipo;
}

Apunte::~Apunte()
{
    //dtor
}

void Apunte:: imprime()
{
    cout<<GetnumCatalogo() <<"  " <<Gettitulo()<< "   "<< Getautor()<<endl;
}

void Apunte:: imprime(char completo)
{
    if (completo == 'c' || completo == 'C')
    {
        cout<< "Titulo: "<<Gettitulo()<<endl;
        cout<< "Autor: "<<Getautor()<<endl;
        cout<< "Numero de catalogo: "<<GetnumCatalogo()<<endl;
        cout<< "Área: "<<Getarea()<<endl;
        cout<< "Numero de paginas: "<<Getpaginas()<<endl;
        cout<<"Fecha de edicion: "<< GetanioEdicion()<<endl;
    }
}


ostream& Apunte::guardar(){

    ostream &os = anioEdicion.guardar();
    //heredado

    os<<tipo.c_str()<<endl<<titulo.c_str()<<endl<<to_string(numCatalogo)<<endl<<editorial.c_str()<<endl<<idioma.c_str()<<endl;

    //específico
    os<<to_string(paginas)<<endl<<autor.c_str()<<endl<<area.c_str();

    return os;

}
