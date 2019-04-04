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
    Tipo* get(int pos);
    void limparLista();
};
