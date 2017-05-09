#pragma once
#include "bibliotecas.h"

class Decimal{
public:
    double valor;

    Decimal(){
        valor=0;
    }

    Decimal(double v){
        valor=v;
    }

    /**
     * Atribuicao pelo tipo primitivo
     */
    void operator=(double outroValor){
        valor=outroValor;
    }

    string paraTexto(){
        return NumberToString<double>(valor);
    }
};

