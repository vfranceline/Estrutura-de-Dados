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

    public:
    listaCircular();
    void editarAtual(std::string palavra);
    void inserir(std::string palavra);
    void eliminarPalavra (std::string palavra);
    void palavraAnterior();
    void palavraPosterior();
    void printText();
};

listaCircular::listaCircular(){
    inicio = nullptr;
}

void listaCircular::inserir(std::string palavra){
    Node *novo, *atual;

    novo = new Node();
    
    if (novo == nullptr){
        cout << "sem memoria" << endl;
        return;
    }

    novo->info = palavra;
    atual = inicio;

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

}