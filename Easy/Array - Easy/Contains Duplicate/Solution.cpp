#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> umap;
        int size = nums.size();
        int count = 0;

        for ( int i = 0; i < nums.size(); i += 1 ) {
            int key = nums.at(i);
            if (umap.find(key) == umap.end()) {
                umap[key] = 1;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2,3,1};
    cout << solution.containsDuplicate(nums) <<endl;
    return 0;
}
