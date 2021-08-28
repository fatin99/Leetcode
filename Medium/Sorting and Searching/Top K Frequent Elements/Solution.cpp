#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i ++) {
           if (map.find(nums[i]) == map.end()) {
               map[nums[i]] = 1;
           } else {
               map[nums[i]]++;
           }
        }
        vector<int> output = {};
        int max = 0;
        int curr = 0;
        for (int i = 0; i < k; i ++){
            for (auto i : map) { 
                if (i.second > max) {
                    max = i.second;
                    curr = i.first;
                }
            }
            output.push_back(curr);
            map[curr] = 0;
            max = 0;
        }
        return output;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1};
    int k = 1;
    vector<int> output = solution.topKFrequent(nums, k);
    for (int i = 0; i < output.size(); i ++) {
        cout << output[i] << " ";
    }
    return 0;
}