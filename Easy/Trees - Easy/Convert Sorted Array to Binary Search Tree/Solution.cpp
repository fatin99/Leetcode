#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        vector<int> left = {nums.begin(), nums.begin() + mid};
        vector<int> right = {nums.begin() + 1 + mid, nums.end()};
        addNode(left, root);
        addNode(right, root);
        
        return root;
    }

    void addNode(vector<int>& nums, TreeNode* parent) {
        if (nums.empty() || parent == nullptr) {
            return;
        }
        
        int mid = nums.size() / 2;
        TreeNode* curr = new TreeNode(nums[mid]);

        if (curr->val < parent->val) {
            parent->left = curr;
        } else {
            parent->right = curr;
        }

        vector<int> left = {nums.begin(), nums.begin() + mid};
        vector<int> right = {nums.begin() + 1 + mid, nums.end()};
        addNode(left, curr);
        addNode(right, curr);
    }
};

void print(TreeNode* t, int space = 10) {
	vector<TreeNode*> parent{t};
	vector<TreeNode*> children;

	while (true) {
		bool allNull = true;
		for (int i = 0; i < parent.size(); i++) {
			if (parent.at(i)) { 
                allNull = false; 
                break; 
            }
		}

		if (allNull) {
            break;
        }
		printf("%*s", space, "");

		for (int i = 0; i < parent.size(); i++) {
			if (parent[i]) {
				cout << " " << parent[i]->val << " ";
				children.push_back(parent[i]->left);
				children.push_back(parent[i]->right);
			} else {
				cout << " " << "x" << " ";
				children.push_back(NULL);
				children.push_back(NULL);
			}
		}
		cout << endl;

		parent = children;
		children.clear();
		space -= 2;
	}
}

int main() {
    vector<int> input = {1,3};
    Solution solution;
    print(solution.sortedArrayToBST(input));  
    return 0;
}
