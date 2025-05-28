struct Node
{
    int valor;
    Node *prox;
};

class listaOrdenada
{
    private:
    Node  *inicio;

    public:
    listaOrdenada();
    bool isEmpty();
    bool isFull();
    void push(int item);
    void pop(int item);
    void print();
    Node* ordena(Node* inicio);
};

