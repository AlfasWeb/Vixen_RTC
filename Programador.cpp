#include "Programador.h"

bool Programador::estaNoIntervalo(int minutosAgora, int inicio, int fim) {
  if (inicio < fim)
    return (minutosAgora >= inicio && minutosAgora < fim);
  else
    return (minutosAgora >= inicio || minutosAgora < fim);
}

bool Programador::ativo(const DateTime& agora) {

  int dia = agora.dayOfTheWeek();
  int minutosAgora = agora.hour() * 60 + agora.minute();

  for (int i = 0; i < total; i++) {

    Programacao p = horarios[i];
    int inicio = p.hinicio * 60 + p.minicio;
    int fim    = p.hfim    * 60 + p.mfim;

    if (p.dias[dia] && estaNoIntervalo(minutosAgora, inicio, fim))
      return true;

    if (inicio > fim) {
      int ontem = (dia - 1 + 7) % 7;
      if (p.dias[ontem] && estaNoIntervalo(minutosAgora, inicio, fim))
        return true;
    }
  }

  return false;
}
