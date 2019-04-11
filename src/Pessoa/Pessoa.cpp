#include "Pessoa.h"

Pessoa::Pessoa(string _nome, int _rg) {
  setNome(_nome);
  setRg(_rg);
}

Pessoa::~Pessoa() {
}

void Pessoa::setNome(string _nome) {
  nome.assign(_nome);
}

string Pessoa::getNome() {
  return nome;
}

void Pessoa::setRg(int _rg) {
  rg = _rg;
}

int Pessoa::getRg() {
  return rg;
}

string Pessoa::toString() {
  return nome + (rg != -1 ? "," + to_string(rg) : "");
}