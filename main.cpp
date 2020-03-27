#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Relacion.hpp"
#include "Tupla.hpp"

using namespace std;

vector<string> s_relaciones;
vector<Relacion> relaciones;

void escribirRelaciones(){
    fstream rw("relaciones.txt", ios::out);
    if(!rw){
        rw.open("relaciones.txt", ios::out);
        for(int i = 0;i < s_relaciones.size();i++){
            rw << s_relaciones[i] << ';';
        }
    }else{
        for(int i = 0;i < s_relaciones.size();i++){
            rw << s_relaciones[i] << ';';
        }
    }
}

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
    string nombre = x.getNombre() + ".cafl";
    fstream rr(nombre, ios::out | ios::binary);
    rr.write(reinterpret_cast<const char *>(&x), sizeof(x));
}

void printRelacion(Relacion x){
    cout << "Nombre: " << x.getNombre() << endl;
    for(int i = 0;i < x.getEncabezados().size();i++){
        if(i == 0)
            cout << "ID" << setw(3);
        cout << x.getEncabezados()[i] << setw(3);
        if(i == x.getEncabezados().size()-1)
            cout << endl;
    }
    if(x.getObjetos().empty()){
        cout << "Esta base aun no tiene objetos" << endl;
    }else{
        //for(int i = )
    }
}

void opciones(int x){
    switch(x){
        case 1:{
            string nombre, enc;
            vector<string> encabezados;
            char resp = 's';
            cout << "Ingrese el nombre de la relacion: ";
            cin >> nombre;
            while(resp != 27){
                cout << "Ingrese el nombre del encabezado: ";
                cin >> enc;
                encabezados.push_back(enc);
                cout << "Ingrese cualquier tecla para ingresar otro encabezado, ESC para salir," << endl << "despues presione enter: ";
                cin >> resp;
            }
            s_relaciones.push_back(nombre);
            Relacion temp(nombre, encabezados);
            relaciones.push_back(temp);
            escribirRelaciones();
            escribirRelacion(temp);
            break;
        }

        case 2:{
            int pos;
            for(int i = 0;i < relaciones.size();i++){
                cout << i << ". " << relaciones[i].getNombre() << endl;
            }
            cout << "Ingrese el indice de la relacion que desea ver: ";
            cin >> pos;
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
        opciones(opcion);
    }while(opcion != 0);
    cout << "Fin del programa" << endl;
    return 0;
}