#include <chrono>
#include <thread>
#include "lib/tipos.h"
#include "lib/parseo.h"
#include "lib/utilities.h"
#include "lib/eg.h"
#include "lib/cl.h"
#include "lib/wp.h"

#define TIEMPO chrono::high_resolution_clock::now

int main(int argv, char* argc[]){
    int reps = atoi(argc[1]);
    int cantEquipos;
    int cantPartidos;
    cin >> cantEquipos;
    cin >> cantPartidos;

    vector<Partido> partidos;
    map<int, Equipo> equipos;

    levantarDatos(cantPartidos, partidos, equipos);

    matriz A (cantEquipos, vector<double> (cantEquipos));
    matriz b (cantEquipos, vector<double> (1));
    matriz x;
    matriz L1 (cantEquipos, vector<double> (cantEquipos));
    matriz L2 (cantEquipos, vector<double> (cantEquipos));
    matriz y (cantEquipos, vector<double> (1));

    generarMatrizACMM(partidos, equipos, A);
    generarMatrizbCMM(equipos, b);

    vector<double> resultados_eg (reps);
    vector<double> resultados_ch (reps);
    for (int i = 0; i < reps; ++i)
    {
        /*** Gaussian Elim ***/
        matriz A_ = A;
        auto inicio = TIEMPO();
        x = gaussian_elim(A_, b);
        auto fin = TIEMPO();
        double t = (double) chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();
        resultados_eg[i] = t;

        /*** Cholesky ***/
        inicio = TIEMPO();
        factorizacionDeCholesky(A, L1, L2);
        y = forward_substitution(L1, b);
        x = backwards_substitution(L2, y);
        fin = TIEMPO();
        t = (double) chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();
        resultados_ch[i] = t;

        this_thread::sleep_for(chrono::milliseconds(5));
    }

    cout << "eg,ch" << endl;
    cout << fixed << setprecision(0);
    for (int i = 0; i < reps; ++i){
        cout << resultados_eg[i] << "," << resultados_ch[i] << endl;
    }

    return 0;
}
