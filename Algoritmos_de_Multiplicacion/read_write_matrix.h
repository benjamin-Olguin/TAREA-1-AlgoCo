#ifndef READ_WRITE_MATRIX_H
#define READ_WRITE_MATRIX_H
#include <bits/stdc++.h>
using namespace std;

void write_result(ofstream &outfile, vector<vector<int>>& matrixC, double time, int r1, int c2) {
    /*
    ***
    *  outfile    : ofstream&
    *  matrixC    : vector<vector<int>>&
    *  time       : double
    *  iteration  : int
    *  r1         : int
    *  c2         : int
    ***
    Esta función escribe los resultados de la multiplicación de matrices en un archivo de output.
    Incluye el tiempo de ejecución y el resultado de la multiplicación.
    Los resultados se presentan en formato de matriz.
    */
    outfile << "Resultado de la multiplicación de matrices:\n";
    outfile << "Tiempo de ejecución: " << time << " ms" << endl << endl;

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            outfile << matrixC[i][j] << "\t";
        }
        outfile << "\n";
    }

    outfile << "\n";
}

void read_matrices(string& inputFile, vector<vector<int>>& matrixA, vector<vector<int>>& matrixB, int &r1, int &c1, int &r2, int &c2) {
    /*
    ***
    *  inputFile  : string&
    *  matrixA    : vector<vector<int>>&
    *  matrixB    : vector<vector<int>>&
    *  r1         : int&
    *  c1         : int&
    *  r2         : int&
    *  c2         : int&
    ***
    Esta función lee dos matrices desde un archivo de entrada. 
    Extrae las dimensiones de las matrices y sus elementos. 
    Las matrices se almacenan en `matrixA` y `matrixB`, y sus dimensiones en las variables `r1`, `c1`, `r2` y `c2`.
    */

    ifstream infile(inputFile);
    
    // Leer las dimensiones de la matriz A
    infile >> r1 >> c1;
    matrixA.resize(r1, vector<int>(c1));
    
    // Leer los valores de la matriz A
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            infile >> matrixA[i][j];
        }
    }
    
    // Leer las dimensiones de la matriz B
    infile >> r2 >> c2;
    matrixB.resize(r2, vector<int>(c2));
    
    // Leer los valores de la matriz B
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            infile >> matrixB[i][j];
        }
    }

    infile.close();
}

#endif // READ_WRITE_MATRIX_H