#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool hasDigits = false;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == ' ') {
                if (hasDigits) {
                    s.erase(i, s.length()-1);
                }
                s.erase(i, 1);
                i -= 1;
            } else if (!isdigit(s[i])) {
                if (i < s.length() - 1){
                    if (s[i] == '-' || s[i] == '+') {
                        if (hasDigits) {
                            s.erase(i, s.length()-1);
                        } else {
                            if (!isdigit(s[i+1])) {
                                if (!hasDigits) {
                                    return 0;
                                }
                                s.erase(i, 1);
                                i -= 1;
                            } else {
                                hasDigits = true;
                            }
                        }
                    } else if (s[i] == '.'){
                        if (!hasDigits) {
                            return 0;
                        } else {
                            s.erase(i, s.length()-1);
                        }
                    } else {
                        if (!hasDigits) {
                            return 0;
                        }
                        s.erase(i, s.length()-1);
                    }
                } else {
                    if (!hasDigits) {
                        return 0;
                    }
                    s.erase(i, s.length()-1);
                }
            } else {
                hasDigits = true;
            }
        }

        bool isNeg = false;
        if (s[0] == '-') {
            isNeg = true;
            s.erase(0,1);
        }
        if (s[0] == '+') {
            s.erase(0,1);
        }
        int output = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (output > INT_MAX - (s[i] - '0')) {
                if (isNeg) {
                    return INT_MIN;
                } else {
                    return INT_MAX;
                }
            }
            output += (s[i] - '0');
            if (i < s.length() - 1) {
                if (output > INT_MAX/10) {
                    if (isNeg) {
                        return INT_MIN;
                    } else {
                        return INT_MAX;
                    }
                }
                output *= 10;
            }
        }
        if (isNeg) {
            output *= (-1);
        }
        return output;
    }
};

int main() {
    Solution solution;
    string s = "  -42";
    cout << solution.myAtoi(s) <<endl;
    return 0;
}