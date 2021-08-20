#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i = 0; i < prices.size()-1; i++) {
            int currPrice = prices.at(i);
            int nextPrice = currPrice;
            int index = i;
            for (int j = i+1; j < prices.size(); j++) {
                if (prices.at(j) > prices.at(j-1)) {
                    nextPrice = prices.at(j);
                    index = j;
                } else {
                    break;
                }
            }
            sum += (nextPrice - currPrice);
            i = index;
        }
        return sum;
    }
    
    int maxProfit2(vector<int>& prices){
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices.at(i) > prices.at(i - 1))
                maxprofit += prices.at(i) - prices.at(i - 1);
        }
        return maxprofit;
    }
};

int main() {
    Solution solution;
    vector<int> prices{7,6,4,3,1};
    cout << solution.maxProfit2(prices) <<endl;
    return 0;
}
