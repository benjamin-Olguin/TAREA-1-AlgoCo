#ifndef READ_WRITE_VECTORS_H
#define READ_WRITE_VECTORS_H

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> read_data(string& toBeRead){
    /*
    ***
    *  toBeRead  : string&
    ***
    Lee un archivo de entrada y extrae varios vectores de enteros. 
    Cada vector está precedido por su tamaño. 
    Devuelve un vector de vectores de enteros.
    */
    ifstream infile(toBeRead);
    vector<vector<int>> vec;
    int totalVecs;
    infile >> totalVecs;

    for (int i = 0; i<totalVecs; i++){
        int vecSize;
        infile >> vecSize;
        vector<int> currVec(vecSize);
        for (int j = 0; j<vecSize; j++) infile >> currVec[j];
        vec.push_back(currVec);
    }
    
    infile.close();    
    return vec;
}

void write_result(ofstream &outfile, double &time, int &iteration, vector<int>& vec){
    /*
    ***
    *  outfile    : ofstream&
    *  time       : double&
    *  iteration  : int&
    ***
    Escribe los resultados de la prueba en un archivo de salida. 
    Indica el número de prueba y el tiempo de ejecución en milisegundos.
    */
    outfile << "Prueba " << iteration+1 << ":" << endl;
    outfile << "Tiempo de ejecución " << iteration+1 << ": " << time << "ms" << endl << endl;
    
    outfile << "[ ";
    for (int val : vec){
        outfile << val << " ";
    }
    outfile << "]" << endl << endl;
}

#endif // READ_WRITE_VECTORS_H