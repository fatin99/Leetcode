#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>  
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int diff = 0;
        for (int i = 0; i < prices.size(); i ++) { //only one pass needed
            if (min > prices[i]) {
                min = prices[i];
            }
            if (diff < (prices[i] - min)) {
                diff = prices[i] - min;
            }
        }
        return diff;
    }
};

int main() {
    vector<int> prices = {7,3,9,6,8};
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}
