#include <bits/stdc++.h>
#include "read_write_vectors.h"
using namespace std;

void bubble_sort(vector<int>& vec){
    /*
    ***
    *  vec  : vector<int>&
    ***
    Esta función implementa el algoritmo de ordenamiento "bubble sort". 
    Compara pares consecutivos de elementos en el vector y los intercambia si están 
    en el orden incorrecto. Repite el proceso hasta que el vector esté ordenado.
    */
    int n = vec.size();
    for(int i = 0; i < n-1; i++){
        
        for(int j = 0; j < n-1-i; j++){
            if(vec[j]>vec[j+1]) swap(vec[j], vec[j+1]);
        }
        
    }
}

int main(){
    /*
    ***
    Lee datos de un archivo, ordena los vectores con bubble sort, 
    mide el tiempo de ejecución de cada ordenamiento y escribe los resultados en un archivo.
    ***
    */
    string input = "../datasets/ordenamiento/input.txt";
    string output = "../datasets/ordenamiento/output.txt";

    vector<vector<int>> vec = read_data(input);
    ofstream outfile(output);
    for(int i = 0; i < vec.size(); i++){
        auto start = chrono::high_resolution_clock::now();
        
        bubble_sort(vec[i]);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> duration = end - start;
        double time = duration.count();
        write_result(outfile, time, i, vec[i]);
    }

    outfile.close();

    return 0;
}
