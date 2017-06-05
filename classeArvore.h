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

    ~NoArvore(){
        delete this;
    }

    void imprime(){
        cout << conteudo << endl;
    }
};

template <typename T> struct Arvore{
    NoArvore<T> * raiz=new NoArvore<T>;


    Fila<NoArvore<T> *> * listaEnderecos=new Fila<NoArvore<T> *>;

    /**
     * Cria arvore vazia
     */
    Arvore(){
    }

    ~Arvore(){

    }

    void inicializaRaiz(T conteudo){
        if(raiz->conteudo == 0) raiz->conteudo=conteudo;
    }

    void insere_ArvoreDeBusca(T conteudo){
        if(estaVazia()) raiz->conteudo=conteudo;
        else insere(new NoArvore<T>(conteudo), raiz, raiz, true);
    }

    void insere_ArvoreDeBusca(NoArvore<T> * no){
        insere(no, raiz, raiz, true);
    }

    /**
     * Tentar inserir numa posicao que não existe consiste em falha
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
        NoArvore<T> * resultado;
        if(temp != 0){
            resultado=pega_Pos(conteudo, temp->esq);
            if(resultado != 0) return resultado;
            if(temp->conteudo == conteudo) return temp;
            resultado=pega_Pos(conteudo, temp->dir);
            if(resultado != 0) return resultado;
        }
        return 0;
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

    NoArvore<T> * pegaPai_Pre(T conteudo, NoArvore<T> * atual, NoArvore<T> * pai){
        NoArvore<T> * resultado;
        if(atual != 0){
            if(atual->conteudo == conteudo) return pai;
            //
            resultado=pegaPai_Pre(conteudo, atual->esq, atual);
            if(resultado != 0) return resultado;
            //
            resultado=pegaPai_Pre(conteudo, atual->dir, atual);
            if(resultado != 0) return resultado;
        }
        return 0;
    }

    NoArvore<T> * pegaPai_Em(T conteudo, NoArvore<T> * atual, NoArvore<T> * pai){
        NoArvore<T> * resultado;
        if(atual != 0){
            resultado=pegaPai_Em(conteudo, atual->esq, atual);
            if(resultado != 0) return resultado;
            //
            if(atual->conteudo == conteudo) return pai;
            //
            resultado=pegaPai_Em(conteudo, atual->dir, atual);
            if(resultado != 0) return resultado;
        }
        return 0;
    }

    NoArvore<T> * pegaPai_Pos(T conteudo, NoArvore<T> * atual, NoArvore<T> * pai){
        NoArvore<T> * resultado;
        if(atual != 0){
            resultado=pegaPai_Pos(conteudo, atual->esq, atual);
            if(resultado != 0) return resultado;
            //
            resultado=pegaPai_Pos(conteudo, atual->dir, atual);
            if(resultado != 0) return resultado;
            //
            if(atual->conteudo == conteudo) return pai;
        }
        return 0;
    }

    void limpa(){
        listaEnderecos->disperca();
        preencheListaDeLimpeza(raiz);
        listaEnderecos->imprime();
        while(listaEnderecos->naoEstaVazia()){
            NoArvore<T> * no=listaEnderecos->desenfileira();
            cout << no->conteudo << "\n";
            delete no;
        }
        raiz=new NoArvore<T>{};
        raiz->imprime();
    }

    /**
     * Necessáriamente tem que usar o pos
     * @param temp
     */
    void preencheListaDeLimpeza(NoArvore<T> * atual){
        if(atual == 0) return;
        preencheListaDeLimpeza(atual->esq);
        preencheListaDeLimpeza(atual->dir);
        listaEnderecos->enfileira(atual);
    }

    void apaga(T conteudo, NoArvore<T> * raiz){
        bool aEsquerda=1;
        NoArvore<T> * tempPai=pegaPai_Pre(conteudo, raiz, raiz);
        if(tempPai->dir->conteudo == conteudo) aEsquerda=0;
        NoArvore<T> * tempFilho=pega_Pre(conteudo, raiz);
        preencheListaDeLimpeza(tempFilho);
        if(aEsquerda) tempPai->esq=0;
        else tempPai->dir=0;
    }

    bool estaVazia(){
        return raiz->conteudo == 0;
    }

    void imprime_Pre(){
        ListaEncadeada<T> * lista=new ListaEncadeada<T>;
        lista_Pre(raiz, lista);
        imprime("\n\n");
        lista->imprime();
    }

    void imprime_Em(){
        ListaEncadeada<T> * lista=new ListaEncadeada<T>;
        lista_Em(raiz);
        lista->imprime();
    }

    void imprime_Pos(){
        ListaEncadeada<T> * lista=new ListaEncadeada<T>;
        lista_Pos(raiz);
        lista->imprime();
    }

    ListaEncadeada<T> * lista_Pre(NoArvore<T> * raiz){
        ListaEncadeada<T> * lista=new ListaEncadeada<T>;
        lista_Pre(raiz, lista);
        return lista;
    }

    ListaEncadeada<T> * lista_Em(NoArvore<T> * raiz){
        ListaEncadeada<T> * lista=new ListaEncadeada<T>;
        lista_Em(raiz, lista);
        return lista;
    }

    ListaEncadeada<T> * lista_Pos(NoArvore<T> * raiz){
        ListaEncadeada<T> * lista=new ListaEncadeada<T>;
        lista_Pos(raiz, lista);
        return lista;
    }

    void remove_ArvoreDeBusca(T conteudo){
        NoArvore<T> * ponteiroPai=0, * ponteiroFilho=0;
        if(raiz->conteudo == conteudo){
            ponteiroFilho=raiz;
            raiz=new NoArvore<T>;
        }else{
            ponteiroPai=pegaPai_Pre(conteudo, raiz, raiz);
            ponteiroFilho=pega_Pre(conteudo, ponteiroPai);
            if(ponteiroFilho == 0 || ponteiroPai == 0) return;
            ponteiroPai->esq == ponteiroFilho ? ponteiroPai->esq=0 : ponteiroPai->dir=0;
        }
        ListaEncadeada<T> * lista=lista_Pre(ponteiroFilho);
        for(int i=1; i < lista->tamanho; i++)this->insere_ArvoreDeBusca(lista->pega(i)); // pula a primeira entrada e insere o resto
        apaga(ponteiroFilho->conteudo, ponteiroFilho);
    }

private:

    void insere(NoArvore<T> * no, NoArvore<T> * temp, NoArvore<T> * tempAnterior, bool esquerdo){
        if(temp == 0) esquerdo ? tempAnterior->esq=no : tempAnterior->dir=no;
        else no->conteudo < temp->conteudo ? insere(no, temp->esq, temp, true) : insere(no, temp->dir, temp, false);
    }

    void lista_Pre(NoArvore<T> * temp, ListaEncadeada<T> * lista){
        if(temp != 0){
            lista->adicionaAoFinal(temp->conteudo);
            //printf("Ponteiro: %10p Conteudo: %5i Esquerda: %10p Direita: %10p \n", temp, temp->conteudo, temp->esq, temp->dir );
            lista_Pre(temp->esq, lista);
            lista_Pre(temp->dir, lista);
        }
    }

    void lista_Em(NoArvore<T> * temp, ListaEncadeada<T> * lista){
        if(temp != 0){
            lista_Em(temp->esq, lista);
            lista->adicionaAoFinal(temp->conteudo);
            //printf("Ponteiro: %10p Conteudo: %5i Esquerda: %10p Direita: %10p \n", temp, temp->conteudo, temp->esq, temp->dir );
            lista_Em(temp->dir, lista);
        }
    }

    void lista_Pos(NoArvore<T> * temp, ListaEncadeada<T> * lista){
        if(temp != 0){
            lista_Pos(temp->esq);
            lista_Pos(temp->dir);
            //printf("Ponteiro: %10p Conteudo: %5i Esquerda: %10p Direita: %10p \n", temp, temp->conteudo, temp->esq, temp->dir );
            lista->adicionaAoFinal(temp->conteudo);
        }
    }
};