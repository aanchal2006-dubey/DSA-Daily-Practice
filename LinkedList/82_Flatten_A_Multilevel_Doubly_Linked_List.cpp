/* You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list. 

Return the head of the flattened list. The nodes in the list may have all of their child pointers set to null.

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,9,10,11,12,4,5,6]
*/

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return NULL;

        Node* current = head;

        while (current != NULL) {
            // If we find a child list
            if (current->child != NULL) {
                // 1. Save the original next node
                Node* nextNode = current->next;

                // 2. Recursively flatten the child list
                Node* childHead = flatten(current->child);
                
                // 3. Find the tail of the flattened child list
                Node* childTail = childHead;
                while (childTail->next != NULL) {
                    childTail = childTail->next;
                }

                // 4. Connect current to the child head
                current->next = childHead;
                childHead->prev = current;
                
                // 5. Remove the child reference
                current->child = NULL;

                // 6. Connect child tail to the saved next node
                childTail->next = nextNode;
                if (nextNode != NULL) {
                    nextNode->prev = childTail;
                }
            }
            // Move to the next node
            current = current->next;
        }

        return head;
    }
};

int main() {
    // Creating Level 1: 1 <-> 2 <-> 3 <-> 4
    Node* head = new Node(1);
    head->next = new Node(2); head->next->prev = head;
    head->next->next = new Node(3); head->next->next->prev = head->next;
    head->next->next->next = new Node(4); head->next->next->next->prev = head->next->next;

    // Creating Level 2 (Child of 2): 7 <-> 8 <-> 9
    Node* child7 = new Node(7);
    Node* child8 = new Node(8);
    Node* child9 = new Node(9);
    child7->next = child8; child8->prev = child7;
    child8->next = child9; child9->prev = child8;
    
    head->next->child = child7; // Link node 2 to child 7

    // Creating Level 3 (Child of 8): 11 <-> 12
    Node* child11 = new Node(11);
    Node* child12 = new Node(12);
    child11->next = child12; child12->prev = child11;

    child8->child = child11; // Link node 8 to child 11

    Solution sol;
    Node* flattenedHead = sol.flatten(head);

    // Print the flattened list
    cout << "Flattened List: ";
    Node* curr = flattenedHead;
    while (curr != NULL) {
        cout << curr->val << (curr->next ? " <-> " : "");
        curr = curr->next;
    }
    cout << endl;

    return 0;
}