#ifndef CLASSELISTAENCADEADA_H
#define CLASSELISTAENCADEADA_H

#include "bibliotecas.h"

template <class T> class ListaEncadeada {
public:

    int tamanho;

    struct box {
        char conteudo; // removido o acento
        box *proximo; // removido o acento
    } *inicio, *temp, *temp2;

    ListaEncadeada() {
        tamanho = 0;
        inicio = (box*) malloc(sizeof (box));
        //inicio = (box*) new box;
        inicio->proximo = NULL; // PODE SER 0 TBM
    }

    void adicionaAoInicio(char conteudo) {
        if (tamanho == 0) {
            inicio->conteudo = conteudo;
        } else {
            temp = (box*) malloc(sizeof (box)); // INICIALIZA VARIÁVEL TEMPORÁRIA
            temp->conteudo = conteudo;
            temp->proximo = inicio;
            inicio = temp;
        }
        tamanho++;
    }

    void adicionaAoFinal(char conteudo) {
        if (tamanho == 0) {
            inicio->conteudo = conteudo;
        } else {
            temp = (box*) malloc(sizeof (box));
            temp->conteudo = conteudo; // criei o nó
            temp->proximo = NULL; // se ele é o ultimo ele aponta pra null
            temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
            while (temp2->proximo != NULL) temp2 = temp2->proximo; // move-se ate uma unidade antes do ultimo
            temp2->proximo = temp; // O que era null vira o novo elemento criado
        }
        tamanho++;
    }

    /**
     * É necessário que se atente para o valor2 esteja REALMENTE após o valor1
     * @param conteudo
     * @param valor1
     * @param valor2
     */
    void adicionaEntre(char conteudo, char valor1, char valor2) {
        if (contem(valor1) && contem(valor2)) {
            temp = (box*) malloc(sizeof (box));
            temp->conteudo = conteudo; // criei o nó
            // busca 1 - O elemento que sucede o que sera colocado ao meio
            temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
            while (temp2->proximo->conteudo != valor2) temp2 = temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
            // continua
            temp->proximo = temp2->proximo; // armazena o proximo no novo no
            // busca 2
            temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
            while (temp2->proximo->conteudo != valor1) temp2 = temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
            temp2->proximo->proximo = temp; // O que apontava para o proximo de 'a' agora aponta para o novo elemento criado
            tamanho++;
        }
    }

    void apagaPrimeiro() {
        if (tamanho == 0); // não faz nada
        else {
            temp = inicio;
            inicio = inicio->proximo;
            free(temp);
            tamanho--;
        }
    }

    void apagaUltimo() {
        if (tamanho == 0);
        else {
            temp = inicio; // inicializa variavel que vai percorrer a cadeia
            while (temp->proximo != NULL) temp = temp->proximo; // move-se ate uma unidade antes do ultimo
            temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
            while (temp2->proximo->conteudo != temp->conteudo) temp2 = temp2->proximo; // move-se ate a penultima unidade antes do ultimo
            free(temp); // libera ultimo
            temp2->proximo = NULL; // penultimo aponta pra nulo
            tamanho--;
        }
    }

    /**
     * Ainda nao implementado
     */
    void apagaEntre() {

    }

    bool contem(char conteudo) {
        bool resultado = false;
        temp = inicio;
        while (temp->conteudo != NULL) {
            if (temp->conteudo == conteudo) {
                resultado = true;
                break;
            } else temp = temp->proximo;
        }
        return resultado;
    }

    void imprimeStruct() {
        temp = inicio;
        while (temp != 0) { // deferente de NULL
            printf("Char: %c | Prox: %p\n", temp->conteudo, temp->proximo);
            temp = temp->proximo;
        }
        printf("\n");
    }


};

#endif /* CLASSELISTAENCADEADA_H */

