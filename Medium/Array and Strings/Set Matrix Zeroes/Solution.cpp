#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> columns;
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[i].size(); j ++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for (auto i : rows) { 
            vector<int> zeroes (matrix[i].size(), 0);
            matrix.at(i) = zeroes;
        }
        for (auto i : columns) {
            for (int j = 0; j < matrix.size(); j ++) {
                matrix[j][i] = 0;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    solution.setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i ++) {
        for (int j = 0; j < matrix[i].size(); j ++) {
            cout << " " << matrix[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}