#pragma once

#include "bibliotecas.h"

void Lista01Questao01(){
    Lista<int> *valores=new Lista<int>, *pares=new Lista<int>, *impares=new Lista<int>, *imparMaiorCinquenta=new Lista<int>;
    int valorLido=leInteiro();
    while(valores->tamanho < 100 && valorLido != -1){
        if(valorLido < 256) valores->adicionaAoFinal(valorLido);
        valorLido=leInteiro();
    }
    valores->imprime();
    valores->ordena();
    valores->imprime();
    valores->inverte();
    valores->imprime();
    for(int contador=0; contador < valores->tamanho; contador++){
        int valorAtual=valores->vetor[contador];
        if(valorAtual % 2 == 0 && valorAtual > 1) pares->adicionaAoFinal(valorAtual);
        else impares->adicionaAoFinal(valorAtual);
    }
    cout << "Pares: " << pares->tamanho << "\nImpares: " << impares->tamanho << endl;
    for(int contador=0; contador < impares->tamanho; contador++){
        int valorAtual=impares->vetor[contador];
        if(valorAtual > 50)
            imparMaiorCinquenta->adicionaAoFinal(valorAtual);
    }
    int soma=0;
    for(int contador=0; contador < imparMaiorCinquenta->tamanho; contador++)
        soma+=imparMaiorCinquenta->vetor[contador];
    cout << "(Indeterminado inexistindo {x| x impar e x>50}) Media: " << (float)soma / imparMaiorCinquenta->tamanho << endl;
}


