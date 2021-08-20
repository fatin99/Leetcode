#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include<string>  
using namespace std;

class MinStack {
public:
    vector<int> stack;

    /** initialize your data structure here. */
    MinStack() {
        stack = {};
    }
    
    void push(int val) {
        stack.push_back(val);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        int min = INT_MAX;
        for (int i = 0; i < stack.size(); i ++) {
            if (stack[i] < min) {
                min = stack[i];
            }
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack minstack;
    return 0;
}