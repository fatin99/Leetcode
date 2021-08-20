#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> umap1;
        for (int i = 0; i < s.length(); i ++){
            char key = s[i];
            if (umap1.find(key) == umap1.end()) {
                umap1[key] = 1;
            } else {
                umap1[key] += 1;
            }
        }

        unordered_map<char, int> umap2;
        for (int i = 0; i < t.length(); i ++){
            char key = t[i];
            if (umap2.find(key) == umap2.end()) {
                umap2[key] = 1;
            } else {
                umap2[key] += 1;
            }
        }

        for (auto i : umap1) { 
            if (i.second != umap2[i.first]) {
                return false;
            } 
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "rat";
    string t = "car";
    cout << solution.isAnagram(s, t) <<endl;
    return 0;
}