#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;

        for ( int i = 0; i < nums.size(); i += 1 ) {
            int key = nums.at(i);
            if (umap.find(key) == umap.end()) {
                umap[key] = 1;
            } else {
                umap[key] += 1;
            }
        }

        for (auto i : umap) { //iterate through hashmap to find key with value = 1
            if (i.second == 1) {
                return i.first;
            }
        }

        return 0;
    }
};

int main() {
    Solution solution;
    vector<int> nums{4,1,2,1,2};
    cout << solution.singleNumber(nums) << endl;
    return 0;
}