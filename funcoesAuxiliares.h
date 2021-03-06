#pragma once

#include <unistd.h>
#include "bibliotecas.h"

void resposta(){
    cout << "----------------------------------------------------" << endl
            << "RESPOSTA" << endl
            << "----------------------------------------------------" << endl;
}

void entradas(string s){
    cout << "----------------------------------------------------" << endl
            << "TITULO DA QUESTAO" << endl
            << "----------------------------------------------------" << endl;
    cout << s << endl;
    cout << "----------------------------------------------------" << endl
            << "ENTRADAS" << endl
            << "----------------------------------------------------" << endl;
}

void entradas(){
    cout << "----------------------------------------------------" << endl
            << "ENTRADAS" << endl
            << "----------------------------------------------------" << endl;
}

template <typename T> string NumberToString(T Number){
    ostringstream ss;
    ss << Number;
    return ss.str();
}

template <typename T> T StringToNumber(const string &Text){
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}

int leInteiro(){ // 3 linhas, PQP!
    cout << "Inteiro > ";
    int valor;
    cin >> valor;
    return valor;
}

double leDouble(){
    cout << "Double > ";
    double valor;
    cin >> valor;
    return valor;
}

bool leBool(){
    cout << "Bool > ";
    bool valor;
    cin >> valor;
    return valor;
}

string leString(){
    cout << "String > ";
    string valor;
    cin >> valor;
    return valor;
}

void esperaMs(int tempoMs){
    usleep(tempoMs * 1000000);
}

void imprime(string s){
    cout << s;
}

class Texto{
public:
    string conteudo;

    Texto(string cadeia){
        conteudo=cadeia;
    }

    double pegaDouble(){

    }
};

void teste(){
    
}