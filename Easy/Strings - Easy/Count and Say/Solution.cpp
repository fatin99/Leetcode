#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1){
            return "1";
        }
        string s = countAndSay(n - 1);
        string output = "";
        for (int i = 0; i < s.length(); i ++) {
            char curr = s[i];
            char count = 1;
            for (int j = i+1; j < s.length(); j ++) {
                if (curr == s[j]){
                    count += 1;
                } else {
                    break;
                }
            }
            i += (count - 1);
            output += (count + '0');
            output += curr;
        }
        return output;
    }
};

int main() {
    Solution solution;
    int n = 4;
    cout << solution.countAndSay(4) << endl;
    return 0;
}