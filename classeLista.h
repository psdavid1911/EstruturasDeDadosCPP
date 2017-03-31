/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   classeLista.h
 * Author: david
 *
 * Created on 30 de Março de 2017, 21:36
 */

#ifndef CLASSELISTA_H
#define CLASSELISTA_H

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

using namespace std;

template <class T> class Lista {
public:
    int tamanho;
    T * vetor;

    Lista() {
        tamanho = 0;
    }

    void adiciona(T valor) {
        T * novoVetor = new T[++tamanho];
        int contador = 0;
        for (contador = 0; contador < tamanho - 1; contador++) {
            novoVetor[contador] = vetor[contador];
        }
        novoVetor[contador] = valor;
        //delete inteiros; // essa opcao da problema mas onde vai liberar a memoria? 
        vetor = novoVetor;
    }

    void imprime() {
        cout << "[";
        int contador = 0;
        while (true) {
            cout << vetor[contador];
            contador++;
            if (contador == tamanho)break;
            cout << ", ";
        }
        cout << "]" << endl;
    }



public:

    void ordena() {
        SelectionSort();
    }

    void inverte() {
        T * novoVetor = new T[tamanho];
        int contadorProgressivo = 0;
        for (int contadorRegressivo = tamanho - 1; contadorRegressivo >= 0; contadorRegressivo--) {
            novoVetor[contadorRegressivo] = vetor[contadorProgressivo];
            contadorProgressivo++;
        }
        vetor = novoVetor;
    }

    /*
     * vetorInteiros & vetorInteiros::operator=(vetorInteiros outro){
        this->inteiros = outro.inteiros;
        this->tamanhoDoVetor = outro.tamanhoDoVetor;
    }*/

    T pega(int posicao) {
        return vetor[posicao];
    }

    /*
     verifica se a lista contem o elemento
     */
    bool existe(T elemento) {
        for (int contador = 0; contador < tamanho; contador++)
            if (elemento == vetor[contador])return true;
        return false;
    }

    /**
     * Esse metodo remove TODAS as ocorrencias do elemento.
     * @param valor
     */
    void remove(T valor) {
        Lista novo;
        for (int contador = 0; contador < tamanho; contador++) {
            if (vetor[contador] == valor) continue;
            else novo.adiciona(vetor[contador]);
        }
        this->vetor = novo.vetor;
        this->tamanho = novo.tamanho;
    }

    void removeIndice(int posicao) {
        Lista novo;
        for (int contador = 0; contador < tamanho; contador++) {
            if (contador == posicao) continue;
            else novo.adiciona(vetor[contador]);
        }
        this->vetor = novo.vetor;
        this->tamanho = novo.tamanho;
    }

    T menor() {
        int menor = vetor[0];
        for (int contador = 1; contador < tamanho; contador++)
            if (menor > vetor[contador]) menor = vetor[contador];
        return menor;
    }

    T maior() {
        int maior = vetor[0];
        for (int contador = 1; contador < tamanho; contador++)
            if (maior < vetor[contador]) maior = vetor[contador];
        return maior;
    }

    /**
     * Os elementos devem estar ordenados antes de se utilizar essa função.
     * @param elemento, que deve ser buscado.
     * @return O índice da posicao do elemento desejado.
     */
//    int buscaBinaria(T elemento, int indiceInicio, int largura) {
//        if (indiceInicio > largura) return -1;
//        int indiceMeio = (largura + indiceInicio) / 2;
//        if (elemento == vetor[indiceMeio]) return indiceMeio;
//        else if (elemento < vetor[indiceMeio]) return buscaBinaria(elemento, indiceInicio + 1, indiceMeio);
//        else if (elemento > vetor[indiceMeio]) return buscaBinaria(elemento, indiceMeio, largura - 1);
//    }

    // x => chave| e => Limite inferior (esquerda) | d => Limite Superior (direita)

    int buscaBinaria(T chave, int limiteInferior, int limiteSuperior) {
        int i = (limiteInferior + limiteSuperior) / 2;
        if (vetor[i] == chave)
            return i;
        if (limiteInferior >= limiteSuperior)
            return -1; // Não foi encontrado
        else
            if (vetor[i] < chave)
            return buscaBinaria(chave, vetor, i + 1, limiteSuperior);
        else
            return buscaBinaria(chave, vetor, limiteInferior, i - 1);
    }

    /**
     * Não foi testada ainda
     * @param indiceInicio
     * @param indiceFim
     * @return 
     */
    Lista sublista(int indiceInicio, int largura) {
        Lista novaLista;
        for (int contador = indiceInicio; contador < largura; contador++)
            novaLista.adiciona(vetor[contador]);
        return novaLista;
    }

    int buscaSequencial(T elemento) {
        for (int contador = 0; contador < tamanho; contador++)
            if (elemento == vetor[contador])return contador;
        return -1;
    }

private:

    void SelectionSort() {
        int min, aux;

        for (int i = 0; i < tamanho - 1; i++) {
            min = i;

            for (int j = i + 1; j < tamanho; j++)
                if (vetor[j] < vetor[min])
                    min = j;

            if (min != i) {
                aux = vetor[min];
                vetor[min] = vetor[i];
                vetor[i] = aux;
            }
        }
    }
};

#endif /* CLASSELISTA_H */

