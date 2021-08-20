#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        } else if (m == 0) {
            nums1 = nums2;
            return;
        } else {
            int i = 0;
            int j = 0;
            vector<int> output = {};
            while (i < m || j < n) {
                if (i < m && j < n) {
                    if (nums1.at(i) <= nums2.at(j)) {
                        output.push_back(nums1.at(i));
                        i++;
                    } else {
                        output.push_back(nums2.at(j));
                        j++;
                    }
                } else if (i < m && j == n) {
                    output.push_back(nums1.at(i));
                    i++;
                } else if (i == m && j < n) {
                    output.push_back(nums2.at(j));
                    j++;
                }
            }
            nums1 = output;
        }
    }
};

int main() {
    vector<int> nums1 = {2, 0};
    vector<int> nums2 = {1};
    int m = 1;
    int n = 1;
    Solution solution;
    solution.merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i += 1) {
        cout << " " << nums1.at(i) << " ";
    }
    cout << endl;
    return 0;
}