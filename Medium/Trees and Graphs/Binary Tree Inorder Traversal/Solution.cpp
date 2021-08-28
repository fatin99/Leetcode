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
    vector<int> output = {};

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return output;
    }

    void inorder(TreeNode* curr) { //recursive
        if (curr == nullptr) {
            return;
        }
        inorder(curr->left);
        output.push_back(curr->val);
        inorder(curr->right);
    }   

    vector<int> inorderTraversal2(TreeNode* root) { //iterative
        vector<TreeNode*> visited;
        TreeNode* curr = root;
        while (!visited.empty() || curr != nullptr) {
            if (curr != nullptr) {
                visited.push_back(curr);
                curr = curr->left;
            } else {
                curr = visited.back();
                visited.pop_back();
                output.push_back(curr->val);
                curr = curr->right;
            }
        }
        return output;
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
    vector<int> input = {1,2,3,4,5,6,7};
    
    TreeNode* start;
    if (input.size() != 0) {
        start = new TreeNode(input.at(0));
    } else {
        start = nullptr;
    }
    read(start, input);

    Solution solution;
    print(start);  
    vector<int> output = solution.inorderTraversal2(start);
    for (int i = 0; i < output.size(); i++) {
        cout << " "  << output.at(i) << " ";
    }
    return 0;
}
