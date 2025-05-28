typedef int TipoItem; //para poder trocar o tipo dos elementos da stack de forma mais facil
#include <iostream>

using namespace std;

struct Node2 {
    TipoItem valor;
    Node2 *anterior, *prox;
};

class listaDupla{
    private:
    Node2* inicio;
    Node2* fim;
    
    public:
    listaDupla(); //construtor
    
    bool isEmpty();
    bool isFull();
    void push(TipoItem item);
    void pop(TipoItem item);
    void print();
    void eliminarAntProx(int n);
};


listaDupla::listaDupla(){
    inicio = nullptr;
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
    Node2 *novo;

    novo = new Node2();
    if (novo == nullptr){
        cout << "sem memoria :/"<< endl;
        return;
    }
    novo->valor = item;
    novo->prox = nullptr;
    novo->anterior = nullptr;

    if (inicio == nullptr){
        inicio = novo;
        fim = inicio;
        return;
    } else {
        novo->anterior = fim;
        fim->prox = novo;
        fim = novo;
    }

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

void listaDupla::print(){
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

void listaDupla::eliminarAntProx(int n){
    if(inicio == nullptr){
        return;
    }

    Node2 *atual = inicio;

    while (atual != nullptr){
        Node2 *anterior = atual->anterior;
        Node2 *proximo = atual->prox;

        Node2 *proximoAtual = atual->prox;

        if (atual->valor == n){
            if (anterior != nullptr){
                if (anterior->anterior != nullptr){
                    atual->anterior = anterior->anterior;
                    anterior->anterior->prox = atual;
                } else {
                    atual->anterior = nullptr;
                    inicio = atual;
                }

                delete anterior;
            }

            if (proximo != nullptr){
                if (proximo->prox != nullptr){
                    atual->prox = proximo->prox;
                    proximo->prox->anterior = atual;
                } else {
                    atual->prox = nullptr;
                    fim = atual;
                }
                delete proximo;
            }
        }
        atual = proximoAtual;        
    }
}

int main(){
    listaDupla lista;
    int item;
    int opcao;

    cout << "Programa gerador de lista: \n";

    do{
        cout << "digite 0 para parar o programa! \n";
        cout << "digite 1 para inserir um elemento! \n";
        cout << "digite 2 para remover um elemento! \n";
        cout << "digite 3 para imprimir a lista! \n";
        cout << "digite 4 para remover o antecessor e o sucessor de um elemento! \n";


        cin >> opcao;

        if (opcao == 1){
            cout << "digite o elemento a ser inserido ! \n";
            cin >> item;
            lista.push(item);
        } else if (opcao == 2){
            cout << "digite o elemento a ser removido ! \n";
            cin >> item;
            lista.pop(item);
        } else if (opcao == 3){
            lista.print();
        } else if (opcao == 4){
            cout << "digite o elemento para eliminar seu antecessor e sucessor \n";
            cin >> item;
            lista.eliminarAntProx(item);
        }
        
        
    } while (opcao != 0);

    return 0;
}