#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> umap;
        for (int i = 0; i < s.length(); i ++){
            char key = s[i];
            if (umap.find(key) == umap.end()) {
                umap[key] = 1;
            } else {
                umap[key] += 1;
            }
        }
        for (int i = 0; i < s.length(); i ++){
            if (umap[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    string s = "loveleetcode";
    cout << solution.firstUniqChar(s) <<endl;
    return 0;
}