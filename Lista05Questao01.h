#pragma once
#include "bibliotecas.h"
#include "classeFila.h"

// Velocidade de preparo e entrega do hotcat 1 a cada 4s por funcionário

void Lista05Questao01(){
    entradas();
    imprime("Digite o número de servidores\n");
    int numeroDeServidores=leInteiro();

    int tempo=0;
    Fila<int> * filaDePessoas=new Fila<int>();
    Fila<int> * filaTemporaria=new Fila<int>();
    Fila<int> * filaDeAtendidos=new Fila<int>();

    /**
     * Cria aos alunos na fila
     */
    for(int i=0; i < 1000; i++){
        filaDePessoas.adiciona((rand() % 60 - 30)*60); // adiciona o tempo de chegada entre 0 e 60 // ou -30 < inicioDeEntrega <  30
    }
    filaDePessoas.ordena(); // TRANSFORMA EM FILA DE VERDADE!!!

    /**
     * Armazena o tempo que cada um levou para ser atendido
     */
    while(tempo <= 30 * 60){ // valor extra de tempo limite se remover todos serão atendidos, tempo em segundos
        for(int i=0; i < numeroDeServidores; i++){
            if(filaDePessoas.naoEstaVazia()){
                filaTemporaria.adiciona(abs(filaDePessoas.proximo() - (i * tempo)));
            }else break;
        }
        tempo+=4; // demora 4 segundos pra um ciclo invariavelmente
    }

    /**
     * Soma os tempos de atendimento
     */
    int soma=0;
    while(filaTemporaria.naoEstaVazia()){
        int temp=filaTemporaria.proximo();
        soma+=temp;
        filaDeAtendidos.adiciona(temp);
    }

    /**
     * Cria as 'estatisticas'
     */
    Inteiro numeroDePessoasAtendidas=filaDeAtendidos.tamanho();
    Decimal tempoMedioDeEspera=(soma / filaDeAtendidos.tamanho());
    Decimal tempoMedioDeEsperaMinutos=tempoMedioDeEspera.valor / 60;
    Inteiro numeroDePessoasNaFila=filaDeAtendidos.tamanho() + filaDePessoas.tamanho();
    Inteiro tempoTotalDeFila=soma;


    /**
     * Mostra os resultados
     */
    resposta();
    imprime("Quantidade de pessoas atendidas: " + numeroDePessoasAtendidas.paraString() + "\n");
    imprime("Tempo levado para processar a fila: " + tempoTotalDeFila.paraString() + " segundos \n");
    imprime("Tempo médio na fila: " + tempoMedioDeEspera.paraTexto() + " segundos \n");
    imprime("Tempo médio na fila: " + tempoMedioDeEsperaMinutos.paraTexto() + " minutos \n");
    imprime("Número inicial de pessoas na fila: " + numeroDePessoasNaFila.paraString() + "\n");

    delete filaDeAtendidos;
    delete filaDePessoas;
    delete filaTemporaria;
}
