#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size()-1;
        while (row < matrix.size() && col >= 0) {
            int current = matrix[row][col];
            if (current < target) {
                row++;
            } else if (current > target) {
                col--;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {{-1, 3}};
    int target = 3;
    cout << solution.searchMatrix(matrix, target);
    return 0;
}