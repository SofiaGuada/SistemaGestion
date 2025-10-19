#pragma once
#include "Fecha.h"
class Pago
{
    public:
        Pago();
   int getIdPago(){return _idPago;}
   int getIdEvento(){return _idEvento;}
   int getIdCliente(){return _idCliente;}
   Fecha getFecha(){return _fechaPago;}
   float getMonto(){return _montoTotal;}
   std::string getMetodo(){return _metodo;}
   bool getPagado(){return _pagado;}
   bool getEliminado(){return _eliminado;}

        void setIdPago(int idPago);
        void setIdEvento(int idEvento);
        void setMonto(float monto);
        void setMetodo(std::string metodo);
        void setPagado(bool pagado);
        void setEliminado(bool eliminado);

        void cargar();


    protected:

    private:
       int _idPago;
       int _idEvento;
       int _idCliente;
       Fecha _fechaPago;
       float _montoTotal;
       char _metodo[50];
       bool _pagado;
       bool _eliminado;
};


