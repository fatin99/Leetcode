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
    void deleteNode(ListNode* node) { //pointer to address of 5
        ListNode* temp = node->next; //pointer to address of 1
        node->val = node->next->val; //change value of current node from 5 to 1
        node->next = node->next->next; //skip node with original value 1 and point to next next node
        return;
    }
};

void print(ListNode* start) {
	for (ListNode* p = start; p != NULL; p = p->next) {
		cout << p->val << " ";
	}
	cout << endl;
}

int main() {
    vector<int> input = {4,5,1,9};

    ListNode node(0); // A variable of type ListNode for the "unseen" start node
	ListNode* curr = &node; // A pointer variable that stores the address of node
	for (int i = 0; i < input.size(); i++) {
		curr->next = new ListNode(input.at(i));
		curr = curr->next;
	}
    ListNode* start = node.next;

    Solution solution;
    solution.deleteNode(start->next->next);
    print(start);    
    return 0;
}
