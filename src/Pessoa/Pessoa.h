#pragma once
#include <string>
using namespace std;

class Pessoa {
  private:
    string nome;
    int rg;

  public:
    Pessoa(string _nome = "", int _rg = -1);
    ~Pessoa();
    void setNome(string _nome);
    string getNome();
    void setRg(int _rg);
    int getRg();
};