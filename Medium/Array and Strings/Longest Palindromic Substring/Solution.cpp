#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string output = "";
        if (s.empty()) {
            return output;
        } if (s.length() <= 1) {
            return s.substr(0,1);
        }
        int maxCount = 0;
        for (int i = 0; i < s.length()-1; i ++) {
            int count = 0;
            if (i < s.length()-2) {
                if (s[i] == (s[i+2])) {
                    int start = i;
                    int end = i+2;
                    count = 3;
                    while (start != 0 && end != s.length()-1) {
                        start --;
                        end ++;
                        if (s[start] != s[end]) {
                            start ++;
                            end --;
                            break;
                        }
                        count += 2;
                    }
                    if (count > maxCount) {
                        maxCount = count;
                        output = s.substr(start, end-start+1);
                    }
                } 
                if (s[i] == (s[i+1])) {
                    int start = i;
                    int end = i+1;
                    count = 2;
                    while (start != 0 && end != s.length()-1) {
                        start --;
                        end ++;
                        if (s[start] != s[end]) {
                            start ++;
                            end --;
                            break;
                        }
                        count += 2;
                    }
                    if (count > maxCount) {
                        maxCount = count;
                        output = s.substr(start, end-start+1);
                    }
                } 
            } else if (s[i] == (s[i+1])) {
                int start = i;
                int end = i+1;
                count = 2;
                while (start != 0 && end != s.length()-1) {
                    start --;
                    end ++;
                    if (s[start] != s[end]) {
                        start ++;
                        end --;
                        break;
                    }
                    count += 2;
                }
                if (count > maxCount) {
                    maxCount = count;
                    output = s.substr(start, end-start+1);
                }
            } 
        }
        if (output.empty()) {
            output = s.substr(0,1);
        }
        return output;
    }
};

int main() {
    Solution solution;
    string s = "dddddddd";
    cout << solution.longestPalindrome(s) << endl;
    return 0;
}
