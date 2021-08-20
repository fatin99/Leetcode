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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        TreeNode* curr = root;
        unordered_map<TreeNode*, int> visited; 
        visited[curr] = 1;
        vector<TreeNode*> prev = {  };
        int height = 1;
        int max = height;
        while (true) {
            TreeNode* leftNode = curr->left;
            TreeNode* rightNode = curr->right;
            if (leftNode != nullptr && visited.find(leftNode) == visited.end()) {
                prev.push_back(curr);
                curr = leftNode;
                visited[leftNode] = 1;
                height += 1;
            } else if (rightNode != nullptr && visited.find(rightNode) == visited.end()) {
                prev.push_back(curr);
                curr = rightNode;
                visited[rightNode] = 1;
                height += 1;
            } else if (!prev.empty()) {
                curr = prev.back();
                prev.pop_back();
                if (height > max) {
                    max = height;
                }
                height -= 1;
            } else {
                break;
            }   
        }
        return max;
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
    int null = INT_MIN;
    //vector<int> input = {0,0,0,0,null,null,0,null,null,null,0};
    vector<int> input = {0};
    TreeNode* start;
    if (input.size() != 0) {
        start = new TreeNode(input.at(0));
    } else {
        start = nullptr;
    }
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

    Solution solution;
    print(start);  
    cout << solution.maxDepth(start) << endl;  
    return 0;
}
