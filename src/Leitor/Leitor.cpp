#include "Leitor.h"

Leitor::Leitor(const char* _nomeArquivo)
{
  arquivo = NULL;
  abrir(nomeArquivo);
}

Leitor::~Leitor() {
  arquivo->close();
  delete arquivo;
}

void Leitor::reiniciar() {
  arquivo->clear();
  arquivo->seekg(0, std::ios::beg);
}

void Leitor::abrir(const char* _nomeArquivo) {
  nroLinhas = 0;
  nomeArquivo = _nomeArquivo;
  if (arquivo != NULL) {
    arquivo->close();
    delete arquivo;
  }
  arquivo = new ifstream(nomeArquivo);
}

int Leitor::nroLinhasArquivo() {
  if (nroLinhas == 0) {
    string linha;
    int contador = 0;
    while (getline(*arquivo, linha)) {
      contador++;
    }
    nroLinhas = contador;
  }
  reiniciar();
  return nroLinhas;
}

ifstream& Leitor::getArquivo() {
  return *arquivo;
}
