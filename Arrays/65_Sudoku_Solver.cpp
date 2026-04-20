/* Write a program to solve a sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:
    1. Each of the digits 1-9 must occur exactly once in each row.
    2. Each of the digits 1-9 must occur exactly once in each column.
    3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

The '.' character indicates empty cells.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public: 
    bool isSafe(vector<vector<char> >& board, int row, int col, char dig) {
        //horizontal
        for(int j=0; j<9; j++) {
            if(board[row][j] == dig) {
                return false;
            }
        }

        //vertical
        for(int i=0; i<9; i++) {
            if(board[i][col] == dig) {
                return false;
            }
        }

        //grid
        int srow = (row/3)*3;
        int scol = (col/3)*3;

        for(int i=srow; i<=srow+2; i++) {
            for(int j=scol; j<=scol+2; j++) {
                if(board[i][j] == dig) {
                    return false;
                }
            }
        }
        return true;
    }

    bool helper(vector<vector<char> >&board, int row, int col) {
        if(row == 9) {
            return true;
        }

        int nextRow = row, nextCol = col+1;
        if(nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        if(board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        //place the digit
        for(char dig='1'; dig<='9'; dig++) {
            if(isSafe(board, row, col, dig)) {
                board[row][col] = dig;

                if(helper(board, nextRow, nextCol)) {
                    return true;
                }

                board[row][col] = '.'; //backtracking
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char> >& board) {
        helper(board, 0, 0);
    }
};

int main() {
    Solution sol;
    // Initialize a 9x9 board with empty characters
    vector<vector<char> > board(9, vector<char>(9));

    cout << "Enter the Sudoku puzzle (9x9 grid)." << endl;
    cout << "Use 1-9 for numbers and '.' for empty cells:" << endl;

    // Standard for loop to take user input
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    cout << "\nSolving...\n" << endl;

    sol.solveSudoku(board);

    // Standard for loop to print the solved board
    cout << "Solved Sudoku Grid:" << endl;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            // Add a separator for 3x3 blocks for better readability
            if((j + 1) % 3 == 0 && j < 8) cout << "| ";
        }
        cout << endl;
        if((i + 1) % 3 == 0 && i < 8) {
            cout << "---------------------" << endl;
        }
    }

    return 0;
}