/* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class: 
    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

Input: ["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
Output: [null,null,null,null,-3,null,0,-2]

Explanation:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/

#include<iostream>
#include<stack>
using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> minStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if(s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout<<"Minimum element: "<<minStack.getMin()<<endl; // return -3
    minStack.pop();
    cout<<"Top element: "<<minStack.top()<<endl; // return 0
    cout<<"Minimum element: "<<minStack.getMin()<<endl; // return -2

    return 0;
}