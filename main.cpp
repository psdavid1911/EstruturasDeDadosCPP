
// INCLUE TUDAO, MENOS AS QUESTÕES PROPRIAMENTE DITAS
#include "bibliotecas.h"
// INCLUE AS QUESTÕES
#include "Lista01Questao01.h"
#include "Lista01Questao02.h"
#include "Lista01Questao03.h"
#include "Lista01Questao04.h"
#include "Lista01Questao05.h"
#include "Lista02Questao01.h"
#include "Lista02Questao02.h"
#include "Lista02Questao03.h" // É a questão 4
#include "Lista02Questao04.h"
#include "Lista02Questao05.h"
#include "Lista02Questao06.h"
#include "Lista03Questao01.h"
#include "Lista04Questao01.h"

int main(){
    while(true){
        cout
                << "----------------------------------------------------" << endl
                << "MENU" << endl
                << "----------------------------------------------------" << endl
                << "Escolha a questao que deseja executar:" << endl
                << "LISTA 01" << endl
                << " 1" << ". Questao 01 da lista 01" << endl
                << " 2" << ". Questao 02 da lista 01" << endl
                << " 3" << ". Questao 03 da lista 01" << endl
                << " 4" << ". Questao 04 da lista 01" << endl
                << " 5" << ". Questao 05 da lista 01" << endl
                << "LISTA 02" << endl
                << " 6" << ". Questao 01 da lista 02" << endl
                << " 7" << ". Questao 02 da lista 02" << endl
                << " 8" << ". Questao 03 da lista 02" << endl
                << " 9" << ". Questao 04 da lista 02" << endl
                << "10" << ". Questao 05 da lista 02" << endl
                << "11" << ". Questao 06 da lista 02" << endl
                << "LISTA 03" << endl
                << "12" << ". Questao 01 da lista 03" << endl
                << "LISTA 04" << endl
                << "13" << ". Questao 01 da lista 04" << endl
                << "OUTRAS OPCOES" << endl
                << "98" << ". Arquivo criado exclusivamente para testes." << endl
                << "99" << ". Qualquer outra opcao fecha o programa."
                << endl;




        switch(leInteiro()){
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
                Lista02Questao01();
                break;
            case 7:
                Lista02Questao02();
                break;
            case 8:
                Lista02Questao04();
                break;
            case 9:
                Lista02Questao04();
                break;
            case 10:
                Lista02Questao06();
                break;
            case 11:
                Lista02Questao06();
                break;
            case 12:
                Lista03Questao01();
                break;
            case 13:
                Lista04Questao01();
                break;
            case 98:
                Testes();
                break;
            default:
                exit(0);
                break;
        }
    }
}