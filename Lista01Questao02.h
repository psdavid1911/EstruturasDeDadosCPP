#pragma once
#include "bibliotecas.h"

void Lista01Questao02(){
    string questao="2.Leia um vetor X de N elementos e que:\n" \
            "- Crie outro vetor Y contendo os elementos de X que estão na faixa entre 10 e 40;\n" \
            "- Crie outro vetor W contendo os números que estão nas POSIÇÕES pares;\n" \
            "- Pesquise a existência de um determinado elemento Z no vetor X;\n" \
            "- Escreva o menor e maior elemento do vetor X.\n";
    entradas(questao);
    Lista<int> x, y, w;
    int valorLido=leInteiro();
    while(valorLido != -1){
        x.adiciona(valorLido);
        if(valorLido >= 10 && valorLido <= 40) y.adiciona(valorLido);
        if(x.tamanho % 2 != 0) w.adiciona(valorLido);
        valorLido=leInteiro();
    }
    resposta();
    cout << "X: ";
    x.imprime();
    cout << "Y: ";
    y.imprime();
    cout << "W: ";
    w.imprime();
    cout << "\nIndice do elemento Z: \n";
    int elementoBuscado=leInteiro();
    string existencia=x.existe(elementoBuscado) ? "SIM" : "NÃO";
    cout << "Elemento " << elementoBuscado << " existe em x (INDET. SE POS. N EXISTE) ? " << existencia << endl;
    cout << "Maior: " << x.maior() << " menor: " << x.menor() << endl;
}


