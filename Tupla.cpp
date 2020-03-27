#include "Tupla.hpp"
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

Tupla::Tupla(){
}

Tupla::Tupla(vector<string> x){
    srand(time(0));
    id = 1000 + rand()%9999;
    atributos = x;
    atributos.insert(atributos.begin(),to_string(id));
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
