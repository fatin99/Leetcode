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
    int hammingDistance(int x, int y) {
        bitset<32> bits(x^y);
        return bits.count();
    }
}; 

int main() {
    int x = 1;
    int y = 4;
    Solution solution;
    cout << solution.hammingDistance(x, y) << endl;
    return 0;
}
