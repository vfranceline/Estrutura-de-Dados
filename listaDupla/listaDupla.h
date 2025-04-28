typedef int TipoItem; //para poder trocar o tipo dos elementos da stack de forma mais facil

struct Node2 {
    TipoItem valor;
    Node2 *anterior, *prox;
};

class listaDupla{
    private:
    Node2* inicio;
    Node* fim;
    
    public:
    listaDupla(); //construtor
    ~listaDupla(); //destrutor
    
    bool isEmpty();
    bool isFull();
    void push(TipoItem item);
    TipoItem pop();
    void print();
};
