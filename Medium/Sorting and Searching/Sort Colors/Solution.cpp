#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]] ++;
        }
        int index = 0;
        for (int i = 0; i < 3; i += 1) {
            for (int j = 0 ; j < count[i]; j ++) {
                nums[index] = i;
                index ++;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,0,2,1,1,0};
    solution.sortColors(nums);
    for (int i = 0; i < nums.size(); i ++) {
        cout << nums[i] << " ";
    }
    return 0;
}