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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode*oddHead = head;
        ListNode*odd = oddHead;
        ListNode* evenHead = head->next;
        ListNode* even = evenHead;
        
        while (even->next != nullptr && odd->next != nullptr) {
            odd->next = odd->next->next;
            even->next = even->next->next; 
            odd = odd->next;
            even = even->next; 
            if (even == nullptr || odd == nullptr) {
                break;
            }
        }

        odd->next = evenHead;
        return oddHead;
    }
};

void print(ListNode* start) {
	for (ListNode* p = start; p != NULL; p = p->next) {
		cout << p->val << " ";
	}
	cout << endl;
}

int main() {
    vector<int> input = {0,1,2,3,4,5,6,7,8,9};

    ListNode node(0); // A variable of type ListNode for the "unseen" start node
	ListNode* curr = &node; // A pointer variable that stores the address of node
	for (int i = 0; i < input.size(); i++) {
		curr->next = new ListNode(input.at(i));
		curr = curr->next;
	}
    ListNode* head = node.next;

    Solution solution;
    print(solution.oddEvenList(head));
    return 0;
}   