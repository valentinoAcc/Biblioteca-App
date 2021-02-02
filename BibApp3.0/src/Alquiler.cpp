#include "Alquiler.h"
uint16_t difereciaDias(tm *, Fecha);

Alquiler::Alquiler()
{
    //ctor
}

Alquiler::Alquiler(uint16_t c, bool e, Persona _encargado, Fecha _ultimaFecha){

    alquilado = e;
    contadorAlquiler = c;
    ultimoEncargado = _encargado;
    ultimaFecha = _ultimaFecha;
}

Alquiler::~Alquiler()
{
    //dtor

}


bool Alquiler:: verVenc()
{

    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    int diferencia = difereciaDias(now, ultimaFecha);
    if (alquilado == 1 )
    {
        Persona* last = clientes.back();
        cout <<"El ejemplar se encuentra actualmente alquilado a :"<<last->Getnombre()<<endl;
        cout << "Encargado que se lo alquilo: " << ultimoEncargado.Getnombre()<<endl;
        cout <<"-fecha de hoy: " <<now->tm_mday << '/'<< (now->tm_mon + 1) << '/'<<  (now->tm_year + 1900)<<endl;
        cout <<"-fecha en la que se alquilo: "<< ultimaFecha<<endl;
        if(diferencia >14)
        {
            cout<< "-El alquiler esta vencido"<<endl;
        }

        else
        {
            cout<<"-El alquiler NO esta vencido"<<endl;
        }


    }
    else
    {
        cout<<"El ejemplar no esta siendo alquilado"<<endl;
    }
    return alquilado;
}

uint16_t difereciaDias(tm *f1, Fecha f2)
{
    const int monthDays[12]= { 31, 28, 31, 30, 31, 30,
       31, 31, 30, 31, 30, 31 };
       // initialize count using years and day
    long int n1 = f1->tm_year* 365 + f1->tm_mday;

    // Add days for months in given date
    for (int i = 0; i < f1->tm_mon  ; i++)
        n1 += monthDays[i];

    // SIMILARLY, COUNT TOTAL NUMBER OF
    // DAYS BEFORE 'dt2'

    long int n2 = (f2.Getanio()-1900) * 365 + f2.Getdia();
    for (int i = 0; i < f2.Getmes() - 1; i++)
        n2 += monthDays[i];
    // return difference between two counts
    return (n1 - n2);

}

void Alquiler:: infoAlquiler()
{
    cout<< this<<endl;
}

ostream& operator<<(ostream& os, Alquiler& a)
{
    Persona* cliente = a.GetClientes().back();
    os<< "cliente: "<< cliente->Getnombre()<< endl;
    os << "Encargado que se lo alquilo: " << a.GetultimoEncargado().Getnombre()<<endl;
    os<< "Fecha de alquiler"<<a.GetultimaFecha()<<endl;
    return os;
}

ostream& Alquiler::guardar(){

    int isAlquilado=0;
    if(clientes.size()>0){

        ostream &os = ultimoEncargado.guardar();
        os<< to_string(contadorAlquiler);
        //string nombre;
        //uint32_t dni;

//        for (int i = 0; i < contadorAlquiler; ++i){
//            nombre=clientes[0]->Getnombre();
//            dni=clientes[0]->Getdni();
//            Persona aux = Persona(nombre, dni, Ubicacion("xx","xx","xx",000));
//            aux.guardar();
//        }
//        for (long unsigned i=0; i<clientes.size(); i++)
//        clientes[i]->guardar();
        ultimaFecha.guardar();
        if(alquilado) isAlquilado = 1;
        else isAlquilado = 0;
        os<<isAlquilado;
        return os;

    }else return cout;
}
