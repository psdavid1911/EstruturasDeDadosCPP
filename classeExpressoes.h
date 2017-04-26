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
    }

    double pilhaDeParenteses() {
        return pilhaDeParenteses(exp);
    }

    double pilhaDeParenteses(string expressao) {
        cout << "Entrou >| " << expressao << endl;
        int posicaoInicial = 0;
        int tamanhoDaExpressao = expressao.length();
        int posicaoFinal = expressao.find(')'); // primeiro fechamento
        if (posicaoFinal != -1) {
            for (int x = posicaoFinal; x >= 0; x--) {
                if (expressao.at(x) == '(') {
                    posicaoInicial = x; // Seu par de abertura
                    break;
                }
            }
            tamanhoDaExpressao = posicaoFinal - posicaoInicial;
            return pilhaDeParenteses(exp.replace(posicaoInicial, tamanhoDaExpressao+1,to_string(pilhaDeParenteses(exp.substr(posicaoInicial + 1, tamanhoDaExpressao - 1)))));
        } else return calculaexpressao(expressao.substr(posicaoInicial, tamanhoDaExpressao));
    }

    double calculaexpressao(string expressao) {
        cout << "Entrou para calcular >| " << expressao << endl;
        Pilha<string> pilha;
        int inicio = 0;
        string temp;

        // Monta a pilha de operadores e operandos
        for (int x = 0; x < expressao.length(); x++) {
            switch (expressao.at(x)) {
                case '^':
                    pilha.empilha(temp);
                    temp = "";
                    pilha.empilha("^");
                    inicio = x + 1;
                    break;
                case '*':
                    pilha.empilha(temp);
                    temp = "";
                    pilha.empilha("*");
                    inicio = x + 1;
                    break;
                case '/':
                    pilha.empilha(temp);
                    temp = "";
                    pilha.empilha("/");
                    inicio = x + 1;
                    break;
                case '+':
                    pilha.empilha(temp);
                    temp = "";
                    pilha.empilha("+");
                    inicio = x + 1;
                    break;
                case '-':
                    pilha.empilha(temp);
                    temp = "";
                    pilha.empilha("-");
                    inicio = x + 1;
                    break;
                default:
                    temp += expressao.at(x);
                    break;
            }
        }
        pilha.empilha(temp); // o ultimo valor que falta inserir

        // Esvazia pilha com o resultado
        while (pilha.tamanho() > 1) {
            double temp = 0;
            // Cuidado com essa ordem
            double operando1 = atof(pilha.desempilha().c_str());
            char operador = pilha.desempilha().at(0);
            double operando2 = atof(pilha.desempilha().c_str());

            cout << "operacao" << " " << operando2 << ":" << operador << ":" << operando1 << endl;

            switch (operador) {
                case '^':
                    temp = pow(operando2, operando1);
                    pilha.empilha(to_string<double>(temp));
                    break;
                case '*':
                    temp = (double) operando2 * operando1;
                    pilha.empilha(to_string<double>(temp));
                    break;
                case '/':
                    temp = (double) operando2 / operando1;
                    pilha.empilha(to_string<double>(temp));
                    break;
                case '+':
                    temp = (double) operando2 + operando1;
                    pilha.empilha(to_string<double>(temp));
                    break;
                case '-':
                    temp = (double) operando2 - operando1;
                    pilha.empilha(to_string<double>(temp));
                    break;
                default:
                    break;
            }
        }

        return atof(pilha.desempilha().c_str());
    }

    template <typename Tipo>
    std::string to_string(Tipo const& value) {
        stringstream sstr;
        sstr << value;
        return sstr.str();
    }
};


#endif /* EXPRESSOESMATEMATICAS_H */

