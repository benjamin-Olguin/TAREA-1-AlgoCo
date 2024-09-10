#include <bits/stdc++.h>
#include "read_write_vectors.h"
using namespace std;

int main(){
    /*
    ***
    Lee datos de un archivo, ordena los vectores utilizando la función sort de la STL, 
    mide el tiempo de ejecución de cada ordenamiento y escribe los resultados en un archivo.
    ***
    */
    string input = "../datasets/ordenamiento/input.txt";
    string output = "../datasets/ordenamiento/output.txt";

    vector<vector<int>> vec = read_data(input);
    ofstream outfile(output);
    for(int i = 0; i < vec.size(); i++){
        auto start = chrono::high_resolution_clock::now();
        
        sort(vec[i].begin(), vec[i].end());

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> duration = end - start;
        double time = duration.count();
       write_result(outfile, time, i, vec[i]);
    }

    outfile.close();

    return 0;
}
