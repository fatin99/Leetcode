#include <iostream>
#include <vector>
#include <stack> 
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        int correctSum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            total += nums[i];
            correctSum += i;
        }
        return (correctSum + nums.size()) - total;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0};
    cout << solution.missingNumber(nums) << endl;
    return 0;
}