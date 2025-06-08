#include <iostream>

struct node{
    int info;
    node *esq, *dir;
};

class arvore{ //BST = Binary Search Tree
    public:
    node* raiz;

    arvore();
    void inserirIterativo(node *raiz, int n);
    node *inserirRecursiva(node *raiz, int n);
    void imprimiremordem(node *raiz);
    int buscar(node *raiz, int n);
    int contar(node *raiz);
    int contarFolhas(node *raiz);
    void compararSub (node *raiz);
    bool isBinary(node *raiz);
    bool recursivaIsBinary(node *raiz);
    node *deletarNode(node *raiz, int n);
    node *substituir(node *raiz, node *sucessor);
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
    } else if (n < raiz->info){
        raiz->esq = inserirRecursiva(raiz->esq, n);
    } else {
        std::cout << "numero repetido";
    }
    return raiz;
    
}

void arvore::imprimiremordem(node *raiz){
    if (raiz == nullptr) return;

    imprimiremordem(raiz->esq);
    std::cout << raiz->info << "\n";
    imprimiremordem(raiz->dir);
}

int arvore::buscar(node *raiz, int n){
    if (raiz == nullptr) return -1;

    if (raiz->info == n) return raiz->info;

    if (raiz->info >n){
        return buscar(raiz->esq, n);
    } else{
        return buscar(raiz->dir, n);
    }
}

int arvore::contar(node *raiz){
    if (raiz == nullptr) return 0;
    return (1 + contar(raiz->esq + raiz->dir));
}

int arvore::contarFolhas(node *raiz){
    if (raiz == nullptr) return 0;
    if (raiz->esq == nullptr && !raiz->dir) return 1;
    return (contarFolhas(raiz->esq) + contarFolhas(raiz->dir));
    
}
void arvore::compararSub (node *raiz){
    int e, d;
    if (raiz == nullptr) return;

    e = contarFolhas(raiz->esq);
    d = contarFolhas(raiz->dir);

    if (e>d) std::cout << "esquerda maior";
    else{
        if (e<d) std::cout << "direita maior";
        else std::cout << "iguais";
    }
}

bool arvore::isBinary(node *raiz){
    if (raiz == nullptr) return false;

    if (raiz->dir != nullptr && raiz->esq != nullptr){
        return true;
    } else {
        if (raiz->dir == nullptr && raiz->esq == nullptr){
            return true;
        } else {
            return false;
        }
    }
}

bool arvore::recursivaIsBinary(node *raiz){
    if (raiz == nullptr) return false;

    if ((raiz->dir == nullptr && raiz->esq == nullptr) || (raiz->dir != nullptr && raiz->esq != nullptr)){
        return (recursivaIsBinary(raiz->esq) && recursivaIsBinary(raiz->dir))
    } else{
        return false;
    }
}

node *arvore::deletarNode(node *raiz, int n){
    node *aux;
    if (raiz == nullptr) return raiz;
    
    if (n > raiz->info){
        raiz->dir = deletarNode(raiz->dir, n);
    } else {
        if (n < raiz->info){
            raiz->esq = deletarNode(raiz->esq, n);
        } else {
            if (raiz->esq == nullptr){
                aux = raiz;
                raiz = raiz->dir;
                delete aux;
                return raiz;
            } else {
                if (raiz->dir == nullptr){
                    aux = raiz;
                    raiz = raiz->esq;
                    delete aux;
                    return raiz;
                } else {
                    raiz->dir = substituir(raiz, raiz->dir);
                }
            }
        }
    }

    std::cout << "valor nao encontrado" <<endl;
    return raiz;

}

node *arvore::substituir(node *raiz, node *sucessor){
        //sucessor tem que comprir 1 condição, a raiz que aponta a esquerda deve ser nula!
        if(sucessor->esq == nullptr) return nullptr;
        sucessor->esq = substituir(sucessor, sucessor->esq); //busca recursiva
        raiz->info = sucessor->info; // substituindo  
        
        sucesssor = sucessor -> dir;
        delete aux;
    }

int main() {
    arvore minhaArvore;

    // Teste com insercao recursiva
    minhaArvore.raiz = minhaArvore.inserirRecursiva(minhaArvore.raiz, 10);
    minhaArvore.raiz = minhaArvore.inserirRecursiva(minhaArvore.raiz, 5);
    minhaArvore.raiz = minhaArvore.inserirRecursiva(minhaArvore.raiz, 15);
    minhaArvore.raiz = minhaArvore.inserirRecursiva(minhaArvore.raiz, 3);
    minhaArvore.raiz = minhaArvore.inserirRecursiva(minhaArvore.raiz, 4);


    std::cout << "\nImpressao em ordem (Recursiva):\n";
    minhaArvore.imprimiremordem(minhaArvore.raiz);

    // Teste de isBinary
    std::cout << "\nA estrutura atual é uma arvore binaria? ";
    if (minhaArvore.recursivaIsBinary(minhaArvore.raiz))
        std::cout << "Sim\n";
    else
        std::cout << "Nao\n";

    return 0;
}
