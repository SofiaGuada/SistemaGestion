#pragma once
#include <string>
#include "Eventos.h"
class ArchivoEvento
{
    public:
        ArchivoEvento(std::string nombreArchivo="Eventos.dat");
        virtual ~ArchivoEvento();
        bool guardar (Eventos registro);
        bool guardar (int pos, Eventos registro);
        int buscarIDevento(int id);
        Eventos leer(int pos);
        int leerTodos(Eventos evento[],int cantidad);
        int getCantidadRegistros();

        bool eliminar(int pos);

    protected:

    private:
        std::string _nombreArchivo;
};
