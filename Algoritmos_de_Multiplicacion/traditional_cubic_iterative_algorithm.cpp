#include <bits/stdc++.h>
#include "read_write_matrix.h"
using namespace std;

vector<vector<int>> multiply_matrices(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB, int r1, int c1, int r2, int c2) {
    /*
    ***
    *  matrixA : vector<vector<int>>&
    *  matrixB : vector<vector<int>>&
    *  r1      : int
    *  c1      : int
    *  r2      : int
    *  c2      : int
    ***
    Multiplica dos matrices `matrixA` y `matrixB`. 
    La matriz resultante `matrixC` tiene dimensiones `r1 x c2`. 
    Se utiliza la fórmula de multiplicación de matrices estándar:
    cada elemento de la matriz resultante es la suma del producto de los elementos correspondientes de las filas de `matrixA` y las columnas de `matrixB`.
    */
    vector<vector<int>> matrixC(r1, vector<int>(c2, 0));
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < r2; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return matrixC;
}

int main() {
    /*
    ***
    Función principal que lee matrices desde un archivo de entrada, realiza la multiplicación de matrices,
    mide el tiempo de ejecución de la multiplicación y escribe los resultados en un archivo de salida.
    ***
    */

    string input = "../datasets/matrices/input.txt";
    string output = "../datasets/matrices/output.txt";

    // Inicializa las matrices y sus dimensiones
    vector<vector<int>> matrixA, matrixB, matrixC;
    int r1, c1, r2, c2;
    
    // Lee las matrices desde el archivo de input
    read_matrices(input, matrixA, matrixB, r1, c1, r2, c2);
    
    // Verifica si la multiplicación es posible
    if (c1 != r2) {
        cerr << "No es posible multiplicar las matrices. El número de columnas de A debe ser igual al número de filas de B." << endl;
        return -1;
    }

    // Mide el tiempo de la multiplicación de matrices
    auto start = chrono::high_resolution_clock::now();
    
    matrixC = multiply_matrices(matrixA, matrixB, r1, c1, r2, c2);
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    double time = duration.count();
    
    // Escribe el resultado en el archivo de output
    ofstream outfile(output);
    write_result(outfile, matrixC, time, r1, c2);  

    outfile.close();

    return 0;
}
