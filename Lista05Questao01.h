#pragma once
#include "bibliotecas.h"
#include "classeFila.h"

void Lista05Questao01(){
    entradas();
    imprime("Digite o número de servidores\n");
    int numeroDeServidores=leInteiro();

    resposta();
    Fila<int> * famintos=new Fila<int>();
    Fila<int> * temposDeAtendimento=new Fila<int>();

    /**
     * Cria aos alunos na fila
     */
    for(int i=0; i < 10; i++)
        famintos->enfileira((rand() % 60)*60); // adiciona o tempo de chegada entre 0 e 60 e transforma em segundos

    famintos->imprime();
    famintos->ordena(); // muito importante
    famintos->imprime();

    /**
     * Armazena o tempo que cada um levou para ser atendido
     */
    for(int tempo=30 * 60; tempo <= 60 * 60; tempo+=4){
        for(int i=1; i <= numeroDeServidores; i++){
            if(famintos->estaVazia())goto fim;
            temposDeAtendimento->enfileira(abs(tempo - famintos->desenfileira()));
        }
    }
fim:
    int qtdeSaciados=temposDeAtendimento->tamanho();
    /**
     * Soma os tempos de atendimento
     */
    int somaDosTempos=0;
    while(temposDeAtendimento->naoEstaVazia()) somaDosTempos+=temposDeAtendimento->desenfileira();

    /**
     * Cria as 'estatisticas'
     */
    Inteiro atendidos=qtdeSaciados;
    Decimal mediaEspera=(somaDosTempos / qtdeSaciados);
    Decimal mediaConvertida=mediaEspera.valor / 60;
    Inteiro numeroDePessoasNaFila=qtdeSaciados + famintos->tamanho();
    Inteiro tempoTotalDeFila=somaDosTempos;


    /**
     * Mostra os resultados
     */
    imprime("Quantidade de pessoas atendidas: " + atendidos.texto() + "\n");
    imprime("Tempo levado para processar a fila: " + tempoTotalDeFila.texto() + " segundos \n");
    imprime("Tempo médio na fila: " + mediaEspera.paraTexto() + " segundos \n");
    imprime("Tempo médio na fila: " + mediaConvertida.paraTexto() + " minutos \n");
    imprime("Número inicial de pessoas na fila: " + numeroDePessoasNaFila.texto() + "\n");

    delete famintos;
    delete temposDeAtendimento;
}


// Falar dos problemas desse algoritmo que não representa a realidade