#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int bad; 

    int firstBadVersion(int n, int bad) {
        int left = 1;
        int right = n;

        if (isBadVersion(left)) {
            return left;
        }
        if (isBadVersion(right) && !isBadVersion(right-1)) {
            return right;
        }

        while (true) {
            int mid = left/2 + right/2 + 1;
            if (!isBadVersion(mid-1) && isBadVersion(mid)){
                return mid;
            }
            if (isBadVersion(mid-1) && isBadVersion(mid)){
                right = mid-1;
            }
            if (!isBadVersion(mid-1) && !isBadVersion(mid)){
                left = mid;
            }
        }
    }

    bool isBadVersion (int num) {
        if (num >= bad) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    int n = 6;
    int bad = 6;
    Solution solution;
    solution.bad = bad;
    cout << solution.firstBadVersion(n, bad) << endl;
    return 0;
}