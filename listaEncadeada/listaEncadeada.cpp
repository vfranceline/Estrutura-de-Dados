#include <iostream>

using namespace std;

struct Node
{
    int valor;
    Node *prox;
};

class listas {
    private:
    Node *inicio;

    public:
    listas();
    void inserir(int item);
    int retirar(int item);
    void listar();
    void ordenar();
    void retirarRepetidos();
    Node *intercalar(Node *x, Node *y);
    void comprimir(Node *inicio);
};

listas::listas(){
    inicio = nullptr;
}

void listas::inserir(int item){
    Node *newNode = new Node();
    Node *aux = inicio;

    //precisa sem a primeira coisa a ser feita, se tentar 
    //manipular o novo nó vazio vai dar segmentation fault
    if (newNode == nullptr){ 
        //sem memoria
        return;
    }

    newNode->valor = item;
    newNode->prox = nullptr;

    if (inicio == nullptr){ //lista vazia
        inicio = newNode;
    } else { //um ou mais elementos na lista
        while (aux->prox != nullptr){
            aux = aux->prox;
        }
        aux->prox = newNode;
    }
}

int listas::retirar(int item){
    Node *aux = inicio;
    Node *ant = inicio;

    if (inicio == nullptr){
        // tá vazia
        return;
    }

    while (aux != nullptr && aux->valor != item)
    {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == nullptr){
        //numero não encotrado
        return;
    } else {
        if (aux == inicio) inicio = inicio->prox;
        else ant->prox = aux->prox;
    }
    delete aux;
        
}

void listas::listar(){
    if (inicio == nullptr){
        return;
    }
    Node *atual = inicio;
    cout << "[ ";

    while (atual != nullptr)
    {
        cout << atual->valor << " ";
        atual = atual->prox;
    }
    cout << "]" << endl;
    
}

void listas::ordenar(){
    Node *novaLista, *ant = nullptr, *atual, *aux;

    novaLista = nullptr; // Nova lista ordenada que será construída
    
    if (inicio == nullptr) return; // Se a lista original estiver vazia, retorna

    // Percorre todos os nós da lista original
    while (inicio != nullptr){
        // Remove o primeiro nó da lista original
        aux = inicio;
        inicio = inicio->prox;

        // Insere o nó removido (aux) na posição correta da nova lista ordenada
        if (novaLista == nullptr){
            // Caso 1: Nova lista está vazia
            novaLista = aux;
            aux->prox = nullptr;
        } else {
            // Caso 2: Procura posição de inserção na nova lista
            atual = novaLista;
            
            // Encontra o primeiro nó cujo valor é maior que o do nó atual
            while (atual != nullptr && atual->valor < aux->valor)
            {
                ant = atual;
                atual = atual->prox;
            }

            if (atual == nullptr){
                // Subcaso 2a: Insere no final da nova lista
                ant->prox = aux;
                aux->prox = nullptr;
            } else {
                if (atual == novaLista){
                    // Subcaso 2b: Insere no início da nova lista
                    aux->prox = atual;
                    novaLista = aux;
                } else {
                    // Subcaso 2c: Insere entre dois nós na lista
                    // (Atenção: Esta implementação contém um erro lógico)
                    aux->prox = atual;
                    // novaLista = aux; // Isso está incorreto, deveria ser ant->prox = aux
                    ant->prox = aux;
                }
            }
        }
    }
    // Atualiza o início da lista original para apontar para a nova lista ordenada
    inicio = novaLista;
}

void listas::retirarRepetidos(){
    Node *novaLista = nullptr; // Nova lista sem repetições
    Node *aux;                 // Nó atual sendo processado
    Node *fim = nullptr;       // Fim da nova lista
    Node *atual;               // Ponteiro para verificação de duplicatas

    if (inicio == nullptr) return; // Lista vazia, nada a fazer

    while (inicio != nullptr) {
        // Remove nó da lista original
        aux = inicio;
        inicio = inicio->prox;

        if (novaLista == nullptr) {
            // Primeiro elemento da nova lista
            novaLista = aux;
            novaLista->prox = nullptr;
            fim = novaLista;
        } else {
            // Verifica se valor já existe na nova lista
            atual = novaLista; // Começa do início da nova lista
            while (atual != nullptr && atual->valor != aux->valor) {
                atual = atual->prox;
            }

            if (atual == nullptr) {
                // Valor NÃO encontrado: adiciona ao final
                fim->prox = aux;
                fim = aux;
                fim->prox = nullptr;
            } else {
                // Valor ENCONTRADO: descarta o nó
                delete aux;
            }
        }
    }
    // Atualiza o início para a nova lista sem repetições
    inicio = novaLista;
}

Node *dynamicQueue::intercalar(Node *x, Node *y){
    Node *z, *fim, *ax, *ay;

    z = nullptr;

    if (x == nullptr){
        z = y;
    } else {
        if(y == nullptr){
            z = x;
        } else {
            while ((x != nullptr) && (y != nullptr)){
                ax = x;
                x = x->prox;
                ay = y;
                y = y->prox;

                ax->prox = ay;
                ay->prox = nullptr;

                if (z == nullptr){
                    z = ax;
                    fim = ay;
                } else{
                    fim->prox = ax;
                    fim->ay; //???????????????????????
                }
            }
            if (x == nullptr){
                if (y == nullptr){
                    return z;
                } else {
                    fim->prox = y;
                }
            } else{
                fim->prox = x;
            }
            return z;
        }
    }
}

void dynamicQueue::comprimir(Node *inicio){
    Node *x, *aux, *atual, *novo, *cont, *novoz;

    x = nullptr;
    if (inicio ==nullptr) return;
    cont = nullptr;
    while (inicio = nullptr){
        if (x == nullptr){
            novo = new Node();
            novo->valor = inicio->valor;
            x = novo;
            
        }
    }
}
