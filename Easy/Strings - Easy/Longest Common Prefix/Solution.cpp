#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) { //prefix at start of string (not the same as substring)
        if (strs.size() == 0) {
            return "";
        }
        string prefix = strs.at(0); //check using the first string
        for (int i = 1; i < strs.size(); i ++) {
            string curr = strs.at(i); //check next string with the newly shortened prefix
            int index = curr.find(prefix); 
            while (index != 0) { //if prefix is not found in string, index = -1; if prefix is found, index = 0 (since it is at the start of the string)
                prefix = prefix.substr(0, prefix.length() - 1); //remove one character from the end
                if (prefix.length() == 0) { //all characters have been removed
                    return "";
                }
                index = curr.find(prefix); //find for prefix in current string
            }        
        }
        return prefix;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"flower","flow","flight"};
    cout << solution.longestCommonPrefix(strs) << endl;
    return 0;
}