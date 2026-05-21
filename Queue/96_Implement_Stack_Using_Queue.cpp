/* Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, pop, top, and empty).

Implement the MyStack class: 
    - void push (int x) pushes element x to the top of the stack
    - int pop () removes the element from the top of the stack and returns it
    - int top () returns the element at the top of the stack
    - bool empty () returns true if the stack is empty, false otherwise.

Note 1: You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.

Note 2: Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only standard operations of a queue.

Input: ["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output: [null, null, null, 2, 2, false]

Explanation:
MyStack myStack = new MyStack();
myStack.push(1); // stack is: [1]
myStack.push(2); // stack is: [1, 2] (leftmost element is the top of the stack)
myStack.top(); // return 2
myStack.pop(); // return 2, stack is now [1]
myStack.empty(); // return False
*/

#include<iostream>
#include<queue>
using namespace std;

class MyStack {
public:
    queue<int> q1, q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q1.pop();
        swap(q1, q2);
        return top;
    }
    
    int top() {
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q2.push(top);
        q1.pop();
        swap(q1, q2);
        return top;
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout << myStack.top() << endl; // return 2
    cout << myStack.pop() << endl; // return 2
    cout << myStack.empty() << endl; // return False
    return 0;
}