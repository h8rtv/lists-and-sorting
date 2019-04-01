#pragma once
#include <string>
using std::string;

class Pessoa {
  private:
    string nome;
    string rg;

  public:
    Pessoa(string _nome = "", string _rg = "");
    ~Pessoa();
    void setNome(string _nome);
    string getNome();
    void setRg(string _rg);
    string getRg();
};