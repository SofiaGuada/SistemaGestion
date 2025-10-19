#pragma once
#include "Fecha.h"
class Reservas
{
    public:
        Reservas();
        virtual ~Reservas();
        int getIdReserva(){ return _idReserva;}
        int getIdCliente(){return _idCliente;}
        void setIdCliente(int idcliente);
        void setIdReserva(int idReserva);
        Fecha getFechaReserva();
        void setFechaReserva(Fecha fecha);
        int getcantidadInvitados();
        void setCantidadInvitados(int cantidad);


        void setTotal(float total);
        float getTotal(){return _total;}
        float getPrecioInicial(){return _precioInicial;}
        void setPrecioInicial(float precioInicial);
        ///servicios
        void setIdServicio(int idServicio);
        int getIdServicio(){return _idServicio;}

        void cargarReserva();
        void mostrarReservas(Reservas reserva);
        void listarReservas();
        void calcularPrecioInicial();
        void calcularTotalDeLaReserva();

    protected:

    private:
        int _idReserva;
        int _idServicio;
        int _idCliente;
        int _cantidadInvitados;
        float _precioInicial;
        float _total;
        Fecha _fechaReserva;
        bool _confirmado;
        bool _eliminado;
};
