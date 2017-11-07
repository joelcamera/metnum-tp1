#include "eg.h"
#include "utilities.h"
#include "tipos.h"
#include "parseo.h"

void upper_triangulate(matriz& A, matriz& b){
    /* Convierte una matriz cuadrada y vector asociado
     * en triangular superior `in place`.
     */
    unsigned int n = A.size();

    for (unsigned int k = 0; k != n - 1; k++) {

        for (unsigned int i = k + 1; i != n; i++) {

            if (A[k][k] == 0) {
                fail("Error! El pivote no puede ser 0.");
            }

           double m = A[i][k]/A[k][k];

           for (unsigned int j = k; j != n; j++) {
               A[i][j] = A[i][j] - m*A[k][j];
           }

           b[i][0] = b[i][0] - m*b[k][0];
        }
    }
}

matriz backwards_substitution(const matriz& A, const matriz& b){
    /* Hace sustitución hacia atras sobre una matriz
     * triangular superior y genera un vector
     * de resultados.
     */
    unsigned int n = A.size();
    matriz x (n, vector<double> (1));

    for (int i = n - 1; i >= 0; i--) {

        double sum = 0;
        for (unsigned int j = i + 1; j != n; j++) {
            sum += A[i][j] * x[j][0];
        }

        x[i][0] = (b[i][0] - sum) / A[i][i];
    }

    return x;
}

matriz forward_substitution(const matriz& A, const matriz& b){
    unsigned int n = A.size();
    matriz y (n, vector<double> (1));

    for (unsigned int i = 0; i < n; i++){
        double sum = 0;
        for(unsigned int j = 0; j < i; j++){
            sum += A[i][j] * y[j][0];
        }

        y[i][0] = (b[i][0] - sum)/ A[i][i];
    }

    return y;
}

matriz gaussian_elim(matriz &A, matriz &b){
    /* Soluciona el sistema de ecuaciones Ax=b.
     * Modifica ambos argumentos.
     */

    upper_triangulate(A, b);
    return backwards_substitution(A, b);
}
