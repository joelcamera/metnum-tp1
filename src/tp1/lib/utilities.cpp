#include "utilities.h"


void show_matrix(string name, const matriz &A) {
    cerr << "Matriz: " << name << endl;
    cerr << fixed << setprecision(3);
    for (auto i : A) {
        for (auto j : i) {
            cerr << setfill(' ') << setw(11) << j;
        }
        cerr << endl;
    }
    cerr << endl;
}

void show_result(const map<int, Equipo>& equipos, const matriz &x) {
    // Imprimo en el orden de los id de los equipos.
    for(auto it = equipos.begin(); it != equipos.end(); ++it){
        cout << it->second.id << ",";
        cout << x[it->second.index][0] << endl;
    }
}


void show_vector_partidos(const vector<Partido>& partidos){
    for(auto it = partidos.begin(); it != partidos.end(); ++it){
        cerr << "Fecha: " << it->fecha << endl;
        cerr << "Equipo1 id: " << it->equipo1
             << "  - Goles Eq1: " << it->goles1
             << "  |  Equipo2 id: " << it->equipo2
             << "  - Goles Eq2: " << it->goles2
             << endl;
    }
    cerr << endl;
}


void show_map_equipos(const map<int, Equipo>& equipos){
    for(auto it = equipos.begin(); it != equipos.end(); ++it){
        cerr << "Key: " << it->first << endl;
        cerr << "Value: { " << endl;
        cerr << "Id: " << it->second.id << " | " << "Index: " << it->second.index << endl;
        cerr << "Jugados: " << it->second.jugados << " | Ganados: " << it->second. ganados << " | Perdidos: " <<
        it->second.perdidos << " | Empatados: " << it->second.empatados << endl << "}" << endl;
    }

    cerr << endl;
}

matriz rand_matrix(int n, int m) {
    /* Generates a nxm matrix full of random doubles between -5 and 5.
     */
    srand(time(NULL));

    matriz out (n, vector<double> (m));

    for (auto& i : out) {
        for (auto& j : i) {
            j = ((rand() % 100) / 10.0) - 5;
        }
    }

    return out;
}

void fail(string msg){
    cerr << msg;
    exit(1);
}
