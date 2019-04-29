#include "ListaSequencial.h"
#include <stdexcept>

const int SIZE_ALOCACAO = 100;

template <class Tipo>
Tipo& ListaSequencial<Tipo>::operator[] (int pos) {
  Tipo* value = get(pos);
  if (Util::getInstance().addC(), value == NULL) {
    throw std::out_of_range("Índice fora do alcance.");
  }
  return *value;
}

template <class Tipo>
ListaSequencial<Tipo>::ListaSequencial(int _tamanho, bool _ownerOfObjs):
  tamanho(0),
  espacoAlocado(_tamanho),
  listaSequencial(NULL),
  ownerOfObjs(_ownerOfObjs)
{
  
  if (Util::getInstance().addC(), espacoAlocado > 0)
    instanciar(espacoAlocado);
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
bool ListaSequencial<Tipo>::set(int pos, Tipo* value) {
  if (Util::getInstance().addC(), pos < 0 || pos >= tamanho) return false;
  listaSequencial[pos] = value;
  return true;
}

template <class Tipo>
void ListaSequencial<Tipo>::limparLista() {
  if (Util::getInstance().addC(), ownerOfObjs) {
    for (int i = 0; Util::getInstance().addC(), i < tamanho; i++) {
      delete listaSequencial[i];
    }
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

template<class Tipo>
void ListaSequencial<Tipo>::insertion_sort() {
  int i, j;
  Tipo* pivo = NULL;
  for (i = 1; Util::getInstance().addC(), i < tamanho; i++) {
    Util::getInstance().addM(), pivo = listaSequencial[i];
    for (j = i - 1; Util::getInstance().addC(), j >= 0; j--)
      if (Util::getInstance().addC(), *listaSequencial[j] > *pivo)
        Util::getInstance().addM(), listaSequencial[j + 1] = listaSequencial[j];
      else break;
    if (Util::getInstance().addC(), i != j + 1)
      Util::getInstance().addM(), listaSequencial[j + 1] = pivo;
  }
}

template<class Tipo>
void ListaSequencial<Tipo>::selection_sort() {
  int iMenor, i, j;
  Tipo* tmp = NULL;
  for (i = 0; Util::getInstance().addC(), i < tamanho - 1; i++) {
    iMenor = i;
    for (j = i + 1; Util::getInstance().addC(), j < tamanho; j++) {
      if (Util::getInstance().addC(), *listaSequencial[j] < *listaSequencial[iMenor])
        Util::getInstance().addM(), iMenor = j;
    }
    if (Util::getInstance().addC(), i != iMenor) {
      Util::getInstance().addM(), tmp = listaSequencial[iMenor];
      Util::getInstance().addM(), listaSequencial[iMenor] = listaSequencial[i];
      Util::getInstance().addM(), listaSequencial[i] = tmp;
    }
  }
}

template<class Tipo>
void ListaSequencial<Tipo>::bubble_sort() {
  bool trocaOcorreu;
  Tipo* tmp = NULL;
   do {
    trocaOcorreu = false;
    for (int i = 0; i < tamanho - 1; i++)
      if (Util::getInstance().addC(), *listaSequencial[i] > *listaSequencial[i + 1]) {
        Util::getInstance().addM(), tmp = listaSequencial[i];
        Util::getInstance().addM(), listaSequencial[i] = listaSequencial[i + 1];
        Util::getInstance().addM(), listaSequencial[i + 1] = tmp;
        Util::getInstance().addM(), trocaOcorreu = true;
      }
  } while (trocaOcorreu);
}

template class ListaSequencial<Pessoa>;
