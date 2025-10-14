#include <iostream>
#include "ManagerClientes.h"
using namespace std;
ManagerClientes::ManagerClientes()
{
    //ctor
}

ManagerClientes::~ManagerClientes()
{
    //dtor
}
void ManagerClientes::CargarCliente(){
        int idClientes;
        string nombre,apellido,dni,email,telefono;
        bool estado;

  idClientes = _repo.getNuevoID();
  cout << "ID CLIENTE: #" << idClientes << endl;
  cout <<"NOMBRE: ";
  cin>>nombre;
  cout<<"APELLIDO: ";
  cin>>apellido;
  cout<<"DNI: ";
  cin>>dni;
  cout<<"EMAIL: ";
  cin>>email;
  cout<<"TELEFONO / CELULAR: ";
  cin>>telefono;
  cout<<"ACTIVO 1-SI 0-NO: ";
  cin>>estado;

  Cliente cliente(idClientes,nombre,apellido,dni,email,telefono,estado);
  if(_repo.guardar(cliente)){
    cout<<"CLIENTE GUARDADO CORRECTAMENTE "<<endl;
  }
  else {
    cout<<"ERROR AL GUARDAR AL CLIENTE "<<endl;
  }

}
void ManagerClientes::mostrarClientes(Cliente cliente){
  cout<<"ID CLIENTE: #" <<cliente.getidCliente()<<endl;
  cout<<"NOMBRE: "<<cliente.getNombre()<<endl;
  cout<<"APELLIDO: "<<cliente.getApellido()<<endl;
  cout<<"DNI: "<<cliente.getDni()<<endl;
  cout<<"EMAIL: "<<cliente.getEmail()<<endl;
  cout<<"TELEFONO / CELULAR: "<<cliente.getTelefono()<<endl;
  cout<<"ESTADO: "<< (cliente.getEstado() ? "DISPONIBLE ":"NO DISPONIBLE ")<<endl;

}

void ManagerClientes::ListarClientes(){
int cantidad = _repo.getCantidadRegistros();

  for (int i = 0; i < cantidad; i++)
  {
    Cliente cliente = _repo.leer(i);
    mostrarClientes(cliente);
    cout << "--------------------------" << endl;
  }
}
void ManagerClientes::buscarClientes(){
    int id;
    cout<<"INGRESAR ID DE CLIENTE: ";
    cin>>id;
    int cantidad = _repo.getCantidadRegistros();
    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        Cliente h = _repo.leer(i);
        if (h.getidCliente() == id) {
            cout<<"-----CLIENTE ENCONTRADO-----"<<endl;
            mostrarClientes(h);
            cout<<"---------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "NO SE ENCONTRO AL CLIENTE." << endl;
    }
}
void ManagerClientes::eliminarClientes(){
  int id,pos;
   Cliente cliente;
   char eliminar;

   cout<<"---- ELIMINAR CLIENTE ----"<<endl;
   cout<<"INGRESE ID DE CLIENTE: ";
   cin>>id;

    pos=_repo.buscarIDcliente(id);
   if(pos==-1){
    cout<<"EL CLIENTE NO EXISTE! "<<endl;
    return ;
  }
  cliente= _repo.leer(pos);

  cout<<"INFORMACION DEL CLIENTE "<<endl;
  cout<<endl;
  mostrarClientes(cliente);

  cout<<endl;
  cout<<"QUIERE ELIMINAR? S/N ";
  cin>>eliminar;

  if (eliminar== 's' or eliminar == 'S'){
    cliente.setEliminado(true);
    cliente.setEstado(false);

  if(_repo.eliminar(pos)){
    cout<<"EL CLIENTE FUE ELIMINADO"<<endl;
  }
  else {
    cout<<"OCURRIO UN ERROR AL ELIMINAR AL CLIENTE "<<endl;
  }
  }
}

