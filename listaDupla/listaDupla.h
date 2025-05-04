typedef int TipoItem; //para poder trocar o tipo dos elementos da stack de forma mais facil

struct Node2 {
    TipoItem valor;
    Node2 *anterior, *prox;
};

class listaDupla{
    private:
    Node2* inicio;
    // Node2* fim; //não estamos usando
    Node2* pares;
    Node2* impares;

    void pushImpar(TipoItem item);
    void pushPar(TipoItem item);
    void popSublistas(Node2*& sublista, TipoItem item);
    
    public:
    listaDupla(); //construtor
    
    bool isEmpty();
    bool isFull();
    void push(TipoItem item);
    
    void pop(TipoItem item);
    void printPares();
    void printImpares();
    void printCrescente();
    void printDecrescente();

};
