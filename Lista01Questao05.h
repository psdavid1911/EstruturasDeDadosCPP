/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista01Questao05.h
 * Author: david
 *
 * Created on 31 de Março de 2017, 09:09
 */

#ifndef LISTA01QUESTAO05_H
#define LISTA01QUESTAO05_H

#include <cstdlib>
#include "classeLista.h"
#include "funcoesAuxiliares.h"

using namespace std;

/*
 * 
 */
int Lista01Questao05() {
    entradas();
    Lista<int> a, repetidos;
    int valorLido = leInteiro();
    int tamanhoInicial;
    while (valorLido != -1) {
        a.adiciona(valorLido);
        valorLido = leInteiro();
    }
    resposta();
    tamanhoInicial = a.tamanho;
    a.ordena();
    a.imprime();
    for (int contador = 0; contador < a.tamanho - 1; contador++)
        if (a.vetor[contador] == a.vetor[contador + 1]) {
            int valorAtual = a.vetor[contador--];
            a.remove(valorAtual);
            a.adiciona(valorAtual);
            repetidos.adiciona(valorAtual);
        }

    if (repetidos.tamanho == 0) cout << "Não tem elementos repetidos" << endl;
    else {
        cout << "Numero de elementos ÚNICOS que se repetiam: " << repetidos.tamanho << endl;
        cout << "Numero de elementos repetidos: " << tamanhoInicial - repetidos.tamanho << endl;
        cout << "Lista ordenada das repeticoes: ";
        repetidos.imprime();
    }
    a.ordena();
    cout << "Lista ordenada e sem repeticoes: ";
    a.imprime();
    int indiceDoElemento;
    indiceDoElemento = a.buscaBinaria(2, 0, a.tamanho);
    cout << "Indice do elemento 2 da busca binaria(-1 se não existir): " << indiceDoElemento << endl;
    cout << "Elemento: " << a.vetor[indiceDoElemento] << endl;
    
    return 0;
}

#endif /* LISTA01QUESTAO05_H */

