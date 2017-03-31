/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   01.cpp
 * Author: david
 *
 * Created on 30 de Março de 2017, 00:50
 */

#include "funcoesAuxiliares.h"
#include "Lista01Questao01.h"
#include "Lista01Questao02.h"
#include "Lista01Questao03.h"

#include "Lista01Questao05.h"


using namespace std;

int main() {
    while (true) {
        cout << "----------------------------------------------------" << endl
                << "MENU" << endl
                << "----------------------------------------------------" << endl
                << "Escolha a questao que deseja executar:" << endl
                << endl
                << "1" << ". Questao 01 da lista 01" << endl
                << "2" << ". Questao 01 da lista 02" << endl
                << "3" << ". Questao 01 da lista 03" << endl
                << "4" << ". Questao 01 da lista 04" << endl
                << "5" << ". Questao 01 da lista 05" << endl
                << endl;
        switch (leInteiro()) {
            case 1:
                Lista01Questao01();
                break;
            case 2:
                Lista01Questao02();
                break;
            case 3:
                Lista01Questao03();
                break;
            case 4:
                //Lista01Questao04();
                break;
            case 5:
                Lista01Questao05();
                break;
            default:
                break;
        }
    }
}