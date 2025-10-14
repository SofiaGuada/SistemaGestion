#pragma once
#include "ManagerClientes.h"
#include "ManagerEventos.h"

class Menu
{
    public:
        Menu();
      void mostrar();

    protected:
        void mostrarOpciones();
        int seleccionarOpcion();
        void ejecutarOpcion(int opcion);
         ManagerClientes _managerCliente;
         ManagerEventos _managerEvento;



    private:
        int _cantidadOpciones;
};
