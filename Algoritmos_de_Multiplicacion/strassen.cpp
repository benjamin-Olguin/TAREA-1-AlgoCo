#include <bits/stdc++.h>
#include "read_write_matrix.h"
using namespace std;

vector<vector<int>> add_matrix(vector<vector<int>> matrix_A, vector<vector<int>> matrix_B, int split_index, int multiplier = 1){
    /*
    *  Parámetros:
    *  matrix_A  : Matriz a la que se le sumará `matrix_B` (tamaño: `split_index x split_index`).
    *  matrix_B  : Matriz que se sumará a `matrix_A` (tamaño: `split_index x split_index`).
    *  split_index  : Tamaño de la submatriz (debe ser igual en ambas matrices).
    *  multiplier  : Factor por el cual se multiplica `matrix_B` antes de sumar (por defecto es 1).
    ***
    Función para sumar dos matrices `matrix_A` y `matrix_B` de tamaño `split_index x split_index`.
    La función realiza la suma de matrices considerando un posible multiplicador para `matrix_B`.
    El resultado se guarda en `matrix_A`, que es retornado.
    */
    for (auto i = 0; i < split_index; i++){
        for (auto j = 0; j < split_index; j++){
            matrix_A[i][j] = matrix_A[i][j] + (multiplier * matrix_B[i][j]);
            }
        }
    return matrix_A;
}
 
vector<vector<int>> multiply_matrix(vector<vector<int> > matrix_A, vector<vector<int> > matrix_B){
    /*
    *  Parámetros:
    *  matrix_A  : Matriz a multiplicar (dimensiones: `row_1 x col_1`).
    *  matrix_B  : Matriz a multiplicar (dimensiones: `row_2 x col_2`).
    *  
    *  Retorna:
    *  La matriz resultante de la multiplicación de `matrix_A` y `matrix_B` (dimensiones: `row_1 x col_2`).
    ***
    Función para multiplicar dos matrices `matrix_A` y `matrix_B` utilizando el algoritmo de Strassen.
    La multiplicación se realiza de la siguiente manera:
    1. Se dividen las matrices en submatrices de tamaño `split_index x split_index`.
    2. Se calculan los productos intermedios usando una serie de multiplicaciones y sumas de submatrices.
    3. Se combinan los productos intermedios para formar la matriz resultante.
    */
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    int row_2 = matrix_B.size();
 
    if (col_1 != row_2) {
        cout << "\nError: El número de columnas en la matriz A debe ser igual al número de filas en la matriz B\n";
        return {};
    }
 
    vector<int> result_matrix_row(col_2, 0);
    vector<vector<int> > result_matrix(row_1, result_matrix_row);
 
    if (col_1 == 1){
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    }
    else {
        int split_index = col_1 / 2;
 
        vector<int> row_vector(split_index, 0);
 
        vector<vector<int>> a00(split_index, row_vector);
        vector<vector<int>> a01(split_index, row_vector);
        vector<vector<int>> a10(split_index, row_vector);
        vector<vector<int>> a11(split_index, row_vector);
        vector<vector<int>> b00(split_index, row_vector);
        vector<vector<int>> b01(split_index, row_vector);
        vector<vector<int>> b10(split_index, row_vector);
        vector<vector<int>> b11(split_index, row_vector);
 
        for (auto i = 0; i < split_index; i++){
            for (auto j = 0; j < split_index; j++){
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + split_index];
                a10[i][j] = matrix_A[split_index + i][j];
                a11[i][j] = matrix_A[i + split_index][j + split_index];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + split_index];
                b10[i][j] = matrix_B[split_index + i][j];
                b11[i][j] = matrix_B[i + split_index][j + split_index];
            }
        }
        vector<vector<int>> p(multiply_matrix( a00, add_matrix(b01, b11, split_index, -1)));
        vector<vector<int>> q(multiply_matrix( add_matrix(a00, a01, split_index), b11));
        vector<vector<int>> r(multiply_matrix( add_matrix(a10, a11, split_index), b00));
        vector<vector<int>> s(multiply_matrix( a11, add_matrix(b10, b00, split_index, -1)));
        vector<vector<int>> t(multiply_matrix( add_matrix(a00, a11, split_index), add_matrix(b00, b11, split_index)));
        vector<vector<int>> u(multiply_matrix( add_matrix(a01, a11, split_index, -1), add_matrix(b10, b11, split_index)));
        vector<vector<int>> v(multiply_matrix( add_matrix(a00, a10, split_index, -1), add_matrix(b00, b01, split_index)));
 
        vector<vector<int>> result_matrix_00( add_matrix( add_matrix(add_matrix(t, s, split_index), u, split_index), q, split_index, -1));
        vector<vector<int>> result_matrix_01( add_matrix(p, q, split_index));
        vector<vector<int>> result_matrix_10( add_matrix(r, s, split_index));
        vector<vector<int>> result_matrix_11( add_matrix( add_matrix(add_matrix(t, p, split_index), r, split_index, -1), v, split_index, -1));
 
        for (auto i = 0; i < split_index; i++){
            for (auto j = 0; j < split_index; j++) {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + split_index] = result_matrix_01[i][j];
                result_matrix[split_index + i][j] = result_matrix_10[i][j];
                result_matrix[i + split_index][j + split_index] = result_matrix_11[i][j];
            }
        }
 

        a00.clear(); a01.clear(); a10.clear(); a11.clear(); b00.clear(); b01.clear(); b10.clear(); b11.clear();
        p.clear(); q.clear(); r.clear(); s.clear(); t.clear(); u.clear(); v.clear();
        result_matrix_00.clear();
        result_matrix_01.clear();
        result_matrix_10.clear();
        result_matrix_11.clear();
    }
    return result_matrix;
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
    
    matrixC = multiply_matrix(matrixA, matrixB);
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    double time = duration.count();
    
    // Escribe el resultado en el archivo de output
    ofstream outfile(output);
    write_result(outfile, matrixC, time, r1, c2);

    outfile.close();

    return 0;
}