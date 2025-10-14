#pragma once
#include <string>

class Fecha
{
    public:
        Fecha();
        Fecha(int dia, int mes, int anio);

        int getDia();
        void setDia(int dia);
        int getMes();
        void setMes(int mes);
        int getAnio();
        void setAnio(int anio);

        void cargarFecha();
        void mostrarFecha();

        std::string toString(); ///DD/MM/YY

    protected:

    private:
        int _dia,_mes,_anio;
};


