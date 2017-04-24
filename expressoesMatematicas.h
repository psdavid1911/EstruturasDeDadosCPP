#ifndef EXPRESSOESMATEMATICAS_H
#define EXPRESSOESMATEMATICAS_H

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include "classeLista.h"
#include "classePilha.h"

using namespace std;

template <class T> class Expressao {
public:
    string exp;
    Pilha<T> expressao;

    Expressao(string exp) {
        this->exp = exp;
        //        for (int x = 0; x < exp.length(); x++) {
        //            expressao.empilha(exp.at(x));
        //        }
    }

    int pilhaDeParenteses() {
        int posicaoInicial = 0;
        int posicaoFinal = exp.find(')'); // primeiro fechamento
        for (int x = posicaoFinal; x >= 0; x--) {
            if (exp.at(x) == '(') {
                posicaoInicial = x; // Seu par de abertura
                break;
            }
        }
        int tamanhoDaExpressao = posicaoFinal - posicaoInicial;
        calculaexpressao(exp.substr(posicaoInicial + 1, tamanhoDaExpressao - 1));
    }

    int calculaexpressao(string expressao) {
        Pilha<string> pilha;
        int inicio = 0;

        // Monta a pilha de operadores e operandos
        for (int x = 0; x < expressao.length(); x++) {
            switch (expressao.at(x)) {
                case '^':
                    pilha.empilha(expressao.substr(inicio, x - inicio - 1));
                    pilha.empilha("^");
                    inicio = x + 1;
                    break;
                case '*':
                    pilha.empilha(expressao.substr(inicio, x - inicio - 1));
                    pilha.empilha("*");
                    inicio = x + 1;
                    break;
                case '/':
                    pilha.empilha(expressao.substr(inicio, x - inicio - 1));
                    pilha.empilha("/");
                    inicio = x + 1;
                    break;
                case '+':
                    pilha.empilha(expressao.substr(inicio, x - inicio - 1));
                    pilha.empilha("+");
                    inicio = x + 1;
                    break;
                case '-':
                    pilha.empilha(expressao.substr(inicio, x - inicio - 1));
                    pilha.empilha("-");
                    inicio = x + 1;
                    break;
                default:
                    break;
            }
        }

        // Mostra conteudo da pilha
        for(int i=0; i< pilha.tamanho(); i++){
            cout << pilha.pega(i) << " ";
        }
        cout << endl;
        
        // Esvazia pilha com o resultado
        while (pilha.tamanho() > 1) {
            double temp = 0;
            // Cuidado com essa ordem
            double operando1 = atof(pilha.desempilha().c_str());
            char operador = pilha.desempilha().at(0);
            double operando2 = atof(pilha.desempilha().c_str());

            switch (operador) {
                case '^':
                    temp = pow(operando1, operando2);
                    pilha.empilha(to_string<double>(temp));
                    break;
                case '*':
                    temp = (double) operando1 * operando2;
                    pilha.empilha(to_string<double>(temp));
                    break;
                case '/':
                    temp = (double) operando1 / operando2;
                    pilha.empilha(to_string<double>(temp));
                    break;
                case '+':
                    temp = (double) operando1 + operando2;
                    pilha.empilha(to_string<double>(temp));
                    break;
                case '-':
                    temp = (double) operando1 - operando2;
                    pilha.empilha(to_string<double>(temp));
                    break;
                default:
                    break;
            }
        }
    }

    template <typename Tipo>
    std::string to_string(Tipo const& value) {
        stringstream sstr;
        sstr << value;
        return sstr.str();
    }
};


#endif /* EXPRESSOESMATEMATICAS_H */

