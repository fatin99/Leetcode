#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> output;

        for (int i = digits.size() - 1; i >= 0; i--) {
            int insert = carry + digits.at(i);

            if (insert == 10) {
                if (i == 0) {
                    output.insert(output.begin(), 0);
                    output.insert(output.begin(), 1);
                } else {
                    output.insert(output.begin(), 0);
                    carry = 1;
                }
                
            } else {
                output.insert(output.begin(), insert);
                carry = 0;
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
    vector<int> nums{9};
    print(solution.plusOne(nums));
    return 0;
}
