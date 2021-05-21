#include<stdlib.h> 
#include<iostream> 
using namespace std;

//declaramos la primera clase con sus distintos atributos y metodos

class usuario {
  //Declaramos sus atributos publicos
  public:
    char estatus;
    char area_n;
    char region;
    char nom;
  //Declaramos sus atributos protegidos
  protected:
    char ID;
    char contraseña;
    int comp;
  //Declaramos sus metodos que en este caso todos son publicos 
  public: 
    usuario (char , char , char ,char , char , char); //Constructor
    usuario (int ID, char contraseña, char estatus, char area_n, char region, char nombre);
      char crear() {return ID;} //metodo con return
      int verificar () {return comp;}
      void enviar_mensaje(char ID); //metodos con input
};

//En el constructor identificamos las variables que vamos a usar con la clase usuario y sus clases hijas (heredadas)

usuario::usuario (char _estatus , char _area_n , char _region ,char _ID , char _contraseña , char _comp){
  ID = _ID;
  contraseña = _contraseña;
  comp = _comp;
  estatus = _estatus;
  area_n = _area_n;
  region = _region;
}

usuario::usuario (int _ID, char _contraseña, char _estatus, char _area_n, char _region, char _nombre){
  ID = _ID;
  contraseña = _contraseña;
  nom = _nombre;
  estatus = _estatus;
  area_n = _area_n;
  region = _region;
}

//Metodo de crear en el cual se recopila informacion para usar en ambas posibilidades de cuenta (cliente y negocio)

char usuario::crear (){
  cout<<"Introduce tu nombre/empresa: "<< ID << endl;
  cout<<"Introduce tu contraseña: "<< contraseña << endl;
  cout<<"Activo (0) o inactivo (1) segun sea el caso: "<< estatus <<endl;
  cout<<"Introduce tu area de trabajo: "<< area_n << endl;
  cout<<"Introduce tu region/ubicacion de trabajo: "<< region << endl;
}

int usuario::verificar (){
  char ID1;
  char contraseña1;
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
}

void usuario::enviar_mensaje(char ID){
  
}

class cliente : public usuario {
  public:
    char nombre;
  public:
    cliente(char);
};

class negocio : public usuario {
  public:
    char nobre_negocio;
};

class producto {
  public:
    char nombre_producto;
    float precio;
  protected:
    producto (char , float);
      char crear (char nombre_producto , char &precio);
      void eliminar_producto ();
      void cambiar_nombre ();
      void cambiar_precio ();
};


int main (){
  usuario us("Activo" , "Autobuses" , "Naucalpan" , "Alternet" , "1234uml" , "comp" );
  us.crear();
}
