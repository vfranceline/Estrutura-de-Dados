#include <iostream>
#include "listaOrdenada.hpp"

using namespace std;

listaOrdenada::listaOrdenada(){
    inicio = nullptr;
}

bool listaOrdenada::isEmpty(){
    return (inicio == nullptr);
}

bool listaOrdenada::isFull(){
    Node *newNode;

    try{
        newNode = new Node;
        delete newNode;
        return false;
    } catch (bad_alloc exception){
        return true;
    }
}

void listaOrdenada::push(int item){
    Node *newNode = new Node();

    if (newNode == nullptr){
        cout << "sem memoria \n";
        return;
    }

    newNode->valor = item;

    Node *atual = inicio;
    Node *anterior = inicio;
    
    if (inicio == nullptr){ //se a lista estiver vazia
        inicio = newNode;
        newNode->prox = nullptr;
    } else {
        while (atual != nullptr && atual->valor < item){
            anterior = atual;
            atual = atual->prox;
        }

        if (atual == nullptr){ // novo item é o maior da lista
            anterior->prox = newNode;
            newNode->prox = nullptr;
        } else {
            if (inicio == atual){ //se o novo item for o menor da lista (menor q o inicio)
                newNode->prox = inicio;
                inicio = newNode;
            } else { //novo item no meio da lista
                anterior->prox = newNode;
                newNode->prox = atual;
            }
        }
    }
}

void listaOrdenada::pop(int item){
    if (isEmpty()){
        cout << "lista vazia, não foi possivel remover nenhum elemento";
        return;
    } else {
        Node *atual = inicio;
        Node *anterior = inicio;

        while (atual != nullptr && atual->valor != item)
        {
            anterior = atual;
            atual = atual->prox;
        }
        
        if (atual == nullptr){
            cout << "número não encontrado";
        } else {
            if (atual == inicio){
                inicio = inicio->prox;
            } else {
                anterior->prox = atual->prox;
            }
            delete atual;
        }
    }
}

void listaOrdenada::print(){
    if (isEmpty()) {
        cout << "lista vazia \n";
    } else{
        Node* atual = inicio;
        cout << "[ ";
        while (atual != nullptr) {
            cout << atual->valor << " ";
            atual = atual->prox;
        }
        cout << "]" << endl;
    }
}