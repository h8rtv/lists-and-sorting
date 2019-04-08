#include "ListaSequencial.h"

const int SIZE_ALOCACAO = 100;

using namespace std;


template <class Tipo>
Tipo& ListaSequencial<Tipo>::operator[] (int pos) {
  return *listaSequencial[pos];
}

template <class Tipo>
ListaSequencial<Tipo>::ListaSequencial(int _tamanho) {
  tamanho = 0;
  espacoAlocado = _tamanho;
  if (espacoAlocado > 0) {
    instanciar(espacoAlocado);
  } else {
    listaSequencial = NULL;
  }
}

template <class Tipo>
ListaSequencial<Tipo>::~ListaSequencial() {
  delete[] listaSequencial;
}

template <class Tipo>
void ListaSequencial<Tipo>::adicionar(Tipo* valor) {
  if (espacoAlocado == 0) {
    instanciar(SIZE_ALOCACAO);
  }
  if (tamanho >= espacoAlocado) realocar(SIZE_ALOCACAO);
  listaSequencial[tamanho] = valor;
  tamanho++;
}

template <class Tipo>
int ListaSequencial<Tipo>::getTamanho() {
  return tamanho;
}

template <class Tipo>
Tipo* ListaSequencial<Tipo>::get(int pos) {
  if (pos < 0 || pos > tamanho) return NULL;
  return listaSequencial[pos];
}

template <class Tipo>
void ListaSequencial<Tipo>::limparLista() {
  for (int i = 0; i < tamanho; i++) {
    delete listaSequencial[i];
  }
  delete[] listaSequencial;
  listaSequencial = NULL;
  tamanho = 0;
  espacoAlocado = 0;
}

template <class Tipo>
void ListaSequencial<Tipo>::instanciar(int tamanho) {
  if (listaSequencial != NULL) {
    limparLista();
  } else {
    listaSequencial = new (nothrow) Tipo*[tamanho];
    if (listaSequencial == NULL) {
      cout << "Não foi possível alocar " << sizeof(Tipo) * tamanho << " bytes." << endl;
      exit(1);
    }
    espacoAlocado = tamanho;
  }
}

template <class Tipo>
bool ListaSequencial<Tipo>::temProximo(int pos) {
  return pos >= 0 && pos < tamanho;
}

template <class Tipo>
void ListaSequencial<Tipo>::realocar(int tamanhoExtra) {
    if (listaSequencial == NULL) {
      instanciar(tamanhoExtra);
    } else {
      try {
        Tipo** buffer = new Tipo*[tamanho + tamanhoExtra];
        copy(listaSequencial, listaSequencial + tamanho, buffer);
        delete[] listaSequencial;
        listaSequencial = buffer;
        espacoAlocado += tamanhoExtra;
      } catch (bad_alloc& erro) {
        cerr << "Não foi possível alocar " << sizeof(Tipo) * tamanho << " bytes." << endl;
        exit(1);
      }
    }
}

template class ListaSequencial<Pessoa>;
