#include <iostream>
#include <fstream>
#include <vector>
#include "Relacion.hpp"
#include "Tupla.hpp"

using namespace std;

vector<string> s_relaciones;
vector<Relacion> relaciones;

void leerRelaciones(fstream &r){
    string linea;
    while(r >> linea){
        int pos = 0;
        for(int i = 0;i < linea.size();i++){
            if(linea[i] == ';'){
                s_relaciones.push_back(linea.substr(pos, i-pos));
                pos = i+1;
            }
        }
        if(linea.size()-pos != 0)
            s_relaciones.push_back(linea.substr(pos, linea.size() - pos));
    }
}

void escribirRelacion(Relacion x){

}

void opciones(int x){
    switch(x){
        case 1:{
            break;
        }

        case 2:{
            break;
        }

        case 3:{
            break;
        }

        case 0:{
            break;
        }

        default:{
            cout << "La opcion ingresada no es valida" << endl;
            break;
        }
    }
    cout << endl;
}

void mostrarMenu(){
    cout << "---------Menu----------" << endl;
    cout << "1. Crear relacion" << endl;
    cout << "2. Ver relaciones" << endl;
    cout << "3. Insertar tupla" << endl;
    cout << "0. Salir" << endl;
    cout << "Opcion ingresada: ";
}

int main(){
    fstream rr("relaciones.txt", ios::in);
    if(!rr){
        cout << "El archivo no existe" << endl;
    }else{
        leerRelaciones(rr);
    }
    int opcion = 0;
    do{
        mostrarMenu();
        cin >> opcion;
        cout << endl;
    }while(opcion != 0);
    cout << "Fin del programa" << endl;
    return 0;
}