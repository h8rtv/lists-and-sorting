#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include "../Pessoa/Pessoa.h"
#include "../Util/Util.h"

using namespace std;

template <class Tipo>
class ListaSequencial {
  private:
    int espacoAlocado;
    int tamanho;
    Tipo** listaSequencial;
    bool ownerOfObjs;

  public:
    Tipo& operator[] (int pos);
    ListaSequencial(int _tamanho = 0, bool _ownerOfObjs = true);
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
    bool set(int pos, Tipo* value);
    void instanciar(int _tamanho);
    void limparLista();
    bool temProximo(int pos);
    void selection_sort();
    void insertion_sort();
    void bubble_sort();
    void merge_sort();
    void merge_sort_recursion(Tipo** aux, int comeco, int fim);
    void quick_sort();
    void quick_sort_recursion(int comeco, int fim);
    void shell_sort();
};
