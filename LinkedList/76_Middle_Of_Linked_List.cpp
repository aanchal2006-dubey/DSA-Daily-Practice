/* Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next; // Move slow pointer by 1
            fast = fast->next->next; // Move fast pointer by 2
        }

        return slow; // When fast pointer reaches the end, slow pointer will be at the middle  
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
            temp->next = newNode;
        }
    }

    Solution solution;
    ListNode* middle = solution.middleNode(head);

    cout<<"The middle node value is: "<<middle->val<<endl;

    return 0;
}