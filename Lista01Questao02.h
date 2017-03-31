#ifndef LISTA01QUESTAO02_H
#define LISTA01QUESTAO02_H

#include <cstdlib>
#include "classeLista.h"
#include "funcoesAuxiliares.h"

using namespace std;

int Lista01Questao02() {
    entradas();
    Lista<int> x, y, z;
    int valorLido = leInteiro();
    // Leia um vetor X de N elementos e que:
    while (valorLido != -1) {
        x.adiciona(valorLido);
        // Crie outro vetor Y contendo os elementos de X que estão na faixa entre 10 e 40;
        if (valorLido >= 10 && valorLido <= 40) y.adiciona(valorLido);
        // Crie outro vetor W contendo os números que estão nas posições pares;
        if (x.tamanho % 2 != 0) z.adiciona(valorLido);
        valorLido = leInteiro();
    }
    resposta();
    //Pesquise a existência de um determinado elemento Z no vetor X;
    cout << "z: ";
    z.imprime();
    cout << "Elemento '2' de 'z' existe em x (INDET. SE POS. N EXISTE) ? " << x.existe(z.pega(2)) << endl;

    cout << "Maior: " << x.maior() << " menor: " << x.menor() << endl;

    return 0;
}


#endif /* LISTA01QUESTAO02_H */

