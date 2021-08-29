#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> output = {-1, -1};
        if (nums.size() == 0) {
            return output;
        }
        if (nums.size() == 1 && nums[0] == target) {
            return {0, 0};
        }
        if (nums.size() == 2) {
            if (nums[0] == target && nums[1] == target) {
                return {0, 1};
            } else if (nums[0] == target && nums[1] != target) {
                return {0, 0};
            } else if (nums[0] != target && nums[1] == target) {
                return {1, 1};
            } else {
                return output;
            }
        }
        int right = nums.size()-1;
        int left = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            int curr = nums[mid];
            if (curr == target) {
                int leftIndex = mid-1;
                while (leftIndex >= 0) {
                    int leftCurr = nums[leftIndex];
                    if (leftCurr != target) {
                        break;
                    }
                    leftIndex--;
                }
                output[0] = (leftIndex+1 >= 0) ? leftIndex+1 : 0;
                int rightIndex = mid+1;
                while (rightIndex < nums.size()) {
                    int rightCurr = nums[rightIndex];
                    if (rightCurr != target) {
                        break;
                    }
                    rightIndex++;
                }
                output[1] = (rightIndex-1 <= nums.size()-1) ? rightIndex-1 : nums.size()-1;
                break;
            } else if (mid == 0 || mid == nums.size()-1) {
                break;
            } else if (curr > target) {
                if (nums[mid-1] < target) {
                    break;
                }
                right = mid;
            } else if (curr < target) {
                if (nums[mid+1] > target) {
                    break;
                }
                left = mid + 1;
            } 
        }
        return output;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,4};
    int target = 4;
    vector<int> output = solution.searchRange(nums, target);
    for (int i = 0; i < output.size(); i ++) {
        cout << output[i] << " ";
    }
    return 0;
}