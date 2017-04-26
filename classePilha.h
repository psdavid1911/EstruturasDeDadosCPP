#ifndef CLASSEPILHA_H
#define CLASSEPILHA_H

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include "classeLista.h"

using namespace std;

template <class T> class Pilha{
public:
    Lista<T> pilha;

    Pilha(){
    }

    void empilha(T conteudo){
        pilha.adiciona(conteudo);
    }

    T desempilha(){
        T elemento=pilha.pega(pilha.tamanho - 1);
        pilha.removeIndice(pilha.tamanho - 1);
        return elemento;
    }

    int tamanho(){
        return pilha.tamanho;
    }

    int ultimoIndice(){
        return(pilha.tamanho - 1);
    }

    bool estaVazia(){
        return pilha.tamanho == 0;
    }

    bool naoEstaVazia(){
        return !estaVazia();
    }

    T pega(int i){
        return pilha.pega(i);
    }

};

#endif
