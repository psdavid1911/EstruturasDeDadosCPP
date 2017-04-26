#ifndef LISTA02QUESTAO01_H
#define LISTA02QUESTAO01_H

#include "bibliotecas.h"

void Lista02Questao01() {
    Matriz<int> a(5, 4);
    Matriz<int> b(4, 3);
    Matriz<int> c(5, 3);

    //    Matriz<int> a(1, 2);
    //    Matriz<int> b(2, 3);
    //    Matriz<int> c(1, 3);

    cout << "Leitura da matriz a" << endl;
    a.promptLeituraTodasAsPosicoes();
    a.imprime();
    cout << "Leitura da matriz b" << endl;
    b.promptLeituraTodasAsPosicoes();
    b.imprime();
    resposta();
    cout << "Impressao da matriz c" << endl;
    c = a*b;
    c.imprime();
}

#endif /* LISTA02QUESTAO01_H */

