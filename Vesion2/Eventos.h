#pragma once
#include <string>
#include "Fecha.h"
///que pueden hacer en mi programa, o que puede hacer el usuario
///objetivo un reporte, cual es el importe que obtuve o cuanto gaste cual es mi ganancia

class Eventos
{
    public:
        Eventos();
        Eventos(int idEven,int idClien,std::string nombre,Fecha fechaEvento,int cant,bool confirmado);

        int getIdEvento();
        void setIdEvento(int idEvento);
        int getidCliente();
        void setidCliente(int id) ;

        std::string getNombreEvento();
        void setNombreEvento(std::string nombreEvento);
        Fecha getFechaEvento();
        void setFechaEvento(Fecha fechaEvento);

        int getcantidadInvitados();
        void setCantidad(int cantidad);
        bool getConfirmado();
        void setConfirmado(bool confirmado);
        bool getEliminado();
        void setEliminado(bool eliminado);
        void cargarEventos();

    private:
        int _idEvento;
        int _idCliente;
        char _nombreEvento[50];
        Fecha _fechaEvento;
        int _cantidadInvitados;
        bool _confirmado;
        bool _eliminado;


};


