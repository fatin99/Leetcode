#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct compare {
        inline bool operator() (const vector<int>& vec1, const vector<int>& vec2) {
            return (vec1[0] < vec2[0]);
        }
    };

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare());
        vector<vector<int>> output = {};
        for (int i = 0; i < intervals.size(); i ++) {
            vector<int> curr = {};
            int start = i;
            int end = i+1;
            int count = 0;
            curr.push_back(intervals[start][0]);
            int last = intervals[end-1][1];
            while(end < intervals.size()) {
                if (intervals[start][1] >= intervals[end][0]) {
                    if (intervals[start][1] < intervals[end][1]) {
                        last = intervals[end][1];
                        start = end;
                    }
                    count ++;
                    end ++;
                } else {
                    break;
                }
            }
            curr.push_back(last);
            i += count;
            output.push_back(curr);
        }
        return output;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}}; 
    //vector<vector<int>> intervals = {{1,4},{4,5}}; 
    //vector<vector<int>> intervals = {{1,4},{0,4}};
    //vector<vector<int>> intervals = {{1,4},{2,3}};  
    //vector<vector<int>> intervals = {{1,10},{4,5},{6,7},{8,9}}; 
    //vector<vector<int>> intervals = {{2,3},{5,5},{2,2},{3,4},{3,4}}; 
    vector<vector<int>> output = solution.merge(intervals);
    for (int i = 0; i < output.size(); i ++) {
        for (int j = 0; j < output[i].size(); j ++) {
            cout << " " << output[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}