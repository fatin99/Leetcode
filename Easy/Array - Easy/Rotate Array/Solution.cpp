#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void print(std::vector<int> const &input) {
        for (int i = 0; i < input.size(); i++) {
            std::cout << input.at(i) << ' ';
        }
    }

    void rotate(vector<int>& nums, int k) {
        vector<int> output;
        if (nums.size() == k) {
            return;
        }
        k = k % nums.size();

        for ( int i = nums.size() - k; i < nums.size(); i += 1 ) {
            if (nums.size() - k >= 0) {
                output.push_back(nums.at(i));
            }
        }

        int maxSize = nums.size() - k;
        for ( int i = 0; i < max(maxSize, 1); i += 1 ) {
            if (i < nums.size()) {
                output.push_back(nums.at(i));
            }
        }

        nums = output;
        print(nums);   
    }

    void rotate2(vector<int>& nums, int k){
        k = k % nums.size();
        int count = 0;

        for (int start = 0; count < nums.size(); start++) {
            int current = start;
            int prev = nums[start];

            do {
                int next = (current + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{1};
    int k = 1;
    solution.rotate(nums, k);
    return 0;
}
