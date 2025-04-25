#include <iostream>
#include "DynamicStack.h"

using namespace std;

int main(){
    dynamicStack pilha1;
    TipoItem item;
    int opcao;

    cout << "Programa gerador de pilha: \n";

    do{
        cout << "digite 0 para parar o programa! \n";
        cout << "digite 1 para inserir um elemento! \n";
        cout << "digite 2 para remover um elemento! \n";
        cout << "digite 3 para imprimir a pilha! \n";

        cin >> opcao;

        if (opcao == 1){
            cout << "digite o elemento a ser inserido ! \n";
            cin >> item;
            pilha1.push(item);
        } else if (opcao == 2){
            item = pilha1.pop();
            cout << "elemento removido: " << item << endl;
        } else if (opcao == 3){
            pilha1.print();
        }
        
    } while (opcao != 0);

    return 0;
}