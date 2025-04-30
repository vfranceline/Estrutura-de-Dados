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
    } else if ((atual == inicio)){ //antes do inicio
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

    //TO-DO: lista ordenada com sublistas
    //sublistas de pares e impares

    
}

void listaDupla::pop(TipoItem item){
    if (isEmpty()){
        cout << "lista vazia! \nnão foi possivel remover nenhum elemento";
        return;
    } else {
        Node2 *atual = inicio;
        while ((atual != nullptr) && (atual->valor != item)){
            atual = atual->prox;
        }
        
        if (atual == nullptr){
            cout << "não existe esse elemento na lista \n";
            return;

        } 
        if ((inicio == atual) && (atual->prox == nullptr)){
            inicio = nullptr;
            return;
        }
        if (inicio == atual){
            inicio = inicio->prox;
            inicio->anterior = nullptr;
        } else {
            if (atual->prox == nullptr){
                atual->anterior->prox = nullptr;
            } else {
                atual->anterior->prox = atual->prox;
                atual->prox->anterior = atual->anterior;
            }
        }
        delete atual;
    }
}

void listaDupla::printCrescente(){
    if (isEmpty()) {
        cout << "não existe essa lista \n";
    } else{
        Node2* atual = inicio;
        cout << "[ ";
        while (atual) {
            cout << atual->valor;
            if (atual->prox) cout << " <-> ";
            atual = atual->prox;
        }
        cout << " ]" << endl;
    }
}

void listaDupla::printDecrescente(){
    Node2* atual = inicio;

    while (atual->prox != nullptr){
        atual = atual->prox;
    }

    cout << "[ ";
    while (atual) {
        cout << atual->valor;
        if (atual->anterior) cout << " <-> ";
        atual = atual->anterior;
    }
    cout << " ]" << endl;
}

