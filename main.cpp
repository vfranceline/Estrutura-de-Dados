#include <iostream>

struct Node {
    int info;
    struct Node *prox;
};

class DinamicStack {
private: //em cpp o default é private (em java o default é public)
    Node *topo;
    
public:
    DinamicStack();

    void empilhar (int n);
    int desempilhar ();
    void listar();
};

DinamicStack::DinamicStack(){
    topo = nullptr;
}

void DinamicStack::empilhar(int n) {
    Node *novo = new Node(); // Cria um novo nó
    novo->info = n; // Define o valor do nó
    novo->prox = topo; // O novo nó aponta para o topo atual
    topo = novo; // O topo agora aponta para o novo nó
}

int DinamicStack::desempilhar() {
    if (topo == nullptr) {
        std::cout << "Pilha vazia!" << std::endl;
        return -1; // Retorna -1 se a pilha estiver vazia
    } else {
        Node *remover = topo; // O nó a ser removido é o topo
        int valor = topo->info; // Armazena o valor do topo para retornar
        topo = topo->prox; // O topo agora aponta para o próximo nó
        delete remover; // Libera a memória do nó removido
        return valor; // Retorna o valor do nó removido
    }
}

void DinamicStack::listar() {
    if (topo == nullptr) {
        std::cout << "Pilha vazia!" << std::endl;
    } else {
        Node *atual = topo;
        while (atual != nullptr) {
            std::cout << atual->info << " "; // Imprime o valor do nó
            atual = atual->prox; // Move para o próximo nó
        }
        std::cout << std::endl;
    }
}

int main() {
    DinamicStack pilha;

    // Testando a pilha
    pilha.empilhar(10);
    pilha.empilhar(20);
    pilha.empilhar(30);
    
    std::cout << "Conteúdo da pilha: ";
    pilha.listar(); // Deveria exibir 30 20 10

    std::cout << "Desempilhando: " << pilha.desempilhar() << std::endl; // Deveria exibir 30
    std::cout << "Conteúdo da pilha após desempilhar: ";
    pilha.listar(); // Deveria exibir 20 10

    return 0;
}

/*
int main()
{
    DinamicStack pilha;
    return 0;
    
    void DinamicStack::empilhar(int n){
        Node *novo;
        novo = new Node();
        novo->info =n
        
        if (topo == nullptr){
            novo -> prox = nullptr;
        }
        else{
            //return false;
            novo -> prox = topo;
        }
        
        topo = novo;
    }
    
    int DinamicStack::desempilhar(){
        
        
    }
}
*\