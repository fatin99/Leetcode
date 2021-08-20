#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> row;
            unordered_map<char, int> col;
            for (int j = 0; j < 9; j++) {
                char rowKey = board.at(i).at(j);
                if (rowKey != '.') {
                    if (row.find(rowKey) == row.end()) { //unique char
                        row[rowKey] = 1;
                    } else { //char already exists
                        return false;
                    }
                }

                char colKey = board.at(j).at(i);
                if (colKey != '.') {
                    if (col.find(colKey) == col.end()) { //unique char
                        col[colKey] = 1;
                    } else { //char already exists
                        return false;
                    }
                }
            }
        }
        for (int countI = 0; countI < 9; countI += 3) {
            for (int countJ = 0; countJ < 9; countJ += 3) {
                unordered_map<char, int> box;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char key = board.at(i+countI).at(j+countJ);
                        if (key != '.') {
                            if (box.find(key) == box.end()) { //unique char
                                box[key] = 1;
                            } else { //char already exists
                                return false;
                            }
                        }

                    }
                }
            }
        }
        return true;
    }
};

void print(vector<int> const &input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main() {
    Solution solution;
    vector<vector<char>> board //false
    {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    vector<vector<char>> board2 //true
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    vector<vector<char>> board3 //false
    {
        {'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','1'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}
    };
    cout << boolalpha << solution.isValidSudoku(board2) << endl;
    return 0;
}
