/* Given the head of a linked list, return the node where the cycle begins, if there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Input: head = [3, 2, 0, -4], pos = 1
Output: tails connedt to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
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
    ListNode* detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
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
            return NULL;
        }

        slow = head;

        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
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

    ListNode* head = NULL;
    ListNode* tail = NULL;

    cout << "Enter the node values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Enter the pos (index to connect tail to, -1 for no cycle): ";
    cin >> pos;

    // Create the cycle manually based on pos
    if (pos != -1) {
        ListNode* temp = head;
        for (int i = 0; i < pos; i++) {
            if (temp == NULL) break;
            temp = temp->next;
        }
        // Connect the last node to the node at index 'pos'
        tail->next = temp; 
    }

    Solution sol;
    ListNode* result = sol.detectCycle(head);

    if (result) {
        // To find the index of the returned node for the output message
        int index = 0;
        ListNode* temp = head;
        while (temp != result) {
            temp = temp->next;
            index++;
        }
        cout << "Tail connects to node index " << index << " (Value: " << result->val << ")" << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // Note: In a real application, you'd need to break the cycle 
    // before attempting to 'delete' nodes to avoid infinite loops.
    return 0;
}