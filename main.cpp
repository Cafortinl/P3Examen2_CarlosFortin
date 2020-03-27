#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Relacion.hpp"
#include "Tupla.hpp"

using namespace std;

vector<string> s_relaciones;
vector<Relacion> relaciones;

void setRelacion(string x){
    string nombre,s_encabezados;
    vector<string> encabezados;
    int pos = 0;
    for(int i = 0;i < x.size();i++){
        if(x[i] == '/'){
            nombre = x.substr(pos, i-pos);
            pos = i+1;
            s_encabezados = x.substr(pos,x.size()-pos);
        }
    }
    pos = 0;
    for(int j = 0;j < s_encabezados.size();j++){
        if(s_encabezados[j] == ','){
            encabezados.push_back(s_encabezados.substr(pos, j - pos));
            pos = j + 1;
        }
    }
    if(s_encabezados.size() - pos != 0)
        encabezados.push_back(s_encabezados.substr(pos, s_encabezados.size() - pos));
    Relacion temp(nombre, encabezados);
    relaciones.push_back(temp);
}

void escribirRelaciones(){
    fstream rw("relaciones.txt", ios::out);
    if(!rw){
        rw.open("relaciones.txt", ios::out);
        for(int i = 0;i < s_relaciones.size();i++){
            rw << s_relaciones[i] << '/';
            for(int j = 0; j < relaciones[i].getEncabezados().size();j++){
                rw << relaciones[i].getEncabezados()[j] << ',';
            }
            rw << ';';
        }
    }else{
        for(int i = 0;i < s_relaciones.size();i++){
            rw << s_relaciones[i] << '/';
            for(int j = 0; j < relaciones[i].getEncabezados().size();j++){
                rw << relaciones[i].getEncabezados()[j] << ',';
            }
            rw << ';';
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
                setRelacion(linea.substr(pos, i-pos));
                pos = i+1;
            }
        }
        if(linea.size()-pos != 0){
            s_relaciones.push_back(linea.substr(pos, linea.size() - pos));
            setRelacion(linea.substr(pos, linea.size() - pos));
        }
    }
}

void leerRelacion(string x){
    string nombre = x + ".txt";
    fstream rr(nombre, ios::in | ios::binary);
    Relacion temp;
    if(!rr.is_open()){
        rr.open(nombre, ios::in | ios::binary);
        rr.read(reinterpret_cast<char *>(&temp), sizeof(Relacion));
        relaciones.push_back(temp);
    }else{
        rr.read(reinterpret_cast<char *>(&temp), sizeof(Relacion));
        relaciones.push_back(temp);
    }
}

void escribirRelacion(Relacion x){
    string nombre = x.getNombre() + ".cafl";
    fstream rw(nombre, ios::out | ios::binary);
    rw.write(reinterpret_cast<const char *>(&x), sizeof(Relacion));
}

void printRelacion(Relacion x){
    cout << "Nombre: " << x.getNombre() << endl;
    cout << '[';
    for(int i = 0;i < x.getEncabezados().size();i++){
        cout << x.getEncabezados()[i] << setw(3);
        if(i == x.getEncabezados().size()-1)
            cout << ']' << endl;
    }
    if(x.getObjetos().empty()){
        cout << "Esta base aun no tiene objetos" << endl;
    }else{
        for(int i = 0;i < x.getObjetos().size();i++){
            x.getObjetos()[i].toString();
        }
    }
}

void opciones(int x){
    switch(x){
        case 1:{
            string nombre, enc;
            vector<string> encabezados;
            encabezados.push_back("ID");
            char resp = 's';
            cout << "Ingrese el nombre de la relacion: ";
            cin >> nombre;
            cout << "(No es necesario escribir el atributo ID, el programa lo hace por defecto)" << endl;
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
            //escribirRelacion(temp);
            break;
        }

        case 2:{
            int pos;
            for(int i = 0;i < relaciones.size();i++){
                cout << i << ". " << relaciones[i].getNombre() << endl;
            }
            cout << "Ingrese el indice de la relacion que desea ver: ";
            cin >> pos;
            if(pos <= relaciones.size()-1){
                printRelacion(relaciones[pos]);
                cout << endl;
            }else
                cout << "El indice ingresado no es valido" << endl;
            break;
        }

        case 3:{
            int pos;
            vector<string> atributos;
            string atrib;
            for(int i = 0;i < relaciones.size();i++){
                cout << i << ". " << relaciones[i].getNombre() << endl;
            }
            cout << "Ingrese el indice de la relacion que desea ingresarle una tupla: ";
            cin >> pos;
            if(pos <= relaciones.size()-1){
                for(int i = 1;i < relaciones[pos].getEncabezados().size();i++){
                    cout << "Ingrese el atributo " << (char)34 << relaciones[pos].getEncabezados()[i] << (char)34 << ": ";
                    cin >> atrib;
                    atributos.push_back(atrib);
                }
                Tupla temp(atributos);
                relaciones[pos].addObjeto(temp);
                escribirRelacion(relaciones[pos]);
            }else
                cout << "El indice ingresado no es valido" << endl;
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
        cout << "Entro" << endl;
        leerRelaciones(rr);
    }
    if(!s_relaciones.empty()){
        for(int i = 0;i < s_relaciones.size();i++){
            //leerRelacion(s_relaciones[i]);
        }
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