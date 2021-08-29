#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
 
    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
 
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right]; 
        int i = left;
        for (int j = left; j <= right - 1; j++) {
            if (nums[j] >= pivot) { //Change this line to "<=" in order to get smallest
                swap(&nums[i], &nums[j]);
                i++;
            }
        }
        swap(&nums[i], &nums[right]);
        return i;
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        int pos = partition(nums, left, right);
        if (pos - left == k) {
            return nums[pos];
        }
        if (pos - left > k) {
            return quickSelect(nums, left, pos - 1, k);
        } else {
            return quickSelect(nums, pos + 1, right, k - pos + left - 1);
        }
        return -1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k-1);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << solution.findKthLargest(nums,k);
    return 0;
}