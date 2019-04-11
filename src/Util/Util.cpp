#include "Util.h"

Util::Util(): relatorio() {}

Util::~Util() {}

Util& Util::getInstance() {
  static Util instance;
  return instance;
}

void Util::start() {
  running = true;
  relatorio.c = 0;
  relatorio.m = 0;
  relatorio.start = high_resolution_clock::now();
}

void Util::addC(long _c) {
  relatorio.c += _c;
}

void Util::addM(long _m) {
  relatorio.m += _m;
}

void Util::stopAndPrint() {
  if (running) {
    auto end = high_resolution_clock::now();
    duration diff = end - relatorio.start;
    cout << "C(n): " << relatorio.c << endl;
    cout << "M(n): " << relatorio.m << endl;
    cout << "TEMPO: " << diff.count() << endl;
    running = false;
  }
}
