#ifndef reportesT_INCLUDED
#define reportesT_INCLUDED

#include "usuarios.h"

#include<stdlib.h> 
#include<iostream> 
#include<string>
using namespace std;

const int M = 200;

class reporte {
    private:
        usuario *usuarios[M];
        string num_reporte;
        int num_reportes;
    public:
        reporte();
        ~reporte();
        void setReporte (string);
        string getReporte ();
        void numReporte (string producto);
        void numReporte (string ID);
        void testers ();
        void crearCliente (string _estatus, string _area_n, string _region,  string _ID , string _contraseña , string _nombre);
        void crearNegocio (string _estatus, string _area_n, string _region,  string _ID , string _contraseña , string _nombre_negocio);
        void mostrar (int);

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

void reporte :: crearCliente (string _estatus, string _area_n, string _region,  string _ID , string _contraseña , string _nombre){
    usuarios [num_reportes] = new cliente (_estatus,  _area_n,  _region,   _ID ,  _contraseña ,  _nombre);
}

void reporte :: crearNegocio (string _estatus, string _area_n, string _region,  string _ID , string _contraseña , string _nombre_negocio){
    usuarios [num_reportes] = new negocio (_estatus,  _area_n,  _region,   _ID ,  _contraseña ,  _nombre_negocio);
}

#endif reportesT_INCLUDED