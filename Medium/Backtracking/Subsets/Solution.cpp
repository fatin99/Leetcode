#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> output;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack({}, nums);
        return output;
    }

    void backtrack(vector<int> curr, vector<int> nums) {
        if (curr.size() == nums.size()) {
            output.push_back(curr);
            return;
        }
        output.push_back(curr);
        for(int i = 0; i < nums.size(); i ++) { 
            if (find(curr.begin(), curr.end(), nums[i]) != curr.end()) {
                continue;
            }
            else {
                if (!curr.empty()) {
                    if (nums[i] > curr.back()) {
                        curr.push_back(nums[i]);
                        backtrack(curr, nums);
                        curr.pop_back();
                    }
                } else {
                    curr.push_back(nums[i]);
                    backtrack(curr, nums);
                    curr.pop_back();
                }
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0};
    vector<vector<int>> output = solution.subsets(nums);
    for (int i = 0; i < output.size(); i ++) {
        for (int j = 0; j < output[i].size(); j ++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}