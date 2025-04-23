void pop(int n){
  Nodo *antes, *atual;
  if (inicio == nullptr){
    cout << "lista vazia";
    return;
  }

  atual = inicio;

  while ((atual != nullptr) && (atual->info != n)){
    antes = atual;
    //alguma coisa q eu nn consegui ler
    if (atual == nullptr){
      //printa nn achou o numero
    }
    if (atual == inicio){
      inicio = inicio->prox;
    }
    else{
      antes->prox = atual->prox;
    }
    delete atual;
  }
}
