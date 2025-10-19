#include <iostream>
#include  <cstring>
#include "Servicios.h"
using namespace std;

Servicios::Servicios()
{
    //ctor
}

void Servicios::setIdServicio(int idServicio){
}
void Servicios::setNombreServicio(string nombreServicio){
 strncpy(_NombreServicio, nombreServicio.c_str(), 29);
  _NombreServicio[29] = '\0';

}
void Servicios::setCosto(float costo){
}
void Servicios::setEliminado(bool _eliminado){
}

void Servicios::cargar(){

   cout<<"ID SERVICIO: ";
   cin>>_IdServicio;
   cout<<"NOMBRE DEL SERVICIO: ";
   cin>>_NombreServicio;
   cout<<"PRECIO: ";
   cin>>_Costo;

 _eliminado=false;
}
bool Servicios::guardar(){
    FILE *pArchivo = fopen("Servicios.dat", "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(this, sizeof(Servicios), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}
void Servicios::cargarServicios(){
Servicios s;
s.cargar();
  if(s.guardar()){
    cout<<"GUARDADO CORRECTAMENTE "<<endl;
  }
  else {
    cout<<"ERROR AL GUARDAR "<<endl;
  }

}

void Servicios::listarServicios() {
    FILE* pArchivo = fopen("Servicios.dat", "rb");
    if (pArchivo == nullptr) {
        return;
    }

    Servicios s;
    cout << "LISTA DE SERVICIOS DISPONIBLES "<<endl;
    cout << "------------------------------------"<<endl;
    while (fread(&s, sizeof(Servicios), 1, pArchivo) == 1) {
        if (!s.getEliminado()){
          cout << "ID: #" <<s.getIdServicio()<<endl;
          cout << "NOMBRE/TIPO: "<<s.getNombreServicio()<<endl;
          cout << "PRECIO: $"<<s.getCosto()<<endl;
          cout << "------------------------------------"<<endl;
        }
    }

    fclose(pArchivo);
}
