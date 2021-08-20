#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            int key = nums.at(i);
            if (umap.find(key) == umap.end()) {
                umap[key] = 1;
            } else {
                umap[key] += 1;
            }
        }

        int first = 0;
        int second = 0;
        for (auto i : umap) { //iterate through hashmap
            int check = target - i.first;
            if (umap.find(check) != umap.end()) { //this is the pair
                if (check == i.first) {
                    if (i.second >= 2) {
                        first = i.first;
                        second = check;
                        break;
                    }
                } else {
                    first = i.first;
                    second = check;
                    break;
                }
            }
        }

        vector<int> output;
        int indexFirst = 0;
        int indexSecond = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) == first) {
                indexFirst = i;
                break;
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums.at(i) == second) {
                indexSecond = i;
                break;
            }
        }
        if (indexFirst < indexSecond) {
            output.push_back(indexFirst);
            output.push_back(indexSecond);
        } else {
            output.push_back(indexSecond);
            output.push_back(indexFirst);
        }
        return output;
    }
};

void print(vector<int> const &input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main() {
    Solution solution;
    vector<int> nums{2,7,11,15};
    int target = 9;
    print(solution.twoSum(nums, target));
    return 0;
}
