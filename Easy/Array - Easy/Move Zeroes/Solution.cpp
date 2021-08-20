#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) != 0) {
                int temp = nums.at(count);
                nums.at(count) = nums.at(i);
                nums.at(i) = temp;
                count += 1;
            }
        }
    }
};

void print(vector<int> const &input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main() {
    Solution solution;
    vector<int> nums{0,1,0,3,12};
    solution.moveZeroes(nums);
    print(nums);
    return 0;
}
