#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>  
#include <math.h>
#include <bitset>        
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bits(n);
        for (int i = 0; i < bits.size()/2; i ++) {
            bool temp = bits[i];
            bits[i] = bits[bits.size()-1-i];
            bits[bits.size()-1-i] = temp;
        }
        return bits.to_ulong();
    }
};

int main() {
    uint32_t n = 11111111111111111111111111111101;
    Solution solution;
    cout << solution.reverseBits(n) << endl;
    return 0;
}
