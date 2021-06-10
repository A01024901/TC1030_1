#ifndef usuarios_INCLUDED
#define usuarios_INCLUDED

#include<stdlib.h> 
#include<iostream> 
#include<string>
using namespace std;

//declaramos la primera clase con sus distintos atributos y metodos

class usuario {
  //Declaramos sus atributos publicos
  private:
    string estatus;
    string area_n;
    string region;
    string nom;
  //Declaramos sus atributos protegidos
  private:
    string ID;
    string contraseña;
  //Declaramos sus metodos que en este caso todos son publicos 
  public: 
    usuario();
    usuario (string , string , string , string, string ); //Constructor
    void setSeguridad (string , string); //Metodo setter
    string getID ();
    string getContraseña ();
      //Metodos que seran usados en el polimorfismo
      virtual void mostrar() = 0; //Clase abstracata para nominar el esqueleto de la funcion 
      virtual int verificar () ;
};

//En el constructor identificamos las variables que vamos a usar con la clase usuario y sus clases hijas (heredadas)

usuario::usuario (){
  nom = "nombre";
  estatus = "_estatus";
  area_n = "_area_n";
  region = "_region";
}

usuario::usuario (string _estatus, string _area_n, string _region,  string _ID , string _contraseña){
  estatus = _estatus;
  area_n = _area_n;
  region = _region;
  ID = _ID;
  contraseña = _contraseña;
}

//Metodo setter para la seccion privada de la clase

void usuario :: setSeguridad(string _ID, string _contraseña){
  ID = _ID;
  contraseña = _contraseña;
}

//Metodos getters de variables impotantes o requeridas 

string usuario :: getID(){
  return ID;
}

string usuario :: getContraseña(){
  return contraseña;
}

//Metodo de crear en el cual se recopila informacion para usar en ambas posibilidades de cuenta (cliente y negocio)

void usuario::mostrar (){
  cout<<"Introduce tu nombre/empresa: "<< ID << endl;
  cout<<"Introduce tu contraseña: "<< contraseña << endl;
  cout<<"Activo (0) o inactivo (1) segun sea el caso: "<< estatus <<endl;
  cout<<"Introduce tu area de trabajo: "<< area_n << endl;
  cout<<"Introduce tu region/ubicacion de trabajo: "<< region << endl;
}

//Metodo para verificar que la cuenta sea en realidad la cuenta que dice. En caso de ser correcto regresa un 1, si es falso regresa 0
int usuario::verificar (){
  string ID1;
  string contraseña1;
  contraseña1 = "1,2,3,4";
  int opc;
  while (contraseña != contraseña1){
    cout << "Introduce tu nombre/empresa/ID: "<< ID1 << endl;
    cout << "Introduce tu contraseña: "<< contraseña1 << endl;
    if (contraseña == contraseña1){
      return 1 ;
    }
    else {
      cout << "Contraseña incorrecta... deseas volver a intentar??? "<< endl;
      cout << "Si (0)     No (1)" << opc <<endl;
      if (opc == 1){
        cout << "Gracias por participar"<< endl;
        return 0 ;
      }
    }
  }
  return 0 ;
}

//Clase con herencia  de usuario, subseccion que es el cliente, ya que proviene y comparte metodos y atributos.
class cliente : public usuario {
  private:
    string nombre;
  public:
    cliente ();
    cliente(string , string , string , string , string , string);
    void mostrar ();
};

//Metodo constructor de cliente.
cliente :: cliente (){
  nombre = '_';
}

//Conbstructor con sobrecarga.
cliente :: cliente (string _estatus, string _area_n, string _region,  string _ID , string _contraseña , string _nombre) : usuario (_estatus, _area_n, _region,  _ID , _contraseña){
  nombre = _nombre;
}

//Metodo sobreescrito mostrar que proviene de la clase abstracta.
void cliente :: mostrar (){
    usuario :: mostrar ();
  cout<<"Su nombre es:"<< nombre << endl;
}

//Clase con herencia negocio que proviene de usuario. 
class negocio : public usuario {
  private:
    producto p;//Composicion con producto
    string nombre_negocio;
  public:
    negocio ();
    negocio (string , string , string , string , string , string);
    void mostrar ();
};

//Metodo constructor de negocio con herencia de usuasrio 
negocio :: negocio (string _estatus, string _area_n, string _region,  string _ID , string _contraseña , string _nobre_negocio) : usuario (_estatus, _area_n, _region,  _ID , _contraseña){
  nombre_negocio = _nobre_negocio;
}

//Metodo sobreescrito de mostrar
void negocio :: mostrar (){
    usuario::mostrar();
  cout<<"Su nombre de empresa es:"<<nombre_negocio<<endl;
}

//Clase producto. 
class producto {
  private:
    string nombre_producto;
    float precio;
  protected:
    producto (string , float);
      ~producto ();
      void cambiar_nombre (string);
      void cambiar_precio (float);
      string get_nombre ();
      float get_precio();
};

//Metodo setter con nombre "cambiar_nombre"
void producto :: cambiar_nombre (string _nombre){
 nombre_producto = _nombre;
}

//Metodo setter con nombre "cambiar_precio"
void producto :: cambiar_precio (float _precio){
 precio = _precio;
}

//Metodo getter con nombre "get_nombre"
string producto :: get_nombre (){
  return nombre_producto;
}

//Metodo getter con nombre "get_precio"
float producto :: get_precio (){
  return precio;
}

#endif 