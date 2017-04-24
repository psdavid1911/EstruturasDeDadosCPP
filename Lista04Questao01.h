#ifndef LISTA04QUESTAO01_H
#define LISTA04QUESTAO01_H

#include "classePilha.h"
#include "expressoesMatematicas.h"



void Lista04Questao01(){
    string exp = "2+3*4(7+1)^2";
    //getline(cin, exp);
    Expressao<int> manipulador( exp );
    //manipulador.pilhaDeParenteses();
    manipulador.calculaexpressao("1+2");
    
}

#endif /* LISTA04QUESTAO01_H */

