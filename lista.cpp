template <typename TYPE>
Lista<TYPE>::Lista(){}

template <typename TYPE>
Lista<TYPE>::~Lista(){
  if(getSize() <= 0){
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
bool Lista<TYPE>::isEmpty(){
  if(getSize() == 0){
    return true;
  }
  else{
    return false;
  }
}

template <typename TYPE>
int Lista<TYPE>::getSize(){
  Node *aux = list.next;
  int cont = 0;
  while(aux != nullptr){
    cont++;
    aux = aux->next;
  }
  return cont;
}

template <typename TYPE>
bool Lista<TYPE>::add(const TYPE &value, int pos){}

template <typename TYPE>
TYPE Lista<TYPE>::remove(int pos){}

template <typename TYPE>
int Lista<TYPE>::search(const TYPE &elm){
  int i;
  Node *aux = list.next;
  for (i = 1; i <= getSize(); i++){
    if (aux->data == elm)
      return true;
    aux = aux->next;
  }
  return false;
}

template <typename TYPE>
void Lista<TYPE>::print(){
  Node *aux = list.next;
  while(aux != nullptr){
    cout<<aux->data<<endl;
    aux = aux->next;
  }
}