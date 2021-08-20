#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include<string>  
using namespace std;

class Solution {
public:
    vector<int> nums;
    vector<int> original;

    Solution(vector<int>& input) {
        nums = input;
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        nums = original;
        return nums;
    }
    
    void swap(int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> output = {};
        for (int i = 0; i < nums.size(); i += 1){
            int random = rand() % nums.size();
            swap(i, random);
        }
        return nums;
    }

    vector<int> shuffle2() { 
        vector<int> output = {};
        vector<int> temp = nums;
        while (!temp.empty()) {
            int random = rand() % temp.size();
            output.push_back(temp[random]);
            temp.erase(temp.begin()+random);
        }
        return output;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

void print (vector<int> nums) {
    for (int i = 0; i < nums.size(); i ++) {
        cout << " " << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution* obj = new Solution(nums);
    vector<int> param_1 = obj->shuffle();
    print(param_1);
    vector<int> param_2 = obj->reset();
    print(param_2);
    return 0;
}