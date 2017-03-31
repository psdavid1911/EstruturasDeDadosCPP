#ifndef LISTA01QUESTAO04_H
#define LISTA01QUESTAO04_H

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

void Lista01Questao04() {
    entradas();
    Lista<int> lista;
    int busca;
    do {
        int valorLido = leInteiro();
        lista.adiciona(2);
        lista.adiciona(3);
        lista.adiciona(5);
        lista.adiciona(7);
        for (int numero = 2; numero < 2 * valorLido; numero++) {
            if (numero % 2 == 0 || numero % 3 == 0 || numero % 5 == 0 || numero % 7 == 0) {
            } else lista.adiciona(numero);
        }
        lista.imprime();
        busca = lista.buscaSequencial(valorLido);
    } while (busca == -1);
    resposta();
    if(busca>2)cout << "Esquerda: " << lista.vetor[busca-2] << "   " << lista.vetor[busca-1] << endl;
    cout << "Valor: " << lista.vetor[busca] << endl;
    cout << "Direita: " << lista.vetor[busca+1] << "   " << lista.vetor[busca+2] << endl;



}
#endif /* LISTA01QUESTAO01_H */

