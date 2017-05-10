#include <iostream>
using namespace std;

template <typename T> struct No{
    T conteudo;
    No * proximo;

    No(){
        proximo=0;
    }

    No(T conteudo){
        this->conteudo=conteudo;
        proximo=0;
    }

    No(T conteudo, No * proximo){
        this->conteudo=conteudo;
        this->proximo=proximo;
    }
};

template <typename T> struct ListaEncadeada{
    No<T> * inicio;
    int tamanho;

    ListaEncadeada(){
        inicio=new No<T>();
        tamanho=0;
    }

    ~ListaEncadeada(){
        limpa();
    }

    void adicionaAoInicio(T conteudo){
        if(tamanho == 0) inicio->conteudo=conteudo;
        else{
            No<T> * temp=new No<T>(inicio->conteudo, inicio->proximo);
            inicio->conteudo=conteudo;
            inicio->proximo=temp;
        }
        tamanho++;
    }

    void adicionaAoFinal(T conteudo){
        if(tamanho == 0) inicio->conteudo=conteudo;
        else{
            No<T> * tempInicio=inicio;
            No<T> * temp=new No<T>(conteudo);
            while(tempInicio->proximo != 0) tempInicio=tempInicio->proximo; // move-se ate uma unidade antes do ultimo
            tempInicio->proximo=temp; // O que era null vira o novo elemento criado
        }
        tamanho++;
    }

    /**
     * Se nao existe qualquer dos elementos não faz nada
     */
    void adicionaEntre(T conteudo, T valor1, T valor2){
        No<T> * tempInicio=inicio;
        while(tempInicio){
            // Se esta ao meio
            if(tempInicio->conteudo == valor1){
                adicionaApos(conteudo, tempInicio);
                return;
            }
            if(tempInicio->conteudo == valor2){
                adicionaApos(conteudo, tempInicio);
                return;
            }
            tempInicio=tempInicio->proximo;
        }
    }

    void imprime(){
        No<T> * temp=inicio;
        while(temp){
            cout << "Char:" << temp->conteudo << "| Prox: " << temp->proximo << endl;
            temp=temp->proximo;
        }
        cout << "Tamanho:: " << tamanho << endl << endl;
    }

    void removePrimeiro(){
        if(tamanho == 1){
            T vazio; // ponteiro vazio ( GAMBIARRA -.- )
            inicio->conteudo=vazio;
            tamanho--;
        }
        if(tamanho == 0) return; // Contribui para a instrucao acima
        else{
            No<T> * temp=inicio;
            inicio=inicio->proximo;
            delete temp;
            tamanho--;
        }
    }

    void removeUltimo(){
        if(tamanho == 0)return;
        else{
            No<T> * temp=inicio;
            if(!temp->proximo){
                removePrimeiro();
                return;
            }
            while(temp->proximo->proximo) temp=temp->proximo; // move-se ate uma unidade antes do ultimo
            No<T> * tempParaApagar=temp->proximo;
            temp->proximo=0;
            delete tempParaApagar;
            tamanho--;
        }
    }

    bool contem(T conteudo){
        No<T> * temp=inicio;
        while(temp->proximo)
            if(temp->conteudo == conteudo)return true;
            else temp=temp->proximo;
        return false;
    }

    void remove(T elemento){
        No<T> * temp=inicio;
        if(temp->conteudo == elemento){
            removePrimeiro();
            return;
        }
        while(temp->proximo){
            if(temp->proximo->conteudo == elemento){
                removeProximoDepoisDe(temp);
                return;
            }
            temp=temp->proximo;
        }
    }

    bool estaVazia(){
        return tamanho == 0;
    }

    bool naoEstaVazia(){
        return !estaVazia();
    }

    /**
     * Não foi testada ainda
     * @return 
     */
    T pega(int indice){
        if(indice >= tamanho || indice < 0){// 0 1
            T vazio;
            return vazio;
        }
        No<T> * enderecoDoIndice=inicio;
        int contador=0;
        while(contador != indice){//2 2
            contador++;
            enderecoDoIndice=enderecoDoIndice->proximo;
        }
        return enderecoDoIndice->conteudo;
    }

    T pegaPrimeiro(){
        return inicio->conteudo;
    }

    /**
     * Não é eficiente na execução, mas economiza memória RAM
     */
    void limpa(){
        for(int i=0; i < tamanho; i++){
            removePrimeiro();
        }
    }

    void trocaNos(T no1, T no2){
        if(contem(no1) && contem(no2)){
            No<T> * indice1=inicio;
            while(indice1->conteudo != no1) indice1=indice1->proximo;
            No<T> * indice2=inicio;
            while(indice2->conteudo != no2) indice2=indice2->proximo;
            // troca
            T temp=indice1->conteudo;
            indice1->conteudo=indice2->conteudo;
            indice2->conteudo=temp;
        }else return;
    }

    void SelectionSort(){
        int min, aux;
        for(int i=0; i < tamanho - 1; i++){
            min=i;
            for(int j=i + 1; j < tamanho; j++)
                if(pega(j) < pega(min))
                    min=j;
            if(min != i)
                trocaNos(pega(min), pega(i));
        }
    }

    void ordena(){
        SelectionSort();
    }

private:

    void adicionaApos(T conteudo, No<T> * endereco){
        No<T> * temp=new No<T>(conteudo);
        temp->proximo=endereco->proximo;
        endereco->proximo=temp;
        tamanho++;
    }

    void removeProximoDepoisDe(No<T> * anterior){
        No<T> * tempParaDeletar=anterior->proximo;
        if(!anterior->proximo->proximo){
            removeUltimo();
            return;
        }
        anterior->proximo=anterior->proximo->proximo;
        delete tempParaDeletar;
        tamanho--;
    }
};

void teste(){
    ListaEncadeada<int> * l=new ListaEncadeada<int>();
    l->adicionaAoFinal(4);
    l->adicionaAoFinal(5);
    l->adicionaAoFinal(1);
    l->adicionaAoFinal(7);
    l->adicionaAoFinal(2);
    l->ordena();
    l->imprime();
}