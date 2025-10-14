#pragma once
#include "ArchivoCliente.h"
class ManagerClientes
{
    public:
        ManagerClientes();
        virtual ~ManagerClientes();
        void CargarCliente();
        void ListarClientes();
        void buscarClientes();
        void eliminarClientes();
        void mostrarClientes(Cliente cliente);


    protected:

    private:
        ArchivoCliente _repo;
};
