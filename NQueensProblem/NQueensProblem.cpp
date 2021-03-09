// NQueensProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include <vector>
#include <time.h>

#include "first_try.h"
#include "recursively.h"

int main() {
    //std::cout << solveNQueens(4, { 0,0 });
    //std::cout << solveNQueens(4, { 1,1 });
    //std::cout << solveNQueens(6, { 2,1 });

    int n = 8;
    std::pair<int, int> coor = { 2,1 };
    std::cout << "board size: " << n << "\nfirst point\nrow: " << coor.second << "\ncol: " << coor.first << "\n\n";


    clock_t start, end;
    double seconds;

    start = clock();
    std::cout << solveNQueens_slow(n, coor);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "\nfirst algorithm time: " << seconds << " sec \n\n";

    start = clock();
    std::cout << solveNQueens(n, coor);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "\nrecursive algorithm time: " << seconds << " sec \n\n";

    system("pause");
}

