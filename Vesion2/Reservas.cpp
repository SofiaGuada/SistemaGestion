#include <iostream>
#include "Reservas.h"
#include "Cliente.h"
#include "Eventos.h"
#include "Servicios.h"
#include "ArchivoCliente.h"
using namespace std;

Reservas::Reservas()
{
    //ctor
}

Reservas::~Reservas()
{
    //dtor
}
void Reservas::setIdCliente(int idcliente){
     _idCliente=idcliente;
}
void Reservas::setIdServicio(int idServicio){
    _idServicio=idServicio;
}
Fecha Reservas::getFechaReserva(){
  return _fechaReserva;
}
void Reservas::setIdReserva(int idReserva){
   if(idReserva > 0 ){
    _idReserva=idReserva;
   }
}

void Reservas::setFechaReserva(Fecha fecha){
  _fechaReserva=fecha;
}
int Reservas::getcantidadInvitados(){
   return _cantidadInvitados;
}
void Reservas::setCantidadInvitados(int cantidad){
    if (cantidad>30){
        _cantidadInvitados=cantidad;
    }
}
void Reservas::setTotal(float total){
   _total=total;
}

void Reservas::cargarReserva(){
   FILE *pfile;
   pfile=fopen("Reserva.dat","ab");
   if(pfile==nullptr){
        cout<<"No se pude abrir el archivo "<<endl;
    return;
   }

   ArchivoCliente archivo;
   int cantidad = archivo.getCantidadRegistros();

   cout<<"CLIENTES DISPONIBLES: "<<endl;
   for(int i=0;i<cantidad;i++){
     Cliente cliente=archivo.leer(i);
     if(!cliente.getEliminado()){
        cout<<"ID: #"<< cliente.getidCliente()<<" - "<<cliente.getNombre()<<endl;
     }
   }
   Reservas reserva;
   int idCliente,idReserva;
   cout<<"INGRESAR ID RESERVA : ";
   cin>>idReserva;
     reserva.setIdReserva(idReserva);


   cout<<"INGRESAR ID CLIENTE QUE VA A REALIZAR LA RESERVA :";
   cin>>idCliente;

   bool existe=false;
   for(int i=0;i<cantidad;i++){
  Cliente cliente=archivo.leer(i);
      if(cliente.getidCliente() == idCliente &&!cliente.getEliminado()){
        existe=true;
        break;
      }
   }
   if(!existe){
     cout<<"EL CLIENTE NO EXISTE "<<endl;
     fclose(pfile);
     return;
   }

int agregar=0;
   reserva.setIdCliente(idCliente);

  int cantidadInvitados=0;
   cout<<"CANTIDAD DE INVITADOS: ";
   cin>>cantidadInvitados;
   reserva.setCantidadInvitados(cantidadInvitados);
   reserva.calcularPrecioInicial();

   cout<<"AGREGA SERVICIOS ? 1.SI 0.NO ";
   cin>>agregar;

   int idServicio;
   if(agregar==1){
     Servicios servis;
     servis.listarServicios();
     cout<<"QUE ID SERVICIO AGREGA: ";
     cin>>idServicio;
     reserva.setIdServicio(idServicio);
     reserva.calcularTotalDeLaReserva();
}
else {
    cout<<"NO AGREGA NINGUN SERVICIO "<<endl;
    reserva.setTotal(reserva.getPrecioInicial());
}
    Fecha fechaReserva;
   cout<<"FECHA DE RESERVA "<<endl;
   fechaReserva.cargarFecha();
   reserva.setFechaReserva(fechaReserva);

   fwrite(&reserva, sizeof(Reservas), 1, pfile);
   fclose(pfile);
   cout << " Reserva guardada correctamente "<<endl;


}
///mostrar
void Reservas::mostrarReservas(Reservas reserva){
    cout<<"ID RESERVA: "<<reserva.getIdReserva()<<endl;
    cout<<"ID CLIENTE: "<<reserva.getIdCliente()<<endl;
    cout<<"ID SERVICIO CONTRATADO: "<<reserva.getIdServicio()<<endl;
    cout<<"CANTIDAD DE INVITADOS: "<<reserva.getcantidadInvitados()<<endl;
    cout<<"FECHA DE RESERVA: ";
    reserva.getFechaReserva().mostrarFecha();
    cout<<"TOTAL DE LA RESERVA: $"<<reserva.getTotal()<<endl;
    cout<<endl;
}
void Reservas::calcularPrecioInicial() {
    if (_cantidadInvitados >= 500) _precioInicial = 250000;
    else if (_cantidadInvitados >= 200) _precioInicial = 120000;
    else if (_cantidadInvitados >= 100) _precioInicial = 90000;
    else _precioInicial = 60000;
}
//void Reservas::calcularTotalDeLaReserva(){
//
//    float total=0;
//    total = _precioInicial + servicio.getCosto();
//    setTotal(total);
//    cout<<" TOTAL: "<<total;
//    cout<<endl;
//}
void Reservas::calcularTotalDeLaReserva() {
    FILE* pfile = fopen("Servicios.dat", "rb");
    if (pfile == nullptr) {
        cout << "No se pudo abrir el archivo de servicios." << endl;
        setTotal(_precioInicial);
        return;
    }

    Servicios servicio;
    bool encontrado = false;

    while (fread(&servicio, sizeof(Servicios), 1, pfile) == 1) {
        if (servicio.getIdServicio() == _idServicio && !servicio.getEliminado()) {
            float total = _precioInicial + servicio.getCosto();
            setTotal(total);
            encontrado = true;
            break;
        }
    }

    fclose(pfile);

    if (!encontrado) {
        cout << " Servicio no encontrado. Se usará solo el precio inicial." << endl;
        setTotal(_precioInicial);
    }
}

void Reservas::listarReservas(){
    FILE *pfile;
   pfile=fopen("Reserva.dat","rb");
   if(pfile==nullptr){
        cout<<"No se pude abrir el archivo "<<endl;
    return;
   }

 Reservas reserva;
    while (fread(&reserva, sizeof(Reservas), 1, pfile) == 1) {
        mostrarReservas(reserva);
        std::cout << "--------------------------" << std::endl;
    }

    fclose(pfile);
}
