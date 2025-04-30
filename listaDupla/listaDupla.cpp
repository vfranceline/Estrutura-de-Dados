#include <iostream>
#include "listaDupla.h"

using namespace std;

listaDupla::listaDupla(){
    inicio  = nullptr;
}

    
bool listaDupla::isEmpty(){
    return (inicio == nullptr);
}

bool listaDupla::isFull(){
    Node2 *newNode;
    
    try {
        newNode = new Node2;
        delete newNode;
        return false;
    } catch (bad_alloc exception){
        return true;
    }
}

void listaDupla::push(TipoItem item){
    Node2 *novo, *atual;

    novo = new Node2();
    if (novo == nullptr){
        cout << "sem memoria :/"<< endl;
        return;
    }
    novo->valor = item;

    if (inicio == nullptr){
        novo->anterior = nullptr;
        novo->prox = nullptr;
        inicio = novo;
        return;
    }

    atual = inicio;

    while ((atual->prox != nullptr) && (novo->valor > atual->valor)){
        atual = atual->prox;
    }

    if ((atual->prox == nullptr) && (novo->valor > atual->valor)){
        atual->prox = novo;
        novo->anterior = atual;
        novo->prox = nullptr;
        return;
    } else if ((atual == inicio) && (atual->valor <= novo->valor)){ //antes do inicio
        novo->prox = inicio;
        inicio->anterior = novo;
        novo->anterior = nullptr;
        inicio = novo;
    } else{ //meio
        novo->anterior = atual->anterior;
        atual->anterior->prox = novo;
        novo->prox = atual;
        atual->anterior = novo;
    }

    //TO-DO: lista ordenada simples com sublistas
    //sublistas de pares e impares

    
}

bool listaDupla::pop(TipoItem item){
    if (isEmpty()){
        cout << "lista vazia! \n não foi possivel remover nenhum elemento";
        return false;
    } else {
        Node2 *atual = inicio;
        while ((atual->prox != nullptr) && (atual->valor != item)){
            atual = atual->prox;
        }
        
        if (atual->valor == item){
            atual->anterior->prox = atual->prox; //nn é isso, tem q ter um aux

        } else {
            return false;
        }
    }
}

void listaDupla::print(){
    Node2* atual = inicio;
    while (atual) {
        cout << atual->valor;
        if (atual->prox) cout << " <-> ";
        atual = atual->prox;
    }
    cout << endl;
}

