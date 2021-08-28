#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:
    unordered_map<int, vector<string>> map;

    void preorder(TreeNode* root, int level) {
        if (root == nullptr) {
            map[level].push_back("null");
            return;
        }
        map[level].push_back(to_string(root->val));
        preorder(root->left, level + 1);
        preorder(root->right, level + 1);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string output;
        preorder(root, 0);
        for (int i = 0; i < map.size()-1; i++) {
            for (int j = 0; j < map[i].size(); j ++) {
                string curr = map[i][j];
                if (curr == "null" && i == map.size()-2) {
                    for (int k = j + 1; k < map[i].size(); k ++) {
                        string next = map[i][k];
                        if (next != "null") {
                            if (i > 0) {
                                output.push_back(',');
                            }
                            output.append(curr);
                            break;
                        }
                    }
                } else {
                    if (i > 0) {
                        output.push_back(',');
                    }
                    output.append(curr);
                }
            }
        }
        return output;
    }

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

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> input = {};
        stringstream ss(data);
        if (data.size() == 0) {
            return nullptr;
        }
        while( ss.good() ) {
            string substr = "";
            getline( ss, substr, ',' );
            if (substr != "null") {
                input.push_back(stoi(substr));
            } else {
                input.push_back(INT_MIN);
            }
        }

        TreeNode* start;
        if (input.size() != 0) {
            start = new TreeNode(input.at(0));
        } else {
            return nullptr;
        }
        read(start, input);
        return start;
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
    Codec codec;
    TreeNode* output = codec.deserialize("1 2 3 # # 4 5");
    print(output);
    cout << codec.serialize(output) << endl;
    return 0;
}
