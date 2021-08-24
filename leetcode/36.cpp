//
// Created by 赖於领 on 2021/8/10.
//

#include <vector>
#include <iostream>

using namespace std;

//有效的数独

class Solution {
public:

    bool isValidRowOrCol(vector<char> board) {

        char origin = board[0];

        for (int i = 1; i < board.size(); ++i) {
            if (origin == '.' || board[i] == '.') {
                continue;
            }
            if (origin == board[i]) {
                return false;
            }
        }

        return true;
    }

    bool isValidMiniSudoku(vector<vector<char>> &board, int row, int col) {

        char origin = board[row][col];
        int origin_row = row, origin_col = col;
        for (int i = 0; i < (row + 1) % 3; ++i) {
            origin_col = col;
            for (int j = 0; j < (col + 1) % 3; ++j) {
                if (origin == '.' || board[origin_row][origin_col] == '.') {
                    continue;
                }
                if (origin == board[origin_row][origin_col]) {
                    return false;
                }
            }
            origin_row++;
        }

        return true;
    }

    vector<char> getCol(vector<vector<char>> &board, int row, int col) {
        if (row == 8) {
            return {};
        }
        vector<char> result;

        for (int i = row; i < 9; ++i) {
            result.push_back(board[row][col]);
        }

        return result;
    }

    vector<char> getRow(vector<vector<char>> &board, int row, int col) {
        if (col == 8) {
            return {};
        }
        vector<char> result;

        for (int i = col; i < 9; ++i) {
            result.push_back(board[row][col]);
        }

        return result;
    }

    bool isValidSudoku(vector<vector<char>> &board) {

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (isValidRowOrCol(getRow(board, i, j)) && isValidRowOrCol(getCol(board, i, j)) &&
                    isValidMiniSudoku(board, i, j)) {
                } else {
                    return false;
                }
            }
        }


        return true;
    }
};

