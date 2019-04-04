#include "ListaEncadeada.h"
#include <stdlib.h>
#include "../Pessoa/Pessoa.h"


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
int ListaEncadeada<Tipo>::getTamanho() {
  return tamanho;
}

template <class Tipo>
bool ListaEncadeada<Tipo>::temProximo(int pos) {
  return pos >= 0 && pos < tamanho;
}

template <class Tipo>
Tipo* ListaEncadeada<Tipo>::get(int pos) {
  if (pos >= tamanho || pos < 0) return NULL;
  Node<Tipo>* ptr = start;
  while (pos) {
    ptr = ptr->getnext();
    pos--;
  }
  return ptr->getvalue();
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