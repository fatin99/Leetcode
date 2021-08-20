#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val; //member 1
    ListNode *next; //member 2
    
    ListNode(int x) : 
        val(x), 
        next(NULL) 
        {} 
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> umap; 
        for (ListNode* p = head; p != nullptr; p = p->next) {
            if (umap.find(p) == umap.end()) {
                umap[p] = 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

void print(ListNode* start) {
	for (ListNode* p = start; p != nullptr; p = p->next) {
		cout << p->val << " ";
	}
	cout << endl;
}

int main() {
    vector<int> input = {1};
    int pos = -1;

    ListNode node(0); // A variable of type ListNode for the "unseen" start node
	ListNode* curr = &node; // A pointer variable that stores the address of node
    ListNode* tail;
	for (int i = 0; i < input.size(); i++) {
		curr->next = new ListNode(input.at(i));
		curr = curr->next;
        if (i == pos) {
            tail = curr;
        }
	}
    ListNode* head = node.next;
    curr->next = tail;

    Solution solution;
    if (solution.hasCycle(head)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
