/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // If there is only one node, delete it and return an empty list
        if (head->next == nullptr) {
            return nullptr;
        }
        // brute force solution
        // get n
        ListNode* current_node = head;
        cout << "run1: current node value" << current_node->val << endl;
        int size = 0;
        while (current_node != nullptr) {
            current_node = current_node->next;
            size++;
        }
        cout << "size of linked list is  is " << size << endl;
        int to_middle = (size / 2);
        cout << "to_middle is " << to_middle << endl;
        int count = 0;
        current_node = head;
        cout << "run2: current node value" << current_node->val << endl;

        while (count < to_middle - 1) {
            current_node = current_node->next;
            count++;
        }
        // current node reaches the node before the middle node, remove the
        // middle node
        cout << "post middle run: current node value" << current_node->val
             << endl;
        ListNode* middle_node = current_node->next;
        // if (middle_node -> next != nullptr) {
        current_node->next = middle_node->next;
        // }

        return head;
    }
};