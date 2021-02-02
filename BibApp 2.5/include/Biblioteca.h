#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

#include "Ejemplar.h"
#include "Ubicacion.h"
#include "Persona.h"
#include "Alquiler.h"

using namespace std;

class Biblioteca


{
    public:

        Biblioteca();
        /*! Constructor
        *   Constructor clase biblioteca.
        * @param: string nombre de la biblioteca, ubicacion, vector de encargados
        * @retunr: -
        */
        Biblioteca(string, Ubicacion, vector<Persona>);
        virtual ~Biblioteca();

        /* Setters y Getters*/
        string Getnombre() { return nombre; }
        void Setnombre(string val) { nombre = val; }
        Ubicacion Getubicacion() { return ubicacion; }
        void Setubicacion(Ubicacion val) { ubicacion = val; }
        vector<Persona> Getencargados() { return encargados; }
        void Setencargados(vector<Persona> val) { encargados = val; }
        Persona GetEncargadoActual() { return encargadoActual; }
        void SetEncargadoActual(Persona val) { encargadoActual = val; }
        uint32_t GetcantEjemplares() { return cantEjemplares; }
        void SetcantEjemplares(uint32_t val) { cantEjemplares = val; }
        map<uint32_t, Ejemplar*> Getcatalogo() { return catalogo; }
        void Setcatalogo(map<uint32_t, Ejemplar*> val) { catalogo = val; }
        map<uint32_t, Alquiler*> Getalquileres() { return alquileres; }
        void Setalquileres(map<uint32_t, Alquiler*> val) { alquileres = val; }
        Persona getEncargado(int indice);
        int getCantEncargados();

        /*! Method
        *  Inserta el ejemplar en el mapa de ejemplares y alquileres de le biblioteca. verifica que no se haya
        * agregado un libro eliminado.
        * @param: Ejemplar*: el ejemplar que quiero a agregar a mi mapa catalogo
        * @retunr: -
        */
        void ingresarEjemplar(Ejemplar*);

        /*! Method
        *  Borra el el ejemplar del numero de catalogo en los parametros. lo agrega a un vector de eliminados
        * @param: uint16_t : corresponde al numero de ctalogo que busco eliminar
        * @retunr: -
        */
        void eliminarEjemplar(uint32_t);

        /*! Method
        *   Setea el objeto alquiler, informandoel ejemplar del numeroCatalogo esta siendo alquilado
        * @param: numeroCatalogo corresponde al libro que se alquila
        * bool true si se esta alquilando, false si se esta devolviendo
        * Fecha en la que se alquilo o fecha en la que se devuelve
        * Persona que lo alquilo
        * Persona encargada en el momento que se alquilo
        * @param:uint32_t: nro de catalogo del libro que voy a alquilar
        *        bool: true si el libro se esta alquilando
                 Fecha: setea la fecha del alquiler
                 string: nombre del cliente que lo alquila
                 Persona: Encargado a cargo del alquiler
        * @retunr: -
        */
        void alquilerEjemplar(uint32_t, bool, Fecha, string, Persona);

        /*! Method
        *  devolucion de un ejemplar setea el atributo alquilado en false
        * @param:-
        * @retunr: uint32_t num catalogo
        */
        void alquilerEjemplar(uint32_t);

        /*! Method
        *  contador del mapa alquileres, dvuelve la catidad de libros que estan siendo alquilados
        * @param:-
        * @retunr: uint32_t catidad de libros alquilados
        */
        uint32_t cantAlquilados();

        /*! Method
        * Lista los ejemplares alquilados con su numero de catlogo, Titulo , persona que lo alquilo, encargado del alquiler
        * Vencimiento y si esta vencido o o no
        * @param: -
        * @retunr: -
        */
        void listarAlquilados();
        /*! Method
        *   Recorre el mapa de alquileres, segun los parametros que le pase lista todos los ejemplares o solo de las clases derivadas
            y el orden en que se presentan
        * @param:string "que se muestra", si le paso "todos" muestra todos los ejemplares, si le paso un tipo(libro, revista etc) muestra solo la subclase
        *        char es el orden en que se muestran, 'n' corrresponde al numero de catalogo y 't' alfabeticamente por titulo
        * @retunr: -
        */
        void listarEjemplares( string, char);

        /*! Method
        *   Imprime detalladamente un ejemplar especifico
        * @param: uint32_t numero de catalogo del ejemplar que quiera imprimir
        * @retunr: -
        */
        void imprimir(uint32_t);

        /*! Method     (le cambiaria el nombre a info de alquiler por los parametros que devuelve)
        *   Verifica si el libro que le paso esta alquilado y si se vencio el alquiler
        * @param: uint32_t numero de catalodo de dicho libro
        * @retunr: bool: true si esta alquilado, false si no esta alquilado
        */
        bool vencimientoAlquiler(uint32_t);

        /*! Method
        *   Muestr ala cantidad de veces que el ejemplar fue alquiado y los clientes que elo alquilaron
        * @param: uint32_t numero de catalogo del ejemplar
        * @retunr: -
        */
        void historialAlquileres(uint32_t _nCatalogo);

        /*! Method
        *   Recive un parametro de tipo Persona y lo inserta en el vector de encargados de la biblioteca
        * @param: Persona encargado que se esta agregado
        * @retunr: -
        */
        void agregarEncargado(Persona _encargado);

        /*! Method
        *   Imprime una de los encargados trabajando para la biblioteca con todos sus datos
        * @param: -
        * @retunr: -
        */
        void listarEncargados();

    protected:

    private:

        string nombre;
        Ubicacion ubicacion;
        vector<Persona> encargados;
        Persona encargadoActual;
        uint32_t cantEjemplares=0;
        map<uint32_t, Ejemplar*> catalogo;
        map<uint32_t, Alquiler*> alquileres;
        vector<uint32_t> eliminados;

};

#endif // BIBLIOTECA_H
