#pragma once
#include "bibliotecas.h"

class Funcionario{
public:
    string nome;
    bool masculino;
    int numeroDePecas;

    Funcionario(){
    }

    Funcionario(string nome, bool masculino, int numeroDePecas){
        this->nome=nome;
        this->masculino=masculino;
        this->numeroDePecas=numeroDePecas;
    }

    void adiciona(string nome, bool masculino, int numeroDePecas){
        this->nome=nome;
        this->masculino=masculino;
        this->numeroDePecas=numeroDePecas;
    }
};

void Lista02Questao02(){
    Lista<Funcionario> listaDeFuncionariosMasculinos;
    Lista<Funcionario> listaDeFuncionariosFemininos;
    bool continua=true;
    while(continua){
        cout << "Digite um nome: ";
        string s=leString();
        cout << "É homem 0/1 (false/true)?: ";
        bool b=leBool();
        cout << "Quantas pecas possui ? ";
        int i=leInteiro();
        if(b)listaDeFuncionariosMasculinos.adiciona(Funcionario(s, b, i));
        else listaDeFuncionariosFemininos.adiciona(Funcionario(s, b, i));

        cout << "Deseja inserir um novo funcionário 0/1 (false/true)? ";
        continua=leBool();
    }
    resposta();
    int quantidade=0;
    for(int contador=0; contador < listaDeFuncionariosMasculinos.tamanho; contador++){
        Funcionario f=listaDeFuncionariosMasculinos.vetor[contador];
        quantidade+=f.numeroDePecas;
    }
    cout << "Quantidade de peças func. masculinos: " << quantidade << endl;
    quantidade=0;
    for(int contador=0; contador < listaDeFuncionariosFemininos.tamanho; contador++){
        Funcionario f=listaDeFuncionariosFemininos.vetor[contador];
        quantidade+=f.numeroDePecas;
    }
    cout << "Quantidade de peças func. femininos: " << quantidade << endl;
    for(int contador=0; contador < listaDeFuncionariosFemininos.tamanho; contador++){
        listaDeFuncionariosMasculinos.adiciona(listaDeFuncionariosFemininos.vetor[contador]);
    }
    int maiorValor=0;
    int funcionario=0;
    for(int contador=0; contador < listaDeFuncionariosMasculinos.tamanho; contador++){
        int numeroDePecasDeste=listaDeFuncionariosMasculinos.vetor[contador].numeroDePecas;
        if(numeroDePecasDeste > maiorValor){
            maiorValor=numeroDePecasDeste;
            funcionario=contador;
        }
    }
    cout << "Funcionario com mais pecas: " << listaDeFuncionariosMasculinos.vetor[funcionario].nome
            << " Numero de pecas: " << maiorValor
            << endl;
}
