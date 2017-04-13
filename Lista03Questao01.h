/* 
 * File:   Lista03Questao01.h
 * Author: david
 *
 * Created on 12 de Abril de 2017, 19:04
 */

#ifndef LISTA03QUESTAO01_H
#define LISTA03QUESTAO01_H

#include <cstdlib>
#include <stdio.h>

void Lista03Questao01() {

    /**
     * ESTRUTURA FORNECIDA PELO PROFESSOR
     */
    struct box {
        char conteudo; // removido o acento
        box *proximo; // removido o acento
    } *inicio, *fim, *temp, *temp2;
    /**
     * INÍCIO
     */
    inicio = (box*) malloc(sizeof (box));
    inicio->proximo = NULL; // PODE SER 0 TBM
    printf("\n\n\nChar: %c | Prox: %p\n\n", inicio->conteudo, (*inicio).proximo); // AS DUAS FORMAS SERVEM
    /**
     * Questao 1
     */
    inicio->conteudo = 'a'; // O FIM TAMBÉM É O INICIO
    printf("Char: %c | Prox: %p\n\n", inicio->conteudo, (*inicio).proximo); // AS DUAS FORMAS SERVEM
    /**
     * Questao 2
     */
    temp = (box*) malloc(sizeof (box)); // INICIALIZA VARIÁVEL TEMPORÁRIA
    temp->conteudo = 'b';
    temp->proximo = inicio;
    inicio = temp;
    printf("Char: %c | Prox: %p\n", inicio->conteudo, (*inicio).proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    /**
     * Questao 3
     */
    temp = (box*) malloc(sizeof (box));
    temp->conteudo = 'c'; // criei o nó
    temp->proximo = NULL; // se ele é o ultimo ele aponta pra null
    temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp2->proximo != NULL) temp2 = temp2->proximo; // move-se ate uma unidade antes do ultimo
    temp2->proximo = temp; // O que era null vira o novo elemento criado
    printf("Char: %c | Prox: %p\n", inicio->conteudo, inicio->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->conteudo, inicio->proximo->proximo->proximo);
    /**
     * Questao 4
     */
    temp = (box*) malloc(sizeof (box));
    temp->conteudo = 'd'; // criei o nó
    temp->proximo = NULL; // se ele é o ultimo ele aponta pra null
    temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp2->proximo != NULL) temp2 = temp2->proximo; // move-se ate uma unidade antes do ultimo
    temp2->proximo = temp; // O que era null vira o novo elemento criado
    printf("Char: %c | Prox: %p\n", inicio->conteudo, inicio->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->conteudo, inicio->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo);
    /**
     * Questao 5 - OBS MINHA LÓGICA LEVA EM CONSIDERAÇÃO A ÚLTIMA OCORRENCIA ANTES DA PRIMEIRA
     */
    temp = (box*) malloc(sizeof (box));
    temp->conteudo = 'e'; // criei o nó
    // busca 1 - O elemento que sucede o que sera colocado ao meio
    temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp2->proximo->conteudo != 'c') temp2 = temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
    // continua
    temp->proximo = temp2->proximo; // armazena o proximo no novo no
    // busca 2
    temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp2->proximo->conteudo != 'a') temp2 = temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
    temp2->proximo->proximo = temp; // O que apontava para o proximo de 'a' agora aponta para o novo elemento criado
    printf("Char: %c | Prox: %p\n", inicio->conteudo, inicio->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->conteudo, inicio->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo);
    /**
     * Questao 6
     */
    temp = (box*) malloc(sizeof (box));
    temp->conteudo = 'f'; // criei o nó
    temp->proximo = NULL; // se ele é o ultimo ele aponta pra null
    temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp2->proximo != NULL) temp2 = temp2->proximo; // move-se ate uma unidade antes do ultimo
    temp2->proximo = temp; // O que era null vira o novo elemento criado
    printf("Char: %c | Prox: %p\n", inicio->conteudo, inicio->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->conteudo, inicio->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo);
    /**
     * Questao 7
     */
    temp = (box*) malloc(sizeof (box)); // INICIALIZA VARIÁVEL TEMPORÁRIA
    temp->conteudo = 'g';
    temp->proximo = inicio;
    inicio = temp;
    printf("Char: %c | Prox: %p\n", inicio->conteudo, inicio->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->conteudo, inicio->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo->proximo);
    /**
     * Questao 8
     */
    temp = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp->proximo != NULL) temp = temp->proximo; // move-se ate uma unidade antes do ultimo
    temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp2->proximo->conteudo != temp->conteudo) temp2 = temp2->proximo; // move-se ate a penultima unidade antes do ultimo
    free(temp); // libera ultimo
    temp2->proximo = NULL; // penultimo aponta pra nulo
    printf("Char: %c | Prox: %p\n", inicio->conteudo, inicio->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->conteudo, inicio->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo);
    //printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo->proximo);
    /**
     * Questao 9
     */
    temp = inicio;
    inicio = inicio->proximo;
    free(temp);
    printf("Char: %c | Prox: %p\n", inicio->conteudo, inicio->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->conteudo, inicio->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo);
    //printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo);
    //printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo->proximo);
    /**
     * Questao 10 - OBS MINHA LÓGICA LEVA EM CONSIDERAÇÃO A ÚLTIMA OCORRENCIA ANTES DA PRIMEIRA
     */
    temp = (box*) malloc(sizeof (box));
    temp->conteudo = 'h'; // criei o nó
    // busca 1 - O elemento que sucede o que sera colocado ao meio
    temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp2->proximo->conteudo != 'e') temp2 = temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
    // continua
    temp->proximo = temp2->proximo; // armazena o proximo no novo no
    // busca 2
    temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp2->proximo->conteudo != 'a') temp2 = temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
    temp2->proximo->proximo = temp; // O que apontava para o proximo de 'a' agora aponta para o novo elemento criado
    printf("Char: %c | Prox: %p\n", inicio->conteudo, inicio->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->conteudo, inicio->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo);
    //printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo->proximo);
    /**
     * Questao 11
     */
    temp = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp->proximo->conteudo != 'a') temp = temp->proximo; // move-se ate uma unidade antes da do conteudo que se removera
    temp2 = temp->proximo;
    temp->proximo = temp->proximo->proximo;
    free(temp2);
    printf("Char: %c | Prox: %p\n", inicio->conteudo, inicio->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->conteudo, inicio->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo);
    //printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo);
    //printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo->proximo);
    /**
     * Questao 12 - OBS MINHA LÓGICA LEVA EM CONSIDERAÇÃO A ÚLTIMA OCORRENCIA ANTES DA PRIMEIRA
     */
    printf("TRATAMENTO DE ERROS:  QUESTAO AMBIGUA DADO OS VALORES PREEXISTENTES, IMPOSSIVEL!!\n\n");
    /**
     * Questao 13 
     */
    temp = (box*) malloc(sizeof (box));
    temp->conteudo = 'j'; // criei o nó
    temp->proximo = NULL; // se ele é o ultimo ele aponta pra null
    temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp2->proximo != NULL) temp2 = temp2->proximo; // move-se ate uma unidade antes do ultimo
    temp2->proximo = temp; // O que era null vira o novo elemento criado
    printf("Char: %c | Prox: %p\n", inicio->conteudo, inicio->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->conteudo, inicio->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo);
    //printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo->proximo);
    /**
     * Questao 14 - OBS MINHA LÓGICA LEVA EM CONSIDERAÇÃO A ÚLTIMA OCORRENCIA ANTES DA PRIMEIRA (!!!***MODIFICADO***!!!) MUDAR OUTROS TAMBÉM
     */
    temp = (box*) malloc(sizeof (box));
    temp->conteudo = 'k'; // criei o nó
    // busca 1 - O elemento que sucede o que sera colocado ao meio
    temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp2->proximo->conteudo != 'h') temp2 = temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
    // continua
    temp->proximo = temp2->proximo; // armazena o proximo no novo no
    // busca 2
    temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp2->conteudo != 'b') temp2 = temp2->proximo; // move-se ate uma unidade antes da do conteudo desejado
    temp2->proximo = temp; // O que apontava para o proximo de 'a' agora aponta para o novo elemento criado
    printf("Char: %c | Prox: %p\n", inicio->conteudo, inicio->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->conteudo, inicio->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo->proximo);
    /**
     * Questao 15
     */
    temp = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp->proximo->conteudo != 'd') temp = temp->proximo; // move-se ate uma unidade antes da do conteudo que se removera
    temp2 = temp->proximo;
    temp->proximo = temp->proximo->proximo;
    free(temp2);
    temp = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp->proximo->conteudo != 'k') temp = temp->proximo; // move-se ate uma unidade antes da do conteudo que se removera
    temp2 = temp->proximo;
    temp->proximo = temp->proximo->proximo;
    free(temp2);
    printf("Char: %c | Prox: %p\n", inicio->conteudo, inicio->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->conteudo, inicio->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo);
    //printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo);
    //printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo->proximo);
    /**
     * Questao 16 - LER A QUESTAO E GENERALIZAR, VOCE SABE QUE PODE SER MELHOR AKI.
     */
    temp = inicio;
    inicio = inicio->proximo;
    free(temp);
    printf("Char: %c | Prox: %p\n", inicio->conteudo, inicio->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->conteudo, inicio->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo);
    //printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo);
    //printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo);
    //printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo->proximo);
    /**
     * Questao 17
     */
    temp = (box*) malloc(sizeof (box));
    temp->conteudo = 'l'; // criei o nó
    temp->proximo = NULL; // se ele é o ultimo ele aponta pra null
    temp2 = inicio; // inicializa variavel que vai percorrer a cadeia
    while (temp2->proximo != NULL) temp2 = temp2->proximo; // move-se ate uma unidade antes do ultimo
    temp2->proximo = temp; // O que era null vira o novo elemento criado
    printf("Char: %c | Prox: %p\n", inicio->conteudo, inicio->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->conteudo, inicio->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->conteudo, inicio->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n", inicio->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo);
    printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo);
    //printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo);
    //printf("Char: %c | Prox: %p\n\n", inicio->proximo->proximo->proximo->proximo->proximo->proximo->conteudo, inicio->proximo->proximo->proximo->proximo->proximo->proximo->proximo);
}

#endif /* LISTA03QUESTAO01_H */


