#pragma once
#include "ManagerClientes.h"
#include "ManagerEventos.h"
#include "Servicios.h"
#include "Reservas.h"
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
         Servicios _servicio;
         Reservas _reservas;


    private:
        int _cantidadOpciones;
};
