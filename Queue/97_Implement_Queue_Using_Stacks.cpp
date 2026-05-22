/* Implement a first in first out (FIFO) queue using two stacks. The implemented queue should support all the functions of a normal queue (push, pop, peek, empty). 

Implement the MyQueue class: 
    - void push (int x) pushes element x to the back of the queue.
    - int pop() removes the element from the front of the queue and returns it.
    - int peek() returns the element at the front of the queue without removing it.
    - bool empty() returns true if the queue is empty, false otherwise.

Notes: You must use only standard operations of a stack, which means only push to top, peek/pop from top, size and is empty operations are valid.

Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only standard operations of a stack.

Input: ["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output: [null, null, null, 1, 1, false]

Explanation:
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost element is the front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is now [2]
myQueue.empty(); // return False
*/

#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int front = s2.top();
        s2.pop();
        return front;
    }
    
    int peek() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost element is the front of the queue)
    cout << myQueue.peek() << endl; // return 1
    cout << myQueue.pop() << endl; // return 1, queue is now [2]
    cout << (myQueue.empty() ? "true" : "false") << endl; // return False
}