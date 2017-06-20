#pragma once

#include "funcoesAuxiliares.h"

struct sitaucaoDoNo{
    bool visitado=false;
};

template <typename T> struct GrafoIndirecionado{
    Matriz<T> *arestas;
    sitaucaoDoNo *statusDe;

    GrafoIndirecionado(int nNos){
        arestas=new Matriz<T>(nNos);
        statusDe=new sitaucaoDoNo[nNos];
    }

    ListaEncadeada<T> *buscaCaminho(int noOrigem, int noMeta){
        ListaEncadeada<int> *resultado=new ListaEncadeada<int>, *resultadoParcial=new ListaEncadeada<int>;
        int valorDeCorte=999;
        buscaProfundidade(--noOrigem, --noMeta, 0, resultadoParcial, resultado, valorDeCorte); // 99 arbitrário
        return resultado;
    }

    void adicionaAresta(int no1, int no2, T pesoDaAresta){
        arestas->adiciona(--no1, --no2, pesoDaAresta);
        arestas->adiciona(no2, no1, pesoDaAresta);
    }

    void removeAresta(int no1, int no2){
        arestas->adiciona(--no1, --no2, 0);
        arestas->adiciona(no2, no1, 0);
    }

    //    void imprime(int tDaColuna){
    //        cout << "Tamanho:\n" << arestas->numeroDeLinhas << "\nMatriz de adjascencias:\n";
    //        arestas->imprime(tDaColuna);
    //    }

    /**
     * Precisa ser um float para continuar
     * @param tamanhoDaColuna
     */
    void imprime(int tDaColuna){ // tamanho da coluna
        ostringstream os;
        os << "%" << tDaColuna << "i";
        const char * temp=os.str().c_str();
        // cabecalho
        printf("(I = índices)\n");
        printf("%s", "I|");
        for(int coluna=0; coluna < arestas->numeroDeColunas; coluna++)printf(temp, coluna + 1);
        printf("\n--");
        for(int coluna=0; coluna < arestas->numeroDeColunas * tDaColuna; coluna++)printf("-");
        cout << endl;
        // ------------
        for(int linha=0; linha < arestas->numeroDeLinhas; linha++){
            printf("%i|", linha + 1);
            for(int coluna=0; coluna < arestas->numeroDeColunas; coluna++)
                printf(temp, arestas->matriz[linha * arestas->numeroDeColunas + coluna]); //cout << matriz[linha * numeroDeColunas + coluna] << "   ";
            cout << endl;
        }
        cout << endl;
    }

private:

    void buscaProfundidade(int noOrigem, int noMeta, int somaAtual, ListaEncadeada<int> *resultadoParcial, ListaEncadeada<int> *resultado, int &valorDeCorte){ // entra soma sempre 0
        cout << "somaAtual: " << somaAtual << "  valorDeCorte:" << valorDeCorte << endl;
        resultado->imprime();
        if(somaAtual > valorDeCorte){
            printf("\nvoltei\n");
            return;
        }// cutoff, corte da arvofre de possibilidades
        else if(noOrigem == noMeta){ // encontrou a meta, faz backtrack, adiciona o resultado + caminho
            valorDeCorte=somaAtual; // muda o valor de corte para aumentar as chances de realiza-lo
            resultadoParcial->adicionaAoFinal(noOrigem + 1); // acrescenta no à lista de nos que esta navegando
            resultadoParcial->adicionaAoInicio(somaAtual);
            resultado->inicio=resultadoParcial->copia()->inicio;
            resultadoParcial->removePrimeiro(); // Limpa o resultado
            return;
        }else
            for(int noDestino=0; noDestino < arestas->numeroDeLinhas; noDestino++){ //navega todos os nos adjascentes
                if(arestaExiste(noOrigem, noDestino) && statusDe[noDestino].visitado == false){ // se ele vai visitar, se a aresta existe ...
                    resultadoParcial->adicionaAoFinal(noOrigem + 1); // acrescenta no à lista de nos que esta navegando
                    statusDe[noOrigem].visitado=true;
                    buscaProfundidade(noDestino, noMeta, somaAtual + pegaPeso(noOrigem, noDestino), resultadoParcial, resultado, valorDeCorte); // vai somando ate chegar na meta
                    statusDe[noOrigem].visitado=false;
                    resultadoParcial->removeUltimo(); // Depois de ter buscado e voltado, a busca ja nao importa mais e é removida, continua buscando...
                }
            }// percorreu todos ou esse noOrigem É TERMINAL // faz backtrack e continua ou acaba;    

    }

    int pegaPeso(int no1, int no2){
        return arestas->pega(no1, no2);
    }

    bool arestaExiste(int x, int y){
        return arestas->pega(x, y) != 0;
    }
};