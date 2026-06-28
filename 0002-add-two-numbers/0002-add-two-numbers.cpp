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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // just compute left to right, bring carry on number, no create new list
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        int sum = 0, carry_on = 0;
        ListNode* sum_head = new ListNode();
        ListNode* sum_node = sum_head;
        while (node1 != nullptr && node2 != nullptr) {
            // extract value from both list
            sum = node1->val + node2->val + carry_on;
            int digit = sum % 10;
            carry_on = sum / 10;
            // create new node for the sum node, do the traversal only if there
            // is more node
            sum_node->val = digit;
            if (node1->next != nullptr && node2->next != nullptr) {
                ListNode* new_sum_node = new ListNode();
                sum_node->next = new_sum_node;
                sum_node = new_sum_node;
            }
             // traverse to the next node
                node1 = node1->next;
                node2 = node2->next;
        }

        // wrap up left over traversal if exist
        while (node1 != nullptr) {
            sum = node1->val + carry_on;
            int digit = sum % 10;
            carry_on = sum / 10;
            ListNode* new_sum_node = new ListNode();
            new_sum_node->val = digit;
            
            sum_node->next = new_sum_node;
            sum_node = new_sum_node;
            // traverse to the next node
            node1 = node1->next;
        }  
        while (node2 != nullptr) {
            sum = node2->val + carry_on;
            int digit = sum % 10;
            carry_on = sum / 10;
            ListNode* new_sum_node = new ListNode();
            new_sum_node->val = digit;
            
            sum_node->next = new_sum_node;
            sum_node = new_sum_node;
            // traverse to the next node
            node2 = node2->next;
        }
        // edge case, carry on exist, create a new node for carry on value 
        if (carry_on == 1) {
            ListNode* new_sum_node = new ListNode(1);            
            sum_node->next = new_sum_node;
            sum_node = new_sum_node;
        }
        return sum_head;
    }
};