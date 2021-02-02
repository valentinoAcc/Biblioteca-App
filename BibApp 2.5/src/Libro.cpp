#include "Libro.h"

Libro::Libro()
{
    //ctor
}

Libro::~Libro()
{
    //dtor
}

Libro::Libro(string au, string is, uint16_t pag, string pai, string enc, string gen, string ti, uint32_t numC, string ed, Fecha anio, string id, string t){

    autor = au;
    isbn=is;
    cantPaginas = pag;
    pais = pai;
    encuadernacion = enc;
    genero = gen;
    titulo = ti;
    numCatalogo = numC;
    editorial = ed;
    anioEdicion = anio;
    idioma = id;
    tipo = t;

}

Libro::Libro(string au){

    autor = au;


}

void Libro:: imprime()
{
    cout<<GetnumCatalogo() <<"            " <<Gettitulo()<< "            "<< Getautor()<<endl;
}

void Libro:: imprime(char completo)
{
    if (completo == 'c' || completo == 'C')
    {
        cout<< "Titulo: "<<Gettitulo()<<endl;
        cout<< "Autor: "<<Getautor()<<endl;
        cout<< "Numero de catalogo: "<<GetnumCatalogo()<<endl;
        cout<< "Genero: "<< Getgenero()<<endl;
        cout<< "Idioma: "<<Getidioma()<<endl;
        cout<< "ISBN: "<<Getisbn()<<endl;
        cout<< "Editorial: "<<Geteditorial()<<endl;
        cout<< "Fecha de edicion: "<< GetanioEdicion()<<endl;
        cout<< "Pais: "<<Getpais()<<endl;
        cout<< "Cantidad de Paginas: "<< GetcantPaginas()<<endl;
    }
}
/*
void Libro:: cargarDatos()
{

    string aux;
    Fecha fechaaux;
    uint16_t auxnum;

    cin.clear();
    cout<< "Titulo: ";
    getline(cin, aux);
    this->Settitulo(aux);

    cin.clear();
    cout<< "Editorial: ";
    getline(cin, aux);
    this->Seteditorial(aux);

    cin.clear();
    cout<< "Idioma: ";
    getline(cin, aux);
    this->Setidioma(aux);

    cin.clear();
    cout<< "Fecha de Edicion: ";
    cin >>fechaaux; //operador sobrecargado

    cin.clear();
    cout<< "Autor: ";
    getline(cin, aux);
    this->Setautor(aux);

    cin.clear();
    cout<<"ISBN: ";
    getline(cin, aux);
    this->Setisbn(aux);

    cin.clear();
    cout<<"Cantidad de paginas: ";
    cin>>auxnum;
    this->SetcantPaginas(auxnum);

    cin.clear();
    cout<<"Pais: ";
    getline(cin, aux);
    this->Setpais(aux);

    cin.clear();
    cout<<"Genero: ";
    getline(cin, aux);
    this->Setgenero(aux);

}
*/
