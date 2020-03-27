#pragma once;
#include "Tupla.hpp"
#include <string>
#include <vector>

using namespace std;

class Relacion{
    private:
        vector<string> encabezados;
        string nombre;
        vector<Tupla> objetos;
    public:
        Relacion();
        Relacion(string n, vector<string> r);
        void setEncabezados(vector<string> x);
        vector<string> getEncabezados();
        void addEncabezado(string x);
        string getEncabezado(int x);
        void setNombre(string x);
        string getNombre();
        void setObjetos(vector<Tupla> x);
        vector<Tupla> getObjetos();
        void addObjeto(Tupla x);
        Tupla getObjeto(int x);
        void getObjetosString();
};