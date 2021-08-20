#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int maxCount = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i ++) {
            char key = s[i];
            if (umap.find(key) == umap.end()) {
                umap[key] = i;
                count += 1;
            } else {
                i = umap[key];
                umap = unordered_map<char, int>();
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        return max(maxCount, count);
    }
};

int main() {
    Solution solution;
    string s = "";
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
