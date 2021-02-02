#include "Biblioteca.h"
#include <iterator>
#include <fstream>
bool compara( Ejemplar* l,  Ejemplar* r) {

    if((l->Gettitulo()).compare(r->Gettitulo())<0) return true;
    else return false;

}

Biblioteca::Biblioteca(string n, Ubicacion u){

    nombre = n;
    ubicacion = u;


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
                alquileres.insert({e->GetnumCatalogo(), new Alquiler(0,false, GetEncargadoActual(), Fecha(1,1,2000))});
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
            vector<Persona*> usuarios = alquiler->GetClientes();
            cout<<"El ejemplar fue alquilado "<<alquiler->GetcontadorAlquiler()<<" veces"<<endl;
            cout<<endl;
            cout<<"***CLIENTES***"<<endl;
            for (int i = 0; i < usuarios.size(); ++i){
                cout<< "Nombre: "<< usuarios[i]->Getnombre()<<endl;
                cout<< "DNI: " << usuarios[i]->Getdni() <<endl;
                cout<< usuarios[i]->Getubicacion()<<endl;

            }


        }
    }catch (const char* err){
        throw;
    }

}

void Biblioteca::alquilerEjemplar(uint32_t numero, bool estado, Fecha fAlquiler, uint32_t clienteDni, Persona enc){

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


                vector<Persona*> auxListado = alquiler->GetClientes();
                Persona* clienteAux = clientes[clienteDni];
                vector<uint32_t> catalogoAux;
                if(alquiler->GetcontadorAlquiler()>0){
                    catalogoAux = clienteAux->GetNcatalogos();
                    catalogoAux.push_back(numero);
                }else{
                    catalogoAux = {numero};
                }
                auxListado.push_back(clienteAux);
                clienteAux->setNcatalogos(catalogoAux);
                alquiler->agregaCliente(clienteAux);
                clientes[clienteDni] = clienteAux;

                alquiler->SetcontadorAlquiler(auxListado.size());
                //alquiler->SetClientes(auxListado);

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

void Biblioteca::agregarCliente(Persona* _cliente){

    clientes.insert(pair<uint32_t, Persona*>(_cliente->Getdni(), _cliente));



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

Persona* Biblioteca:: getCliente(uint32_t indice)
{
    return clientes[indice];
}

int Biblioteca::getCantEncargados()
{
    return encargados.size();
}

void Biblioteca::guardar(){
    streambuf *psbuf, *backup;
    backup = cout.rdbuf();
    ofstream file;

    file.open("ejemplares.txt");
    psbuf = file.rdbuf();
    cout.rdbuf(psbuf);


    cout<<to_string(catalogo.size());
    for (auto it=catalogo.begin(); it!=catalogo.end(); ++it){
            (it->second->guardar());
        }
    cout.rdbuf(backup);
    file.close();

    backup = cout.rdbuf();
    file.open("alquileres.txt");
    psbuf = file.rdbuf();
    cout.rdbuf(psbuf);
    int i = 0;
    for (auto it=alquileres.begin(); it!=alquileres.end(); it++){

        if(it->second->GetcontadorAlquiler()>0) i++;
    }

    cout<< to_string(i)<<endl;;
    for (auto it=alquileres.begin(); it!=alquileres.end(); it++){

            (it->second->guardar());
            if(it->second->GetcontadorAlquiler()>0) cout<<endl<<it->first<<endl;
        }
    cout.rdbuf(backup);
    file.close();

    backup = cout.rdbuf();
    file.open("encargados.txt");
    psbuf = file.rdbuf();
    cout.rdbuf(psbuf);
    cout<<to_string(encargados.size())<<endl;
    for (int i=0; i<encargados.size(); i++){
            (encargados[i].guardar());
        }
    cout.rdbuf(backup);
    file.close();

    //cout<<clientes.at(37321654)->Getnombre()<<clientes.at(37321654)->Getdni();
    backup = cout.rdbuf();
    file.open("clientes.txt");
    psbuf = file.rdbuf();
    cout.rdbuf(psbuf);
    cout<<to_string(clientes.size())<<endl;
    for (auto it=clientes.begin(); it!=clientes.end(); it++){

        (it->second->guardar());

    }

    cout.rdbuf(backup);
    file.close();

}

void Biblioteca::cargaEncargados(){

    ifstream file;
    string dir, tel, mail, nombre, sAux;
    vector <uint32_t> nCat;
    uint32_t aux;
    uint16_t cp;
    int cant, nEjemplares;
    file.open("encargados.txt");
    getline(file, sAux);
    cant = stoi(sAux);
    //file>>cant;

    for ( int i = 0; i<cant; i++){
        getline(file, dir);
        getline(file, tel);
        getline(file, sAux);
        cp = stoi(sAux);
        getline(file, mail);
        getline(file, sAux);
        nEjemplares = stoi(sAux);

        for (int j = 0; j<nEjemplares; j++){
            getline(file, sAux);
            aux = stoi(sAux);
            nCat.push_back(aux);
        }
        getline(file, sAux);
        aux = stoi(sAux);
        getline(file, nombre);

        Persona encargado = Persona(nombre, aux, Ubicacion(dir, tel, mail, cp));
        encargado.setNcatalogos(nCat);
        agregarEncargado(encargado);

    }

    file.close();

}

void Biblioteca::cargaEjemplares(){

    ifstream file;
    string tipo, sAux, titulo, editorial, idioma, autor, isbn, pais, genero, encuadernacion, subtitulos, volumen, issn, area;
    uint32_t aux, nCat;
    uint16_t dia, mes, anio, pags, duracion;
    bool refe;
    int cant;
    file.open("ejemplares.txt");
    getline(file, sAux);
    cant = stoi(sAux);
    //file>>cant;

    for ( int i = 0; i<cant; i++){
        getline(file, sAux);
        dia = stoi(sAux);
        getline(file, sAux);
        mes = stoi(sAux);
        getline(file, sAux);
        anio = stoi(sAux);
        getline(file, tipo);
        getline(file, titulo);
        getline(file, sAux);
        nCat = stoi(sAux);
        getline(file, editorial);
        getline(file, idioma);
        if (tipo == "Libro"){

            getline(file, sAux);
            pags = stoi(sAux);
            getline(file, autor);
            getline(file, isbn);
            getline(file, pais);
            getline(file, genero);
            getline(file, encuadernacion);
            Libro *libro = new Libro(autor, isbn, pags, pais, encuadernacion, genero, titulo, nCat, editorial, Fecha(dia,mes,anio), idioma, tipo);
            ingresarEjemplar(libro);
        }
        if (tipo == "Apunte"){

            getline(file, sAux);
            pags = stoi(sAux);
            getline(file, autor);
            getline(file, area);
            Apunte *apunte = new Apunte(area, pags, autor, titulo, nCat, editorial, Fecha(dia, mes, anio), idioma, tipo);
            ingresarEjemplar(apunte);
        }

        if (tipo == "Dvd"){

            getline(file, sAux);
            duracion = stoi(sAux);
            getline(file, genero);
            getline(file, subtitulos);
            Dvd *dvd = new Dvd(genero, duracion, subtitulos, titulo, nCat, editorial, Fecha(dia, mes, anio), idioma, tipo);
            ingresarEjemplar(dvd);

        }

        if (tipo == "Revista"){

            getline(file, sAux);
            aux = stoi(sAux);
            if (aux==0) refe = false;
            else refe = true;
            getline(file, volumen);
            getline(file, issn);
            Revista *revista = new Revista (volumen, issn,refe, titulo, nCat, editorial, Fecha(dia, mes, anio), idioma, tipo);
            ingresarEjemplar(revista);
        }


    }

    file.close();

}

void Biblioteca::cargaClientes(){

    ifstream file;
    string dir, tel, mail, nombre, sAux;
    vector <uint32_t> nCat;
    uint32_t aux;
    uint16_t cp;
    int cant, nEjemplares;
    file.open("clientes.txt");
    getline(file, sAux);
    cant = stoi(sAux);
    //file>>cant;

    for ( int i = 0; i<cant; i++){
        getline(file, dir);
        getline(file, tel);
        getline(file, sAux);
        cp = stoi(sAux);
        getline(file, mail);
        getline(file, sAux);
        nEjemplares = stoi(sAux);

        for (int j = 0; j<nEjemplares; j++){
            getline(file, sAux);
            aux = stoi(sAux);
            nCat.push_back(aux);
        }
        getline(file, sAux);
        aux = stoi(sAux);
        getline(file, nombre);

        Persona* cliente = new Persona(nombre, aux, Ubicacion(dir, tel, mail, cp));
        cliente->setNcatalogos(nCat);
        agregarCliente(cliente);

    }

    file.close();

}
