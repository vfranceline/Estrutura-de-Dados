#include <iostream>
#include "listaDupla.h"

using namespace std;

listaDupla::listaDupla(){
    inicio = nullptr;
    pares = nullptr;
    impares = nullptr;
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

    // if (item%2 == 0){
    //     pushPar(item);
    // } else {
    //     pushImpar(item);
    // }

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
        // if (item%2 == 0){
        //     popSublistas(pares, item);
        // } else {
        //     popSublistas(impares, item);
        // }
    }
}

void listaDupla::pushImpar(TipoItem item){
    Node2 *novo, *atual;

    novo = new Node2();
    if (novo == nullptr){
        cout << "sem memoria :/"<< endl;
        return;
    }
    novo->valor = item;

    if (impares == nullptr){
        novo->anterior = nullptr;
        novo->prox = nullptr;
        impares = novo;
        return;
    }

    atual = impares;

    while ((atual->prox != nullptr) && (novo->valor > atual->valor)){
        atual = atual->prox;
    }

    if ((atual->prox == nullptr) && (novo->valor > atual->valor)){
        atual->prox = novo;
        novo->anterior = atual;
        novo->prox = nullptr;
        return;
    } else if ((atual == impares)){ //antes do inicio
        novo->prox = impares;
        impares->anterior = novo;
        novo->anterior = nullptr;
        impares = novo;
    } else{ //meio
        novo->anterior = atual->anterior;
        atual->anterior->prox = novo;
        novo->prox = atual;
        atual->anterior = novo;
    }
}

void listaDupla::pushPar(TipoItem item){
    Node2 *novo, *atual;

    novo = new Node2();
    if (novo == nullptr){
        cout << "sem memoria :/"<< endl;
        return;
    }
    novo->valor = item;

    if (pares == nullptr){
        novo->anterior = nullptr;
        novo->prox = nullptr;
        pares = novo;
        return;
    }

    atual = pares;

    while ((atual->prox != nullptr) && (novo->valor > atual->valor)){
        atual = atual->prox;
    }

    if ((atual->prox == nullptr) && (novo->valor > atual->valor)){
        atual->prox = novo;
        novo->anterior = atual;
        novo->prox = nullptr;
        return;
    } else if ((atual == pares)){ //antes do inicio
        novo->prox = pares;
        pares->anterior = novo;
        novo->anterior = nullptr;
        pares = novo;
    } else{ //meio
        novo->anterior = atual->anterior;
        atual->anterior->prox = novo;
        novo->prox = atual;
        atual->anterior = novo;
    }
}

void listaDupla::popSublistas(Node2*& inicioSublista, TipoItem item){
    Node2* atual = inicioSublista;

    while((atual != nullptr) && (atual->valor != item)){
        atual = atual->prox;
    }
    if(atual == nullptr){
        cout << "não exite esse elemento \n";
        return;
    }
    if (atual == inicioSublista && atual->prox == nullptr){
        //se o elemento a ser removido for o primeiro e unico na lista
        inicioSublista = nullptr;
        return;
    }
    if (inicioSublista == atual){
        //se o elemento a ser removido for o primeiro na lista
        inicioSublista = inicioSublista->prox;
        inicioSublista->anterior = nullptr;
    } else {
        if (atual->prox == nullptr){
            //se o elemento a ser removido for o ultimo da lista
            atual->anterior->prox = nullptr;
        } else {
            atual->anterior->prox = atual->prox;
            atual->prox->anterior = atual->anterior;
        }
    }
    delete atual;
}

void listaDupla::printCrescente(){
    if (isEmpty()) {
        cout << "lista vazia \n";
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

void listaDupla::printPares(){
    Node2* atual = pares;
    cout << "Pares: [ ";
    while (atual) {
        cout << atual->valor;
        if (atual->prox) cout << " <-> ";
        atual = atual->prox;
    }
    cout << " ]\n";
}

void listaDupla::printImpares(){
    Node2* atual = impares;
    cout << "Impares: [ ";
    while (atual) {
        cout << atual->valor;
        if (atual->prox) cout << " <-> ";
        atual = atual->prox;
    }
    cout << " ]\n";
}
