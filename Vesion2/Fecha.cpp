#include <iostream>
#include "Fecha.h"
using namespace std;

Fecha::Fecha()
 : _dia(0),_mes(0),_anio(0){ ///obligatorio para composicion

}

Fecha::Fecha(int dia, int mes, int anio){
   setDia(dia);
   setMes(mes);
   setAnio(anio);
}

int Fecha::getDia(){
   return _dia;
}

int Fecha::getMes(){
   return _mes;
}

int Fecha::getAnio(){
   return _anio;
}

void Fecha::setDia(int dia){
     _dia=dia;
}

void Fecha::setMes(int mes){
     _mes=mes;
}

void Fecha::setAnio(int anio){
    _anio=anio;
}
void Fecha::cargarFecha(){
    cout<<"DIA: ";
    cin>>_dia;
    cout<<"MES: ";
    cin>>_mes;
    cout<<"ANIO: ";
    cin>>_anio;
}
void Fecha::mostrarFecha(){
    cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
}
/*
std::string Fecha::toString(){
   return to_string(_dia)+"/"+to_string(_mes)+"/"+to_string(_anio);

   }
*/
