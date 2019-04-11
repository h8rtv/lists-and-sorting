#include "ListaEncadeada.h"
#include <stdexcept>

template <class Tipo>
Tipo& ListaEncadeada<Tipo>::operator[] (int pos) {
  Tipo* value = get(pos);
  if (Util::getInstance().addC(), value == NULL) {
    throw std::out_of_range("Índice for do alcance.");
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
  if (Util::getInstance().addC(), tamanho == 0) {
    start->setvalue(valor);
  } else {
    Node<Tipo>* node = new Node<Tipo>(valor, end);
    end->setnext(node);
    Util::getInstance().addM(), end = node;
  }
  tamanho++;
}

template <class Tipo>
void ListaEncadeada<Tipo>::unshift(Tipo* valor) {
  if (Util::getInstance().addC(), tamanho == 0) {
    start->setvalue(valor);
  } else {
    Node<Tipo>* node = new Node<Tipo>(valor, NULL, start);
    start->setprev(node);
    Util::getInstance().addM(), start = node;
  }
  tamanho++;
}

template <class Tipo>
void ListaEncadeada<Tipo>::pop() {
  if (Util::getInstance().addC(), tamanho != 0) {
    Node<Tipo>* newend = end->getprev();
    delete end;
    Util::getInstance().addM(), end = newend;
    tamanho--;
  }
}

template <class Tipo>
void ListaEncadeada<Tipo>::shift() {
  if (Util::getInstance().addC(), tamanho != 0) {
    Node<Tipo>* newstart = start->getnext();
    delete start;
    Util::getInstance().addM(), start = newstart;
    tamanho--;
  }
}

template <class Tipo>
void ListaEncadeada<Tipo>::add(Tipo* valor, int index) {
  if (Util::getInstance().addC(), index >= 0 && index < tamanho) {
    if (Util::getInstance().addC(), tamanho == 0) {
      start->setvalue(valor);
    } else {
      Node<Tipo>* nodePosterior = getNode(index);
      Node<Tipo>* node = new Node<Tipo>(valor, nodePosterior->getprev(), nodePosterior);
      nodePosterior->getprev()->setnext(node);
      nodePosterior->setprev(node);
    }
    tamanho++;
  }
}

template <class Tipo>
void ListaEncadeada<Tipo>::remove(int index) {
  if (Util::getInstance().addC(), index >= 0 && index < tamanho) {
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
  if (Util::getInstance().addC(), pos >= tamanho || pos < 0) return NULL;
  Node<Tipo>* ptr = start;
  while (Util::getInstance().addC(), pos) {
    Util::getInstance().addM(), ptr = ptr->getnext();
    pos--;
  }
  return ptr;
}

template <class Tipo>
Tipo* ListaEncadeada<Tipo>::get(int pos) {
  Node<Tipo>* node = getNode(pos);
  if (Util::getInstance().addC(), node == NULL) return NULL;
  return node->getvalue();
}

template <class Tipo>
void ListaEncadeada<Tipo>::limparLista() {
  end = NULL;
  Node<Tipo>* ptr = NULL;
  while (Util::getInstance().addC(), start) {
    ptr = start->getnext();
    delete start;
    Util::getInstance().addM(), start = ptr;
  }
}

template <class Tipo>
Node<Tipo>* ListaEncadeada<Tipo>::getbegin() {
  return start;
}

template <class Tipo>
Node<Tipo>* ListaEncadeada<Tipo>::getend() {
  return end;
}

template class ListaEncadeada<Pessoa>;