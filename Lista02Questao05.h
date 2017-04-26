#ifndef LISTA02QUESTAO05_H
#define LISTA02QUESTAO05_H

#include "bibliotecas.h"

class RegistroDeAgenda {
public:
    string nome;
    string endereco;
    string telefone;
    string situacao;

    RegistroDeAgenda() {
    }

    RegistroDeAgenda(string nome, string endereco, string telefone, string situacao) {
        this->nome = nome;
        this->endereco = endereco;
        this->telefone = telefone;
        this->situacao = situacao;
    }

    void imprime() {
        cout
                << "["
                << "nome: " << nome
                << ", endereço: " << endereco
                << ", telefone: " << telefone
                << ", situação: " << situacao
                << "]"
                << endl;
    }

    string getEndereco() const {
        return endereco;
    }

    void setEndereco(string endereco) {
        this->endereco = endereco;
    }

    string getNome() const {
        return nome;
    }

    void setNome(string nome) {
        this->nome = nome;
    }

    string getSituacao() const {
        return situacao;
    }

    void setSituacao(string situacao) {
        this->situacao = situacao;
    }

    string getTelefone() const {
        return telefone;
    }

    void setTelefone(string telefone) {
        this->telefone = telefone;
    }

};

class Agenda {
public:
    Lista<RegistroDeAgenda> agenda;

    Agenda() {

    }

    int busca(string nome) {
        for (int posicao = 0; posicao < agenda.tamanho; posicao++)
            if (agenda.vetor[posicao].nome == nome) return posicao;
        return -1;
    }

    void adiciona(string nome, string endereco, string telefone, string situacao) {
        agenda.adiciona(RegistroDeAgenda(nome, endereco, telefone, situacao));
    }

    int tamanho() {
        return agenda.tamanho;
    }

    RegistroDeAgenda registro(int posicao) {
        return agenda.vetor[posicao];
    }

    void imprime() {
        for (int posicao = 0; posicao < agenda.tamanho; posicao++)
            agenda.vetor[posicao].imprime();
    }

    // COM O USUÁRIO

    void promptAdiciona() {
        cout
                << "Escreva respectivamente o nome, o endereço, o telefone, e a situação de um registro da agenda"
                << endl;
        string nome = leString(); // MUITÍSSIMO ESTRANHO.
        string endereco = leString();
        string telefone = leString();
        string situacao = leString();
        adiciona(nome, endereco, telefone, situacao);
    }

    void promptAdiciona5() {
        for (int contador = 0; contador < 5; contador++) {
            cout
                    << "Escreva respectivamente o nome, o endereço, o telefone, e a situação de um registro da agenda"
                    << endl;
            string nome = leString(); // MUITÍSSIMO ESTRANHO.
            string endereco = leString();
            string telefone = leString();
            string situacao = leString();
            adiciona(nome, endereco, telefone, situacao);
        }
    }

    void promptAlterarRegistro() {
        cout << "Quem? ";
        string nomePesquisado = leString();
        cout
                << "Escreva respectivamente o nome, o endereço, o telefone, e a situação de um registro da agenda"
                << endl;
        RegistroDeAgenda* r = agenda.vetor;
        int posicaoDoRegistro = busca(nomePesquisado);
        if (posicaoDoRegistro != -1) {
            r += posicaoDoRegistro;
            r->setNome(leString());
            r->setEndereco(leString());
            r->setTelefone(leString());
            r->setSituacao(leString());
        }
    }

    void promptBusca() {
        cout << "Quem? ";
        string nomePesquisado = leString();
        int posicaoDoRegistro = busca(nomePesquisado);
        RegistroDeAgenda* r = agenda.vetor;
        r += posicaoDoRegistro;
        r->imprime();
    }
};

#endif /* LISTA02QUESTAO05_H */

