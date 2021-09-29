#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, string> numPad;
    
    vector<string> letterCombinations(string digits) {
        initialize();
		vector<string> output;
        if (digits.empty()) return output;
        output.push_back("");

        for(int i = 0; i < digits.size(); i ++) {
            char digit = digits[i];
            vector<string> temp;
            string currentLetters = numPad[digit - '0'];
            for(int j = 0; j < currentLetters.size(); j ++) {
                char candidate = currentLetters[j];
                for(int k = 0; k < output.size(); k ++) {
                    string curr = output[k];
                    temp.push_back(curr + candidate);
                }
            }
            output.swap(temp);
        }
        return output;
    }

    void initialize() {
        numPad[2] = "abc";
        numPad[3] = "def";
        numPad[4] = "ghi";
        numPad[5] = "jkl";
        numPad[6] = "mno";
        numPad[7] = "pqrs";
        numPad[8] = "tuv";
        numPad[9] = "wxyz";
    }
};

int main() {
    Solution solution;
    string digits = "23";
    vector<string> output = solution.letterCombinations(digits);
    for (int i = 0; i < output.size(); i ++) {
        cout << output[i] << " ";
    }
    return 0;
}