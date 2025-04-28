#include <iostream>
#include "DynamicStack.h"
#include <cstddef> //para o NULL

using namespace std;

//construtor
dynamicStack::dynamicStack(){
    topo = nullptr;
}

//destrutor
dynamicStack::~dynamicStack(){
    Node* temp;

    while (topo != nullptr){
        temp = topo;
        topo = topo->prox;
        delete temp;
    }
} 

bool dynamicStack::isEmpty(){
    return (topo == nullptr);
}

bool dynamicStack::isFull(){
    Node* nodeNovo;

    try{
        nodeNovo = new Node;
        delete nodeNovo;
        return false;

    } catch(bad_alloc exception){
        return true;
    }
}

void dynamicStack::push(TipoItem item){
    if (isFull()){
        cout << "a pilha está cheia! \n não foi possivel inserir o elemento";
    } else{
        Node* nodeNovo = new Node;
        nodeNovo->valor = item;
        nodeNovo->prox = topo;
        topo = nodeNovo;
    }
}

TipoItem dynamicStack::pop(){
    if (isEmpty()){
        cout << "pilha vazia! \n não foi possivel remover nenhum elemento";
        return 0;
    } else {
        Node* temp;
        temp = topo;
        TipoItem item = topo->valor;
        topo = temp->prox;
        delete temp;
        return item;
    }
}

void dynamicStack::print(){ 
    Node* temp = topo;
    cout << "pilha: [ ";

    while (temp != nullptr){
        cout << temp->valor << " ";
        temp = temp->prox;
    }

    cout << "]\n ";
}