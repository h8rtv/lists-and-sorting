#include "Pessoa.h"

Pessoa::Pessoa(string _nome, string _rg) {
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

void Pessoa::setRg(string _rg) {
  rg.assign(_rg);
}

string Pessoa::getRg() {
  return rg;
}