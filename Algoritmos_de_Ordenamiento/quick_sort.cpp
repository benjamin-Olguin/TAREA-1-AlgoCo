#include <bits/stdc++.h>
#include "read_write_vectors.h"
using namespace std;

int partition(vector<int>& vec, int left, int right){
    /*
    ***
    *  vec   : vector<int>&
    *  left  : int
    *  right : int
    ***
    Esta función realiza la partición del vector para el algoritmo QuickSort. 
    Selecciona un elemento aleatorio como pivote, reorganiza los elementos de manera que 
    todos los elementos menores que el pivote queden a su izquierda y los mayores a su derecha.
    Retorna la posición final del pivote.
    */

    int randomIndex = left + rand() % (right - left + 1);
    swap(vec[left], vec[randomIndex]);  
    int pivot = vec[left];
    int leftMostPos = left;
    for(int i = left+1; i <= right; i++){
        if(vec[i] < pivot){
            leftMostPos++;
            swap(vec[i], vec[leftMostPos]);
        }
    }
    swap(vec[left], vec[leftMostPos]);
    return leftMostPos;
}

void quick_sort(vector<int>& vec, int left, int right){
    /*
    ***
    *  vec   : vector<int>&
    *  left  : int
    *  right : int
    ***
    Implementa el algoritmo QuickSort de manera recursiva. 
    Divide el vector utilizando la función partition y luego ordena las dos mitades resultantes.
    */
    if(left<=right){
        int pivot = partition(vec, left, right);
        quick_sort(vec, left, pivot-1);
        quick_sort(vec, pivot+1, right);
    }
}


int main(){
    /*
    ***
    Lee datos de un archivo, ordena los vectores con QuickSort, 
    mide el tiempo de ejecución de cada ordenamiento y escribe los resultados en un archivo.
    ***
    */
    string input = "../datasets/ordenamiento/input.txt";
    string output = "../datasets/ordenamiento/output.txt";

    vector<vector<int>> vec = read_data(input);
    ofstream outfile(output);
    for(int i = 0; i < vec.size(); i++){
        auto start = chrono::high_resolution_clock::now();
        
        quick_sort(vec[i], 0, vec[i].size()-1);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> duration = end - start;
        double time = duration.count();
        write_result(outfile, time, i, vec[i]);
    }

    outfile.close();

    return 0;
}
