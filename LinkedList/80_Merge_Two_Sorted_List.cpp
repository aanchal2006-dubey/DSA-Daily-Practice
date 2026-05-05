/* you are given the head of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
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
    Node* mergeTwoLists(Node* list1, Node* list2) {
        if(list1 == NULL) {
            return list2;
        }
        if(list2 == NULL) {
            return list1;
        }

        Node* head = NULL;
        Node* tail = NULL;

        if(list1->data < list2->data) {
            head = tail = list1;
            list1 = list1->next;
        }
        else {
            head = tail = list2;
            list2 = list2->next;
        }

        while(list1 != NULL && list2 != NULL) {
            if(list1->data < list2->data) {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }

        if(list1 != NULL) {
            tail->next = list1;
        }
        else {
            tail->next = list2;
        }

        return head;
    }
};

int main() {
    int n, m, val;

    cout << "Enter number of nodes in list1: ";
    cin >> n;
    Node* list1 = NULL;
    Node* tail1 = NULL;

    cout << "Enter values for list1: ";
    for(int i = 0; i < n; i++) {
        cin >> val;
        Node* newNode = new Node(val);
        if(list1 == NULL) {
            list1 = tail1 = newNode;
        }
        else {
            tail1->next = newNode;
            tail1 = tail1->next;
        }
    }

    cout << "Enter number of nodes in list2: ";
    cin >> m;
    Node* list2 = NULL;
    Node* tail2 = NULL;

    cout << "Enter values for list2: ";
    for(int i = 0; i < m; i++) {
        cin >> val;
        Node* newNode = new Node(val);
        if(list2 == NULL) {
            list2 = tail2 = newNode;
        }
        else {
            tail2->next = newNode;
            tail2 = tail2->next;
        }
    }

    Solution sol;
    Node* mergedList = sol.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    while(mergedList != NULL) {
        cout << mergedList->data << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}