#include "Gravador.h"

Gravador::Gravador() {
  arquivo = NULL;
  nomeArquivo = "default.txt";
}

void Gravador::abrir(const char* _nomeArquivo) {
  nomeArquivo = _nomeArquivo;
  if (arquivo != NULL) {
    arquivo->close();
    delete arquivo;
  }
  arquivo = new ofstream(nomeArquivo);
}

Gravador::~Gravador() {
  delete arquivo;
}

ofstream& Gravador::getArquivo() {
  return *arquivo;
}