#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        unordered_set<vector<int>, VectorHash> outputSet;

        if (nums.empty()) {
            return output;
        }
        
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i ++) {
            int key = nums.at(i);
            if (umap.find(key) == umap.end()) {
                umap[key] = 1;
            } else {
                umap[key] += 1;
            }
        }

        for (auto i : umap) {
            for (auto j : umap) {
                if (i.first == j.first) {
                    if (i.second < 2) {
                        continue;
                    }
                }
                int currSum = i.first + j.first;
                int key = 0 - currSum;
                if (umap.find(key) == umap.end()) {
                    continue;
                } else if (key != i.first && key != j.first) {
                    vector<int> temp = {i.first, j.first, key};
                    sort(temp.begin(), temp.end());
                    outputSet.insert(temp);
                } else if (key != i.first || key != j.first) {
                    if (umap[key] > 1) {
                        vector<int> temp = {i.first, j.first, key};
                        sort(temp.begin(), temp.end());
                        outputSet.insert(temp);
                    }
                } else {
                    if (umap[key] > 2) {
                        vector<int> temp = {i.first, j.first, key};
                        sort(temp.begin(), temp.end());
                        outputSet.insert(temp);
                    }
                }
            }
        }

        for (auto i : outputSet) { 
            output.push_back(i);
        }
        return output;
    }
};

int main() {
    Solution solution;
    vector<int> nums{-1,0,1,2,-1,-4};
    vector<vector<int>> output = solution.threeSum(nums);
    for (int i = 0; i < output.size(); i ++) {
        for (int j = 0; j < output[i].size(); j ++) {
            cout << " " << output[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}
