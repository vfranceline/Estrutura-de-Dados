#include <iostream>
#include "listaOrdenada.hpp"

using namespace std;

int main(){
    listaOrdenada lista1;
    int item;
    int opcao;

    cout << "Programa gerador de fila: \n";

    do{
        cout << "digite 0 para parar o programa! \n";
        cout << "digite 1 para inserir um elemento! \n";
        cout << "digite 2 para remover um elemento! \n";
        cout << "digite 3 para imprimir a fila! \n";

        cin >> opcao;

        if (opcao == 1){
            cout << "digite o elemento a ser inserido ! \n";
            cin >> item;
            lista1.push(item);
        } else if (opcao == 2){
            cout << "digite o elemento a ser removido ! \n";
            cin >> item;
            lista1.pop(item);
        } else if (opcao == 3){
            lista1.print();
        }
        
    } while (opcao != 0);

    return 0;
}