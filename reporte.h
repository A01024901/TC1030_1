#ifndef reporte_INCLUDED
#define reporte_INCLUDED

#include "usuarios.h"

#include<time.h>
#include<stdlib.h> 
#include<iostream> 
#include<string>
using namespace std;

//Constante que dice el numero maximo de usuaris prueba. 
const int M = 200;

//clase reporte donde se aplica polimorfismo
class reporte {
    private:
        usuario *usuarios[M];//apuntador para el uso de polimorfismo
        string num_reporte;
        int num_reportes;
    public:
        //constructores y destructores 
        reporte();
        ~reporte();
        //setter reporte
        void setReporte (string);
        //getter reporte
        string getReporte ();
        string numReporte (string nom_producto);
        string numReporte (string ID , string nom_producto);//sobrecarga del metodo numReporte 
        void testers ();
        //Crear objetos 
        void crearCliente (string _estatus, string _area_n, string _region,  string _ID , string _contraseña , string _nombre);
        void crearNegocio (string _estatus, string _area_n, string _region,  string _ID , string _contraseña , string _nombre_negocio);
        //Mostrar objeto
        void mostrar ();

};

reporte :: reporte (){
    num_reportes = 0;
}

reporte :: ~reporte(){
    for (int i = 0 ; i < num_reportes ; i++){
        delete usuarios[i];
    }
}

void reporte :: setReporte (string _numReporte){
    num_reporte = _numReporte;
}

string reporte :: getReporte (){
    return num_reporte;
}

/*Los siguientes metodos incrementan el numero en reportes y regresan una cadena de characteres que va relacionada con l nombre del producto 
Y el ID en el caso de que se tengan ambos. */

string reporte:: numReporte(string nom_producto){
    num_reportes++;
    num_reporte = nom_producto;
    return (num_reporte);
}

string reporte:: numReporte(string ID , string nom_producto){
    num_reportes++;
    num_reporte = ID + nom_producto;
    return (num_reporte);
}


//Generador de casos de prueba 
void reporte :: testers (){
    usuarios[num_reportes] = new cliente ("Activo", "Automotriz", "Norte", "01024901" , "1234", "Alex");
    num_reportes = num_reportes + 1;
    usuarios[num_reportes] = new cliente ("Activo", "Comida", "Sur", "01025001" , "5678", "Edgar");
    num_reportes = num_reportes + 1;
    usuarios[num_reportes] = new cliente ("Inactivo", "Muebles", "Este", "01026001" , "90123", "Ulises");
    num_reportes = num_reportes + 1;
    usuarios[num_reportes] = new cliente ("Inactivo", "Computacion", "Oeste", "01027001" , "4567", "Orlando");
    num_reportes = num_reportes + 1;
}

//Crear objeto clase cliente
void reporte :: crearCliente (string _estatus, string _area_n, string _region,  string _ID , string _contraseña , string _nombre){
    usuarios [num_reportes] = new cliente (_estatus,  _area_n,  _region,   _ID ,  _contraseña ,  _nombre);
    reporte::mostrar;
}

//Crear objeto clase negocio
void reporte :: crearNegocio (string _estatus, string _area_n, string _region,  string _ID , string _contraseña , string _nombre_negocio){
    usuarios [num_reportes] = new negocio (_estatus,  _area_n,  _region,   _ID ,  _contraseña ,  _nombre_negocio);
    reporte::mostrar;
}

void reporte :: mostrar (){
    usuario::mostrar;
}

#endif 