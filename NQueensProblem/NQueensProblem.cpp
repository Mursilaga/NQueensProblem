// NQueensProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include <vector>


std::string prepareOutput(std::vector<std::vector<int>> &board) {
    std::string result = "";
    for (auto &row : board) {
        for (auto &cell : row) {
            if (cell == 1)
                result += "Q";
            else
                result += ".";
        }
        result += "\n";
    }
    return result;
}


bool checkCell(std::vector<std::vector<int>> &board, int row, int col) {
    if (board[row][col] != 0)
        return false;

    auto diag_u = row - col, diag_d = row + col;
    for (auto i = 0; i < board.size(); i++, diag_u++, diag_d--) {
        if (board[row][i] == 1 || board[i][col] == 1)
            return false;

        if (diag_u >= 0 && diag_u < board.size()
            && board[diag_u][i] == 1)
            return false;

        if (diag_d >= 0 && diag_d < board.size()
            && board[diag_d][i] == 1)
            return false;
    }
    return true;
}

void undoStep(std::vector<std::vector<int>> &board, std::vector<std::pair<int, int>> &steps) {
    board[steps.rbegin()->first][steps.rbegin()->second] = (int)(0-steps.size());
    for (auto r = 0; r < board.size(); r++) {
        for (auto c = 0; c < board.size(); c++) {
            if (board[r][c] < (int)(0 - steps.size())) {
                board[r][c] = 0;
            }
        }
    }
    steps.pop_back();
}


std::string solveNQueens(int n, std::pair<int, int> mandatoryQueenCoordinates) {
    if (n == 1)
        return "Q\n";
    if (n < 4)
        return "";

    std::vector<std::vector<int>>board(n, std::vector<int>(n, 0));
    board[mandatoryQueenCoordinates.second][mandatoryQueenCoordinates.first] = 1;
    
    std::vector<std::pair<int, int>> steps;
    steps.push_back(std::pair<int, int>(mandatoryQueenCoordinates.second, mandatoryQueenCoordinates.first));

    while (true) {
        for (auto r = 0; r < n; r++) {
            for (auto c = 0; c < n; c++) {
                if (checkCell(board, r, c)) {
                    steps.push_back(std::pair<int, int>(r, c));
                    board[r][c] = 1;
                    break;
                }
            }
        }
        if (steps.size() < n)
            undoStep(board, steps);

        if (steps.size() == 0)
            return "";

        if (steps.size() == n)
            break;
    }


    return prepareOutput(board);
}


int main()
{
    //std::cout << solveNQueens(4, { 0,0 });
    //std::cout << solveNQueens(4, { 1,0 });
    std::cout << solveNQueens(8, { 0,0 });
    system("pause");
}

