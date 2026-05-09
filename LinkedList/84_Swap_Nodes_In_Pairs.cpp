/* Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed).

Input: head = [1,2,3,4]
Output: [2,1,4,3] 

Input: head = [1, 2, 3]
Output: [2, 1, 3] 
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* first = head;
        ListNode* second = head->next;
        
        first->next = swapPairs(second->next);
        second->next = first;
        
        return second;
    }
};

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution solution;
    ListNode* swappedHead = solution.swapPairs(head);

    // Print the swapped linked list
    ListNode* current = swappedHead;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}