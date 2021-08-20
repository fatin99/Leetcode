#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        for (int i = 0; i < numRows; i ++) {
            output.push_back({});
        }
        if (numRows > 0) {
            output[0] = {1};
        }
        if (numRows > 1) {
            output[1] = {1, 1};
        }
        if (numRows > 2) {
            for (int i = 2; i < numRows; i ++) {
                output[i].push_back(1);
                for (int j = 1; j < i; j ++) {
                    output[i].push_back(output[i-1][j-1] + output[i-1][j]);
                }
                output[i].push_back(1);
            }
        }
        return output;
    }
};

int main() {
    Solution solution;
    int numRows = 5;
    vector<vector<int>> output = solution.generate(numRows);
    for (int i = 0; i < output.size(); i ++) {
        for (int j = 0; j < output[i].size(); j ++) {
            cout << " " << output[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}