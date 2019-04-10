#include "ListaEncadeada.h"


template <class Tipo>
Tipo& ListaEncadeada<Tipo>::operator[] (int pos) {
  Tipo* value = get(pos);
  if (value == NULL) {
    throw "Não foi possível acessar a esta posição";
  }
  return *value;
}

template <class Tipo>
ListaEncadeada<Tipo>::ListaEncadeada()
{
  start = new Node<Tipo>;
  end = start;
  tamanho = 0;
}

template <class Tipo>
ListaEncadeada<Tipo>::~ListaEncadeada() {
  limparLista();
}

template <class Tipo>
void ListaEncadeada<Tipo>::push(Tipo* valor) {
  if (tamanho == 0) {
    start->setvalue(valor);
  } else {
    Node<Tipo>* node = new Node<Tipo>(valor, end);
    end->setnext(node);
    end = node;
  }
  tamanho++;
}

template <class Tipo>
void ListaEncadeada<Tipo>::unshift(Tipo* valor) {
  if (tamanho == 0) {
    start->setvalue(valor);
  } else {
    Node<Tipo>* node = new Node<Tipo>(valor, NULL, start);
    start->setprev(node);
    start = node;
  }
  tamanho++;
}

template <class Tipo>
void ListaEncadeada<Tipo>::pop() {
  if (tamanho != 0) {
    Node<Tipo>* newend = end->getprev();
    delete end;
    end = newend;
    tamanho--;
  }
}

template <class Tipo>
void ListaEncadeada<Tipo>::shift() {
  if (tamanho != 0) {
    Node<Tipo>* newstart = start->getnext();
    delete start;
    start = newstart;
    tamanho--;
  }
}

template <class Tipo>
void ListaEncadeada<Tipo>::add(Tipo* valor, int index) {
  if (index >= 0 && index < tamanho) {
    if (tamanho == 0) {
      start->setvalue(valor);
    } else {
      Node<Tipo>* nodePosterior = getNode(index);
      Node<Tipo>* node = new Node<Tipo>(valor, nodePosterior->getprev(), nodePosterior);
      nodePosterior->setprev(node);
      nodePosterior->getprev()->setnext(node);
    }
    tamanho++;
  }
}

template <class Tipo>
void ListaEncadeada<Tipo>::remove(int index) {
  if (index >= 0 && index < tamanho) {
    Node<Tipo>* nodeARemover = getNode(index);
    Node<Tipo>* ant = nodeARemover->getprev();
    Node<Tipo>* pos = nodeARemover->getnext();
    pos->setprev(ant);
    ant->setnext(pos);
    delete nodeARemover;
    tamanho--;
  }
}

template <class Tipo>
int ListaEncadeada<Tipo>::getTamanho() {
  return tamanho;
}

template <class Tipo>
bool ListaEncadeada<Tipo>::temProximo(int pos) {
  return pos >= 0 && pos < tamanho;
}

template <class Tipo>
Node<Tipo>* ListaEncadeada<Tipo>::getNode(int pos) {
  if (pos >= tamanho || pos < 0) return NULL;
  Node<Tipo>* ptr = start;
  while (pos) {
    ptr = ptr->getnext();
    pos--;
  }
  return ptr;
}

template <class Tipo>
Tipo* ListaEncadeada<Tipo>::get(int pos) {
  Node<Tipo>* node = getNode(pos);
  if (node == NULL) return NULL;
  return node->getvalue();
}

template <class Tipo>
void ListaEncadeada<Tipo>::limparLista() {
  end = NULL;
  Node<Tipo>* ptr = NULL;
  while (start) {
    ptr = start->getnext();
    delete start;
    start = ptr;
  }
}

template class ListaEncadeada<Pessoa>;