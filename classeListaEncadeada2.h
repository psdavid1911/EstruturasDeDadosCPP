#pragma once
#include "bibliotecas.h"

template <class T> class ListaEncadeada2{
public:
    int tamanho;

    struct No{
        T conteudo;
        No &proximo;
    } &inicio;

    ListaEncadeada2(){
        tamanho=0;
        inicio=new No;
        inicio.proximo=NULL;
    }

    void adicionaAoInicio(T conteudo){
        No &temp;
        if(tamanho == 0)inicio.conteudo=conteudo;
        else{
            &temp=new No; // INICIALIZA VARIÁVEL TEMPORÁRIA
            temp.conteudo=conteudo;
            temp.proximo=inicio;
            inicio=temp;
        }
        tamanho++;
    }
};