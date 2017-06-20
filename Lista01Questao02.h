#pragma once
#include "bibliotecas.h"

void Lista01Questao02(){
    Lista<int> *x=new Lista<int>, *y=new Lista<int>, *w=new Lista<int>;
    int valorLido=leInteiro();
    while(valorLido != -1){
        x->adicionaAoFinal(valorLido);
        if(valorLido >= 10 && valorLido <= 40) y->adicionaAoFinal(valorLido);
        if(x->tamanho % 2 != 0) w->adicionaAoFinal(valorLido);
        valorLido=leInteiro();
    }
    cout << "X: ";
    x->imprime();
    cout << "Y: ";
    y->imprime();
    cout << "W: ";
    w->imprime();
    cout << "\nIndice do elemento Z: \n";
    int elementoBuscado=leInteiro();
    string existencia=x->contem(elementoBuscado) ? "SIM" : "NÃO";
    cout << "(Indeterminado caso inexista) Elemento " << elementoBuscado << " existe em x  ? " << existencia << endl;
    cout << "Maior: " << x->maior() << " menor: " << x->menor() << endl;
}


