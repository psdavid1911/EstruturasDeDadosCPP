#pragma once
#include "bibliotecas.h"

class Inteiro{
public:
    int valor;

    Inteiro(){
        valor=0;
    }

    Inteiro(int v){
        valor=v;
    }

    /**
     * Usa o operador para atribuir valor
     */
    void operator=(int right){
        this->valor=right;
    }

    string paraString(){
        return NumberToString<int>(valor);
    }
};