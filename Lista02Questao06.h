#ifndef LISTA02QUESTAO06_H
#define LISTA02QUESTAO06_H

#include "bibliotecas.h"

void Lista02Questao06() {
    Agenda agenda;
    while (true) {
        cout
                << "----------------------------------------------------" << endl
                << "MENU INTERNO" << endl
                << "----------------------------------------------------" << endl
                << "O que deseja fazer? " << endl
                << "1. Inserir um registro" << endl
                << "2. Alterar um registro" << endl
                << "3. Exibir um registro" << endl
                << "4. Exibir todos os registros" << endl
                << "Qualquer outra opcao ele sai..." << endl;

        int opcao = leInteiro();
        switch (opcao) {
            case 1:
                agenda.promptAdiciona();
                break;
            case 2:
                agenda.promptAlterarRegistro();
                break;
            case 3:
                resposta();
                agenda.promptBusca();
                break;
            case 4:
                resposta();
                agenda.imprime();
                break;
            default:
                return;
        }
    }
}
#endif

// Elegante 
// Boa prática de programação