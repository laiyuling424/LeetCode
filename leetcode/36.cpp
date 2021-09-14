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

        if (board.empty()) {
            return true;
        }

        char origin = board[0];

        if (origin == '.') {
            return true;
        }

        for (int i = 1; i < board.size(); ++i) {
            if (board[i] == '.') {
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
        if (origin == '.') {
            return true;
        }
        //row 行
        //col 列
        int origin_row = row, origin_col = col;
        for (int i = row % 3;; i++) {
            if (i == 0 && (col % 3) == 0) {
                break;
            }
            for (int j = col % 3; j < 3; j++) {
                if (j == 0) {
                    break;
                }
                if (origin_row != row) {
                    j -= (col % 3);
                }
                if (board[origin_row][origin_col + j] == '.') {
                    continue;
                }
                if (origin == board[origin_row][origin_col + j]) {
                    return false;
                }
            }
            origin_row++;
            if (i == 0) {
                break;
            }
        }

        return true;
    }

    vector<char> getCol(vector<vector<char>> &board, int row, int col) {
        if (row == 8) {
            return {};
        }
        vector<char> result;

        for (int i = row; i < 9; ++i) {
            if (board[row][col] == '.') {
                continue;
            }
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
            if (board[row][col] == '.') {
                continue;
            }
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


//class Solution {
//public:
//    bool isValidSudoku(vector<vector<char>>& board) {
//        int row[9][10] = {0};// 哈希表存储每一行的每个数是否出现过，默认初始情况下，每一行每一个数都没有出现过
//        // 整个board有9行，第二维的维数10是为了让下标有9，和数独中的数字9对应。
//        int col[9][10] = {0};// 存储每一列的每个数是否出现过，默认初始情况下，每一列的每一个数都没有出现过
//        int box[9][10] = {0};// 存储每一个box的每个数是否出现过，默认初始情况下，在每个box中，每个数都没有出现过。整个board有9个box。
//        for(int i=0; i<9; i++){
//            for(int j = 0; j<9; j++){
//                // 遍历到第i行第j列的那个数,我们要判断这个数在其所在的行有没有出现过，
//                // 同时判断这个数在其所在的列有没有出现过
//                // 同时判断这个数在其所在的box中有没有出现过
//                if(board[i][j] == '.') continue;
//                int curNumber = board[i][j]-'0';
//                if(row[i][curNumber]) return false;
//                if(col[j][curNumber]) return false;
//                if(box[j/3 + (i/3)*3][curNumber]) return false;
//
//                row[i][curNumber] = 1;// 之前都没出现过，现在出现了，就给它置为1，下次再遇见就能够直接返回false了。
//                col[j][curNumber] = 1;
//                box[j/3 + (i/3)*3][curNumber] = 1;
//            }
//        }
//        return true;
//    }
//};

