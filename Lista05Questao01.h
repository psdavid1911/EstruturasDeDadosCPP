#pragma once
#include "bibliotecas.h"

void Lista05Questao01(){
    entradas();
    imprime("Digite o número de servidores\n");
    int numeroDeServidores=leInteiro();
    resposta();
    Fila<int> * famintos=new Fila<int>();
    Fila<int> * temposDeAtendimento=new Fila<int>();
    for(int i=0; i < 60 * 60; i++){
        if(i < 15 * 30 && rand() % 20 < 6)famintos->enfileira(i);
        else if(i < 25 * 30 && rand() % 20 < 11)famintos->enfileira(i);
        else if(i < 30 * 30 && rand() % 20 < 16)famintos->enfileira(i);
        else if(i < 35 * 30 && rand() % 20 < 16)famintos->enfileira(i);
        else if(i < 45 * 30 && rand() % 20 < 11)famintos->enfileira(i);
        else if(i < 60 * 30 && rand() % 20 < 6)famintos->enfileira(i);
        if(i > (30 * 60) && i % 4 == 0){
            for(int j=1; j <= numeroDeServidores; j++){
                if(famintos->estaVazia())break;
                temposDeAtendimento->enfileira(i - famintos->desenfileira());
            }
        }
    }
    // Soma dos tempos
    int qtdeSaciados=temposDeAtendimento->tamanho(); // nao perde o valor
    int somaDosTempos=0;
    while(temposDeAtendimento->naoEstaVazia()) somaDosTempos+=temposDeAtendimento->desenfileira();
    // Valores
    Inteiro atendidos=qtdeSaciados;
    Decimal mediaEspera=(somaDosTempos / qtdeSaciados);
    Decimal mediaConvertida=mediaEspera.valor / 60;
    Inteiro numeroDePessoasNaFila=qtdeSaciados + famintos->tamanho();
    Inteiro tempoTotalDeFila=somaDosTempos;
    // Mostra Resultados
    imprime("Quantidade de pessoas atendidas: " + atendidos.texto() + "\n");
    imprime("Tempo levado para processar a fila: " + tempoTotalDeFila.texto() + " segundos \n");
    imprime("Tempo médio na fila: " + mediaEspera.paraTexto() + " segundos \n");
    imprime("Tempo médio na fila: " + mediaConvertida.paraTexto() + " minutos \n");
    imprime("Número inicial de pessoas na fila: " + numeroDePessoasNaFila.texto() + "\n");
    // Apaga memórias
    delete famintos;
    delete temposDeAtendimento;
}
