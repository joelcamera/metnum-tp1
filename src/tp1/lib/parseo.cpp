#include "tipos.h"
#include "parseo.h"


void levantarDatos(int cantPartidos, vector<Partido>& partidos, map<int, Equipo>& equipos){
    int idxeq = 0;
    for(int i = 0; i < cantPartidos; i++){
        Partido p;
        cin >> p.fecha;
        cin >> p.equipo1;
        cin >> p.goles1;
        cin >> p.equipo2;
        cin >> p.goles2;
        partidos.push_back(p);

        // Como tengo que hacer lo mismo por cada equipo generé esta funcion que mira al primer equipo
        // pasado por parametro con respecto del segundo
        cargarAEquipos(equipos, p.equipo1, p.equipo2, p.goles1, p.goles2, idxeq);
        cargarAEquipos(equipos, p.equipo2, p.equipo1, p.goles2, p.goles1, idxeq);
    }
}


void cargarAEquipos(map<int, Equipo>& equipos, int eq1, int eq2, int g1, int g2, int& idxeq){
    // Reviso si estan los equipos, si estan los modifico, sino los agrego.

    auto it = equipos.find(eq1);
    if(it != equipos.end()){
        // El equipo está agregado, le cargo los datos
        it->second.jugados++;
        it->second.ganados = g1 > g2 ? it->second.ganados+1 : it->second.ganados;
        it->second.perdidos = g1 < g2 ? it->second.perdidos+1 : it->second.perdidos;
        it->second.empatados = g1 == g2 ? it->second.empatados+1 : it->second.empatados;

    } else {
        // El equipo no está, lo agrego.
        Equipo eq;
        eq.id = eq1;
        eq.index = idxeq;
        idxeq++;
        eq.jugados = 1.0;
        eq.ganados = g1 > g2 ? 1.0 : 0.0;
        eq.perdidos = g1 < g2 ? 1.0 : 0.0;
        eq.empatados = g1 == g2 ? 1.0 : 0.0;

        equipos.insert({eq1, eq});
    }
}


void generarMatrizbCMM(map<int, Equipo>& equipos, matriz& b){

    for(auto it = equipos.begin(); it != equipos.end(); ++it){
        b[it->second.index][0] = 1 + ((it->second.ganados - it->second.perdidos)/2);
    }
}


void generarMatrizACMM(vector<Partido>& partidos,
                       map<int, Equipo>& equipos,
                       matriz& A){
    int eq_idx1;
    int eq_idx2;
    int n = A.size();

    // Agrega los valores entre los equipos (no la diagonal)
    for(auto it_part = partidos.begin(); it_part != partidos.end(); ++it_part){
        auto it_eq = equipos.find(it_part->equipo1);
        eq_idx1 = it_eq->second.index;
        it_eq = equipos.find(it_part->equipo2);
        eq_idx2 = it_eq->second.index;

        A[eq_idx1][eq_idx2]--;
        A[eq_idx2][eq_idx1]--;
    }

    // Seteo la diagonal en 2 por si tengo equipos "de menos"
    for (int i = 0; i < n; ++i){
        A[i][i] = 2;
    }
    // Y le sumo los jugados
    for(auto it_eq = equipos.begin(); it_eq != equipos.end(); ++it_eq){
        A[it_eq->second.index][it_eq->second.index] += it_eq->second.jugados;
    }
}
