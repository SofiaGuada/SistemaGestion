#pragma once
#include "Fecha.h"
#include <string>
class Servicios
{
    public:
        Servicios();
        int getIdServicio(){return _IdServicio;}
        void setIdServicio(int idServicio);
        std::string getNombreServicio(){return _NombreServicio;}
        void setNombreServicio(std::string nombreServicio);
        float getCosto(){return _Costo;}
        void setCosto(float costo);
        bool getEliminado(){return _eliminado;}
        void setEliminado(bool eliminado);

        void cargar();
        void cargarServicios();
        bool guardar();
        void listarServicios();

    private:
        int _IdServicio;
        char _NombreServicio[30];
        float _Costo;
        bool _eliminado;
};
