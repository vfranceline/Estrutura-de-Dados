#include <iostream>

struct NodeD
{
    int valor;
    NodeD *prox;
    NodeD *ant
};

class listaDupla {
    private:
    NodeD *inicio;

    public:
    listaDupla();
    void inserir(int item);
    void retirar(int item);
    void listar();
    void ordenar();
    NodeD* multiplosTres(Node* inicio);
};

listaDupla::listaDupla(){
    inicio = nullptr;
}

// Considerando uma lista duplamente encadeada (dinâmica) contendo 
// números inteiros, escreva uma função, em C++, para eliminar todos os elementos 
// múltiplos de três e retornar uma fila contendo estes elementos (ordenados).

NodeD* head;  // cabeça da lista original

// Remove da lista 'original' todos os nós múltiplos de 3
// e retorna uma nova lista duplamente encadeada contendo esses nós, em ordem crescente.
NodeD* multiplosTres(NodeD*& original) {
    NodeD* listaM3_head = nullptr;  // cabeça da lista de múltiplos de 3
    NodeD* listaM3_tail = nullptr;  // cauda da lista de múltiplos de 3

    NodeD* atual = original;
    while (atual) {
        NodeD* proximo = atual->prox;
        
        if (atual->valor % 3 == 0) {
            // 1) Desanexa 'atual' da lista original
            if (atual->ant)
                atual->ant->prox = atual->prox;
            else
                original = atual->prox;   // removendo a cabeça original

            if (atual->prox)
                atual->prox->ant = atual->ant;

            // isola o nó removido
            atual->ant = atual->prox = nullptr;

            // 2) Insere 'atual' na lista de múltiplos de 3, em ordem
            if (!listaM3_head) {
                // primeira inserção
                listaM3_head = listaM3_tail = atual;
            }
            else {
                // buscar posição de inserção
                NodeD* it = listaM3_head;
                while (it && it->valor < atual->valor) {
                    it = it->prox;
                }
                if (!it) {
                    // inserção no fim
                    listaM3_tail->prox = atual;
                    atual->ant = listaM3_tail;
                    listaM3_tail = atual;
                }
                else {
                    // inserção antes de 'it'
                    atual->prox = it;
                    atual->ant = it->ant;
                    if (it->ant)
                        it->ant->prox = atual;
                    else
                        listaM3_head = atual;  // novo head da lista de múltiplos
                    it->ant = atual;
                }
            }
        }

        atual = proximo;
    }

    return listaM3_head;
}
