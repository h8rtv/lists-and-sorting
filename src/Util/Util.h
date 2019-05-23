#pragma once
#include <chrono>
#include <iostream>
#include "../ListaSequencial/ListaSequencial.h"

using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;
typedef std::chrono::_V2::system_clock::time_point time_point;
typedef std::chrono::duration<double> duration;

template<class Tipo>
class ListaSequencial;

struct Relatorio {
  Relatorio() {
    c = 0;
    m = 0;
    start = high_resolution_clock::now();
  }
  long c;
  long m;
  time_point start;
};

class Util {
  private:
    Util();
    Relatorio relatorio;
    bool running;
    void zerarRelatorio();
  public:
    ~Util();
    static Util& getInstance();
    void start();
    void addC(long _c = 1);
    void addM(long _m = 1);
    void stopAndPrint();
};

namespace Helper {
  int max(int a, int b);
  template <class Tipo>
  void swap(Tipo** lista, int pos1, int pos2) {
    Tipo* tmp = lista[pos1];
    lista[pos1] = lista[pos2];
    lista[pos2] = tmp;
  }
  namespace QuickSort {
    /* Algoritimo de particionar vetor: 
      Organiza os elementos da lista de forma que os elementos maiores
      que o elemento na posição 'pivo' fiquem posteriores e menores fiquem
      anteriores.
    */
    template <class Tipo>
    int particionarLomuto(Tipo** lista, int comeco, int fim) {
      int i, j;
      Tipo pivo = *lista[fim];
      for (i = comeco, j = i; i < fim; i++)
        if (*lista[i] < pivo)
          swap(lista, j++, i);    
      swap(lista, j, fim);
      return j;
    }
    template <class Tipo>
    int particionarHoare(Tipo** lista, int comeco, int fim) {
      int C = 0, M = 0;
      Util& util = Util::getInstance();
      int i = comeco - 1,
          j = fim + 1;
      // Evita overflow de int comparado com a solução trivial (comeco + fim) / 2,
      // mas é um pouco mais custoso.
      int meio = comeco + (fim - comeco) / 2;
      
      M++;
      Tipo& pivo = *lista[meio];
      while (true) {
        do {
          i++;
          C++;
        } while (*lista[i] < pivo);

        do {
          j--;
          C++;
        } while (*lista[j] > pivo);

        C++;
        if (i >= j) {
          util.addC(C);
          util.addM(M);
          return j;
        }

        M += 3;
        swap(lista, i, j);
      }
    }
  }
  namespace MergeSort {
    /* Realiza o merge in-place, utilizando uma lista auxiliar */
    template <class Tipo>
    void merge(Tipo** lista, Tipo** aux, int comeco, int meio, int fim) {
      Util& util = Util::getInstance();
      int i = comeco,
          j = meio + 1,
          k = comeco;
      int moves = max(meio - i + 1, fim - j + 1);
      util.addC(2 * moves);
      util.addM(moves);
      while (i <= meio && j <= fim)
        if (*lista[i] < *lista[j])
          aux[k++] = lista[i++];
        else
          aux[k++] = lista[j++];

      moves = meio - i + 1;
      util.addC(moves);
      util.addM(moves);
      while (i <= meio)
        aux[k++] = lista[i++];

      moves = fim - j + 1;
      util.addC(moves);
      util.addM(moves);
      while (j <= fim)
        aux[k++] = lista[j++];

      util.addM(fim - comeco);
      std::copy(aux + comeco, aux + fim + 1, lista + comeco);
    }
  }
};