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
    int pairSum(ListNode* head) {
        // 1. find middle 
        ListNode* prev_ptr = head;
        ListNode* fast_ptr = head; 
        ListNode* slow_ptr = head; 
        while (fast_ptr != nullptr && fast_ptr -> next != nullptr) {
            prev_ptr = slow_ptr;
            slow_ptr = slow_ptr -> next; 
            fast_ptr = fast_ptr ->next -> next; 
        }
        // cut off first and second half of the Linked List
        prev_ptr->next = NULL; 
        
        // 2. reverse second half linked list, refer 206
        ListNode *prev_node = nullptr; 
        ListNode *sec_head_ptr = slow_ptr; 
        while (sec_head_ptr != nullptr) {
            ListNode *temp_ptr = sec_head_ptr ->next; 
            sec_head_ptr->next = prev_node;
            prev_node = sec_head_ptr; 
            sec_head_ptr = temp_ptr; 
        }
        // 3. compute 
        // check 
        ListNode* first_curr_ptr = head; 
        ListNode* second_curr_ptr = prev_node; 
        
        int max_val = 0; 
        int curr_val = 0;
        while (first_curr_ptr != nullptr) {
            curr_val =  first_curr_ptr->val + second_curr_ptr-> val;

            first_curr_ptr = first_curr_ptr->next;
            second_curr_ptr = second_curr_ptr->next;
            max_val = max(max_val, curr_val);
        }

        return max_val;
    }
};