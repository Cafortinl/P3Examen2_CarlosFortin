#include "Relacion.hpp"
#include "Tupla.hpp"
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

Relacion::Relacion(){
}

Relacion::Relacion(string n, vector<string> r){
    nombre = n;
    encabezados = r;
}

void Relacion::setEncabezados(vector<string> x){
    encabezados = x;
}

vector<string> Relacion::getEncabezados(){
    return encabezados;
}

void Relacion::addEncabezado(string x){
    encabezados.push_back(x);
}

string Relacion::getEncabezado(int x){
    return encabezados[x];
}

void Relacion::setNombre(string x){
    nombre = x;
}

string Relacion::getNombre(){
    return nombre;
}

void Relacion::setObjetos(vector<Tupla> x){
    objetos = x;
} 

vector<Tupla> Relacion::getObjetos(){
    return objetos;
}

void Relacion::addObjeto(Tupla x){
    objetos.push_back(x);
}

Tupla Relacion::getObjeto(int x){
    return objetos[x];
}

void Relacion::getObjetosString(){
    for(int i = 0;i < objetos.size();i++){
        for(int j = 0;j < objetos[i].getAtributos().size();j++){
            cout <<'['<< objetos[i].getAtributos()[j] << ']';
        }
        cout << endl;
    }
}