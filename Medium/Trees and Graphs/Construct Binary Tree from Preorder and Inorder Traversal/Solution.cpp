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
    int getIndex(int pre, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i ++) {
            if (inorder[i] == pre) {
                return i;
            }
        }
        return 0;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { //iterative
        TreeNode node = TreeNode(preorder[0]);
        TreeNode* root = &node;
        vector<TreeNode*> prev = {root};
        
        for (int i = 1; i < preorder.size(); i ++) {
            int indexCurr = getIndex(preorder[i], inorder);
            
            for (int j = prev.size()-1; j >= 0; j --) {
                int indexPrev = getIndex(prev[j]->val, inorder);
                
                if (indexPrev > indexCurr && prev[j]->left == nullptr) {
                    prev[j]->left = new TreeNode(preorder[i], nullptr, nullptr);
                    prev.insert(prev.begin()+j, prev[j]->left);
                    break;
                
                } else if (indexPrev < indexCurr && prev[j]->right == nullptr) {
                    prev[j]->right = new TreeNode(preorder[i], nullptr, nullptr);
                    prev.insert(prev.begin()+j+1, prev[j]->right);
                    break;
                }
            }
        }
        return root;
    }

    TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder) { //recursive
        return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps > pe){
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[ps]);
        int pos;
        for(int i = is; i <= ie; i++){
            if(inorder[i] == node->val){
                pos = i;
                break;
            }
        }
        node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
        node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
        return node;
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
    //vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> preorder = {1, 2, 4, 3, 5, 7, 8, 6};
    //vector<int> inorder = {4,2,5,1,6,3,7};
    vector<int> inorder = {4, 2, 1, 7, 5, 8, 3, 6};
    Solution solution;
    print(solution.buildTree(preorder, inorder));
    return 0;
}
