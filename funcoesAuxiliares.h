/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcoesAuxiliares.h
 * Author: david
 *
 * Created on 30 de Março de 2017, 21:48
 */

#ifndef FUNCOESAUXILIARES_H
#define FUNCOESAUXILIARES_H

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

using namespace std;

void resposta() {
    cout << "----------------------------------------------------" << endl
            << "RESPOSTA" << endl
            << "----------------------------------------------------" << endl;
}

void entradas(string s) {
    cout << "----------------------------------------------------" << endl
            << "TITULO DA QUESTAO" << endl
            << "----------------------------------------------------" << endl;
    cout << s << endl;
    cout << "----------------------------------------------------" << endl
            << "ENTRADAS" << endl
            << "----------------------------------------------------" << endl;
}

void entradas() {
    cout << "----------------------------------------------------" << endl
            << "ENTRADAS" << endl
            << "----------------------------------------------------" << endl;
}

template <typename T> string NumberToString(T Number) {
    ostringstream ss;
    ss << Number;
    return ss.str();
}

template <typename T> T StringToNumber(const string &Text) {
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}

int leInteiro() { // 3 linhas, PQP!
    cout << "Entrada > ";
    int valor;
    cin >> valor;
    return valor;
}

double leDouble() {
    cout << "Entrada > ";
    double valor;
    cin >> valor;
    return valor;
}

bool leBool(){
    cout << "Entrada > ";
    bool valor;
    cin >> valor;
    return valor;
}

string leString(){
    cout << "Entrada > ";
    string valor;
    cin >> valor;
    return valor;
}

void imprime(string s) {
    cout << s;
}

class Inteiro {
public:
    int valor;

    Inteiro() {

    }

    Inteiro(int v) {
        valor = v;
    }

    string paraString() {
        return NumberToString<int>(valor);
    }
};

#endif /* FUNCOESAUXILIARES_H */

