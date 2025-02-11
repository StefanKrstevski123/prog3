#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


bool isValid(int queens[], int col) {
    for (int prevCol = 0; prevCol < col; prevCol++) {
        if (queens[prevCol] == queens[col] ||  abs(queens[prevCol] - queens[col]) == abs(prevCol - col)) {  
            return false;
        }
    }
    return true;
}


void solveNQueens(int col, int boardSize, int queens[], vector<vector<int>>& solutions) {
    if (col == boardSize) {
        solutions.push_back(vector<int>(queens, queens + boardSize));
        return;
    }

    for (int row = 0; row < boardSize; row++) {
        queens[col] = row;  
        if (isValid(queens, col)) {
            solveNQueens(col + 1, boardSize, queens, solutions);
        }
    }
}

int main() {
    int boardSize;
    cin >> boardSize;

    vector<vector<int>> solutions;
    int queens[boardSize]; 

    solveNQueens(0, boardSize, queens, solutions);


    int solutionCount = 0;
    for (const auto& solution : solutions) {
        cout << ++solutionCount << '\n';
        for (int col = 0; col < boardSize; col++) {
            cout << "(" << solution[col] << ", " << col << ") ";
        }
        cout << '\n'<< endl;
    }

    cout << "Broj na resenija: " << solutionCount << '\n';
    return 0;
}
