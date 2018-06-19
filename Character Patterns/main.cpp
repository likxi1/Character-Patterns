//
//  main.cpp
//  Character Patterns
//
//  Created by Dai Long on 6/19/18.
//  Copyright © 2018 Dai Long. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

void fildot(int **arr, int m, int n) {
    for(int i = 1; i < m; i += 3) {
        for(int j = 1; j < n; j += 3) {
            arr[i][j] = 1; arr[i][j+1] = 1;
            arr[i+1][j] = 1; arr[i+1][j+1] = 1;
        }
    }
}

void pPattern(int **arr, int m, int n) {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

void readfile() {
    const string path = "/Users/dailong/Desktop/C++Basics/Character Patterns/Character Patterns/data";
    int **arr = nullptr;
    
    ifstream FILE(path);
    
    if (FILE.fail()) {
        cout << "Cant open file!!" << endl; return;
    }
    
    int num_test;
    FILE >> num_test;
    
    int m, n;
    while (num_test--) {
        FILE >> m >> n;
        m = 3 * m + 1;
        n = 3 * n + 1;
        arr = new int *[m];
        for (int i = 0; i < m; ++i) arr[i] = new int[n]();
        
        fildot(arr, m, n);
        pPattern(arr, m, n);
    }
    
}

int main(int argc, const char * argv[]) {
    readfile();
    std::cout << "Hello, World!\n";
    return 0;
}
