#include <iostream>
#include "Menu.h"
using namespace std;
Menu::Menu()
{
  _cantidadOpciones=6;
}

void Menu::mostrar(){
   int opcion;

   do{
    system("cls");
    opcion=seleccionarOpcion();
    system("cls");
    ejecutarOpcion(opcion);
    system("pause");

   }while (opcion!=0);

}
void Menu::mostrarOpciones(){
   cout<<"-----MENU CLIENTES-----"<<endl;
   cout<<"1- CARGAR CLIENTE"<<endl;
   cout<<"2- MOSTRAR CLIENTE "<<endl;
   cout<<"3- BUSCAR CLIENTE "<<endl;
   cout<<"4- CARGAR EVENTO "<<endl;
   cout<<"5- MOSTRAR EVENTO "<<endl;
   cout<<"6- BUSCAR EVENTO "<<endl;

   cout<<"0- SALIR "<<endl;

}
int Menu::seleccionarOpcion(){
    int opcion;
   mostrarOpciones();
   cout<<"-----------------"<<endl;
   cout<<"Opcion: ";
   cin>>opcion;

   while(opcion<0|| opcion>_cantidadOpciones){
    cout<<"Opcion Incorrecta...."<<endl;
       cout<<"Opcion: ";
       cin>>opcion;

   }
   return opcion;
}
void Menu::ejecutarOpcion(int opcion){
    switch(opcion){
case 1:
    _managerCliente.CargarCliente();
    break;
 case 2:
     _managerCliente.ListarClientes();
    break;
case 3:
    _managerCliente.buscarClientes();
    break;
case 4:
    _managerEvento.cargarEvento();
    break;
case 5:
    _managerEvento.listarEvento();
    break;
case 6:
    _managerEvento.buscarIdEvento();
    break;


case 0:
    cout<<"Gracias por usar mi app "<<endl;
    break;

    }
}
