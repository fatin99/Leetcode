#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include<string>  
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0; //check for overflow
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0; //check for overflow
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

void print(vector<char> const &input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main() {
    Solution solution;
    int x = 1534236469;
    cout << solution.reverse(x) << endl;
    return 0;
}