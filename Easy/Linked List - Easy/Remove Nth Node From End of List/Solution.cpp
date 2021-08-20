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

    void deleteNode(ListNode* node, ListNode* head, int n) {
            if (n != 1) { //not tail node
                ListNode* temp = node->next; 
                node->val = node->next->val; 
                node->next = node->next->next; 
            } else { //delete tail node
                ListNode* p = head;
                while (p->next->next != nullptr) {
                    p = p->next; //point to node before tail node
                }
                p->next = nullptr;
            }
        return;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) { //2 passes
        int size = 0;
        for (ListNode* p = head; p != nullptr; p = p->next) {
            size ++;
        }

        if (size == 1) {
            return nullptr;
        }

        ListNode* curr = head;
        for (int i = 0; i < size-n; i += 1) {
            curr = curr->next;
        }
        deleteNode(curr, head, n);

        return head;
    }

    ListNode* removeNthFromEnd2(ListNode* head, int n) { //only 1 pass
        ListNode node(0); 
	    ListNode* dummy = &node; 
        dummy->next = head;

        ListNode* first = dummy;
        ListNode* second = dummy;

        // Advances first pointer so that the gap between first and second is n nodes apart
        for (int i = 0; i < n + 1; i++) {
            first = first->next;
        }

        // Move first to the end, maintaining the gap
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;
        return dummy->next;
    }
};

void print(ListNode* head) {
	for (ListNode* p = head; p != nullptr; p = p->next) {
		cout << p->val << " ";
	}
	cout << endl;
}

int main() {
    vector<int> input = {1};
    int n = 1;

    ListNode node(0); // A variable of type ListNode for the "unseen" start node
	ListNode* curr = &node; // A pointer variable that stores the address of node
	for (int i = 0; i < input.size(); i++) {
		curr->next = new ListNode(input.at(i));
		curr = curr->next;
	}
    ListNode* head = node.next;

    Solution solution;
    print(solution.removeNthFromEnd2(head, n));
    return 0;
}
