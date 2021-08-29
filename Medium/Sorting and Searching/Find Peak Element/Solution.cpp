#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        if (nums.size() == 2) {
            return (nums[0] > nums[1]) ? 0 : 1;
        }
        int right = nums.size()-1;
        int left = 0;
        int mid = nums.size()/2;
        while (left <= right) {
            mid = (left + right) / 2;
            int curr = nums[mid];
            if (mid == 0) {
                if (curr > nums[mid+1]) {
                    return mid;
                }
            }
            if (mid == nums.size()-1) {
                if (curr > nums[mid-1]) {
                    return mid;
                }
            }
            if (curr > nums[mid-1] && curr > nums[mid+1]) {
                return mid;
            } else if (curr > nums[mid-1] && curr < nums[mid+1]) {
                left = mid + 1;
            } else if (curr < nums[mid-1] && curr > nums[mid+1]) {
                right = mid;
            } else {
                right = mid;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,1,2};
    cout << solution.findPeakElement(nums);
    return 0;
}