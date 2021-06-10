#include "usuarios.h"
#include "reporte.h"

#include<stdlib.h> 
#include<iostream> 
#include<string>
using namespace std;

int main (){
    reporte rep;
    rep.testers();//Crear los casos de prieba 
    rep.crearCliente("Activo", "Automotriz" , "Norte" , "0104504", "1234" , "Alex");//crear objeto cliente
    rep.crearNegocio("Activo", "Automotriz" , "Norte" , "0104504", "1234" , "Starbooks_INC");//crear objeto negocio
}