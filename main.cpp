#include "usuarios.h"
#include "reporte.h"

#include<stdlib.h> 
#include<iostream> 
#include<string>
using namespace std;

int main (){
    reporte rep;
    rep.testers();
    rep.crearCliente("Activo", "Automotriz" , "Norte" , "0104504", "1234" , "Alex");
    rep.mostrar();
    rep.crearNegocio("Activo", "Automotriz" , "Norte" , "0104504", "1234" , "Starbooks_INC");
}