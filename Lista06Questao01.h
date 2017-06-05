#pragma once
#include "bibliotecas.h"
#include "classeArvore.h"

void Lista06Questao01(){
    Arvore<int> * arvore=new Arvore<int>;
    arvore->insere_ArvoreDeBusca(33);
    arvore->insere_ArvoreDeBusca(15);
    arvore->insere_ArvoreDeBusca(41);
    arvore->insere_ArvoreDeBusca(38);
    arvore->insere_ArvoreDeBusca(34);
    arvore->insere_ArvoreDeBusca(47);
    arvore->insere_ArvoreDeBusca(43);
    arvore->insere_ArvoreDeBusca(49);
    arvore->imprime_Pre();
    arvore->remove_ArvoreDeBusca(33);
    arvore->imprime_Pre();
}


