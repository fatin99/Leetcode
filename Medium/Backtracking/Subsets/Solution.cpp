#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> output;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //backtrack({}, nums);
        backtrack2({}, nums, 0);
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

    void backtrack2(vector<int> curr, vector<int> nums, int start){
        output.push_back(curr);
        for(int i = start; i < nums.size(); i++){
            curr.push_back(nums[i]);
            backtrack2(curr, nums, i+1);
            curr.pop_back();
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> output = solution.subsets(nums);
    for (int i = 0; i < output.size(); i ++) {
        for (int j = 0; j < output[i].size(); j ++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}