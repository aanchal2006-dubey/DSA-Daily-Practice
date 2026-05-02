/* Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node (0-indexed).
*/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};                                 

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head == NULL) {
            return false; // An empty list cannot have a cycle
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next; // Move slow pointer by 1
            fast = fast->next->next; // Move fast pointer by 2

            if(slow == fast) { // If both pointers meet, there is a cycle
                return true;
            }
        }

        return false; // If fast pointer reaches the end, there is no cycle
    }
};

int main() {
    int n;
    cout<<"Enter the number of nodes in the linked list: ";
    cin>>n;

    ListNode* head = NULL;
    cout<<"Enter the values of the nodes: "<<endl;
    for(int i=0; i<n; i++) {
        int val;
        cin>>val;

        ListNode* newNode = new ListNode(val);

        if(head == NULL) {
            head = newNode;
        } else {
            ListNode* temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode; // Connect the last node to the new node
        }
    }

    int pos;
    cout<<"Enter the position to create a cycle (0-indexed, -1 for no cycle): ";
    cin>>pos;

    if(pos != -1) {
        ListNode* temp = head;
        for(int i=0; i<pos; i++) {
            temp = temp->next; // Move to the node at the specified position
        }
        ListNode* tail = head;
        while(tail->next != NULL) {
            tail = tail->next; // Move to the last node
        }
        tail->next = temp; // Create a cycle by connecting the last node to the node at the specified position
    }

    Solution solution;
    bool result = solution.hasCycle(head);
    if(result) {
        cout<<"The linked list has a cycle."<<endl;
    } else {
        cout<<"The linked list does not have a cycle."<<endl;
    }

    return 0;
}