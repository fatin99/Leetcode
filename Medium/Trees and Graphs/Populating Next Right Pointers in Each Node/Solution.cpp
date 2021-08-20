#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    unordered_map<int, vector<Node*>> map;

    void preorder(Node* root, int level) {
        if (root == nullptr) {
            return;
        }
        map[level].push_back(root);
        preorder(root->left, level + 1);
        preorder(root->right, level + 1);
    }

    Node* connect(Node* root) {
        preorder(root, 0);
        for (int i = 0; map[i].size() > 0; i++) {
            for (int j = 0; j < map[i].size(); j ++) {
                if (j == map[i].size()-1) {
                    map[i][j]->next = NULL;
                } else {
                    map[i][j]->next = map[i][j+1];
                }
            }
        }
        return root;
    }
};

void read(Node* start, vector<int> input) {
    int i = 1;
	vector<Node*> parents{start};
	vector<Node*> children;
    int count = 0;

    while (i < input.size()) {
		if (count < parents.size() * 2) {
			Node* c; 
            if (input.at(i) == INT_MIN) {
                c = NULL;
            } else {
                c = new Node(input.at(i));
            }
			Node* n = parents[count / 2];
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

void print(Node* t, int space = 10) {
	vector<Node*> parent{t};
	vector<Node*> children;

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
    vector<int> input = {1,2,3,4,5,6,7};
    
    Node* start;
    if (input.size() != 0) {
        start = new Node(input.at(0));
    } else {
        start = nullptr;
    }
    read(start, input);

    Solution solution;
    print(start);  
    Node* root = solution.connect(start);
    Node* curr = root;
    while (curr != NULL) {
        cout << curr->val;
        if (curr->next == nullptr) {
            cout << "#";
            root = root->left;
            curr = root;
        } else {
            curr = curr->next;
        }
    }
    return 0;
}
