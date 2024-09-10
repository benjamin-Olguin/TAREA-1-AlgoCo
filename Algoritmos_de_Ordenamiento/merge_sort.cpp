#include <bits/stdc++.h>
#include "read_write_vectors.h"
using namespace std;

void merge(vector<int>& vec, int left, int center, int right){
    /*
    ***
    *  vec    : vector<int>&
    *  left   : int
    *  center : int
    *  right  : int
    ***
    Esta función combina dos sub-vectores ordenados en un solo vector ordenado. 
    El primer sub-vector va desde `left` hasta `center`, y el segundo desde `center + 1` hasta `right`. 
    Utiliza vectores temporales para almacenar los valores y los inserta de vuelta en el vector original de manera ordenada.
    */
    int sizeL = center - left +1;
    int sizeR = right - center;

    vector<int> leftVec(sizeL), rightVec(sizeR);

    for(int i = 0; i < sizeL; i++) leftVec[i] = vec[left + i];
    for(int i = 0; i < sizeR; i++) rightVec[i] = vec[center + i + 1];

    int i = 0, j = 0, k = left;

    while (i<sizeL && j<sizeR){
        if(rightVec[j] <= leftVec[i]){
            vec[k] = rightVec[j];
            j++;
        } else {
            vec[k] = leftVec[i];
            i++;
        }
        k++;
    }
    
    while (j < sizeR){
        vec[k] = rightVec[j];
        j++;
        k++;    
    }

    while (i < sizeL){
        vec[k] = leftVec[i];
        i++;
        k++;    
    }
}

void merge_sort(vector<int>& vec, int left, int right){
    /*
    ***
    *  vec   : vector<int>&
    *  left  : int
    *  right : int
    ***
    Implementa el algoritmo "merge sort" de manera recursiva. 
    Divide el vector en dos mitades hasta que los sub-vectores son de tamaño 1, 
    luego los combina de nuevo de manera ordenada usando la función merge.
    */
    if(left >= right) return;
    int center = left + (right - left)/2;
    merge_sort(vec, left, center);
    merge_sort(vec, center+1, right);
    merge(vec, left, center, right);
}


int main(){
    /*
    ***
    Lee datos de un archivo, ordena los vectores con merge sort, 
    mide el tiempo de ejecución de cada ordenamiento y escribe los resultados en un archivo.
    ***
    */
    string input = "../datasets/ordenamiento/input.txt";
    string output = "../datasets/ordenamiento/output.txt";

    vector<vector<int>> vec = read_data(input);
    ofstream outfile(output);
    for(int i = 0; i < vec.size(); i++){
        auto start = chrono::high_resolution_clock::now();
        
        merge_sort(vec[i], 0, vec[i].size()-1);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> duration = end - start;
        double time = duration.count();
        write_result(outfile, time, i, vec[i]);
    }

    outfile.close();

    return 0;
}
