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

int main()
{
    DinamicStack pilha;
    return 0;
    
    void DinamicStack::empilhar(int n){
        Node *novo;
        novo = new Node();
        
        if (topo == nullptr){
            novo -> prox = nullptr;
        }
        else{
            //return false;
            novo -> prox = topo;
        }
        
        topo = novo;
    }
}
