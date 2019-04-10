#pragma once
#include <cstddef>
#include "Node/Node.h"
#include "../Pessoa/Pessoa.h"

using namespace std;

template <class Tipo>
class ListaEncadeada {
  private:
    int tamanho;
    Node<Tipo>* start;
    Node<Tipo>* end;

  public:
    Tipo& operator[] (int pos);
    ListaEncadeada();
    ~ListaEncadeada();
    int getTamanho();
    bool temProximo(int pos);
    void push(Tipo* valor);
    void pop();
    void unshift(Tipo* valor);
    void shift();
    void add(Tipo* valor, int index);
    void remove(int index);
    Tipo* get(int pos);
    Node<Tipo>* getNode(int pos);
    void limparLista();
};
