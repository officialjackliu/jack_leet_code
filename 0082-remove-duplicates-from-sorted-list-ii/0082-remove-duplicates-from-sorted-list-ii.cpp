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
            duplicate nodes, can be multiple nodes,
            needs to delete every one of them
            slow pointer point to head of the duplicate value, fast pointer
           points to the value after
        */
        // 0. base case, 0 nodes
        if (head == nullptr) {
            return nullptr;
        }
        // 1. create a dummy variable
        ListNode* dummy = new ListNode(-1000, head);

        ListNode* slow = dummy;
        ListNode* fast = head;
        dummy->next = head;
        // int fast_val = fast->val;
        // int slow_val = slow->val;
        // 2. traversal
        // duplicate with fast == slow, iterate fast until fast != slow, delete
        // those duplicate nodes
        while (fast != nullptr && fast->next != nullptr) {
            if (fast->val == fast->next->val) {
                while (fast->next != nullptr && fast->val == fast->next->val) {
                    fast = fast->next;
                }
                slow->next = fast->next;
            }
            else {
                slow = slow->next;
            }
            fast = fast->next;
        }

        return dummy->next;
    }
};