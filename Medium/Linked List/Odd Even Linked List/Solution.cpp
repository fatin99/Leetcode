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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) { 
        //Note: not tested locally. Equivalence of 2 ListNodes depends on memory address, NOT value. Depend on Leetcode's implementation
        if (headA == nullptr || headB == nullptr)  {
            return nullptr;
        }
    
        ListNode* currA = headA;
        ListNode* currB = headB;
    
        while( currA != currB){
            if (currA != nullptr) {
                currA = currA->next;
            } else { //if reached the end of the linked list, restart the loop
                currA = headB;
            }  
            if (currB != nullptr) {
                currB = currB->next;
            } else { //if reached the end of the linked list, restart the loop
                currB = headA;
            }  
        }

        return currA;
    }
};

void print(ListNode* start) {
	for (ListNode* p = start; p != NULL; p = p->next) {
		cout << p->val << " ";
	}
	cout << endl;
}

int main() {
    vector<int> input1 = {4,1,8,4,5};
    vector<int> input2 = {5,6,1,8,4,5};

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
    print(solution.getIntersectionNode(l1, l2));
    return 0;
}   