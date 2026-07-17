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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       // 1. create variables 
       ListNode* dummy = new ListNode(0, head);
       ListNode* fast = dummy; 
       ListNode* slow = dummy;

       // 2. shift the fast pointer to create a "n" nodes gap between fast and slow 
       for (int i = 0; i < n; i++) {
            fast = fast->next;
       }

       // 3. two pointer parallel traversal, shift the slow pointer that it points to the node that needs to delete
       while (fast->next != nullptr) {
            fast = fast->next; 
            slow = slow->next;
       }

       // 4. delete the nth node 
       ListNode* delete_node = slow->next; 
       slow->next = slow->next->next; 
       delete delete_node;  
       
       // 5. return head
       return dummy->next;
    }
};