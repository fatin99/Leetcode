#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int carry = 0;

    void updateVal(int newVal, ListNode *curr) {
        if (newVal >= 10) {
            curr->val = newVal - 10;
            carry = 1;
        } else {
            curr->val = newVal;
            carry = 0;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1); //res=result to represent another list for result.
        ListNode* curr = res; //curr=current to loop over the result list.

        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                updateVal(l2->val + carry, curr);
                l2 = l2->next;
            } else if (l2 == nullptr) {
                updateVal(l1->val + carry, curr);
                l1 = l1->next;
            } else {
                updateVal(l1->val + l2->val + carry, curr);
                l1 = l1->next;
                l2 = l2->next;
            }
            if ((l1 != nullptr || l2 != nullptr)) {
                curr->next = new ListNode(0);
                curr = curr->next;
            }
        }

        if (carry == 1) {
            curr->next = new ListNode(1);
        }

        return res;
    }
};

void print(ListNode* start) {
	for (ListNode* p = start; p != NULL; p = p->next) {
		cout << p->val << " ";
	}
	cout << endl;
}

int main() {
    vector<int> input1 = {9,9,9,9,9,9,9};
    vector<int> input2 = {9,9,9,9};

    ListNode node1(0); // A variable of type ListNode for the "unseen" start node
	ListNode* curr = &node1; // A pointer variable that stores the address of node
	for (int i = 0; i < input1.size(); i++) {
		curr->next = new ListNode(input1.at(i));
		curr = curr->next;
	}
    ListNode* l1 = node1.next;

    ListNode node2(0); // A variable of type ListNode for the "unseen" start node
    curr = &node2; // A pointer variable that stores the address of node
	for (int i = 0; i < input2.size(); i++) {
		curr->next = new ListNode(input2.at(i));
		curr = curr->next;
	}
    ListNode* l2 = node2.next;

    Solution solution;
    ListNode* output = (solution.addTwoNumbers(l1, l2));
    print(output);
    return 0;
}   