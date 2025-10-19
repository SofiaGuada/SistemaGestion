#include <iostream>
#include <cstring>
#include "Cliente.h"
using namespace std;

Cliente::Cliente()
:_idCliente(0),_nombre("-"),_apellido("-"),_dni("-"),_email("-"),_telefono("0"){

}

Cliente::Cliente(int idCliente,string nombre, string apellido,string dni,string email,string telefono,bool estado)
{
    setidCliente(idCliente);
    setNombre(nombre);
    setApellido(apellido);
    setDni(dni); ///agregado
    setEmail(email);
    setTelefono(telefono);
    setEstado(estado);
}


int Cliente::getidCliente() {
     return _idCliente;
}

void Cliente::setidCliente(int id) {
     _idCliente = id;
}

string Cliente::getNombre(){
   return _nombre;
}
void Cliente::setNombre (string nombre){
strncpy(_nombre, nombre.c_str(), 299);
  _nombre[299] = '\0';
}

string Cliente::getApellido(){
   return _apellido;
}
void Cliente::setApellido (string apellido){
strncpy(_apellido, apellido.c_str(), 299);
  _apellido [299] = '\0';

}
string Cliente::getDni(){
   return _dni;
}
void Cliente::setDni(string dni){
  strncpy(_dni,dni.c_str(),19);
  _dni [19]= '\0';
}

string Cliente::getEmail(){
   return _email;
}
void Cliente::setEmail(string email){
strncpy(_email, email.c_str(), 299);
  _email[299] = '\0';

}

string Cliente::getTelefono(){
   return _telefono;
}
void Cliente::setTelefono (string telefono){
strncpy(_telefono, telefono.c_str(), 14);
  _telefono[14] = '\0';
}
bool Cliente::getEstado(){
   return _estado;
}
void Cliente::setEstado(bool estado){
  _estado=estado;
}
bool Cliente::getEliminado(){
     return _eliminado;
}
void Cliente::setEliminado(bool eliminado){
    _eliminado=eliminado;
}

void Cliente::cargar(){
  cout<<"Id de Cliente: ";
  cin>>_idCliente;
  cout<<"Nombre: ";
  cin>>_nombre;
  cout<<"Apellido: ";
  cin>>_apellido;
  cout<<"email: ";
  cin>>_email;
  cout<<"Telefono ";
  cin>>_telefono;
}

void Cliente::mostrar(){
  cout<<"Id de Cliente: "<<_idCliente<<endl;
  cout<<"Nombre: "<<_nombre<<endl;
  cout<<"Apellido: "<<_apellido<<endl;
  cout<<"email: "<<_email<<endl;
  cout<<"Telefono "<<_telefono<<endl;
}



