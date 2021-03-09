#pragma once

std::vector <bool> column, maindiag, antidiag;
std::vector<int> result;
int start_row;

void init(int board_size) {
    int diag_size = board_size * 2 - 1;
    result.resize(board_size);
    column.resize(board_size);
    maindiag.resize(diag_size);
    antidiag.resize(diag_size);

    for (int i = 0; i < board_size; i++)
        column[i] = true;

    for (int i = 0; i < diag_size; i++) {
        maindiag[i] = true;
        antidiag[i] = true;
    }
}

void setMandatory(std::pair<int, int> reserved) {
    maindiag[reserved.first + reserved.second] = false;
    antidiag[reserved.second - reserved.first + result.size() - 1] = false;
    column[reserved.first] = false;
    start_row = reserved.second;
    result[reserved.second] = reserved.first;
}


std::string prepareOutput(bool is_solved) {
    if (!is_solved)
        return "";

    std::string output = "";
    for (int &row : result) {
        output.append(row, '.');
        output.append("Q");
        output.append(result.size() - row - 1, '.');
        output.append("\n");
    }
    return output;
}


void setQueen(int cur_row, bool& solution) {
    cur_row++;
    if (cur_row == start_row) {
        cur_row++;
    }

    int cur_col = -1;
    do {
        cur_col += 1;
        solution = false;
        if (column[cur_col] && maindiag[cur_row + cur_col] && antidiag[cur_row - cur_col + result.size() - 1]) {
            result[cur_row] = cur_col;
            column[cur_col] = maindiag[cur_row + cur_col] = antidiag[cur_row - cur_col + result.size() - 1] = false;
            if (cur_row < result.size() - 1) {
                setQueen(cur_row, solution);
                if (!solution) {
                    column[cur_col] = maindiag[cur_row + cur_col] = antidiag[cur_row - cur_col + result.size() - 1] = true;
                }
            }
            else {
                solution = true;
            }
        }
    } while (!(solution || (cur_col == (result.size() - 1))));
}


std::string solveNQueens(int n, std::pair<int, int> mandatoryQueenCoordinates) {
    if (n == 1)
        return "Q\n";
    if (n < 4)
        return "";

    init(n);
    setMandatory(mandatoryQueenCoordinates);
    bool has_solution;
    setQueen(-1, has_solution);
    return prepareOutput(has_solution);
}