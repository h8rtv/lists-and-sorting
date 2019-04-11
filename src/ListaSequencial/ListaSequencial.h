#pragma once
#include <iostream>
#include <stdlib.h>
#include "../Pessoa/Pessoa.h"
#include "../Util/Util.h"

using namespace std;

template <class Tipo>
class ListaSequencial {
  private:
    int espacoAlocado;
    int tamanho;
    Tipo** listaSequencial;

  public:
    Tipo& operator[] (int pos);
    ListaSequencial(int _tamanho = 0);
    ~ListaSequencial();
    int getTamanho();
    void push(Tipo* valor);
    void pop();
    void unshift(Tipo* valor);
    void shift();
    void add(Tipo* valor, int index);
    void remove(int index);
    void realocar(int tamanhoExtra);
    Tipo* get(int pos);
    void instanciar(int _tamanho);
    void limparLista();
    bool temProximo(int pos);
};
