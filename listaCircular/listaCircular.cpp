#include <iostream>
#include <string>

using namespace std;

struct Node
{
    std::string info;
    Node *anterior, *prox;
};

class listaCircular {
    private:
    Node *inicio;
    Node *fim;
    Node *atual

    public:
    listaCircular();
    void editarAtual(std::string palavra);
    void inserir(std::string palavra);
    void eliminarPalavra (std::string palavra);
    void palavraAnterior();
    void palavraPosterior();
    void printText();
    void printAtual();
};

listaCircular::listaCircular(){
    inicio = nullptr;
    fim = nullptr;
}

void listaCircular::inserir(std::string palavra){
    Node *novo, *aux;

    novo = new Node();
    
    if (novo == nullptr){
        cout << "sem memoria" << endl;
        return;
    }

    novo->info = palavra;
    aux = inicio;

    if (inicio == nullptr){
        novo->prox = novo;
        novo->anterior = novo;
        inicio = novo;
    } else {
        novo->prox = inicio;
        inicio->anterior = novo;
        fim->prox = novo;
        novo->anterior = fim;
        inicio->prox = novo;     
    }

    fim = novo;
}

void listaCircular::printText(){
    Node *atual = inicio;
    cout << "lista circular = [";

    while(atual->prox != inicio){
        cout << atual->info << " ";
        atual = atual->prox;
    }
    cout << "] \n" << endl;
}

void listaCircular::printAtual(){
    Node *a
}