#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> output;
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        this->n = nums.size();
        backtrack({}, nums);
        return output;
    }

    void backtrack(vector<int> curr, vector<int> nums) {
        if (curr.size() == n) {
            output.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i ++) { 
            if (find(curr.begin(), curr.end(), nums[i]) != curr.end()) {
                continue;
            }
            else {
                curr.push_back(nums[i]);
                backtrack(curr, nums);
                curr.pop_back();
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2,};
    vector<vector<int>> output = solution.permute(nums);
    for (int i = 0; i < output.size(); i ++) {
        for (int j = 0; j < output[i].size(); j ++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}