#include <iostream>
#include <cstring>
#include "Eventos.h"
using namespace std;

Eventos::Eventos(){
}

Eventos::Eventos(int idEven,int idClien,string nombre,Fecha fechaEvento,int cant,bool confirmado)
{
     setIdEvento(idEven);
     setidCliente(idClien);
     setNombreEvento(nombre);
     setFechaEvento(fechaEvento);
     setCantidad(cant);
     setConfirmado(confirmado);

}
int Eventos::getIdEvento(){
   return _idEvento;
}
void Eventos::setIdEvento(int idEvento){
    _idEvento=idEvento;
}
int Eventos::getidCliente() {
     return _idCliente;
}
void Eventos::setidCliente(int id) {
     _idCliente = id;
}
string Eventos::getNombreEvento(){
   return _nombreEvento;
}
void Eventos::setNombreEvento(string nombreEvento){
strncpy(_nombreEvento, nombreEvento.c_str(),49);
  _nombreEvento [49] = '\0';

}
Fecha Eventos::getFechaEvento(){
    return _fechaEvento;
}
void Eventos::setFechaEvento(Fecha fechaEvento){
    _fechaEvento=fechaEvento;
}
int Eventos::getcantidadInvitados(){
   return _cantidadInvitados;
}
void Eventos::setCantidad(int cantidad){
    if (cantidad>30){
        _cantidadInvitados=cantidad;
    }
}
bool Eventos::getConfirmado(){
   return _confirmado;
}
void Eventos::setConfirmado(bool confirmado){
   _confirmado=confirmado;
}
bool Eventos::getEliminado(){
    return _eliminado;
}
void Eventos::setEliminado(bool eliminado){
    _eliminado=eliminado;
}

void Eventos::cargarEventos(){
        cout<<"Id del Evento: ";
        cin>>_idEvento;
        cout<<"Id de Cliente: ";
        cin>>_idCliente;
        cout<<"Nombre del Evento: ";
        cin>>_nombreEvento;
        cout<<"Cantidad de Invitados: ";
        cin>>_cantidadInvitados;
        _fechaEvento.cargarFecha();

}

