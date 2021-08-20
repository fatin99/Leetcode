#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> primeNumbers = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 
        37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

    long long getStringHash(string s) {
        long long hash = 1;
        for (long long i = 0; i < s.length(); i += 1) {
            hash = (hash * primeNumbers[s[i] - 'a']) % 20147483593;
        }
        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long, vector<string>> umap;
        for (int i = 0; i < strs.size(); i ++) {
            long long key = getStringHash(strs[i]);
            if (umap.find(key) == umap.end()) {
                umap[key] = {strs[i]};
            } else {
                umap[key].push_back(strs[i]);
            }
        }
        vector<vector<string>> output = {};
        for (auto i : umap) {
            output.push_back(i.second);
        }
        return output;
    }

    vector<vector<string>> groupAnagrams2(vector<string>& strs) { //use sorted string as the key
        unordered_map<string, vector<string>> umap;
        for (int i = 0; i < strs.size(); i ++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            if (umap.find(key) == umap.end()) {
                umap[key] = {strs[i]};
            } else {
                umap[key].push_back(strs[i]);
            }
        }
        vector<vector<string>> output = {};
        for (auto i : umap) {
            output.push_back(i.second);
        }
        return output;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"}; 
    vector<vector<string>> matrix = solution.groupAnagrams2(strs);
    for (int i = 0; i < matrix.size(); i ++) {
        for (int j = 0; j < matrix[i].size(); j ++) {
            //cout << " " << matrix[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}