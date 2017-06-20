#pragma once
#include "bibliotecas.h"

void Lista01Questao05(){
    string questao="5. Escreva um algoritmo que receba um vetor de N elementos e verifique a existência de\n" \
            "elementos repetidos. Caso não existam elementos repetidos retorne um “Ok”. Caso\n" \
            "contrário, que remova as repetições dos elementos e que retorne o número de\n" \
            "elementos removidos. A seguir efetue uma pesquisa binária no vetor sem elementos\n" \
            "repetidos.\n";
    entradas(questao);
    Lista<int> a, repetidos;
    int valorLido=leInteiro();
    int tamanhoInicial;
    while(valorLido != -1){
        a.adicionaAoFinal(valorLido);
        valorLido=leInteiro();
    }
    resposta();
    tamanhoInicial=a.tamanho;
    a.ordena();
    a.imprime();
    for(int contador=0; contador < a.tamanho - 1; contador++)
        if(a.vetor[contador] == a.vetor[contador + 1]){
            int valorAtual=a.vetor[contador--];
            a.remove(valorAtual);
            a.adicionaAoFinal(valorAtual);
            repetidos.adicionaAoFinal(valorAtual);
        }
    if(repetidos.tamanho == 0) cout << "Não tem elementos repetidos" << endl;
    else{
        cout << "Numero de elementos ÚNICOS que se repetiam: " << repetidos.tamanho << endl;
        cout << "Numero de elementos repetidos: " << tamanhoInicial - repetidos.tamanho << endl;
        cout << "Lista ordenada das repeticoes: ";
        repetidos.imprime();
    }
    a.ordena();
    cout << "Lista ordenada e sem repeticoes: ";
    a.imprime();
    int indiceDoElemento;
    indiceDoElemento=a.buscaBinaria(2, 0, a.tamanho);
    cout << "Indice do elemento 2 da busca binaria(-1 se não existir): " << indiceDoElemento << endl;
    cout << "Elemento: " << a.vetor[indiceDoElemento] << endl;
}
