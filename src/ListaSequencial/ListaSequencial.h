#pragma once
#include <iostream>
using namespace std;

template <class Tipo>
class ListaSequencial {
  private:
    int espacoAlocado;
    int tamanho;
    Tipo* listaSequencial;

  public:
    ListaSequencial(int _tamanho = 0);
    ~ListaSequencial();
    int getTamanho();
    void adicionar(Tipo* valor);
    void realocar(int tamanhoExtra);
    Tipo* get(int pos);
    void instanciar(int _tamanho);
    short temProximo(int pos);
};
