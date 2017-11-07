#ifndef UTILITIES_H
#define UTILITIES_H

#include "tipos.h"

void show_matrix(string name, const matriz &A);

void show_result(const map<int, Equipo>& equipos, const matriz &x);

void show_vector_partidos(const vector<Partido>& partidos);

void show_map_equipos(const map<int, Equipo>& equipos);

matriz rand_matrix(int n, int m);

void fail(string msg);

void inicializarMatrizConVal(matriz& C, int n, int m, double val);

#endif
