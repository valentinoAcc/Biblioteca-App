#include "Biblioteca.h"
#include <iterator>

bool compara( Ejemplar* l,  Ejemplar* r) {

    if((l->Gettitulo()).compare(r->Gettitulo())<0) return true;
    else return false;

}

Biblioteca::Biblioteca(string n, Ubicacion u, vector<Persona> e){

    nombre = n;
    ubicacion = u;
    encargados = e;

}

Biblioteca::Biblioteca()
{
    //ctor
}

Biblioteca::~Biblioteca()
{
    //dtor
}


void Biblioteca::ingresarEjemplar(Ejemplar *e){

    try{
        auto it = find(eliminados.begin(), eliminados.end(), e->GetnumCatalogo());
        if(it == eliminados.end()){
            if(catalogo.find(e->GetnumCatalogo())==catalogo.end()){
                catalogo.insert({e->GetnumCatalogo(), e});
                alquileres.insert({e->GetnumCatalogo(), new Alquiler(0,false)});
                cantEjemplares++;
            }else throw "Error: Numero de catálogo existente";
        }else throw "Error: Numero de catalogo ya utilizado";
    }catch(const char* e){
        throw;
    }
}


void Biblioteca::eliminarEjemplar(uint32_t e){


    try{
        if(catalogo.find(e)==catalogo.end()){
            throw "Ejemplar no existente";
        }else {
            eliminados.push_back(e);
            catalogo.erase(e);
            cantEjemplares--;
        }
    }catch(const char* err){
        throw;
    }
}

void Biblioteca::historialAlquileres(uint32_t e){

    try{
        if(catalogo.find(e)==catalogo.end()){
            throw "Ejemplar no existente";
        }else {
            auto it = alquileres.find(e);
            Alquiler *alquiler = it->second;
            vector<string> usuarios = alquiler->GetClientes();
            cout<<"El ejemplar fue alquilado "<<alquiler->GetcontadorAlquiler()<<" veces"<<endl;
            cout<<endl;
            cout<<"***CLIENTES***"<<endl;
            for (auto i = usuarios.begin(); i != usuarios.end(); ++i)
            cout << *i << endl;

        }
    }catch (const char* err){
        throw;
    }

}

void Biblioteca::alquilerEjemplar(uint32_t numero, bool estado, Fecha fAlquiler, string cli, Persona enc){

    try{
        if(catalogo.find(numero)==catalogo.end()){
            throw "Ejemplar no existente";
        }else {
            auto it = alquileres.find(numero);
            Alquiler *alquiler = it->second;
            if ((estado == true)&&(alquiler->Getalquilado()==true))throw "Error: El libro ya se encuentra alquilado";
            else{
                alquiler->Setalquilado(estado);
                alquiler->SetultimaFecha(fAlquiler);
                alquiler->SetultimoEncargado(enc);
                vector<string> aux = alquiler->GetClientes();
                aux.push_back(cli);
                alquiler->SetcontadorAlquiler(aux.size());
                alquiler->SetClientes(aux);
            }
        }
    }catch (const char* err){
        throw;
    }
}

void Biblioteca:: alquilerEjemplar(uint32_t numero)
{

            auto it = alquileres.find(numero);

                it->second->Setalquilado(false);

}

uint32_t Biblioteca::cantAlquilados(){

    uint32_t cont = 0;
    for (auto it = alquileres.begin(); it != alquileres.end(); ++it){
        if(it->second->Getalquilado()){
            cont++;
        }
    }
    return cont;
}

void Biblioteca ::listarAlquilados()
{



    for (auto itA=alquileres.begin(); itA!=alquileres.end(); ++itA)
    {


        if(itA->second->Getalquilado() == true)
        {
             cout<< "Numero de catalogo y Titulo:"<<endl;
             catalogo.at(itA->first)->imprime();
            itA->second->verVenc();
            cout<<endl;
        }



    }
}
void Biblioteca::listarEjemplares(string tipo, char orden){  //tipo = tipo 'todos'->todos de ejemplar orden 'n'->Numero  't'->titulo

    vector<Ejemplar*> vecListado;
    if( tipo== "Libro")
    {
        cout<< "Nro Catalogo    "<<"TITULO        "<<"AUTOR"<<endl<<endl;
    }
    else if(tipo== "Revista")
    {
        cout<< "Nro Catalogo    "<<"TITULO        "<<"VOLUMEN"<<endl<<endl;
    }
    else if(tipo== "Dvd")
    {
        cout<< "Nro Catalogo    "<<"TITULO        "<<"GENERO"<<endl<<endl;
    }

    else if(tipo== "Apunte")
    {
        cout<< "Nro Catalogo    "<<"TITULO        "<<"AUTOR"<<endl<<endl;
    }


    switch (orden){

    case 'n':

        for (auto it=catalogo.begin(); it!=catalogo.end(); ++it){
            if(it->second->getTipo()==tipo) it->second->imprime();
            if(tipo=="todos") it->second->imprime();
        }
        break;

    case 't':

        for (auto it=catalogo.begin(); it!=catalogo.end(); ++it){
            vecListado.push_back(it->second);
        }
        sort(vecListado.begin(), vecListado.end(), &compara);
        for (uint16_t i=0; i<vecListado.size(); i++){
            if(vecListado[i]->getTipo()==tipo) vecListado[i]->imprime();
            if(tipo=="todos") vecListado[i]->imprime();
        }
        break;
    }
}

void Biblioteca::imprimir(uint32_t key){

    try{
        auto it = catalogo.find(key);
        if(it==catalogo.end()) throw "Error: Ejemplar no existente";
        else{
            it->second->imprime('c');
        }
    }catch( const char* ){
        throw;
    }


}

bool Biblioteca::vencimientoAlquiler(uint32_t key){

    try{
        auto it = alquileres.find(key);
        auto it2 = catalogo.find(key);
        if(it2==catalogo.end())
        {
            throw "Error: Ejemplar no existente";
            return false;
        }
        else{
                return it->second->verVenc();
        }
    }catch( const char* ){
        throw;
    }

}

void Biblioteca::agregarEncargado(Persona _encargado){

    vector<Persona> encAux = Getencargados();
    encAux.push_back(_encargado);
    Setencargados(encAux);
}
void Biblioteca::listarEncargados()
{
    for(uint16_t i = 0; i < encargados.size(); i++)
	{
		cout <<"Encargado "<<i<<"  "<< encargados[i] << std::endl;
	}
}

Persona Biblioteca:: getEncargado(int indice)
{
    return encargados[indice];
}

int Biblioteca::getCantEncargados()
{
    return encargados.size();
}
