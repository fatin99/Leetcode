#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        int total = m + n;
        int k = min(m,n);
        return choose(total, k);
    }

    int choose(int n, int k) {
        long long result = 1;
        for (int i = 0; i < k; i++) {
            result *= (n - i);
            result /= (i + 1);
        }
        return (int)result;
    }
};

int main() {
    Solution solution;
    int m = 51;
    int n = 9;
    cout << solution.uniquePaths(m, n);
    return 0;
}