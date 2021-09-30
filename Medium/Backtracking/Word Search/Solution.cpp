#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> board;
    string word;
    bool found;
    int m;
    int n;

    bool exist2(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        this->found = false;
        vector<tuple<int, int>> startIndexes;
        unordered_map<int, unordered_map<int, bool>> visited;
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[i].size(); j ++) {
                visited[i][j] = false;
                if (board[i][j] == word[0]) {
                    startIndexes.push_back(make_tuple(i,j));
                }
            }
        }
        for (int i = 0; i < startIndexes.size(); i ++) {
            int row = get<0>(startIndexes[i]);
            int col = get<1>(startIndexes[i]);
            string::iterator current = next(word.begin());
            if (backtrack(current, row, col, 1, 0, visited)) {
                return true;
            }
        }
        return false;
    }

    bool exist(vector<vector<char> > &board, string word) {
        m = board.size();
        n = board[0].size();
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(isFound(board,word.c_str(), x, y)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isFound(vector<vector<char> > &board, const char* w, int x, int y) {
        if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '\0' || *w != board[x][y])
            return false;
        if(*(w+1) == '\0')
            return true;
        char t = board[x][y];
        board[x][y] = '\0';
        if(isFound(board, w + 1 , x - 1, y) || 
           isFound(board, w + 1 , x + 1, y) || 
           isFound(board, w + 1 , x , y - 1) || 
           isFound(board, w + 1 , x , y + 1))
            return true; 
        board[x][y] = t;
        return false;
    }

    bool backtrack(string::iterator current, int row, int col, int count, int prev, unordered_map<int, unordered_map<int, bool>> visited) {
        visited[row][col] = true;
        if (count == word.length()) {
            found = true;
            return true;
        }

        char left = '0';
        char right = '0';
        char up = '0';
        char down = '0';
        if (col > 0) { 
            if (!visited[row][col-1]) {
                left = board[row][col-1];
            }
        }
        if (col < board[row].size()-1) { 
            if (!visited[row][col+1]) {
                right = board[row][col+1];
            }
        }
        if (row > 0) {
            if (!visited[row-1][col]) {
                up = board[row-1][col];
            }
        }
        if (row < board.size()-1) {
            if (!visited[row+1][col]) {
                down = board[row+1][col];
            }
        }

        if (left == *current && prev != 2) backtrack(next(current), row, col-1, count+1, 1, visited);
        if (right == *current && prev != 1) backtrack(next(current), row, col+1, count+1, 2, visited);
        if (up == *current && prev != 4) backtrack(next(current), row-1, col, count+1, 3, visited);
        if (down == *current && prev != 3) backtrack(next(current), row+1, col, count+1, 4, visited);
        
        if (found) return true;
        else return false;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {{'A','A'},
                                  {'A','A'},
                                  {'A','A'}};
    string word = "AAAAAAA";
    cout << solution.exist(board, word);
    return 0;
}