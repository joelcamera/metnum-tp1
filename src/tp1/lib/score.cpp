#include "score.h"

// Partido ganado suma 3
// Partido empatado suma 1
// Partido perdido no suma

matriz generarVectorScore(const map<int, Equipo>& equipos){
	matriz scores(equipos.size(), vector<double> (1));
    for(auto it = equipos.begin(); it != equipos.end(); ++it){
        scores[it->second.index][0] = it->second.ganados * 3 + it->second.empatados;
    }
    return scores;
}