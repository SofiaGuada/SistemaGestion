#include "App.h"
#include <iostream>

using namespace std;

App::App()
{
  _cantidadOpciones=9;
    //ctor
}

App::~App()
{
    //dtor
}

void App::run(){
   int opcion;

   do{
    system("cls");
    opcion=seleccionarOpcion();
    system("cls");
    ejecutarOpcion(opcion);
    system("pause");

   }while (opcion!=0);

}
void App::mostrarOpciones(){
   cout<<"-----MENU PRINCIPAL-----"<<endl;
   cout<<"1- CARGAR CLIENTE"<<endl;


   cout<<"0- SALIR "<<endl;

}
int App::seleccionarOpcion(){
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
void App::ejecutarOpcion(int opcion){
    switch(opcion){
case 1:
    break;
 case 2:
    break;
case 3:
    break;
case 0:
        cout<<"Gracias por usar mi app "<<endl;
    break;
    }
}
