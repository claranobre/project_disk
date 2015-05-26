template <typename TYPE>
Disco<TYPE>::Disco(){}

template <typename TYPE>
Disco<TYPE>::~Disco(){
  if(numDeSetores() <= 0){
    return;
  }
  Node *aux = list.next;
  while(aux->next != nullptr){
    aux = aux->next;
    delete (aux->prev);
  }
  delete aux;
}

template <typename TYPE>
bool Disco<TYPE>::isEmpty(){
  if(numDeSetores() == 0){
    return true;
  }
  else{
    return false;
  }
}

template <typename TYPE>
int Disco<TYPE>::numDeSetores(){
  Node *aux = list.next;
  int cont = 0;
  while(aux != nullptr){
    cont++;
    aux = aux->next;
  }
  return cont;
}

template <typename TYPE>
bool Disco<TYPE>::add(const TYPE &value, int pos){}

template <typename TYPE>
TYPE Disco<TYPE>::remove(int pos){}

template <typename TYPE>
int Disco<TYPE>::search(const TYPE &elm){
  int i;
  Node *aux = list.next;
  for (i = 1; i <= numDeSetores(); i++){
    if (aux->data == elm)
      return true;
    aux = aux->next;
  }
  return false;
}

template <typename TYPE>
void Disco<TYPE>::print(){
  Node *aux = list.next;
  while(aux != nullptr){
    cout<<aux->data<<endl;
    aux = aux->next;
  }
}

template <typename TYPE>
int Disco<TYPE>::formatar(){}

template <typename TYPE>
int Disco<TYPE>::desfragmentar(){}

template <typename TYPE>
int Disco<TYPE>::recuperar(){}