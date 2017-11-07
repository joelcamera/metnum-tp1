#ifndef PARSEO_H
#define PARSEO_H

#include "tipos.h"
#include "utilities.h"

void cargarAEquipos(map<int, Equipo>& equipos, int eq1, int eq2, int g1, int g2, int& idxeq);

void levantarDatos(int cantPartidos, vector<Partido>& partidos, map<int, Equipo>& equipos);

void generarMatrizbCMM(map<int, Equipo>& equipos, matriz& b);

void generarMatrizACMM(vector<Partido>& partidos, map<int, Equipo>& equipos, matriz& A);

#endif
