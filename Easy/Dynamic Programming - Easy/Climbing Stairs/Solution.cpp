#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>  
using namespace std;

class Solution {
public:
    unordered_map<int, int> fibonacci;

    int climbStairs(int n) { //fibonacci sequence
        if (n == 1 || n == 0) {
            return 1;
        } 
        if (fibonacci.find(n) == fibonacci.end()) {
            fibonacci[n] = climbStairs(n-1) + climbStairs(n-2);
        }
        return fibonacci[n];
    }
};

int main() {
    int n = 6;
    Solution solution;
    cout << solution.climbStairs(n) << endl;
    return 0;
}