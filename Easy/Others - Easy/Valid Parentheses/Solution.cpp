#include <iostream>
#include <vector>
#include <stack> 
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '(') {
                myStack.push(')');
            } else if (s[i] == '[') {
                myStack.push(']');
            } else if (s[i] == '{') {
                myStack.push('}');
            } else {
                if (myStack.empty()) {
                    return false;
                } else if (s[i] == myStack.top()) {
                    myStack.pop();
                } else {
                    return false;
                }
            } 
        }
        if (myStack.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution solution;
    string s = "]";
    if (solution.isValid(s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}