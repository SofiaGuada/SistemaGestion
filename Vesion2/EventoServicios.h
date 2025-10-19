#pragma once

class EventoServicios
{
    public:
        EventoServicios();
        virtual ~EventoServicios();

        int getIdEvento(){return _idEvento;}
        void setIdEvento(int idEvento){_idEvento=idEvento;}
        int getIdServicio(){return _idServicio;}
        void setIdServicio(int idServicio){_idServicio=idServicio;}

        bool getEliminado(){return _eliminado;}
        void setEliminado(bool eliminado){_eliminado=eliminado;}

    protected:

    private:
        int _idEvento;
        int _idServicio;
        bool _eliminado;
};

