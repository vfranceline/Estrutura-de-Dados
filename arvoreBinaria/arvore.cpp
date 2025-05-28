#include <iostream>

struct node{
    int info;
    node *esq, *dir;
};

class arvore{ //BST = Binary Search Tree
    public:
    node* raiz;

    arvore();
    node *inserirRecursiva(node *raiz, int n);
    void inserirIterativo(node *raiz, int n);
    void imprimiremordem(node *raiz);

    void deletarArvore(Node* Noatual);
    Node* obterRaiz();
    bool estavazio();
    bool estacheio();
    void remover(int info);
    void deletarNode(No*& noatual);
    void buscar(int& aluno, bool& busca);
    void imprimirpreordem(No* Noatual);
    void imprimirposordem(No* Noatual);
};

arvore::arvore(){
    raiz = nullptr;
}

void arvore::inserirIterativo(node *raiz, int n){
    node *atual, *pai;
    if (raiz == nullptr){
        raiz = new node();
        if (raiz == nullptr) exit(1);

        raiz->info = n;
        raiz->dir = nullptr;
        raiz->esq = nullptr;

        return;
    }
    atual = raiz;
    while (atual != nullptr){
        pai = atual;
        if (n > atual->info){
            atual = atual->dir;
        } else{
            if (n < atual->info){
                atual = atual->esq;
            }
            else{
                std::cout << "número repetido";
                return;
            }
        }
    }
    
}

node *arvore::inserirRecursiva(node *raiz, int n){
    if (raiz == nullptr){
        raiz = new node();
        if (raiz == nullptr) exit(1);

        raiz->info = n;
        raiz->dir = nullptr;
        raiz->esq = nullptr;

        return raiz;
    }

    if (n > raiz->info){
        raiz->dir = inserirRecursiva(raiz->dir, n);
    } else if (n < raiz->i){
        raiz->esq = inserirRecursiva(raiz->esq, n);
    } else {
        std::cout << "numero repetido";
    }
    return raiz;
    
}

void imprimiremordem(node *raiz){
    if (raiz == nullptr) return;

    imprimiremordem(raiz->esq);
    std::cout << raiz->info << "\n";
    imprimiremordem(raiz->dir);
}