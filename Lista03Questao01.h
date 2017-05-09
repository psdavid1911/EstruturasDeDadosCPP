#pragma once
#include "bibliotecas.h"

int Lista03Questao01(){
    resposta();
    /**
     * INÍCIO
     */
    ListaEncadeada<char> * lista=new ListaEncadeada<char>(); // CUIDADO, NÃO ESKECA DOS PRE-REQUISITOS DO  CONSTRUTOR.
    lista->imprime();
    /**
     * Questao 1
     */
    lista->adicionaAoFinal('a');
    lista->imprime();
    /**
     * Questao 2
     */
    lista->adicionaAoInicio('b');
    lista->imprime();
    /**
     * Questao 3
     */
    lista->adicionaAoFinal('c');
    lista->imprime();
    /**
     * Questao 4
     */
    lista->adicionaAoFinal('d');
    lista->imprime();
    /**
     * Questao 5 - OBS MINHA LÓGICA LEVA EM CONSIDERAÇÃO A ÚLTIMA OCORRENCIA ANTES DA PRIMEIRA
     */
    lista->adicionaEntre('e', 'a', 'c');
    lista->imprime();
    /**
     * Questao 6
     */
    lista->adicionaAoFinal('f');
    lista->imprime();
    /**
     * Questao 7
     */
    lista->adicionaAoInicio('g');
    lista->imprime();
    /**
     * Questao 8
     */
    lista->apagaUltimo();
    lista->imprime();
    /**
     * Questao 9
     */
    lista->apagaPrimeiro();
    lista->imprime();
    /**
     * Questao 10 - OBS MINHA LÓGICA LEVA EM CONSIDERAÇÃO A ÚLTIMA OCORRENCIA ANTES DA PRIMEIRA
     */
    lista->adicionaEntre('h', 'a', 'e');
    lista->imprime();
    /**
     * Questao 11
     */
    lista->remove('a');
    lista->imprime();
    /**
     * Questao 12 - OBS MINHA LÓGICA LEVA EM CONSIDERAÇÃO A ÚLTIMA OCORRENCIA ANTES DA PRIMEIRA
     */
    lista->adicionaEntre('l', 'e', 'd');
    lista->imprime();
    /**
     * Questao 13 
     */
    lista->adicionaAoFinal('j');
    lista->imprime();
    /**
     * Questao 14 - OBS MINHA LÓGICA LEVA EM CONSIDERAÇÃO A ÚLTIMA OCORRENCIA ANTES DA PRIMEIRA (!!!***MODIFICADO***!!!) MUDAR OUTROS TAMBÉM
     */
    lista->adicionaEntre('k', 'b', 'h');
    lista->imprime();
    /**
     * Questao 15
     */
    lista->remove('d');
    lista->remove('k');
    lista->remove('i');
    lista->imprime();
    /**
     * Questao 16 - LER A QUESTAO E GENERALIZAR, VOCE SABE QUE PODE SER MELHOR AKI.
     */
    lista->remove('b');
    lista->imprime();
    /**
     * Questao 17
     */
    lista->adicionaAoFinal('l');
    lista->imprime();
    /**
     * Fim
     * @return 
     */
    delete lista;
    return 0;
}