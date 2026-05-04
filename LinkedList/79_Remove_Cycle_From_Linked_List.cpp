/* Given the head of a linked list, the tast is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous note, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed, otherwise it will print false.

Input: head = 1->3->4 pos = 2
Output: true
Explanation: The linked list looks like 1->3->4->3 (with a cycle). A loop is present in the list, and it is removed.
*/

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    void removeLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                isCycle = true;
                break;
            }
        }

        if(!isCycle) {
            return ;
        }

        slow = head;
        Node* prev = NULL;

        while(slow != fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        if(prev == NULL) {
            //Move fast till last node in cycle
            while(fast->next != slow) {
                fast = fast->next;
            }
            fast->next = NULL;
        }
        else {
            prev->next = NULL;
        }
    }
};

int main() {
    int n, pos, val;
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "The list is empty." << endl;
        return 0;
    }

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Enter the position to create a cycle (0-based index, -1 for no cycle): ";
    cin >> pos;

    if (pos >= 0 && pos < n) {
        Node* cycleStartNode = head;
        for (int i = 0; i < pos; i++) {
            cycleStartNode = cycleStartNode->next;
        }
        tail->next = cycleStartNode; // Create a cycle
    }

    Solution solution;
    solution.removeLoop(head);

    // Check if the cycle is removed
    Node* temp = head;
    bool isCycleRemoved = true;
    while (temp != NULL) {
        temp = temp->next;
        if (temp == head) { // If we come back to head, cycle is not removed
            isCycleRemoved = false;
            break;
        }
    }

    cout << (isCycleRemoved ? "true" : "false") << endl;

    return 0;
}