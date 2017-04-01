#ifndef LISTA01QUESTAO01_H
#define LISTA01QUESTAO01_H

#include "classeLista.h"
#include "funcoesAuxiliares.h"
using namespace std;

void Lista01Questao01() {
    string questao = "1. Leia uma lista de no máximo 100 números inteiros, carregando-os em um vetor.\n" \
            "Os números lidos maiores ou iguais que 256 deverão ser ignorados.\n" \
            "- Ordene os números lidos em ordem decrescente.\n" \
            "- Informar quantos são ímpares e quantos são pares.\n" \
            "- Apresente a média dos números ímpares maiores que 50.\n";
    entradas(questao);
    Lista<int> listaDeValores, listaDePares, listaDeImpares, listaDeImparesMaioresQueCinquenta;
    int numeroDePares = 0, numeroDeImpares = 0, valorLido = 0;
    valorLido = leInteiro();
    while (listaDeValores.tamanho < 100 && valorLido != -1) {
        if (valorLido < 256) listaDeValores.adiciona(valorLido);
        valorLido = leInteiro();
    }
    resposta();
    listaDeValores.ordena();
    listaDeValores.inverte();
    listaDeValores.imprime();
    for (int contador = 0; contador < listaDeValores.tamanho; contador++) {
        int valorAtual = listaDeValores.vetor[contador];
        if (valorAtual % 2 == 0 && valorAtual > 1) listaDePares.adiciona(valorAtual);
        else listaDeImpares.adiciona(valorAtual);
    }
    cout << "Pares: " << listaDePares.tamanho << " impares: " << listaDeImpares.tamanho << endl;
    for (int contador = 0; contador < listaDeImpares.tamanho; contador++) {
        int valorAtual = listaDeImpares.vetor[contador];
        if (valorAtual > 50)
            listaDeImparesMaioresQueCinquenta.adiciona(valorAtual);
    }
    int soma = 0;
    for (int contador = 0; contador < listaDeImparesMaioresQueCinquenta.tamanho; contador++)
        soma += listaDeImparesMaioresQueCinquenta.vetor[contador];
    cout << "(Fica indeterminado se não existirem valores) Media: " << (float) soma / listaDeImparesMaioresQueCinquenta.tamanho << endl;
}
#endif /* LISTA01QUESTAO01_H */

