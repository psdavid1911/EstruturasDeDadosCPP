#pragma once
#include "bibliotecas.h"

void Lista07Questao01(){ // INDICES DE 1 A N
    GrafoIndirecionado<int> *grafo=new GrafoIndirecionado<int>(6);

    grafo->adicionaAresta(1, 2, 10);
    grafo->adicionaAresta(1, 3, 20);
    grafo->adicionaAresta(1, 4, 11);
    grafo->adicionaAresta(2, 5, 2);
    grafo->adicionaAresta(3, 4, 4);
    grafo->adicionaAresta(3, 5, 16);
    grafo->adicionaAresta(3, 6, 6);
    grafo->adicionaAresta(4, 6, 30);
    grafo->adicionaAresta(5, 6, 10);
    grafo->imprime(4);

    ListaEncadeada<int> *resultado=grafo->buscaCaminho(1, 6);
    resultado->imprime();
}