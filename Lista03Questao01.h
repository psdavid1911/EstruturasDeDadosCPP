#pragma once
#include "bibliotecas.h"

/**
 * ESTRUTURA FORNECIDA PELO PROFESSOR
 */
// ALTERNATIVA 1
//class box{
//public:
//    char conteudo; // removido o acento
//    box *proximo; // removido o acento
//} *inicio, *temp, *temp2;
// ALTERNATIVA 2

struct box{
    char conteudo; // removido o acento
    box *proximo; // removido o acento
} *inicio, *temp, *temp2;

void imprimeStruct(){
    temp=inicio;
    while(temp != 0){ // deferente de NULL
        printf("Char: %c | Prox: %p\n", temp->conteudo, temp->proximo);
        temp=temp->proximo;
    }
    printf("\n");
}

int Lista03Questao01(){
    /**
     * INÍCIO
     */
    inicio=(box*)malloc(sizeof(box));
    //inicio = (box*) new box;
    inicio->proximo=NULL; // PODE SER 0 TBM
    imprimeStruct();
    /**
     * Questao 1
     */
    inicio->conteudo='a'; // O FIM TAMBÉM É O INICIO
    imprimeStruct();
    /**
     * Questao 2
     */
    temp=(box*)malloc(sizeof(box)); // INICIALIZA VARIÁVEL TEMPORÁRIA
    temp->conteudo='b';
    temp->proximo=inicio;
    inicio=temp;
    imprimeStruct();
    /**
     * Questao 3
     */
    temp=(box*)malloc(sizeof(box));
    temp->conteudo='c'; // criei o nó
    temp->proximo=NULL; // se ele é o ultimo ele aponta pra null
    temp2=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp2->proximo != NULL) temp2=temp2->proximo; // move-se ate uma unidade antes do ultimo
    temp2->proximo=temp; // O que era null vira o novo elemento criado
    imprimeStruct();
    /**
     * Questao 4
     */
    temp=(box*)malloc(sizeof(box));
    temp->conteudo='d'; // criei o nó
    temp->proximo=NULL; // se ele é o ultimo ele aponta pra null
    temp2=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp2->proximo != NULL) temp2=temp2->proximo; // move-se ate uma unidade antes do ultimo
    temp2->proximo=temp; // O que era null vira o novo elemento criado
    imprimeStruct();
    /**
     * Questao 5 - OBS MINHA LÓGICA LEVA EM CONSIDERAÇÃO A ÚLTIMA OCORRENCIA ANTES DA PRIMEIRA
     */
    temp=(box*)malloc(sizeof(box));
    temp->conteudo='e'; // criei o nó
    // busca 1 - O elemento que sucede o que sera colocado ao meio
    temp2=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp2->proximo->conteudo != 'c') temp2=temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
    // continua
    temp->proximo=temp2->proximo; // armazena o proximo no novo no
    // busca 2
    temp2=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp2->proximo->conteudo != 'a') temp2=temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
    temp2->proximo->proximo=temp; // O que apontava para o proximo de 'a' agora aponta para o novo elemento criado
    imprimeStruct();
    /**
     * Questao 6
     */
    temp=(box*)malloc(sizeof(box));
    temp->conteudo='f'; // criei o nó
    temp->proximo=NULL; // se ele é o ultimo ele aponta pra null
    temp2=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp2->proximo != NULL) temp2=temp2->proximo; // move-se ate uma unidade antes do ultimo
    temp2->proximo=temp; // O que era null vira o novo elemento criado
    imprimeStruct();
    /**
     * Questao 7
     */
    temp=(box*)malloc(sizeof(box)); // INICIALIZA VARIÁVEL TEMPORÁRIA
    temp->conteudo='g';
    temp->proximo=inicio;
    inicio=temp;
    imprimeStruct();
    /**
     * Questao 8
     */
    temp=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp->proximo != NULL) temp=temp->proximo; // move-se ate uma unidade antes do ultimo
    temp2=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp2->proximo->conteudo != temp->conteudo) temp2=temp2->proximo; // move-se ate a penultima unidade antes do ultimo
    free(temp); // libera ultimo
    temp2->proximo=NULL; // penultimo aponta pra nulo
    imprimeStruct();
    /**
     * Questao 9
     */
    temp=inicio;
    inicio=inicio->proximo;
    free(temp);
    imprimeStruct();
    /**
     * Questao 10 - OBS MINHA LÓGICA LEVA EM CONSIDERAÇÃO A ÚLTIMA OCORRENCIA ANTES DA PRIMEIRA
     */
    temp=(box*)malloc(sizeof(box));
    temp->conteudo='h'; // criei o nó
    // busca 1 - O elemento que sucede o que sera colocado ao meio
    temp2=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp2->proximo->conteudo != 'e') temp2=temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
    // continua
    temp->proximo=temp2->proximo; // armazena o proximo no novo no
    // busca 2
    temp2=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp2->proximo->conteudo != 'a') temp2=temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
    temp2->proximo->proximo=temp; // O que apontava para o proximo de 'a' agora aponta para o novo elemento criado
    imprimeStruct();
    /**
     * Questao 11
     */
    temp=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp->proximo->conteudo != 'a') temp=temp->proximo; // move-se ate uma unidade antes da do conteudo que se removera
    temp2=temp->proximo;
    temp->proximo=temp->proximo->proximo;
    free(temp2);
    imprimeStruct();
    /**
     * Questao 12 - OBS MINHA LÓGICA LEVA EM CONSIDERAÇÃO A ÚLTIMA OCORRENCIA ANTES DA PRIMEIRA
     */
    printf("TRATAMENTO DE ERROS:  QUESTAO AMBIGUA DADO OS VALORES PREEXISTENTES, IMPOSSIVEL!!\n\n");
    /**
     * Questao 13 
     */
    temp=(box*)malloc(sizeof(box));
    temp->conteudo='j'; // criei o nó
    temp->proximo=NULL; // se ele é o ultimo ele aponta pra null
    temp2=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp2->proximo != NULL) temp2=temp2->proximo; // move-se ate uma unidade antes do ultimo
    temp2->proximo=temp; // O que era null vira o novo elemento criado
    imprimeStruct();
    /**
     * Questao 14 - OBS MINHA LÓGICA LEVA EM CONSIDERAÇÃO A ÚLTIMA OCORRENCIA ANTES DA PRIMEIRA (!!!***MODIFICADO***!!!) MUDAR OUTROS TAMBÉM
     */
    temp=(box*)malloc(sizeof(box));
    temp->conteudo='k'; // criei o nó
    // busca 1 - O elemento que sucede o que sera colocado ao meio
    temp2=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp2->proximo->conteudo != 'h') temp2=temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
    // continua
    temp->proximo=temp2->proximo; // armazena o proximo no novo no
    // busca 2
    temp2=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp2->conteudo != 'b') temp2=temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
    temp2->proximo=temp; // O que apontava para o proximo de 'a' agora aponta para o novo elemento criado
    imprimeStruct();
    /**
     * Questao 15
     */
    temp=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp->proximo->conteudo != 'd') temp=temp->proximo; // move-se ate uma unidade antes da do conteudo que se removera
    temp2=temp->proximo;
    temp->proximo=temp->proximo->proximo;
    free(temp2);
    temp=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp->proximo->conteudo != 'k') temp=temp->proximo; // move-se ate uma unidade antes da do conteudo que se removera
    temp2=temp->proximo;
    temp->proximo=temp->proximo->proximo;
    free(temp2);
    imprimeStruct();
    /**
     * Questao 16 - LER A QUESTAO E GENERALIZAR, VOCE SABE QUE PODE SER MELHOR AKI.
     */
    temp=inicio;
    inicio=inicio->proximo;
    free(temp);
    imprimeStruct();
    /**
     * Questao 17
     */
    temp=(box*)malloc(sizeof(box));
    temp->conteudo='l'; // criei o nó
    temp->proximo=NULL; // se ele é o ultimo ele aponta pra null
    temp2=inicio; // inicializa variavel que vai percorrer a cadeia
    while(temp2->proximo != NULL) temp2=temp2->proximo; // move-se ate uma unidade antes do ultimo
    temp2->proximo=temp; // O que era null vira o novo elemento criado
    imprimeStruct();
    /**
     * Fim
     * @return 
     */
    return 0;
}
