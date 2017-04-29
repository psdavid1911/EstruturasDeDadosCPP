#pragma once
#include "bibliotecas.h"

void Lista01Questao03(){
    string questao="Leia um vetor A e um vetor B, ambos com N elementos e que intercale estes vetores A e \n" \
            "B, formando um outro vetor C da seguinte forma. A seguir efetue uma pesquisa\n" \
            "seqüencial no vetor C.\n" \
            "C[1] <- A[1]\n" \
            "C[2] <- B[1]\n" \
            "C[3] <- A[2]\n" \
            "C[4] <- B[2]\n";
    entradas(questao);
    Lista<int> a, b, c;
    int valorLido=leInteiro();
    while(valorLido != -1){
        a.adiciona(valorLido);
        valorLido=leInteiro();
    }
    valorLido=leInteiro();
    while(valorLido != -1){
        b.adiciona(valorLido);
        valorLido=leInteiro();
    }
    resposta();
    int contador1=0, contador2=0;
    while(true){
        if(contador1 < a.tamanho)c.adiciona(a.vetor[contador1++]);
        if(contador2 < b.tamanho)c.adiciona(b.vetor[contador2++]);
        if(contador1 >= a.tamanho && contador2 >= b.tamanho) break;
    }
    c.imprime();
}
