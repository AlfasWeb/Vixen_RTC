#ifndef PROGRAMADOR_H
#define PROGRAMADOR_H

#include <Arduino.h>
#include <RTClib.h>

struct Programacao {
  bool dias[7];
  int hinicio;
  int minicio;
  int hfim;
  int mfim;
};

class Programador {
private:
  Programacao* horarios;
  const int total; // continua necessário para percorrer o array

  bool estaNoIntervalo(int minutosAgora, int inicio, int fim);

public:
  template <size_t N>
  Programador(Programacao (&h)[N])
    : horarios(h), total(N) {}

  bool ativo(const DateTime& agora);
};

#endif
