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
    void merge(ListNode *curr_node, ListNode* curr_1, ListNode* curr_2) {
        // reach the end of both list
        if (curr_1 == nullptr && curr_2 == nullptr) {
            return;
        }
        // iterate list1: 1. list 1 val is smaller than list 2 or list2 is empty
        else if (curr_1 != nullptr && (curr_2 == nullptr || curr_1->val <= curr_2->val)) {
            ListNode* next_head = new ListNode(curr_1->val);
            // cout << "get node from list1, value is " << curr_1->val << endl;
            curr_node->next = next_head; 
            curr_node = next_head; 
            merge(next_head, curr_1->next, curr_2);
        }
        // iterate list2: 1. list 2 val is smaller than list 1 or list1 is empty
        else if (curr_2 != nullptr && (curr_1 == nullptr || curr_2->val < curr_1->val)) {
            ListNode* next_head = new ListNode(curr_2->val);
             //cout << "get node from list2, value is " << curr_2->val << endl;
            curr_node->next = next_head; 
            curr_node = next_head; 
            merge(next_head, curr_1, curr_2->next);
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // base cases 
        // 1. two lists are null, 2. only list 1 exit, 3. onlylist 3 exist
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        } else if (list1 != nullptr && list2 == nullptr) {
            return list1;
        } else if (list1 == nullptr && list2 != nullptr) {
            return list2;
        }
        ListNode* new_head = new ListNode();
        ListNode* curr_node = new_head;
        if (list1->val <= list2->val) {
            new_head->val = list1->val;
            list1 = list1->next;
        }
        else {
            new_head->val = list2->val;
            list2 = list2->next;
        }
        merge(curr_node, list1, list2); 
        return new_head;
    }
};