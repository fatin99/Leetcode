#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> umap;
        int size = nums.size();
        int count = 0;

        for ( int i = 0; i < nums.size(); i += 1 ) {
            int key = nums.at(i);
            if (umap.find(key) == umap.end()) {
                umap[key] = 1;
            } else {
                count += 1;
                nums.erase(nums.begin() + i);
                i -= 1;
            }
        }

        return size - count;
    }
};

void print(std::vector<int> const &input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main() {
    Solution solution;
    vector<int> nums{1,1,2};
    cout << solution.removeDuplicates(nums) <<endl;
    print(nums);
    return 0;
}
