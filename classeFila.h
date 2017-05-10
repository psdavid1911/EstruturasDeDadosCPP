#pragma once
#include "bibliotecas.h"

using namespace std;

template <class T> class Fila{
public:
    ListaEncadeada<T> fila=new ListaEncadeada<T>();

    Fila(){

    }

    ~Fila(){
        delete fila;
    }

    /**
     * Pega o elemento que chegou primeiro
     * @return 
     */
    T proximo(){
        T elemento=fila.pegaPrimeiro();
        fila.removePrimeiro();
        return elemento;
    }

    /**
     * Adiciona sempre ao fim da fila
     * @param elemento
     */
    void adiciona(T elemento){
        fila.adicionaAoFinal(elemento);
    }

    int tamanho(){
        return fila.tamanho;
    }

    bool existe(T elemento){
        return fila.contem(elemento);
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

    //private:
    //
    //    void remove(int indice){
    //        fila.removeIndice(indice);
    //    }
};