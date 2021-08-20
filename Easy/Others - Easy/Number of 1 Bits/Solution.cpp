#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <bitset>        
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bits(n);
        return bits.count();
    }
}; 

int main() {
    uint32_t n = 00000000000000000000000000001011;
    Solution solution;
    cout << solution.hammingWeight(n) << endl;
    return 0;
}
