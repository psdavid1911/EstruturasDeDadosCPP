#ifndef LISTA01QUESTAO01_H
#define LISTA01QUESTAO01_H

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include "classeLista.h"
#include "funcoesAuxiliares.h"
using namespace std;

/*
 1. Leia uma lista de no máximo 100 números inteiros, carregando-os em um vetor. Os
números lidos maiores ou iguais que 256 deverão ser ignorados.
 Ordene os números lidos em ordem decrescente.
 Informar quantos são ímpares e quantos são pares.
 Apresente a média dos números ímpares maiores que 50.
 */
void Lista01Questao04() {
    entradas();
    Lista lista;
    int valorLido = leInteiro();
    while (valorLido != -1) {
        lista.adiciona(valorLido);
        valorLido = leInteiro();
    }
    resposta();

}
#endif /* LISTA01QUESTAO01_H */

