#pragma once
#include "ArchivoEvento.h"
class ManagerEventos
{
    public:
        ManagerEventos();
        virtual ~ManagerEventos();
        void cargarEvento();
        void mostrarEvento(Eventos evento);
        void listarEvento();
        void buscarIdEvento();
        void eliminar();

    protected:

    private:
        ArchivoEvento _repo;
};
