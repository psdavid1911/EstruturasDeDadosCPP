#pragma once
#include "bibliotecas.h"

void Lista01Questao04(){ // crivo de Eratóstenes
    string questao="Desenvolva um algoritmo que, determine se um determinado número N informado é\n" \
            "primo ou não. Se sim, que encontre e informe os dois primos antecessores de N e os dois\n" \
            "primos sucessores de N. O algoritmo só encerra quando for informado um número N\n" \
            "primo.\n";
    entradas(questao);
    Lista<int> lista;
    int busca;
    do{
        lista.limpa();
        int valorLido=leInteiro();
        lista.adicionaAoFinal(2);
        lista.adicionaAoFinal(3);
        lista.adicionaAoFinal(5);
        lista.adicionaAoFinal(7);
        for(int numero=2; numero < 2 * valorLido; numero++){
            if(numero % 2 == 0 || numero % 3 == 0 || numero % 5 == 0 || numero % 7 == 0){
            }else lista.adicionaAoFinal(numero);
        }
        lista.imprime();
        busca=lista.buscaBinaria(valorLido, 0, lista.tamanho);
    }while(busca == -1);
    resposta();
    if(busca > 2)cout << "Esquerda: " << lista.vetor[busca - 2] << "   " << lista.vetor[busca - 1] << endl;
    cout << "Valor: " << lista.vetor[busca] << endl;
    cout << "Direita: " << lista.vetor[busca + 1] << "   " << lista.vetor[busca + 2] << endl;
}
