#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); i++) {
            int key = nums1.at(i);
            if (umap.find(key) == umap.end()) {
                umap[key] = 1;
            } else {
                umap[key] += 1;
            }
        }

        vector<int> output;
        for (int i = 0; i < nums2.size(); i++) {
            int key = nums2.at(i);
            if (umap.find(key) != umap.end()) {
                if (umap[key] >= 1) {
                    output.push_back(key);
                    umap[key] -= 1;
                }
            } 
        }

        return output;
    }
};

void print(vector<int> const &input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main() {
    Solution solution;
    vector<int> nums1{1,2,2,1};
    vector<int> nums2{2,2};
    print(solution.intersect(nums1, nums2));
    return 0;
}
