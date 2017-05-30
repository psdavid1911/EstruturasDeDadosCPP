#pragma once
#include "bibliotecas.h"
#include "classeArvore.h"

void Lista06Questao01(){
    resposta();
    Arvore<int> * arvore=new Arvore<int>;
    arvore->inicializaRaiz(33);
    arvore->insere(15, 33);
    arvore->insere(41, 33);
    arvore->insere(38, 41);
    arvore->insere(47, 41);
    arvore->insere(34, 38);
    arvore->insere(43, 47);
    arvore->insere(49, 47);
    arvore->imprime_Pre(arvore->raiz);
    imprime("\n");
    arvore->imprime_Em(arvore->raiz);
    imprime("\n");
    arvore->imprime_Pos(arvore->raiz);
    imprime("\n");


    arvore->apaga(47);
    arvore->imprime_Pre(arvore->raiz);
    imprime("\n");

    arvore->estaVazia() ? imprime("Esta vazia\n") : imprime("Não esta vazia\n");

    arvore->limpa(arvore->raiz);
    arvore->imprime_Pre(arvore->raiz);
    imprime("\n");
    arvore->estaVazia() ? imprime("Esta vazia\n") : imprime("Não esta vazia\n");

    delete arvore;
    /**
     * Teste criacao da arvore
     */
    //    cout << "\n"
    //            << arvore->raiz->conteudo
    //            << " "
    //            << arvore->raiz->esq->conteudo
    //            << " "
    //            << arvore->raiz->esq->esq->conteudo
    //            << " "
    //            << arvore->raiz->esq->esq->esq->conteudo
    //            << " "
    //            << arvore->raiz->esq->dir->conteudo
    //            << "\n";
}

