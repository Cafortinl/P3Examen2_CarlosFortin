#pragma once
#include <string>
#include <vector>

using namespace std;

class Tupla{
    private:
        int id;
        vector<string> atributos;
    public:
        Tupla();
        Tupla(string x);
        void setID(int x);
        int getID();
        void setAtributos(vector<string> x);
        vector<string> getAtributos();
        void addAtributo(string x);
        void getAtributo(int x);
        void writeAtributos(string x);
};