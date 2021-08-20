#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include<string>  
#include <math.h>      
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime = {};
        for (int i = 0; i < n; i++) {
            isPrime.push_back(true);
        }

        for (int i = 2; i * i < n; i++) { //Sieve of Eratosthenes O(n log log n)
            if (!isPrime[i]) {
                continue;
            }
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }

        int count = 0;
        for (int i = 2; i < n; i ++) {
            if (isPrime[i]) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    int n = 10;
    Solution solution;
    cout << solution.countPrimes(n) << endl;
    return 0;
}