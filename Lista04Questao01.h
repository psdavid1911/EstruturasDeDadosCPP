#ifndef LISTA04QUESTAO01_H
#define LISTA04QUESTAO01_H

#include "bibliotecas.h"

void Lista04Questao01() {
    resposta();
    string exp = "(5+(2+3+5)+5)-1"; // Tratamento de erros não foi feito (EXPRESSÕES MAL ESCRITAS)
    //getline(cin, exp);
    Expressao<double> manipulador(exp);
    cout << "Resposta: " << manipulador.pilhaDeParenteses() << endl;
}

#endif /* LISTA04QUESTAO01_H */

