#include "Tupla.hpp"
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

Tupla::Tupla(){
}

Tupla::Tupla(vector<string> x){
    srand(time(0));
    id = 1000 + rand()%9999;
    atributos = x;
    atributos.insert(atributos.begin(),to_string(id));
}

Tupla::Tupla(string x){
    int pos = 0;
    for(int i = 0;i < x.size();i++){
        if(x[i] == ','){
            atributos.push_back(x.substr(pos, i - pos));;
            pos = i + 1;
        }
    }
    if(x.size() - pos != 0){
        atributos.push_back(x.substr(pos, x.size() - pos));
    }
    id = stoi(atributos[0]);
}

void Tupla::setID(int x){
    id = x;
}

int Tupla::getID(){
    return id;
}

void Tupla::setAtributos(vector<string> x){
    atributos = x;
}

vector<string> Tupla::getAtributos(){
    return atributos;
}

void Tupla::addAtributo(string x){
    atributos.push_back(x);
}

string Tupla::getAtributo(int x){
    return atributos[x];
}

string Tupla::toString(){
    string salida = "";
    if(atributos.empty()){
        salida = "null";
    }else{
        for(int i = 0;i < atributos.size();i++){
            salida += atributos[i];
            salida += ',';
        }
    }
    return salida;
}