#include "Fecha.h"

Fecha::Fecha()
{
    //ctor
}

Fecha::Fecha(uint16_t d, uint16_t m, uint16_t a)
{
    dia=d;
    mes=m;
    anio=a;
}

Fecha::~Fecha()
{
    //dtor
}
bool Fecha:: confFechaFuturo()
{
    const int monthDays[12]= { 31, 28, 31, 30, 31, 30,
       31, 31, 30, 31, 30, 31 };
       // initialize count using years and day
    long int n1 = now->tm_year* 365 + now->tm_mday;

    // Add days for months in given date
    for (int i = 0; i < now->tm_mon  ; i++)
        n1 += monthDays[i];

    // SIMILARLY, COUNT TOTAL NUMBER OF
    // DAYS BEFORE 'dt2'

    long int n2 = (anio-1900) * 365 + dia;
    for (int i = 0; i < mes - 1; i++)
        n2 += monthDays[i];
    // return difference between two counts
    if((n1 - n2)<0)
    {
        cout<<endl<<"Error: la fecha ingresada esta en el futuro";
        return false;
    }

    else return true;

}
bool Fecha:: confFechaValida()
{

        if ( (mes==1 || mes ==3 || mes == 5 || mes == 7 || mes== 8 || mes== 10
         || mes==12)  && (dia >= 1 || dia<=31) && (anio>=1860 ) )
        {

                return confFechaFuturo();

        }
        else if ( (mes==4 || mes ==6 || mes == 9 || mes == 11)
                && (dia >= 1 || dia<=30)
                && (anio>=1860 ) )
        {
                 return confFechaFuturo();

        }

        else if((mes==2) && (dia>=1 || dia<=28 || 29) && (anio>=1860) &&
                ((anio)>0) && !((anio)%4) &&
                ( ((anio)%100) || !((anio)%400) ) )
        {

                    return confFechaFuturo();
        }

        else
        {
            cout<< "FECHA NO VALIDA";
            return false;
        }
}
ostream& operator<<(ostream& os, const Fecha& dt)
{
    os << dt.dia << '/' << dt.mes << '/' << dt.anio;
    return os;
}

istream& operator >>(istream& is,Fecha& f)

{
    try
    {
        int d,m,y;
        char ch1,ch2;

        string test;

        is>>skipws>>d>>ch1>>m>>ch2>>y;
        if(!is)
        {
            is.clear(ios_base::failbit);
            return is;
        }
        if(ch1!='/' || ch2!='/')
        {
            throw"Error: fecha invalida";
        }
        else
        {
            f = Fecha(d,m,y);
        }

        return is;
    }
    catch(const char* e)
    {
        throw;
    }

}

ostream& Fecha::guardar(){

    ostream& os = cout;
    os<<endl<<dia<<endl<<mes<<endl<<anio<<endl;
    return os;
}
