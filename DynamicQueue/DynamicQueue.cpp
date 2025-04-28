#include <iostream>
#include "DynamicQueue.h"
#include <cstddef> //para o NULL

using namespace std;

//construtor
dynamicQueue::dynamicQueue(){
    inicio = nullptr;
    fim = nullptr;
}

//destrutor
dynamicQueue::~dynamicQueue(){

}

bool dynamicQueue::isEmpty(){
    return (inicio == nullptr);
}

bool dynamicQueue::isFull(){
    Node* novo;
    
    try{
        novo = new Node;
        delete novo;
        return false;

    } catch(bad_alloc exeption){
        return true;
    }
}

void dynamicQueue::push(TipoItem item){
    if (isFull()){
        cout << "sem memoria :/ \n";
    } else {
        Node* novo = new Node;
        novo->valor = item;
        novo->prox = nullptr;

        if (inicio ==  nullptr){
            inicio = novo;
        } else {
            fim->prox = novo;
        }
        fim = novo;
    }

}

TipoItem dynamicQueue::pop(){
    if (isEmpty()){
        cout << "fila vazia \n";
        return 0;
    } else {
        Node* temp;
        temp = inicio;
        inicio = inicio->prox;
        TipoItem item = temp->valor;

        delete temp;
        return item;
    }
}

void dynamicQueue::print(){
    Node* temp = inicio;
    cout << "fila = [ ";

    while (temp != nullptr){
        cout << temp->valor << " ";
        temp = temp->prox;
    }
    cout << "] \n";

}