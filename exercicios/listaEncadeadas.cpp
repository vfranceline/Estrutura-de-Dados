#include <iostream>
#include <string>

struct Node
{
    int valor;
    Node *prox;
};

class listaS {
    private:
    Node *inicio;

    public:
    listaS();
    void inserir(int item);
    void retirar(int item);
    void listar();
    void ordenar();
    void removerAntProx(int x);
    void removerRepetidos(Node* inicio);
    Node* mergeListas(Node*A, Node *B);
    Node* imparesPrimos();
    Node* intersecao(Node* A, Node* B);
    void printMaior();
};

listaS::listaS(){
    inicio = nullptr;
}

void listaS::removerRepetidos(Node* inicio) {
    for (Node* i = inicio; i != nullptr; i = i->prox) {
        Node* antJ = i;
        for (Node* j = i->prox; j != nullptr; j = j->prox) {
            antJ = antJ->prox;
            if (i->dado == j->dado) {
                // Remove o nó repetido
                antJ->prox = j->prox;
                delete j;
            }
        }
    }
}

void listaS::removerAntProx(int x){
    if (inicio == nullptr){
        return;
    }

    Node *atual = inicio;
    Node *preAnt = nullptr;
    Node *antecessor = nullptr;

    while (atual != nullptr && atual->valor != x){
        preAnt = antecessor;
        antecessor = atual;
        atual = atual->prox;
    }

    if (atual == nullptr){
        return; //numero não existe
    }

    if(antecessor != nullptr){
        if (preAnt != nullptr){
            preAnt->prox = atual;
        } else{
            inicio = atual;
        }
        delete antecessor;
    }

    if(atual->prox != nullptr){
        Node *sucessor = atual->prox;
        atual->prox = sucessor->prox;
        delete sucessor;
    }
}

Node* listaS::mergeListas(Node* A, Node* B) {
    // 1) Se uma lista for vazia, retorna logo a outra
    if (!A) return B;
    if (!B) return A;

    // 2) Inicializa o head (início) e o tail (cauda) da nova lista
    Node* head = nullptr;
    if (A->codigo < B->codigo) {
        head = A;        // A começa a lista
        A = A->next;     // avança em A
    }
    else if (B->codigo < A->codigo) {
        head = B;        // B começa a lista
        B = B->next;     // avança em B
    }
    else {
        // Se tiver código igual (cenário raro),
        // escolhe A como primeiro e avança ambas
        head = A;
        A = A->next;
        B = B->next;
    }
    Node* tail = head;    // tail aponta sempre para o último nó construído

    // 3) Loop principal: enquanto houver elementos em A e B
    while (A && B) {
        if (A->codigo < B->codigo) {
            tail->next = A;  // anexa A após tail
            A = A->next;     // avança A
        }
        else if (B->codigo < A->codigo) {
            tail->next = B;  // anexa B após tail
            B = B->next;     // avança B
        }
        else {
            // caso de igual: anexa A e avança A e B para evitar duplicata
            tail->next = A;
            A = A->next;
            B = B->next;
        }
        tail = tail->next;   // move tail para o novo último nó
    }

    // 4) Quando uma das listas acabar, anexa o resto da outra:
    //    se A não for nullptr, tail->next = A; senão tail->next = B
    tail->next = (A ? A : B);

    return head;
}

bool ehPrimo(int n){
    if (n < 2) return false;
    for (int i = 3; i*i <= n; i += 2){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

Node* listaS::imparesPrimos(){
    if(inicio == nullptr) return;

    Node *atual = inicio;
    Node *ant = nullptr;
    Node *inicioPrimos = nullptr;
    
    while (atual != nullptr){
        if (atual->valor % 2 != 0 && ehPrimo(atual->valor)){
            Node *novo = atual;
            atual = atual->prox;
            
            if (ant != nullptr){
                ant->prox = atual;
            }
            novo->prox = inicioPrimos;
            inicioPrimos = novo;
        } else{
            ant = atual;
            atual = atual->prox;
        }
    }
    return inicioPrimos;
}

Node* listaS::intersecao(Node*& A, Node*& B){
    if (A == nullptr) return nullptr;
    if (B == nullptr) return nullptr;

    Node *inicio = nullptr, *fim = nullptr;

    for(Node* atualA = A; atualA != nullptr; atualA = atualA->prox){
        for(Node* atualB = B; atualB != nullptr; atualB = atualB->prox){
            if (atualA->valor == atualB->valor){
                Node* novoElemento = atualA;
                if(inicio == nullptr){
                    inicio = novoElemento;
                    fim = inicio;
                } else{
                    fim->prox = novoElemento;
                    fim = novoElemento;
                }
            }
        }
    }    
    return inicio;
}

// 12. Considere  uma  lista  simplesmente  encadeada  na  qual  cada  nó  contém  as 
// seguintes informações: matrícula (tipo inteiro) de um professor, ponteiro para o 
// próximo  nó  dessa  lista  e  um  ponteiro  para  o  primeiro  nó  de  uma  lista  que 
// contém  os  códigos  (tipo  inteiro)  das  disciplinas  lecionadas  por  este  professor. 
// Implemente  uma  função  em  C++  para  imprimir  a  matrícula  do  professor  que 
// leciona mais disciplinas.

void listasS::printMaior(){
    if (professores == nullptr) return;
    Node* atual = professores;
    int maior = -1;
    int profMais = 0;

    while (atual != nullptr)
    {
        Node *aux = atual->diciplinas;
        int cont = 0;
        while (aux!=nullptr)
        {
            cont++;
            aux = aux->prox;
        }
        if (cont > maior){
            maior = cont;
            profMais = atual->matricula;
        }
        atual = atual->prox;
    }

    std::cout << profMais << std::endl;
}
