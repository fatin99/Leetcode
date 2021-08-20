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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; 
        ListNode* nextTemp;
        
        for (ListNode* curr = head;  curr != nullptr; curr = nextTemp) {
            nextTemp = curr->next; //ptr 2 // ptr 3
            curr->next = prev; //1 point to null //2 point to 1
            prev = curr; // ptr 1 (prev->next point to null)
        }
        return prev;
    }

    ListNode* reverseList2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* p = reverseList2(head->next);
        
        head->next->next = head;
        head->next = nullptr;
        
        return p;
    }
};

void print(ListNode* head) {
	for (ListNode* p = head; p != nullptr; p = p->next) {
		cout << p->val << " ";
	}
	cout << endl;
}

int main() {
    vector<int> input = {1,2,3,4,5};

    ListNode node(0); // A variable of type ListNode for the "unseen" start node
	ListNode* curr = &node; // A pointer variable that stores the address of node
	for (int i = 0; i < input.size(); i++) {
		curr->next = new ListNode(input.at(i));
		curr = curr->next;
	}
    ListNode* head = node.next;

    Solution solution;
    print(solution.reverseList2(head));
    return 0;
}
