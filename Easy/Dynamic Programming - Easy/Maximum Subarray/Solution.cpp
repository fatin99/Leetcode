#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>  
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); i ++) { //O(n2)
            int curr = nums[i];
            if (curr > max) {
                max = curr;
            }
            for (int j = i+1; j <nums.size(); j ++) {
                curr += nums[j];
                if (curr > max) {
                    max = curr;
                }
            }
        }
        return max;
    }

    int maxSubArray2(vector<int>& nums) { //O(n)
        int max_so_far = INT_MIN;
        int max_ending_here = 0;

        for (int i = 0; i < nums.size(); i ++ ) {
            max_ending_here += nums[i];
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
            }
            if (max_ending_here < 0) {
                max_ending_here = 0;
            }
        }
        return max_so_far;
    }
};

int main() {
    vector<int> prices = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solution;
    cout << solution.maxSubArray2(prices) << endl;
    return 0;
}
