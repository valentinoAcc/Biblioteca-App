#include "Menu.h"


Menu::Menu(){

}

Menu::Menu(Biblioteca *b){

    bib = b;

}


Menu::~Menu()
{
    //dtor
}
void Menu :: limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    // Assume POSIX
    system ("clear");
#endif
}

void Menu:: preMenu()
{
    bib->cargaEncargados();
    bib->cargaEjemplares();
    bib->cargaClientes();
    //bib->alquilerEjemplar(111,true,Fecha(10,10,2001),37321654, Persona("Encargado", 37321654, Ubicacion("luro 118", "2235918544", "maxi@c.com", 7609)));
    int aux;
    bib->listarEncargados();
    Persona pAux;
    cout<<endl<<"Seleccione el encargado actual: ";
    do
    {
        cin >>aux;
        if (aux<bib->getCantEncargados())
        {
            pAux= bib->getEncargado(aux);
            bib->SetEncargadoActual(pAux);
            limpiarPantalla();
            cout<<"BIENVENIDO/A "<<pAux.Getnombre()<<endl;

        }
        else
        {
            cout<<"opcion invalida vueva a intentarlo: "<<endl;
        }

    }
    while (aux > bib->getCantEncargados()-1);
            system("pause");
    limpiarPantalla();
}

void Menu:: menuPrincipal()
{
    limpiarPantalla();

    int opcion=0;
	while (opcion != 7)
	{

	    cout << "\n*** BIBLIOTECA "<< bib->Getnombre()<<"***\n";
	    cout << bib->Getubicacion()<<endl;
        cout << "Cantidad de ejemplares registrados: "<<bib->GetcantEjemplares()<<endl;
        cout << "Cantidad de ejemplares alquilados: "<<bib->cantAlquilados()<<endl;
        cout << "\n*** ENCARGADO  ACTUAL***\n"<<endl;
        cout<<bib->GetEncargadoActual()<<endl;


        cout << "\n*** MENU ***\n";
        cout << "\nSeleccione una opcion:\n\n";
        cout << "    1: Alquileres" << endl;
        cout << "    2: Listar Ejemplares" << endl;
        cout << "    3: Opciones Ejemplares" << endl;
        cout << "    4. Opciones Biblioteca" << endl<<endl;
        cout << "    7: Salir" << endl;

        cin >> opcion;
        cout << endl;
		switch (opcion)
		{
		case 1:

		    limpiarPantalla();
            cout << "1. Alquileres: " << endl;
            menuAlquileres();


			break;
		case 2:

		    limpiarPantalla();
		    cout << "2. Lista de Ejemplares: " << endl;
		    menuListado();

			break;

		case 3:

		    menuEjemplares();

			break;

		case 4:

		    limpiarPantalla();
		    menuBiblioteca();

			break;

        case 7:
            limpiarPantalla();
            break;
		default:
			cout << "Opcion Invalida" << endl;

			break;
		}

	}
    bib->guardar();

}


void Menu::menuAlquileres()
{
    uint16_t opcion=0;

    while (opcion != 8)
    {
        limpiarPantalla();
        cout << "\nSeleccione una opcion:\n\n";
        cout << "    1: Alquiler de un Ejemplar" << endl;
        cout << "    2: Listar Alquilados" << endl;
        cout << "    3: Historial ejemplar" << endl<< endl;

        cout << "    8: volver" << endl;

        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case 1:

            limpiarPantalla();
            alquilerEjemplar();


            break;
        case 2:

            limpiarPantalla();
            listadoAlquilados();
            break;

        case 3:
            limpiarPantalla();
            uint32_t nCat;
            cout<<"Ingrese numero de catalogo: ";
            cin>>nCat;
            try{
                bib->historialAlquileres(nCat);
            }catch ( const char * e){
                cout<<e<<endl;
            };


            break;
        case 8:

            limpiarPantalla();


            break;

        default:
            cout << "Opcion Invalida" << endl;

            break;
        }
        system("pause");


    }

}
void Menu:: listadoAlquilados()
{
    bib->listarAlquilados();
}
void Menu::alquilerEjemplar()
{
    bool auxbool;
    uint32_t nC;

    cout<<"Numero de catalogo"<<endl;
    cin>>nC;
    try{
        auxbool= bib->vencimientoAlquiler(nC);
        if(auxbool==true)  //si se encuentra alquilado
        {
            subMenuAlquileres1(nC);

        }
        else // si no esta alquilado
        {
            subMenuAlquileres2(nC);
        }
    }catch(const char* e){
        cout<<e<<endl;
    }

}

void Menu::devolverEjemplar()
{

    uint32_t nC;
    cout<<"Ingrese numero de catalogo"<<endl;
    cin>>nC;
    try{
        bib->alquilerEjemplar(nC);
    }catch(const char* e){
        cout<<e<<endl;
    }

}
void Menu:: subMenuAlquileres1(uint32_t numCatalogoAux)// si el libro esta alquilado
{
	    int aux;
    while (aux != 8)
	{
    cout<<endl<<endl;
    cout<<"1: Terminar Alquiler"<<endl;
    cout<<"8: Volver "<<endl;
    cin>>aux;
		switch (aux)
		{
		case 1:
            bib->alquilerEjemplar(numCatalogoAux);
            cout<<endl<<endl<<"Se finalizo el alquiler"<<endl;

			break;
        case 8:

            break;

		default:
			cout << "Opcion Invalida" << endl;

			break;
		}
	}

}
void Menu:: subMenuAlquileres2(uint32_t nC)// si el libro no esta alquilado
{
    int aux;
    Persona cliente;
    Fecha fechaaux;
    bool confFecha= true;
    do
    {
        cout<<endl<<endl;
        cout<<"1:Alquilar"<<endl;
        cout<<"8: Volver"<<endl;
        cin>>aux;
        switch (aux)
        {
        case 1:
//            cout<<"Ingrese nombre de cliente: "<<endl;
//            cin>>cliente;
            cout<<"Ingrese fecha del alquiler (FORMATO dd/mm/aa) :"<<endl;
            do
            {
            cin>>fechaaux;
            if (fechaaux.confFechaValida()==false)
            {
                cout<<endl<<"intente denuevo: ";
                confFecha=false;
            }else
            {
                confFecha =true;
            }
            } while (confFecha==false);



            bib->alquilerEjemplar(nC,true,fechaaux, 37321654, bib->Getencargados().back());
            cout<<endl<<endl<<"Se alquilo el libro a :"<<cliente<<endl;
            break;
        case 8:
            cout<< "volviendo"<<endl;
            limpiarPantalla();
        default:
            break;
        }

    } while (aux != 8);



}
void Menu::menuEjemplares()
{
    int opcion=0;
    uint32_t n;
    while (opcion != 8)
    {
        limpiarPantalla();
        cout << "\nSeleccione una opcion:\n\n";
        cout << "    1: Ingresar ejemplar" << endl;
        cout << "    2: Eliminar ejemplar" << endl;
        cout << "    3: Ver estado" << endl;

        cout << "    8: volver" << endl;

        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case 1:

            limpiarPantalla();
            try{
                bib->ingresarEjemplar(ingresaEjemplar());
            }catch (const char* e){
                cout<<e<<endl;
            }


            break;
        case 2:

            limpiarPantalla();

            cout<<"Numero de catalogo a eliminar: ";
            cin>>n;
            try{
                bib->eliminarEjemplar(n);
            }catch(const char *e){
                cout<<e<<endl;
            }

            break;

        case 3:

            limpiarPantalla();
            cout<<"Numero de catalogo a revisar: ";
            cin>>n;
            cin.ignore();
            try{
                bib->imprimir(n);

            }catch(const char *e){
                cout<<e<<endl;
            }
            break;

        case 8:

            limpiarPantalla();


            break;

        default:
            cout << "Opcion Invalida" << endl;

            break;
        }
        system("pause");


    }

}

void Menu::menuListado()
{
    int opcion=0;
    string tipo;
    char orden;
    while (opcion != 8)
    {
        orden='x';
        tipo="vacio";
        limpiarPantalla();
        cout << "\nTipo de ejemplar:\n\n";
        cout << "    1: Libro" << endl;
        cout << "    2: Revista" << endl;
        cout << "    3: Dvd" << endl;
        cout << "    4: Apunte" << endl<< endl;
        cout << "    8: volver" << endl;

        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case 1:

            limpiarPantalla();
            tipo="Libro";


            break;
        case 2:

            limpiarPantalla();
            tipo="Revista";

            break;

        case 3:

            limpiarPantalla();
            tipo="Dvd";

            break;

        case 4:
            limpiarPantalla();
            tipo="Apunte";

            break;
        case 8:

            limpiarPantalla();


            break;

        default:
            cout << "Opcion de tipo Invalida" << endl;
            system("pause");
            break;
        }

        if(opcion!=8){

            limpiarPantalla();
            cout << "\nTipo de orden:\n\n";
            cout << "    1: Numero de catalogo" << endl;
            cout << "    2: Titulo" << endl<< endl;

            cout << "    8: volver" << endl;

            cin >> opcion;
            cout << endl;

            switch (opcion)
            {
            case 1:

                limpiarPantalla();
                orden='n';


                break;
            case 2:

                limpiarPantalla();
                orden='t';

                break;


            case 8:

                limpiarPantalla();


                break;

            default:
                cout << "Opcion de orden Invalida" << endl;
                system("pause");
                break;
            }

        }

        if((orden!='x')&&(tipo!="vacio")&&(opcion!=8)){
            bib->listarEjemplares(tipo,orden);
            system("pause");

        }




    }

}

Ejemplar* Menu::ingresaEjemplar(){

    int opcion=0;
    string tipo;
    tipo="vacio";
    limpiarPantalla();
    cout << "\nTipo de ejemplar:\n\n";
    cout << "    1: Libro" << endl;
    cout << "    2: Revista" << endl;
    cout << "    3: Dvd" << endl;
    cout << "    4: Apunte" << endl<< endl;

    cout << "    8: volver" << endl;

    cin >> opcion;
    cout << endl;

    if (opcion==1){

        limpiarPantalla();
        Libro *libro = ingresarLibro();
        return libro;
    }

        else if (opcion==2){

        limpiarPantalla();
        Revista *revista = ingresarRevista();
        return revista;
    }

    else if (opcion==3){

        limpiarPantalla();
        Dvd * dvd = ingresarDvd();
        return dvd;
    }

        else {

        limpiarPantalla();
        Apunte * apunte= ingresarApunte();

        return apunte;

    }
}

Libro* Menu:: ingresarLibro()
{
        string tipo="Libro";
        string autor;
        string isbn;
        uint16_t paginas;
        string pais;
        string encuadernacion;
        string genero;
        string titulo;
        uint32_t numCatalogo;
        string editorial;
        Fecha fechaaux;
        bool confFecha=true;
        string idioma;
        cin.ignore();
        cout<<"Autor: ";
        getline(cin, autor);
        cout<<endl;
        cout<<"ISBN: ";
        cin>>isbn;
        cout<<endl;
        cout<<"Cantidad de paginas: ";
        cin>>paginas;
        cout<<endl;
        cin.ignore();
        cout<<"Pais: ";
        getline(cin, pais);
        cout<<endl;
        cout<<"Encuadernacion: ";
        getline(cin, encuadernacion);
        cout<<endl;
        cout<<"Genero: ";
        getline(cin, genero);
        cout<<endl;
        cout<<"Titulo: ";
        getline(cin, titulo);
        cout<<endl;
        cout<<"Numero de catalogo (recomendado: "<<bib->GetcantEjemplares()+1 <<"): ";
        cin>>numCatalogo;
        cout<<endl;
        cin.ignore();
        cout<<"Editorial: ";
        getline(cin, editorial);
        cout<<endl;
        cout<<"Fecha de edicion (dd/mm/aaaa): ";
        do
            {
            cin>>fechaaux;
            if (fechaaux.confFechaValida()==false)
            {
                cout<<endl<<"intente denuevo: ";
                confFecha=false;
            }else
            {
                confFecha =true;
            }
            } while (confFecha==false);
        cout<<"Idioma: ";
        cin>>idioma;
        Libro* libro = new Libro(autor, isbn, paginas, pais, encuadernacion, genero, titulo, numCatalogo, editorial, fechaaux, idioma, tipo);
        return libro;
}

Revista* Menu:: ingresarRevista()
{
        string tipo="Revista";
        string volumen;
        string issn;
        char refChar;
        bool referato;
        string titulo;
        uint32_t numCatalogo;
        string editorial;
        Fecha fechaaux;
        bool confFecha=true;
        string idioma;
        cin.ignore();
        cout<<"Volumen: ";
        getline(cin, volumen);
        cout<<endl;
        cout<<"ISSN: ";
        cin>>issn;
        cout<<endl;
        cout<<"Referato? (s)i - (n)o: ";
        cin>>refChar;
        if(refChar=='s') referato = true;
        else referato = false;
        cout<<endl;
        cin.ignore();
        cout<<"Titulo: ";
        getline(cin, titulo);
        cout<<endl;
        cout<<"Numero de catalogo (recomendado: "<<bib->GetcantEjemplares()+1 <<"): ";
        cin>>numCatalogo;
        cout<<endl;
        cin.ignore();
        cout<<"Editorial: ";
        getline(cin, editorial);
        cout<<endl;
        cout<<"Fecha de edicion (dd/mm/aaaa): ";
        do
            {
            cin>>fechaaux;
            if (fechaaux.confFechaValida()==false)
            {
                cout<<endl<<"intente denuevo: ";
                confFecha=false;
            }else
            {
                confFecha =true;
            }
            } while (confFecha==false);
        cout<<"Idioma: ";
        cin>>idioma;
        Revista* revista = new Revista(volumen, issn, referato, titulo, numCatalogo, editorial, fechaaux, idioma, tipo);
        return revista;
}

Dvd* Menu:: ingresarDvd()
{
        string tipo="Dvd";
        string genero;
        string subtitulo;
        uint16_t duracion;
        string titulo;
        uint32_t numCatalogo;
        string editorial;
        Fecha anioEdicion;
        string idioma;
        cin.ignore();
        cout<<"Genero: ";
        getline(cin, genero);
        cout<<endl;
        cin.ignore();
        cout<<"Subtitulo: ";
        getline(cin, subtitulo);
        cout<<"Duracion (minutos): ";
        cin>>duracion;
        cout<<endl;
        cin.ignore();
        cout<<"Titulo: ";
        getline(cin, titulo);
        cout<<endl;
        cout<<"Numero de catalogo (recomendado: "<<bib->GetcantEjemplares()+1 <<"): ";
        cin>>numCatalogo;
        cout<<endl;
        cin.ignore();
        cout<<"Editorial: ";
        getline(cin, editorial);
        cout<<endl;
        Fecha fechaaux;
        bool confFecha= true;
        cout<<"Fecha de edicion (dd/mm/aaaa): ";
        do
        {
            cin>>fechaaux;
            if (fechaaux.confFechaValida()==false)
            {
                cout<<endl<<"intente denuevo: ";
                confFecha=false;
            }
            else
            {
                confFecha =true;
            }
        }
        while (confFecha==false);
        cout<<"Idioma: ";
        cin>>idioma;
        Dvd* dvd= new Dvd(genero, duracion, subtitulo, titulo, numCatalogo, editorial, fechaaux, idioma, tipo);
        return dvd;
}

Apunte * Menu:: ingresarApunte()
{
        string tipo="Apunte";
        string area;
        uint16_t paginas;
        string autor;
        string titulo;
        uint32_t numCatalogo;
        string editorial;
        Fecha anioEdicion;
        string idioma;
        cin.ignore();
        cout<<"Area: ";
        getline(cin, area);
        cout<<endl;
        cout<<"Paginas: ";
        cin>>paginas;
        cin.ignore();
        cout<<"Autor: ";
        getline(cin, autor);
        cout<<endl;
        cin.ignore();
        cout<<"Titulo: ";
        getline(cin, titulo);
        cout<<endl;
        cout<<"Numero de catalogo (recomendado: "<<bib->GetcantEjemplares()+1 <<"): ";
        cin>>numCatalogo;
        cout<<endl;
        cin.ignore();
        cout<<"Editorial: ";
        getline(cin, editorial);
        cout<<endl;
        Fecha fechaaux;
        bool confFecha=true;
        cout<<"Fecha de edicion (dd/mm/aaaa): ";
        do
            {
            cin>>fechaaux;
            if (fechaaux.confFechaValida()==false)
            {
                cout<<endl<<"intente denuevo: ";
                confFecha=false;
            }else
            {
                confFecha =true;
            }
            } while (confFecha==false);
        cout<<"Idioma: ";
        cin>>idioma;
        Apunte* apunte= new Apunte(area, paginas, autor, titulo, numCatalogo, editorial, fechaaux, idioma, tipo);
        return apunte;
}

void Menu::menuBiblioteca()
{
    uint16_t opcion=0;

    while (opcion != 8)
    {
        limpiarPantalla();
        cout << "\nSeleccione una opcion:\n\n";
        cout << "    1: Modificar nombre" << endl;
        cout << "    2: Modificar ubicacion" << endl;
        cout << "    3: Agregar encargado" << endl;

        cout << "    8: volver" << endl;

        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case 1:

            limpiarPantalla();
            modificarNombre();


            break;
        case 2:

            limpiarPantalla();
            modificarUbicacion();

            break;

        case 3:

            agregarEncargado();

            break;

        case 8:

            limpiarPantalla();


            break;

        default:
            cout << "Opcion Invalida" << endl;

            break;
        }
        system("pause");


    }

}

void Menu::modificarNombre(){

    string nombre;
    cout<<"Ingrese nombre: ";
    cin.ignore();
    getline(cin, nombre);
    bib->Setnombre(nombre);

}

void Menu::modificarUbicacion(){

    string direccion;
    string telefono;
    string email;
    uint16_t codPostal;
    cin.ignore();
    cout<<"Ingrese direccion: ";
    getline(cin, direccion);
    cout<<"Ingrese telefono: ";
    getline(cin, telefono);
    cout<<"Ingrese email: ";
    getline(cin, email);
    cout<<"Ingrese codigo postal: ";
    cin>>codPostal;
    bib->Setubicacion(Ubicacion(direccion, telefono, email, codPostal));

}

void Menu::agregarEncargado(){


    string nombre;
    uint32_t dni;
    string direccion;
    string telefono;
    string email;
    uint16_t codPostal;
    cin.ignore();
    cout<<"Ingrese nombre completo: ";
    getline(cin, nombre);
    cout<<"Ingrese direccion: ";
    getline(cin, direccion);
    cout<<"Ingrese telefono: ";
    getline(cin, telefono);
    cout<<"Ingrese email: ";
    getline(cin, email);
    cout<<"Ingrese codigo postal: ";
    cin>>codPostal;
    cout<<"Ingrese DNI: ";
    cin>>dni;
    bib->agregarEncargado(Persona(nombre, dni, Ubicacion(direccion, telefono, email, codPostal)));

}




