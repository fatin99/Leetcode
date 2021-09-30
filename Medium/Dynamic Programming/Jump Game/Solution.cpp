#include <bits/stdc++.h>
using namespace std;

class Solution {
public:    
    bool valid = false;
    bool invalid = false;
    int max;

    bool canJump(vector<int>& nums) {
        max = *max_element(nums.begin(), nums.end());
        return hasNextJump(nums.size()-1, nums);
    }    

    bool hasNextJump(int currentIndex, vector<int>& nums) {
        if (currentIndex == 0) {
            valid = true;
            return true;
        }
        int count = 1;
        for (int i = currentIndex - 1; i >= 0; i --) {
            int curr = nums[i];
            if (curr >= count) {
                hasNextJump(i, nums);
            }
            if (valid) break;
            count++;
            if (count > max) {
                invalid = true;
                break;
            }
            if (invalid) {
                break;
            }
        }
        if (valid) return true;
        else return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
    cout << solution.canJump(nums);
    return 0;
}