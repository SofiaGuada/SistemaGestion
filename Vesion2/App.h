#pragma once

class App
{
    public:
        App();
        virtual ~App();
        void run();
        void mostrarOpciones();
        int seleccionarOpcion();
        void ejecutarOpcion(int opcion);

    private:
        int _cantidadOpciones;
};
