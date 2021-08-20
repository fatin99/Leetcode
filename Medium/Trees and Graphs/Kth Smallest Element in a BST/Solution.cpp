#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
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
    int kthSmallest(TreeNode* root, int k) {
        int count = 1;
        stack<TreeNode*> stack;
        TreeNode* curr = root;
        while (!stack.empty() || curr != nullptr) {
            if (curr != nullptr) {
                stack.push(curr);
                curr = curr->left;
            }
            else {
                curr = stack.top();
                stack.pop();
                if (count == k) {
                    return curr->val;
                } else {
                    count ++;
                }
                curr = curr->right;
            }
        }
        return 0;
    }
};

void read(TreeNode* start, vector<int> input) {
    int i = 1;
	vector<TreeNode*> parents{start};
	vector<TreeNode*> children;
    int count = 0;

    while (i < input.size()) {
		if (count < parents.size() * 2) {
			TreeNode* c; 
            if (input.at(i) == INT_MIN) {
                c = NULL;
            } else {
                c = new TreeNode(input.at(i));
            }
			TreeNode* n = parents[count / 2];
			if (count % 2 == 0) {
				n->left = c;
			} else {
				n->right = c;
			}
			if (c) {
                children.push_back(c);
            }
			++count;
			++i;

		} else {
			parents = children;
			children.clear();
			count = 0;
		}
	}
}

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
    int null = INT_MIN;
    vector<int> input = {5,3,6,2,4,null,null,1};
    int k = 3;
    
    TreeNode* start;
    if (input.size() != 0) {
        start = new TreeNode(input.at(0));
    } else {
        start = nullptr;
    }
    read(start, input);

    Solution solution;
    print(start);  
    cout << solution.kthSmallest(start, k) << endl;
    return 0;
}
