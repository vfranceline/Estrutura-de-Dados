typedef int TipoItem; //para poder trocar o tipo dos elementos da stack de forma mais facil

struct Node {
    TipoItem valor;
    Node* prox;
};

class dynamicStack{
    private:
    Node* topo;
    
    public:
    dynamicStack(); //construtor
    ~dynamicStack(); //destrutor

    bool isEmpty();
    bool isFull();
    void push(TipoItem item);
    TipoItem pop();
    void print();
};