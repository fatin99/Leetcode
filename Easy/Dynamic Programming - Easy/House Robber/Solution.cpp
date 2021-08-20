#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>  
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> output = {};
        output.push_back(nums[0]);
        output.push_back(max(nums[0], nums[1]));
        for (int i = 2; i < nums.size(); ++i) {
            output.push_back(max(output[i - 1], output[i - 2] + nums[i]));
        }
        return output.back();
    }
};

int main() {
    vector<int> nums = {1,2,3,1};
    Solution solution;
    cout << solution.rob(nums) << endl;
    return 0;
}
