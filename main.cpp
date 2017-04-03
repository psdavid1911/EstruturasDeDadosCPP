#include "funcoesAuxiliares.h"
#include "Lista01Questao01.h"
#include "Lista01Questao02.h"
#include "Lista01Questao03.h"
#include "Lista01Questao04.h"
#include "Lista01Questao05.h"
#include "Lista02Questao01.h"
#include "Lista02Questao02.h"
#include "Lista02Questao03.h"
#include "Lista02Questao04.h"

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
                << "6" << ". Questao 01 da lista 02" << endl
                << "7" << ". Questao 02 da lista 02" << endl
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
                Lista01Questao04();
                break;
            case 5:
                Lista01Questao05();
                break;
            case 6:
                //Lista02Questao01();
                break;
            case 7:
                Lista02Questao02();
                break;
            case 8:
                //Lista02Questao03();
                break;
            case 9:
                Lista02Questao04();
                break;
            default:
                break;
        }
    }
}