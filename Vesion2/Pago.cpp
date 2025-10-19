#include <iostream>
#include <cstring>
#include "Pago.h"
using namespace std;
Pago::Pago()
{
    //ctor
}

void Pago::setIdPago(int idPago){
    if(idPago>0){
    _idPago=idPago;
    }
}
void Pago::setIdEvento(int idEvento){
    if(idEvento>0){
    _idEvento=idEvento;
}
}
void Pago::setMonto(float monto){
    _montoTotal=monto;
}
void Pago::setMetodo(string metodo){
  strncpy(_metodo, metodo.c_str(), 49);
  _metodo[49] = '\0';

}
void Pago::setPagado(bool pagado){
    _pagado=pagado;
}
void Pago::setEliminado(bool eliminado){
    _eliminado=eliminado;
}

