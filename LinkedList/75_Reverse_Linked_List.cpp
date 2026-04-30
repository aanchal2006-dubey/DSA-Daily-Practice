/* Given the head of a singly linked list, reverse the list and return the new head.

Input: head = [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1] 

Input: head = [1, 2]
Output: [2, 1]

Input: head = []
Output: []
*/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next= NULL;

        while(curr != NULL) {
            next = curr->next; // Store the next node
            curr->next = prev; // Reverse the current node's pointer
            prev = curr;       // Move prev to the current node
            curr = next;       // Move to the next node
        }
        return prev; // At the end, prev will be the new head of the reversed list
    }
};

int main() {
    int n;
    cout<<"Enter the number of nodes in the linked list: ";
    cin>>n;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout<<"Enter the values of the nodes: "<<endl;
    for(int i=0; i<n; i++) {
        int val;
        cin>>val;
        ListNode* newNode = new ListNode(val);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    cout<<"Reversed linked list: ";
    ListNode* temp = reversedHead;
    while(temp != nullptr) {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;

    return 0;
}