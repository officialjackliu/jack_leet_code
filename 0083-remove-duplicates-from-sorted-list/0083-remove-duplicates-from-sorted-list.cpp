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
    ListNode* deleteDuplicates(ListNode* head) {
/*
    solving this question requires the program to "record" the visited/seen elements and remove an element if the program has seen it before 
    variable: 1. a unordered_set, 2. just a single last_seen variable 
*/
    // base case 
    if (head == nullptr) {
        return nullptr;
    }
    int prev_val = head->val; 
    ListNode* node = head;
    ListNode* prev_node = head;
    node = node->next;
    while (node != nullptr) {
        // detect a duplicate, "takes" the node out of the linked list, prev_val remains unchange
        if (node-> val == prev_val) {
            prev_node->next = node->next;
            node = node->next;
            // delete node; 
        }
        else if (node-> val != prev_val) {
            prev_val = node->val;
            // iterate to the next node 
            prev_node = prev_node->next;
            node = node->next;
        }
    }
    return head;
    }
};