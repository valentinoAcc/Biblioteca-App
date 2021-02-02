#include "Revista.h"

Revista::Revista()
{
    //ctor
}

Revista::Revista(string _volumen, string _issn, bool _referato, string _titulo, uint32_t _numCatalogo, string _editorial, Fecha _anioEdicion, string _idioma, string _tipo){

    volumen = _volumen;
    issn = _issn;
    referato = _referato;
    titulo = _titulo;
    numCatalogo = _numCatalogo;
    editorial = _editorial;
    anioEdicion = _anioEdicion;
    idioma = _idioma;
    tipo = _tipo;

}

Revista::~Revista()
{
    //dtor
}

void Revista:: imprime()
{
    cout<<GetnumCatalogo() <<"  " <<Gettitulo()<< "   "<< Getvolumen()<<endl;
}

void Revista:: imprime(char completo)
{
    if (completo == 'c' || completo == 'C')
    {
        cout<< "Titulo: "<<Gettitulo()<<endl;
        cout<< "Volumen: "<<Getvolumen()<<endl;
        cout<< "Numero de catalogo: "<<GetnumCatalogo()<<endl;
        cout<< "Idioma: "<<Getidioma()<<endl;
        cout<< "ISSN: "<<Getissn()<<endl;
        if(Getreferato()){
            cout<< "Referato: SI"<<endl;
        }else   cout<< "Referato: NO"<<endl;
        cout<< "Editorial: "<<Geteditorial()<<endl;
        cout<< "Fecha de edicion: "<<GetanioEdicion()<<endl;


    }
}

ostream& Revista::guardar(){

    ostream &os = anioEdicion.guardar();
    //heredado
    os<<tipo.c_str()<<endl<<titulo.c_str()<<endl<<to_string(numCatalogo)<<endl<<editorial.c_str()<<endl<<idioma.c_str()<<endl;
    //específico
    uint16_t refe=0;
    if (referato==true) refe = 1;
    else refe = 0;

    os<<refe<<endl<<volumen.c_str()<<endl<<issn.c_str();

    return os;

}
