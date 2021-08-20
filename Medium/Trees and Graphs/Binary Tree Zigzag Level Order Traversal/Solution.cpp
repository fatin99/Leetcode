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
    unordered_map<int, vector<int>> map;

    void preorder(TreeNode* root, int level) {
        if (root == nullptr) {
            return;
        }
        map[level].push_back(root->val);
        preorder(root->left, level + 1);
        preorder(root->right, level + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> output;
        preorder(root, 0);
        for (int i = 0; map[i].size() > 0; i++) {
            output.push_back({});
            if (i % 2 == 1) {
                for (int j = 0; j < map[i].size(); j ++) {
                    output.at(i).push_back(map[i][j]);
                }
            } else {
                for (int j = map[i].size()-1; j >= 0; j --) {
                    output.at(i).push_back(map[i][j]);
                }
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
    int null = INT_MIN;
    vector<int> input = {};
    
    TreeNode* start;
    if (input.size() != 0) {
        start = new TreeNode(input.at(0));
    } else {
        start = nullptr;
    }
    read(start, input);

    Solution solution;
    print(start);  
    vector<vector<int>> output = solution.zigzagLevelOrder(start);
    for (int i = 0; i < output.size(); i++) {
        vector<int> curr = output.at(i);
        for (int j = 0; j < curr.size(); j++) {
            cout << " "  << curr.at(j) << " ";
        }
        cout << endl;
    }
    return 0;
}
