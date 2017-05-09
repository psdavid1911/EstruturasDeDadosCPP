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
    No<T>* inicio;
    int tamanho;

    ListaEncadeada(){
        inicio=new No<T>();
        tamanho=0;
    }

    ~ListaEncadeada(){

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

    void apagaPrimeiro(){
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

    void apagaUltimo(){
        if(tamanho == 0)return;
        else{
            No<T> * temp=inicio;
            if(!temp->proximo){
                apagaPrimeiro();
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
            apagaPrimeiro();
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
            apagaUltimo();
            return;
        }
        anterior->proximo=anterior->proximo->proximo;
        delete tempParaDeletar;
        tamanho--;
    }
};


//

//
//    /**
//     * Apaga assim que pega.
//     * @return 
//     */
//    Tipo pega(){
//        Tipo conteudo=inicio->conteudo;
//        apagaPrimeiro();
//        return conteudo;
//    }
//
//