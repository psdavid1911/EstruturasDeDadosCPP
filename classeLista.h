#pragma once
#include "bibliotecas.h"

template <class T> class Lista{
public:
    int tamanho;
    T * vetor;

    Lista(){
        tamanho=0;
    }

    /**
     * Adiciona sempre ao final...
     * @param valor
     */
    void adiciona(T valor){
        T * novoVetor=new T[++tamanho];
        int contador=0;
        for(contador=0; contador < tamanho - 1; contador++){
            novoVetor[contador]=vetor[contador];
        }
        novoVetor[contador]=valor;
        vetor=novoVetor;
    }

    void imprime(){
        if(estaVazia()) return;
        cout << "[";
        int contador=0;
        while(true){
            cout << vetor[contador];
            contador++;
            if(contador == tamanho)break;
            cout << ", ";
        }
        cout << "]" << endl;
    }

    bool estaVazia(){
        if(tamanho <= 0) return true;
        else return false;
    }

    bool naoEstaVazia(){
        return !estaVazia();
    }

    /**
     * Método selection sort
     */
    void ordena(){
        SelectionSort();
    }

    void inverte(){
        T * novoVetor=new T[tamanho];
        int contadorProgressivo=0;
        for(int contadorRegressivo=tamanho - 1; contadorRegressivo >= 0; contadorRegressivo--){
            novoVetor[contadorRegressivo]=vetor[contadorProgressivo];
            contadorProgressivo++;
        }
        vetor=novoVetor;
    }

    /*
     * vetorInteiros & vetorInteiros::operator=(vetorInteiros outro){
        this->inteiros = outro.inteiros;
        this->tamanhoDoVetor = outro.tamanhoDoVetor;
    }*/

    T pega(int posicao){
        return vetor[posicao];
    }

    /*
     verifica se a lista contem o elemento
     */
    bool existe(T elemento){
        for(int contador=0; contador < tamanho; contador++)
            if(elemento == vetor[contador])return true;
        return false;
    }

    /**
     * Esse metodo remove TODAS as ocorrencias do elemento.
     * @param valor
     */
    void remove(T valor){
        Lista novo;
        if(!existe(valor))return;
        for(int contador=0; contador < tamanho; contador++){
            if(vetor[contador] == valor) continue;
            else novo.adiciona(vetor[contador]);
        }
        this->vetor=novo.vetor;
        this->tamanho=novo.tamanho;
    }

    void removeIndice(int posicao){
        Lista novo;
        if(posicaoNaoExiste(posicao)) return;
        for(int contador=0; contador < tamanho; contador++){
            if(contador == posicao) continue;
            else novo.adiciona(vetor[contador]);
        }
        this->vetor=novo.vetor;
        this->tamanho=novo.tamanho;
    }

    bool posicaoExiste(int posicao){
        if(tamanho <= 0 && posicao >= tamanho) return false;
        return true;
    }

    bool posicaoNaoExiste(int posicao){
        return !posicaoExiste(posicao);
    }

    T menor(){
        int menor=vetor[0];
        for(int contador=1; contador < tamanho; contador++)
            if(menor > vetor[contador]) menor=vetor[contador];
        return menor;
    }

    T maior(){
        int maior=vetor[0];
        for(int contador=1; contador < tamanho; contador++)
            if(maior < vetor[contador]) maior=vetor[contador];
        return maior;
    }

    int buscaBinaria(T chave, int limiteInferior, int limiteSuperior){
        int i=(limiteInferior + limiteSuperior) / 2;
        if(vetor[i] == chave)
            return i;
        if(limiteInferior >= limiteSuperior)
            return -1; // Não foi encontrado
        else
            if(vetor[i] < chave)
            return buscaBinaria(chave, i + 1, limiteSuperior);
        else
            return buscaBinaria(chave, limiteInferior, i - 1);
    }

    /**
     * Não foi testada ainda
     * @param indiceInicio
     * @param indiceFim
     * @return 
     */
    Lista sublista(int indiceInicio, int largura){
        Lista novaLista;
        for(int contador=indiceInicio; contador < largura; contador++)
            novaLista.adiciona(vetor[contador]);
        return novaLista;
    }

    int buscaSequencial(T elemento){
        for(int contador=0; contador < tamanho; contador++)
            if(elemento == vetor[contador])return contador;
        return -1;
    }

    void limpa(){
        tamanho=0;
        vetor=new T[++tamanho];
    }

private:

    void SelectionSort(){
        int min, aux;

        for(int i=0; i < tamanho - 1; i++){
            min=i;

            for(int j=i + 1; j < tamanho; j++)
                if(vetor[j] < vetor[min])
                    min=j;

            if(min != i){
                aux=vetor[min];
                vetor[min]=vetor[i];
                vetor[i]=aux;
            }
        }
    }
};
