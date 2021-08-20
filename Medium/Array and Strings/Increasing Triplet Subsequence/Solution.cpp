#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        map<int, int> umap;
        vector<int> list;
        for (int i = 0; i < nums.size(); i ++) {
            if (umap.find(nums[i]) == umap.end()) {
                umap[nums[i]] = i;
                list.push_back(nums[i]);
            }
        }
        if (list.size() < 3) {
            return false;
        }
        for (int i = 0; i < nums.size()-2; i ++) {
            int first = nums[i];
            for (int j = i+1; j < nums.size()-1; j ++) {
                int curr = nums[j];
                if (nums[j] > first) {
                    int second = nums[j];
                    for (int k = j+1; k < nums.size(); k ++) {
                        int curr = nums[k];
                        if (nums[k] > second) {
                            return true;
                        } else if (nums[k] > first) {
                            second = nums[k];
                        } else if (k < nums.size()-2) {
                            first = nums[k];
                            j = k;
                            break;
                        }
                    }
                } else {
                    first = nums[j];
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {20,100,10,12,5,13}; 
    if (solution.increasingTriplet(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}