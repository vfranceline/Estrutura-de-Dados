#include <iostream>
#include <string>

struct Node
{
    std::string info;
    Node *anterior, *prox;
};

class editorTexto {
    private:
    Node *inicio;
    Node *atual;

    public:
    editorTexto();
    void editarAtual(std::string palavra);
    void inserirAtual(std::string palavra);
    void eliminarAtual();
    void navegarPalavras(char direcao);
    void printText();
    void printAtual();
};

editorTexto::editorTexto(){
    inicio = nullptr;
    atual = nullptr;
}

void editorTexto::inserirAtual(std::string palavra){
    Node *novo;

    novo = new Node();

    if (novo == nullptr){
        std::cout << "sem memoria" << std::endl;
        return;
    }

    novo->info = palavra;

    if (inicio == nullptr && atual == nullptr){
        novo->prox = novo;
        novo->anterior = novo;
        inicio = novo;
        atual = novo;
        return;
    } 

    if (atual->prox == inicio){ //atual é a ultima palavra
        novo->prox = inicio;
        inicio->anterior = novo;
        atual->prox = novo;
        novo->anterior = atual;
        atual = atual->prox;
    } else { //atual pode ser inicio ou estar no meio
        novo->prox = atual->prox;
        atual->prox->anterior = novo;
        atual->prox = novo;
        novo->anterior = atual;
        atual = novo;
    }    
}

void editorTexto::editarAtual(std::string palavra){
    if (inicio == nullptr){
        std::cout << "*vazia* ";
        return;
    }

    atual->info = palavra;
}

void editorTexto::eliminarAtual(){
    Node *aux = atual;

    if (inicio == nullptr){
        std::cout << "*vazia* ";
        return;
    }

    if (atual == inicio && atual->prox == inicio){ //se atual for o unico elemento da lista
        atual = nullptr;
        inicio = nullptr;
        std::cout << "lista vazia \n" << std::endl;
    } else {
        atual = atual->anterior;

        if (aux->prox == inicio){ //se atual for o ultimo
            aux->anterior->prox = inicio;
            inicio->anterior = aux->anterior;
        } else if (aux == inicio){ //se atual for o primeiro
            inicio = inicio->prox;
            inicio->anterior = aux->anterior;
            aux->anterior->prox = inicio;
        } else { //se atual estiver no meio
            atual->prox = aux->prox;
            aux->prox->anterior = aux->anterior;
        }
    }

    delete aux;
}

void editorTexto::navegarPalavras(char direcao){
    
    if (inicio == nullptr){
        std::cout << "*vazia*" << std::endl;
        return;
    }

    if (direcao == '>'){
        atual = atual->prox;
    } else if (direcao == '<'){
        atual = atual->anterior;        
    }
}


void editorTexto::printText(){
    Node *aux = inicio;

    std::cout << "\n" << std::endl;

    if (inicio == nullptr){
        std::cout << "*vazia* \n" << std::endl;
        return;
    } else {
        do {
            std::cout << aux->info << " ";
            aux = aux->prox;
        } while (aux != inicio);

        std::cout << "\n" << std::endl;
    }
}

void editorTexto::printAtual(){
    if (atual != nullptr) std::cout << "Palavra atual: " << atual->info << std::endl;
    else std::cout << "*lista vazia* " << std::endl;
}

int main(){

    editorTexto editor;
    char opcao;
    std::string palavra;

    do{
        editor.printText();
        editor.printAtual();

        std::cout << "\nInsira uma opção: " << std::endl;
        std::cout << "E: Editar palavra atual" << std::endl;
        std::cout << "D: Inserir (depois da palavra atual)" << std::endl;
        std::cout << "S: Eliminar palavra" << std::endl;
        std::cout << "<: Palavra anterior" << std::endl;
        std::cout << ">: Palavra posterior" << std::endl;
        std::cout << "X: Sair" << std::endl;
        std::cout << "Digite sua opção: ";
        std::cin >> opcao;

        switch (opcao)
        {
        case 'E':
        case 'e':
            std::cout << "Nova palavra: ";
            std::cin >> palavra;
            editor.editarAtual(palavra);
            break;
        
        case 'D':
        case 'd':
            std::cout << "Palavra a inserir: ";
            std::cin >> palavra;
            editor.inserirAtual(palavra);
            break;
    
        case 'S':
        case 's':
        editor.eliminarAtual();
            break;
    
        case '>':
            editor.navegarPalavras('>');
            break;
    
        case '<':
            editor.navegarPalavras('<');
            break;
    
        case 'X':
        case 'x':
            std::cout << "Saindo..." << std::endl;    
            break;
        
        default:
            std::cout << "Opcao invalida." << std::endl;
            break;
        }
    } while (opcao != 'X' && opcao != 'x');
    
return 0;
}