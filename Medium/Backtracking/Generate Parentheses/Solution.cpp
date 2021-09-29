#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<string> output;

    vector<string> generateParenthesis(int n) {
        this->n = n;
        backtrack("", 0, 0);
        return output;
    }

    void backtrack(string curr, int left, int right) {
        if (curr.length() == 2 * n) {
            output.push_back(curr);
            return;
        }
        if (left < n) {
            curr += "(";
            backtrack(curr, left+1, right);
            curr.pop_back();
        }
        if (right < left) {
            curr += ")";
            backtrack(curr, left, right+1);
            curr.pop_back();
        }
    }
};

int main() {
    Solution solution;
    int n = 4;
    vector<string> output = solution.generateParenthesis(n);
    for (int i = 0; i < output.size(); i ++) {
        cout << output[i] << " ";
    }
    return 0;
}