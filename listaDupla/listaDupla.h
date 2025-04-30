typedef int TipoItem; //para poder trocar o tipo dos elementos da stack de forma mais facil

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
    void printCrescente();
    void printDecrescente();
};
