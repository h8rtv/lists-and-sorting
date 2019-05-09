#include "ListaEncadeada.h"
#include <stdexcept>
#include <cassert>
template <class Tipo>
Tipo& ListaEncadeada<Tipo>::operator[] (int pos) {
  Tipo* value = get(pos);
  if (Util::getInstance().addC(), value == NULL) {
    throw std::out_of_range("Índice fora do alcance.");
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
    Util::getInstance().addM(), start->setvalue(valor);
  } else {
    Util::getInstance().addM();
    Node<Tipo>* node = new Node<Tipo>(valor, end);
    Util::getInstance().addM(), end->setnext(node);
    Util::getInstance().addM(), end = node;
  }
  tamanho++;
}

template <class Tipo>
void ListaEncadeada<Tipo>::unshift(Tipo* valor) {
  if (Util::getInstance().addC(), tamanho == 0) {
    Util::getInstance().addM(), start->setvalue(valor);
  } else {
    Util::getInstance().addM();
    Node<Tipo>* node = new Node<Tipo>(valor, NULL, start);
    Util::getInstance().addM(), start->setprev(node);
    Util::getInstance().addM(), start = node;
  }
  tamanho++;
}

template <class Tipo>
void ListaEncadeada<Tipo>::pop() {
  if (Util::getInstance().addC(), tamanho != 0) {
    Node<Tipo>* newend = end->getprev();
    Util::getInstance().addM(), newend->setnext(NULL);
    delete end;
    Util::getInstance().addM(), end = newend;
    tamanho--;
  }
}

template <class Tipo>
void ListaEncadeada<Tipo>::shift() {
  if (Util::getInstance().addC(), tamanho != 0) {
    Node<Tipo>* newstart = start->getnext();
    Util::getInstance().addM(), newstart->setprev(NULL);
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
      Util::getInstance().addM(2);
      Node<Tipo>* node = new Node<Tipo>(valor, nodePosterior->getprev(), nodePosterior);
      Util::getInstance().addM(), nodePosterior->getprev()->setnext(node);
      Util::getInstance().addM(), nodePosterior->setprev(node);
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
    Util::getInstance().addM(), pos->setprev(ant);
    Util::getInstance().addM(), ant->setnext(pos);
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
  tamanho = 0;
  end = new Node<Tipo>;
  while (Util::getInstance().addC(), start) {
    delete start;
    Util::getInstance().addM(), start = start->getnext();
  }
  start = end;
}

template <class Tipo>
void ListaEncadeada<Tipo>::limparListaSemDesalocar() {
  start = new Node<Tipo>;
  end = start;
  tamanho = 0;
}


template <class Tipo>
Node<Tipo>* ListaEncadeada<Tipo>::getbegin() {
  return start;
}

template <class Tipo>
void ListaEncadeada<Tipo>::mapFromArray(ListaSequencial<Tipo>& array) {
  limparListaSemDesalocar();
  for (int i = 0; i < array.getTamanho(); i++) {
    push(array.get(i)); 
  }
}

template <class Tipo>
ListaSequencial<Tipo>* ListaEncadeada<Tipo>::mapToArray() {
  ListaSequencial<Tipo>* arr = new ListaSequencial<Tipo>(tamanho, false);
  Node<Tipo>* inicio = getbegin();
  while (inicio != NULL) {
    arr->push(inicio->getvalue());
    inicio = inicio->getnext();
  }
  return arr;
}

template<class Tipo>
void ListaEncadeada<Tipo>::insertion_sort() {
  ListaSequencial<Tipo>* array = mapToArray();
  array->insertion_sort();
  mapFromArray(*array);
  delete array;
}

template<class Tipo>
void ListaEncadeada<Tipo>::selection_sort() {
  ListaSequencial<Tipo>* array = mapToArray();
  array->selection_sort();
  mapFromArray(*array);
  delete array;
}

template<class Tipo>
void ListaEncadeada<Tipo>::bubble_sort() {
  ListaSequencial<Tipo>* array = mapToArray();
  array->bubble_sort();
  mapFromArray(*array);
  delete array;
}

template<class Tipo>
void ListaEncadeada<Tipo>::merge_sort() {
  ListaSequencial<Tipo>* array = mapToArray();
  array->merge_sort();
  mapFromArray(*array);
  delete array;
}

template class ListaEncadeada<Pessoa>;
