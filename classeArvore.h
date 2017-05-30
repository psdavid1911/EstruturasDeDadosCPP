#pragma once

#include "bibliotecas.h"

template <typename T> struct NoArvore{
    T conteudo;
    NoArvore * esq;
    NoArvore * dir;

    NoArvore(){
        this->conteudo=0;
        this->esq=0;
        this->dir=0;
    }

    NoArvore(T conteudo){
        this->conteudo=conteudo;
        this->esq=0;
        this->dir=0;
    }

    NoArvore(T conteudo, NoArvore * esquerdo, NoArvore * direito){
        this->conteudo=conteudo;
        this->esq=esquerdo;
        this->dir=direito;
    }

    void imprime(){
        cout << conteudo << endl;
    }
};

template <typename T> struct Arvore{
    NoArvore<T> * raiz=new NoArvore<T>;

    /**
     * Cria arvore vazia
     */
    Arvore(){
    }

    void inicializaRaiz(T conteudo){
        if(raiz->conteudo == 0) raiz->conteudo=conteudo;
    }

    /**
     * 
     */
    void insere(T filho, T pai){
        NoArvore<T> * temp=pega_Pre(pai, raiz);
        if(temp->esq == 0)temp->esq=new NoArvore<T>(filho);
        else if(temp->dir == 0) temp->dir=new NoArvore<T>(filho);
    }

    NoArvore<T> * pega_Pre(T conteudo, NoArvore<T> * temp){
        NoArvore<T> * resultado;
        if(temp != 0){
            if(temp->conteudo == conteudo) return temp;
            resultado=pega_Pre(conteudo, temp->esq);
            if(resultado != 0) return resultado;
            resultado=pega_Pre(conteudo, temp->dir);
            if(resultado != 0) return resultado;
        }
        return 0;
    }

    NoArvore<T> * pega_Em(T conteudo, NoArvore<T> * temp){
        if(temp != 0){
            return pega_Pre(conteudo, temp->esq);
            if(temp->conteudo == conteudo) return temp;
            return pega_Pre(conteudo, temp->dir);
        }
    }

    NoArvore<T> * pega_Pos(T conteudo, NoArvore<T> * temp){
        NoArvore<T> * resultado;
        if(temp != 0){
            resultado=pega_Pos(conteudo, temp->esq);
            if(resultado != 0) return resultado;
            resultado=pega_Pos(conteudo, temp->dir);
            if(resultado != 0) return resultado;
            if(temp->conteudo == conteudo) return temp;
        }
        return 0;
    }

    /**
     * Necessáriamente tem que usar o pos
     * @param temp
     */
    void limpa(NoArvore<T> * temp){
        if(temp != 0){
            limpa(temp->esq);
            limpa(temp->dir);
            temp->esq=0;
            temp->dir=0;
            if(temp == raiz)raiz->conteudo=0;
            else delete temp;
        }
    }

    void apaga(T conteudo){
        bool aEsquerda=1;
        NoArvore<T> * tempPai=pegaPai_Pre(conteudo, raiz);
        if(tempPai->dir->conteudo == conteudo) aEsquerda=0;
        NoArvore<T> * tempFilho=pega_Pre(conteudo, raiz);
        limpa(tempFilho);
        if(aEsquerda) tempPai->esq=0;
        else tempPai->dir=0;
    }

    NoArvore<T> * pegaPai_Pre(T conteudo, NoArvore<T> * temp){
        NoArvore<T> * resultado=temp;
        if(temp != 0){
            if(temp->esq != 0 && temp->esq->conteudo == conteudo || temp->dir != 0 && temp->dir->conteudo == conteudo) return temp;
            resultado=pegaPai_Pre(conteudo, temp->esq);
            if(resultado != 0) return resultado;
            resultado=pegaPai_Pre(conteudo, temp->dir);
            if(resultado != 0) return resultado;
        }
        return 0;
    }

    bool estaVazia(){
        return raiz->conteudo == 0;
    }

    void imprime_Pre(NoArvore<T> * temp){
        if(temp != 0){
            cout << temp->conteudo << ", ";
            imprime_Pre(temp->esq);
            imprime_Pre(temp->dir);
        }
    }

    void imprime_Em(NoArvore<T> * temp){
        if(temp != 0){
            imprime_Em(temp->esq);
            cout << temp->conteudo << ", ";
            imprime_Em(temp->dir);
        }
    }

    void imprime_Pos(NoArvore<T> * temp){
        if(temp != 0){
            imprime_Pos(temp->esq);
            imprime_Pos(temp->dir);
            cout << temp->conteudo << ", ";
        }
    }

};