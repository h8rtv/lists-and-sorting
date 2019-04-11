#include "ListaSequencial.h"
#include <stdexcept>

const int SIZE_ALOCACAO = 100;

template <class Tipo>
Tipo& ListaSequencial<Tipo>::operator[] (int pos) {
  Tipo* value = get(pos);
  if (Util::getInstance().addC(), value == NULL) {
    throw std::out_of_range("Índice for do alcance.");
  }
  return *value;
}

template <class Tipo>
ListaSequencial<Tipo>::ListaSequencial(int _tamanho) {
  tamanho = 0;
  espacoAlocado = _tamanho;
  if (Util::getInstance().addC(), espacoAlocado > 0) {
    instanciar(espacoAlocado);
  } else {
    listaSequencial = NULL;
  }
}

template <class Tipo>
ListaSequencial<Tipo>::~ListaSequencial() {
  limparLista();
}

template <class Tipo>
void ListaSequencial<Tipo>::push(Tipo* valor) {
  if (Util::getInstance().addC(), espacoAlocado == 0) {
    instanciar(SIZE_ALOCACAO);
  }
  if (Util::getInstance().addC(), tamanho >= espacoAlocado) realocar(SIZE_ALOCACAO);
  listaSequencial[tamanho] = valor;
  tamanho++;
}

template <class Tipo>
void ListaSequencial<Tipo>::pop() {
  if (Util::getInstance().addC(), tamanho != 0) {
    delete listaSequencial[tamanho - 1];
    tamanho--;
  }
}

template <class Tipo>
void ListaSequencial<Tipo>::unshift(Tipo* valor) {
  if (Util::getInstance().addC(), espacoAlocado == 0) {
    instanciar(SIZE_ALOCACAO);
  }
  if (Util::getInstance().addC(), tamanho >= espacoAlocado) realocar(SIZE_ALOCACAO);
  int i = tamanho;
  while (Util::getInstance().addC(), i) {
    Util::getInstance().addM(), listaSequencial[i] = listaSequencial[i - 1];
    i--;
  }
  listaSequencial[0] = valor;
  tamanho++;
}

template <class Tipo>
void ListaSequencial<Tipo>::shift() {
  if (Util::getInstance().addC(), tamanho != 0) {
    delete listaSequencial[0];
    int i = 1;
    while (Util::getInstance().addC(), temProximo(i)) {
      Util::getInstance().addM(), listaSequencial[i - 1] = listaSequencial[i];
      i++;
    }
    tamanho--;
  }
}

template <class Tipo>
void ListaSequencial<Tipo>::add(Tipo* valor, int index) {
  if (Util::getInstance().addC(), index >= 0 && index < tamanho) {
    if (Util::getInstance().addC(), espacoAlocado == 0) {
      instanciar(SIZE_ALOCACAO);
    }
    if (Util::getInstance().addC(), tamanho >= espacoAlocado) realocar(SIZE_ALOCACAO);
    int i = tamanho;
    while (Util::getInstance().addC(), i >= index) {
      cout << i << index << endl;
      Util::getInstance().addM(), listaSequencial[i + 1] = listaSequencial[i];
      i--;
    }
    listaSequencial[index] = valor;
    tamanho++;
  }
}

template <class Tipo>
void ListaSequencial<Tipo>::remove(int index) {
  if (Util::getInstance().addC(), index >= 0 && index < tamanho) {
    delete listaSequencial[index];
    int i = index + 1;
    while (Util::getInstance().addC(), temProximo(i)) {
      Util::getInstance().addM(), listaSequencial[i - 1] = listaSequencial[i];
      i++;
    }
    tamanho--;
  }
}

template <class Tipo>
int ListaSequencial<Tipo>::getTamanho() {
  return tamanho;
}

template <class Tipo>
Tipo* ListaSequencial<Tipo>::get(int pos) {
  if (Util::getInstance().addC(), pos < 0 || pos >= tamanho) return NULL;
  return listaSequencial[pos];
}

template <class Tipo>
void ListaSequencial<Tipo>::limparLista() {
  for (int i = 0; Util::getInstance().addC(), i < tamanho; i++) {
    delete listaSequencial[i];
  }
  delete[] listaSequencial;
  listaSequencial = NULL;
  tamanho = 0;
  espacoAlocado = 0;
}

template <class Tipo>
void ListaSequencial<Tipo>::instanciar(int tamanho) {
  if (Util::getInstance().addC(), listaSequencial != NULL) {
    limparLista();
  } else {
    listaSequencial = new (nothrow) Tipo*[tamanho];
    if (Util::getInstance().addC(), listaSequencial == NULL) {
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
  if (Util::getInstance().addC(), listaSequencial == NULL) {
    instanciar(tamanhoExtra);
  } else {
    try {
      Tipo** buffer = new Tipo*[tamanho + tamanhoExtra];
      Util::getInstance().addM(tamanho);
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
