#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        for (int i = 0; i < haystack.size(); i ++){
            char h = haystack[i];
            if (haystack[i] == needle[0]) {
                int index = i;
                for (int j = 0; j < needle.size(); j ++) {
                    char n = needle[j];
                    h = haystack[i];
                    if (needle[j] == haystack[i]) {
                        if (j == needle.size() - 1) {
                            return index;
                        }
                        i++;
                    } else {
                        i = index;
                        break;
                    } 
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    string haystack = "mississippi";
    string needle = "issip";
    cout << solution.strStr(haystack, needle) << endl;
    return 0;
}