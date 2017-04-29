#pragma once
#include "bibliotecas.h"

template <class T> class ListaEncadeada{
public:
    int tamanho;

    struct no{
        T conteudo;
        no *proximo;
    } *inicio;

    ListaEncadeada(){
        tamanho=0;
        inicio=(no*)malloc(sizeof(no));
        inicio->proximo=NULL;
    }

    void adicionaAoInicio(T conteudo){
        no *temp;
        if(tamanho == 0){
            inicio->conteudo=conteudo;
        }else{
            temp=(no*)malloc(sizeof(no)); // INICIALIZA VARIÁVEL TEMPORÁRIA
            temp->conteudo=conteudo;
            temp->proximo=inicio;
            inicio=temp;
        }
        tamanho++;
    }

    void adicionaAoFinal(T conteudo){
        no *temp, *temp2;
        if(tamanho == 0){
            inicio->conteudo=conteudo;
        }else{
            temp=(no*)malloc(sizeof(no));
            temp->conteudo=conteudo; // criei o nó
            temp->proximo=NULL; // se ele é o ultimo ele aponta pra null
            temp2=inicio; // inicializa variavel que vai percorrer a cadeia
            while(temp2->proximo != NULL) temp2=temp2->proximo; // move-se ate uma unidade antes do ultimo
            temp2->proximo=temp; // O que era null vira o novo elemento criado
        }
        tamanho++;
    }

    /**
     * É necessário que se atente para o valor2 esteja REALMENTE após o valor1
     * @param conteudo
     * @param valor1
     * @param valor2
     */
    void adicionaEntre(T conteudo, T valor1, T valor2){
        no *temp, *temp2;
        if(contem(valor1) && contem(valor2)){
            temp=(no*)malloc(sizeof(no));
            temp->conteudo=conteudo; // criei o nó
            // busca 1 - O elemento que sucede o que sera colocado ao meio
            temp2=inicio; // inicializa variavel que vai percorrer a cadeia
            while(temp2->proximo->conteudo != valor2) temp2=temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
            // continua
            temp->proximo=temp2->proximo; // armazena o proximo no novo no
            // busca 2
            temp2=inicio; // inicializa variavel que vai percorrer a cadeia
            while(temp2->proximo->conteudo != valor1) temp2=temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
            temp2->proximo->proximo=temp; // O que apontava para o proximo de 'a' agora aponta para o novo elemento criado
            tamanho++;
        }
    }

    void apagaPrimeiro(){
        no *temp;
        if(tamanho == 0); // não faz nada
        else{
            temp=inicio;
            inicio=inicio->proximo;
            free(temp);
            tamanho--;
        }
    }

    void apagaUltimo(){
        no *temp, *temp2;
        if(tamanho == 0);
        else{
            temp=inicio; // inicializa variavel que vai percorrer a cadeia
            while(temp->proximo != NULL) temp=temp->proximo; // move-se ate uma unidade antes do ultimo
            temp2=inicio; // inicializa variavel que vai percorrer a cadeia
            while(temp2->proximo->conteudo != temp->conteudo) temp2=temp2->proximo; // move-se ate a penultima unidade antes do ultimo
            free(temp); // libera ultimo
            temp2->proximo=NULL; // penultimo aponta pra nulo
            tamanho--;
        }
    }

    /**
     * Ainda nao implementado
     */
    void apagaEntre(){

    }

    /**
     * Apaga assim que pega.
     * @return 
     */
    T pega(){
        T conteudo=inicio->conteudo;
        apagaPrimeiro();
        return conteudo;
    }

    bool contem(T conteudo){
        no *temp;
        bool resultado=false;
        temp=inicio;
        while(temp->conteudo != NULL){
            if(temp->conteudo == conteudo){
                resultado=true;
                break;
            }else temp=temp->proximo;
        }
        return resultado;
    }

    void imprimeStruct(){
        no *temp;
        temp=inicio;
        while(temp != 0){ // deferente de NULL
            cout << "Char:" << temp->conteudo << "| Prox: " << temp->proximo << endl;
            temp=temp->proximo;
        }
        cout << endl;
    }


};
