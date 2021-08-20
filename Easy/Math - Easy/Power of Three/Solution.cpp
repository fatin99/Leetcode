#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include<string>  
#include <math.h>      
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        while (n > 1) {
            if (n % 3 != 0) {
                return false;
            }
            n /= 3;
        }
        return true;
    }

    bool isPowerOfThree2(int n) { //Math
        return ((log10(n) / log10(3)) % 1 == 0);
    }
};

int main() {
    int n = 9;
    Solution solution;
    if (solution.isPowerOfThree(n)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}