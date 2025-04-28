#include <iostream>
#include "listaDuplamente.h"

using namespace std;

listaDupla::listaDupla(){
    inicio  = nullptr;
}

    
bool listaDupla::isEmpty(){
    return (inicio == nullptr);
}

bool listaDupla::isFull(){

}

void listaDupla::push(TipoItem item){
    Node2 *novo, *atual;

    novo = new Node2();
    if (novo == nullptr){
        return;
    }
    novo->valor = n;

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

    if ((atual->prox == nullptr) && (novo->valor > atual->valor)){ //estou enloquecendo aos poucos rapido de mais
        atual->prox = novo;
        novo->anterior = atual;
        novo->prox = nullptr;
        return;
    }

    if (atual == inicio){
        novo->prox = inicio;
        inicio->anterior = novo;
        novo->anterior = nullptr;
        inicio = novo;
        return;
    }

    if(/*ta no meio*/){
        novo->anterior = atual->anterior;
        atual->ant->prox = novo;
        novo->prox = atual;
        atual->ant = novo;
    }

    //exercício: lista ordenada simples com sublistas
    //sublistas de pares e impares (?????????????????????)

    
}
TipoItem listaDupla::pop();
void listaDupla::print();