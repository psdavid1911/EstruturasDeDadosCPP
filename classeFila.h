#pragma once
#include "bibliotecas.h"

using namespace std;

template <class T> class Fila{
public:
    Lista<T> fila;

    Fila(){

    }

    /**
     * Pega o elemento que chegou primeiro
     * @return 
     */
    T proximo(){
        T elemento=fila.pega(0);
        fila.removeIndice(0);
        return elemento;
    }

    /**
     * Adiciona sempre ao fim da fila
     * @param elemento
     */
    void adiciona(T elemento){
        fila.adiciona(elemento);
    }

    int tamanho(){
        return fila.tamanho;
    }

    bool existe(T elemento){
        return fila.existe(elemento);
    }

    bool estaVazia(){
        return fila.estaVazia();
    }

    bool naoEstaVazia(){
        return !estaVazia();
    }

    void disperca(){
        fila.limpa();
    }

    void imprime(){
        fila.imprime();
    }

    void ordena(){
        fila.ordena();
    }

private:

    void remove(int indice){
        fila.removeIndice(indice);
    }
};