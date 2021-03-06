#pragma once
#include "bibliotecas.h"

class Aluno{
public:
    string nome;
    Lista<double> nota;

    Aluno(){
    };

    Aluno(string nome, Lista<double> nota){
        this->nome=nome;
        this->nota=nota;
    }

    void adiciona(string nome, Lista<double> nota){
        this->nome=nome;
        this->nota=nota;
    }
};

void Lista02Questao04(){
    Lista<Aluno> listaDeAlunos;
    bool continua=true;
    while(continua){
        Lista<double> notas;
        cout << "Digite um nome: ";
        string aluno=leString();
        for(int contador=0; contador < 3; contador++){
            cout << "Informe uma nota : " << endl;
            notas.adicionaAoFinal(leInteiro());
        }
        listaDeAlunos.adicionaAoFinal(Aluno(aluno, notas));
        cout << "Deseja inserir um novo aluno 0/1 (false/true)? ";
        continua=leBool();
    }
    resposta();
    for(int contador=0; contador < listaDeAlunos.tamanho; contador++){
        cout << listaDeAlunos.vetor[contador].nome << ": ";
        for(int contador2=0; contador2 < 3; contador2++){
            cout << listaDeAlunos.vetor[contador].nota.vetor[contador2] << " : ";
        }
        cout << endl;
    }
}
