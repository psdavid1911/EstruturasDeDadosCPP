/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista01Questao03.h
 * Author: david
 *
 * Created on 31 de Março de 2017, 09:06
 */

#ifndef LISTA01QUESTAO03_H
#define LISTA01QUESTAO03_H

#include <cstdlib>
#include "classeLista.h"
#include "funcoesAuxiliares.h"


using namespace std;

/*
 * 
 */
int Lista01Questao03() {
    entradas();
    Lista<int> a, b, c;
    int valorLido = leInteiro();
    while (valorLido != -1) {
        a.adiciona(valorLido);
        valorLido = leInteiro();
    }
    valorLido = leInteiro();
    while (valorLido != -1) {
        b.adiciona(valorLido);
        valorLido = leInteiro();
    }
    resposta();
    int contador1=0, contador2=0;
    while(true){
        if(contador1 < a.tamanho)c.adiciona(a.vetor[contador1++]);
        if(contador2 < b.tamanho)c.adiciona(b.vetor[contador2++]);
        if(contador1 >= a.tamanho && contador2 >= b.tamanho) break;
    }
    c.imprime();
    return 0;
}

#endif /* LISTA01QUESTAO03_H */

