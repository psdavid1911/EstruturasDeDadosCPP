#pragma once

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

#include "funcoesAuxiliares.h"

using namespace std;

template <class T> class Matriz{
public:
    T * matriz;
    int numeroDeLinhas;
    int numeroDeColunas;

    Matriz(){

    }

    Matriz(int const numeroDeLinhas, int const numeroDeColunas){
        this->numeroDeLinhas=numeroDeLinhas;
        this->numeroDeColunas=numeroDeColunas;
        matriz=new T[numeroDeLinhas * numeroDeColunas];

    }

    Matriz(int tamanhoDaMatrizQuadrada){
        this->numeroDeLinhas=tamanhoDaMatrizQuadrada;
        this->numeroDeColunas=tamanhoDaMatrizQuadrada;
        matriz=new T[numeroDeLinhas * numeroDeColunas];
    }

    void adiciona(int linha, int coluna, int valor){
        matriz[linha * numeroDeColunas + coluna]=valor;
    }

    Matriz<T> operator*(const Matriz<T>& right) const{
        if(this->numeroDeColunas != right.numeroDeLinhas) return Matriz<T>(*this);
        Matriz<T> result(this->numeroDeLinhas, right.numeroDeColunas);
        for(int linha=0; linha < result.numeroDeLinhas; linha++){
            for(int coluna=0; coluna < result.numeroDeColunas; coluna++){
                T acumulador=0;
                for(int contadorInterno=0; contadorInterno < this->numeroDeColunas; contadorInterno++){
                    acumulador+=(this->matriz[linha * numeroDeColunas + contadorInterno] * right.matriz[contadorInterno * right.numeroDeColunas + coluna]);
                }
                result.matriz[linha * result.numeroDeColunas + coluna]=acumulador;
            }
        }
        return result;
    }

    Matriz<T> operator+(const Matriz<T>& right) const{
        if(this->numeroDeColunas != right.numeroDeColunas || this->numeroDeLinhas != right.numeroDeLinhas)return Matriz<T>(*this);
        Matriz<T> result(*this); // Fazer uma cópia de mim mesmo.
        for(int linha=0; linha < this->numeroDeLinhas; linha++){
            for(int coluna=0; coluna < this->numeroDeColunas; coluna++){
                result.matriz[linha * numeroDeColunas + coluna]=this->matriz[linha * numeroDeColunas + coluna] + right.matriz[linha * numeroDeColunas + coluna];
            }
        }
        return result;
    }

    Matriz<T>& operator+=(const Matriz<T>& right){
        if(this->numeroDeColunas != right.numeroDeColunas || this->numeroDeLinhas != right.numeroDeLinhas)return *this;
        for(int linha=0; linha < this->numeroDeLinhas; linha++)
            for(int coluna=0; coluna < this->numeroDeColunas; coluna++)
                this->matriz[linha * numeroDeColunas + coluna]+=right.matriz[linha * numeroDeColunas + coluna];
        return *this;
    }

    Matriz<T> operator-(const Matriz<T>& right) const{
        if(this->numeroDeColunas != right.numeroDeColunas || this->numeroDeLinhas != right.numeroDeLinhas)return Matriz(*this);
        Matriz<T> result(*this); // Fazer uma cópia de mim mesmo.
        for(int linha=0; linha < this->numeroDeLinhas; linha++){
            for(int coluna=0; coluna < this->numeroDeColunas; coluna++){
                result.matriz[linha * numeroDeColunas + coluna]=this->matriz[linha * numeroDeColunas + coluna] - right.matriz[linha * numeroDeColunas + coluna];
            }
        }
        return result;
    }

    Matriz<T>& operator-=(const Matriz<T>& right){
        if(this->numeroDeColunas != right.numeroDeColunas || this->numeroDeLinhas != right.numeroDeLinhas)return *this;
        for(int linha=0; linha < this->numeroDeLinhas; linha++)
            for(int coluna=0; coluna < this->numeroDeColunas; coluna++)
                this->matriz[linha * numeroDeColunas + coluna]-=right.matriz[linha * numeroDeColunas + coluna];
        return *this;
    }

    Matriz<T>& operator--(){
        for(int linha=0; linha < this->numeroDeLinhas; linha++)
            for(int coluna=0; coluna < this->numeroDeColunas; coluna++)
                this->matriz[linha * numeroDeColunas + coluna]--;
        return *this;
    }

    Matriz<T> operator--(int){ // POSFIXADO
        Matriz<T> result(*this);
        for(int linha=0; linha < this->numeroDeLinhas; linha++)
            for(int coluna=0; coluna < this->numeroDeColunas; coluna++)
                this->matriz[linha * numeroDeColunas + coluna]--;
        return result;
    }

    Matriz<T>& operator++(){
        for(int linha=0; linha < this->numeroDeLinhas; linha++)
            for(int coluna=0; coluna < this->numeroDeColunas; coluna++)
                this->matriz[linha * numeroDeColunas + coluna]++;
        return *this;
    }

    Matriz<T> operator++(int){ // POSFIXADO
        Matriz<T> result(*this);
        for(int linha=0; linha < this->numeroDeLinhas; linha++)
            for(int coluna=0; coluna < this->numeroDeColunas; coluna++)
                this->matriz[linha * numeroDeColunas + coluna]++;
        return result;
    }

    void imprime(){
        for(int linha=0; linha < this->numeroDeLinhas; linha++){
            for(int coluna=0; coluna < this->numeroDeColunas; coluna++)
                cout << matriz[linha * numeroDeColunas + coluna] << "   ";
            cout << endl;
        }
        cout << endl;
    }

    // PROMPTS

    /**
     * Somente inteiros
     */
    void promptLeituraTodasAsPosicoes(){
        for(int linha=0; linha < this->numeroDeLinhas; linha++){
            for(int coluna=0; coluna < this->numeroDeColunas; coluna++){
                adiciona(linha, coluna, leInteiro());
            }
        }
    }

};
