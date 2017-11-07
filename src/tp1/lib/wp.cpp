#include "wp.h"


matriz generarVectorWP(map<int, Equipo>& equipos){
    double valorWp;
    matriz wp(equipos.size(), vector<double> (1));
    for ( auto it = equipos.begin(); it != equipos.end(); ++it ){
        Equipo eq = it->second;
        if (eq.jugados != 0){
            valorWp = eq.ganados/eq.jugados;
            wp[eq.index][0] = valorWp;
        }
    }
    return wp;
}