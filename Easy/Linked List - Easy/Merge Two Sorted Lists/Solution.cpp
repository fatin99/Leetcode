#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;  
        }
        if (l2 == nullptr) {
            return l1;
        }

        ListNode* head;
        ListNode* other;
        if (l1->val <= l2->val) {
            head = l1;
            other = l2;
        } else { //l1->val > l2->val
            head = l2;
            other = l1;
        }

        ListNode* curr = head;
        while (curr != nullptr && other != nullptr) {
            if (curr->next != nullptr) {
                if (curr->next->val > other->val) {
                    ListNode* otherTemp = curr->next;
                    curr->next = other;
                    other = otherTemp;
                }
            } else { //no more nodes to check in l1, append with l2
                curr->next = other;
                other = nullptr;
            }
            curr = curr->next;
        }

        return head;
    }
};

void print(ListNode* head) {
	for (ListNode* p = head; p != nullptr; p = p->next) {
		cout << p->val << " ";
	}
	cout << endl;
}

int main() {
    vector<int> input1 = {1, 2, 4};
    vector<int> input2 = {1, 3, 4};
    ListNode node(0); // A variable of type ListNode for the "unseen" start node
	
    ListNode* curr = &node; // A pointer variable that stores the address of node
	for (int i = 0; i < input1.size(); i++) {
		curr->next = new ListNode(input1.at(i));
		curr = curr->next;
	}
    ListNode* l1 = node.next;

	curr = &node; // A pointer variable that stores the address of node
	for (int i = 0; i < input2.size(); i++) {
		curr->next = new ListNode(input2.at(i));
		curr = curr->next;
	}
    ListNode* l2 = node.next;

    Solution solution;
    print(solution.mergeTwoLists(l1, l2));
    return 0;
}
