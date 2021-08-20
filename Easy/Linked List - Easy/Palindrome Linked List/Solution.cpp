#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : 
        val(0), 
        next(nullptr) 
        {}
    ListNode(int x) : 
        val(x), 
        next(nullptr) 
        {}
    ListNode(int x, ListNode *next) : 
        val(x), 
        next(next) 
        {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> tail;
        for (ListNode* p = head; p != nullptr; p = p->next) {
            tail.push(p);
        }
        for (ListNode* p = head; p != nullptr; p = p->next) {
            if(p->val != tail.top()->val) {
                return false;
            }
            tail.pop();
        }
        return true;
    }
};

void print(ListNode* start) {
	for (ListNode* p = start; p != nullptr; p = p->next) {
		cout << p->val << " ";
	}
	cout << endl;
}

int main() {
    vector<int> input = {1,2,1,1};

    ListNode node(0); // A variable of type ListNode for the "unseen" start node
	ListNode* curr = &node; // A pointer variable that stores the address of node
	for (int i = 0; i < input.size(); i++) {
		curr->next = new ListNode(input.at(i));
		curr = curr->next;
	}
    ListNode* head = node.next;

    Solution solution;
    if (solution.isPalindrome(head)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
