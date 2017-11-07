#include "cl.h"

void factorizacionDeCholesky(const matriz& A, matriz& L1, matriz& L2){
    int n = A.size();
    double sum = 0;

    L1[0][0] = sqrt(A[0][0]);
    L2[0][0] = L1[0][0];

    for(int j = 1; j < n; j++){
        L1[j][0] = (A[j][0] / L1[0][0]);
        L2[0][j] = L1[j][0];
    }

    for(int i = 1; i < (n-1); i++){
        sum = 0;
        for(int k = 0; k < i; k++){
            sum += pow(L1[i][k], 2.0);
        }
        L1[i][i] = sqrt(A[i][i] - sum);
        L2[i][i] = L1[i][i];

        for(int j = i+1; j < n; j++){
            sum = 0;
            for(int k = 0; k < i; k++){
                sum += (L1[j][k] * L1[i][k]);
            }
            L1[j][i] = (A[j][i] - sum) / L1[i][i];
            L2[i][j] = L1[j][i];
        }
    }

    sum = 0;
    for(int k = 0; k < (n-1); k++){
        sum += pow(L1[n-1][k], 2.0);
    }
    L1[n-1][n-1] = sqrt(A[n-1][n-1] - sum);
    L2[n-1][n-1] = L1[n-1][n-1];
}
