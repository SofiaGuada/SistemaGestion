#include <iostream>
#include "ManagerEventos.h"
#include "Fecha.h"
using namespace std;
ManagerEventos::ManagerEventos()
{
    //ctor
}

ManagerEventos::~ManagerEventos()
{
    //dtor
}
void ManagerEventos::cargarEvento(){
    int idE,idC,cant;
    string nombre;
    Fecha fechaEvento;
        bool confirmado;
        cout<<"ID EVENTO : #";
        cin>>idE;
        cout<<"ID CLIENTE: #";
        cin>>idC;
        cout<<"NOMBRE DEL EVENTO: ";
        cin>>nombre;
        cout<<"CANTIDAD DE INVITADOS: ";
        cin>>cant;
        fechaEvento.cargarFecha();
        cout<<"CONFIRMADO ? 1.SI 0.NO ";
        cin>>confirmado;

 Eventos evento (idE,idC,nombre,fechaEvento,cant,confirmado);

 if(_repo.guardar(evento)){
    cout<<"GUARDADO CORRECTAMENTE "<<endl;
 }
 else {
    cout<<"ERROR AL GUARDAR "<<endl;
 }
}
void ManagerEventos::mostrarEvento(Eventos evento){
  cout<<"ID EVENTO: #"<<evento.getIdEvento()<<endl;
  cout<<"ID CLIENTE: #" <<evento.getidCliente()<<endl;
  cout<<"NOMBRE DE EVENTO: "<<evento.getNombreEvento()<<endl;
  cout<<"CANTIDAD DE INVITADOS: "<<evento.getcantidadInvitados()<<endl;
  cout<<"CONFIRMADO: "<< (evento.getConfirmado() ? "SI ":"NO ")<<endl;
}

void ManagerEventos::listarEvento(){
    int cantidad = _repo.getCantidadRegistros();

  for (int i = 0; i < cantidad; i++)
  {
    Eventos evento = _repo.leer(i);
    mostrarEvento(evento);
    cout << "--------------------------" << endl;
  }
}
void ManagerEventos::buscarIdEvento(){
    int id;
    cout<<"INGRESAR ID EVENTO: ";
    cin>>id;
    int cantidad = _repo.getCantidadRegistros();
    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        Eventos h = _repo.leer(i);
        if (h.getIdEvento() == id) {
            cout<<"-----EVENTO ENCONTRADO-----"<<endl;
            mostrarEvento(h);
            cout<<"---------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "NO SE ENCONTRO EL EVENTO." << endl;
    }

}
void ManagerEventos::eliminar(){
      int id,pos;
   Eventos evento;
   char eliminar;

   cout<<"---- ELIMINAR EVENTO ----"<<endl;
   cout<<"INGRESE ID EVENTO: ";
   cin>>id;

    pos=_repo.buscarIDevento(id);
   if(pos==-1){
    cout<<"EL EVENTO NO EXISTE! "<<endl;
    return ;
  }
  evento= _repo.leer(pos);

  cout<<"INFORMACION DEL EVENTO "<<endl;
  cout<<endl;
  mostrarEvento(evento);

  cout<<endl;
  cout<<"QUIERE ELIMINAR? S/N ";
  cin>>eliminar;

  if (eliminar== 's' or eliminar == 'S'){
    evento.setEliminado(true);
    evento.setConfirmado(false);

  if(_repo.eliminar(pos)){
    cout<<"EL EVENTO FUE ELIMINADO"<<endl;
  }
  else {
    cout<<"OCURRIO UN ERROR AL ELIMINAR EL EVENTO "<<endl;
  }
  }
}
