#include <iostream>

struct Node{
    int info;
    Node* left;
    Node* right;
};

class arvoreBinaria{ //BST = Binary Search Tree
    private:
    Node* raiz;

    public:
    arvoreBinaria();
    void deletarArvore(Node* Noatual);
    Node* obterRaiz();
    bool estavazio();
    bool estacheio();
    void inserir(int info);
    void remover(int info);
    void deletarNode(No*& noatual);
    void buscar(int& aluno, bool& busca);
    void imprimirpreordem(No* Noatual);
    void imprimiremordem(No* Noatual);
    void imprimirposordem(No* Noatual);
};

arvoreBinaria::arvoreBinaria() // construtor
{
    raiz = NULL;
}

void arvoreBinaria::deletarArvore(No* Noatual)
{
    if (Noatual != NULL){
        deletarArvore(Noatual->filhoesquerda);

        deletarArvore(Noatual->filhodireita);

        delete Noatual;
    }
}

No* arvoreBinaria::obterRaiz()
{
    return raiz;
}

bool arvoreBinaria::estavazio()
{
    return (raiz == NULL);
}

bool arvoreBinaria::estacheio()
{
    try{
        No* temp = new No;
        delete temp;
        return false;
    } catch(bad_alloc exception){
        return true;
    }
}

void arvoreBinaria::inserir(int info)
{
    if (estacheio()){
        cout << "A Arvore esta cheia!\n";
        cout << "Nao foi possivel inserir este elemento!\n";
    } else{
        No* NoNovo = new No;
        NoNovo->aluno = aluno;
        NoNovo->filhodireita = NULL;
        NoNovo->filhoesquerda = NULL;
        if (raiz == NULL){
            raiz = NoNovo;
        } else{
            No* temp = raiz;
            while (temp != NULL){
                if (aluno.obterRa() < temp->aluno.obterRa()){
                    if (temp->filhoesquerda == NULL){
                        temp->filhoesquerda = NoNovo;
                        break;
                    } else{
                        temp = temp->filhoesquerda;
                    }
                } else{
                    if (temp->filhodireita == NULL){
                        temp->filhodireita = NoNovo;
                        break;
                    } else{
                        temp = temp->filhodireita;
                    }
                }
            }
        }
    }
}

void arvoreBinaria::remover(int info)
{
    removerbusca(info, raiz);
}

void arvoreBinaria::removerbusca(int info, No*& noatual)
{
    if (info.obterRa() < noatual->info.obterRa()){
        removerbusca(info, noatual->filhoesquerda);
    } else if (info.obterRa() > noatual->info.obterRa()){
        removerbusca(info, noatual->filhodireita);
    } else{
        deletarNo(noatual);
    }
}

void arvoreBinaria::deletarNo(No*& noatual)
{
    No* temp = noatual;
    if (noatual->filhoesquerda == NULL){
        noatual = noatual->filhodireita;
        delete temp;
    } else if (noatual->filhodireita == NULL){
        noatual = noatual->filhoesquerda;
        delete temp;
    } else{
        int AlunoSucessor;
        obterSucessor(AlunoSucessor, noatual);
        noatual->aluno = AlunoSucessor;
        removerbusca(AlunoSucessor, noatual->filhodireita);
    }
}

void arvoreBinaria::obterSucessor(int& AlunoSucessor, No* temp)
{
    temp = temp->filhodireita;
    while (temp->filhoesquerda != NULL){
        temp = temp->filhoesquerda;
    }
    AlunoSucessor = temp->aluno;
}

void arvoreBinaria::buscar(int& aluno, bool& busca)
{
    busca = false;
    No* noatual = raiz;
    while (noatual != NULL){
        if (aluno.obterRa() < noatual->aluno.obterRa()){
            noatual = noatual->filhoesquerda;
        } else if (aluno.obterRa() > noatual->aluno.obterRa()){
            noatual = noatual->filhodireita;
        } else{
            busca = true;
            aluno = noatual->aluno;
            break;
        }
    }
}

void arvoreBinaria::imprimirpreordem(No* Noatual)
{
    if (Noatual != NULL){
        cout << Noatual->aluno.obterNome() << ": ";
        cout << Noatual->aluno.obterRa() << endl;

        imprimirpreordem(Noatual->filhoesquerda);

        imprimirpreordem(Noatual->filhodireita);
    }
}

void arvoreBinaria::imprimiremordem(No* Noatual)
{
    if (Noatual != NULL){
        imprimiremordem(Noatual->filhoesquerda);

        cout << Noatual->aluno.obterNome() << ": ";
        cout << Noatual->aluno.obterRa() << endl;

        imprimiremordem(Noatual->filhodireita);            
    }
}

void arvoreBinaria::imprimirposordem(No* Noatual)
{
    if (Noatual != NULL){
        imprimirposordem(Noatual->filhoesquerda);

        imprimirposordem(Noatual->filhodireita);

        cout << Noatual->aluno.obterNome() << ": ";
        cout << Noatual->aluno.obterRa() << endl;            
    }
}