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
    ListNode* reverseList(ListNode* curr, ListNode* prev, int count) {
        if (count == 0) {
            return prev;
        }
        // if (curr != nullptr) {
        //     cout << "curr value is " << curr->val << endl;
        // }
        // if (prev != nullptr) {
        //     cout << "  previous value is " << prev->val << endl;
        // }
        ListNode* next_node = curr->next;
        curr->next = prev;
        count--;
        return reverseList(next_node, curr, count);
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // base case
        if (head->next == nullptr) {
            return head;
        }
        /*
            conceptually it is same as 206 but reverse partial list based on the
           range of index after modification: node (before the left) - (connect
           to) -> node (on right) node (on left) - (connects to) -> node (after
           right)
        */
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr_node = dummy;
        left++;
        right++;
        ListNode* bef_head_rev = nullptr;
        ListNode* head_rev = nullptr;
        ListNode* tail_rev = nullptr;
        ListNode* aft_tail_rev = nullptr;
        int index = 1;
        while (curr_node != nullptr) {
            if (index == left - 1) {
                bef_head_rev = curr_node;
            } else if (index == left) {
                head_rev = curr_node;
            } else if (index == right) {
                tail_rev = curr_node;
                break;
            }
            curr_node = curr_node->next;
            index++;
        }
        // establish the reverse connection
        // Add this safety check
        if (tail_rev == nullptr) {
            // Depending on requirements, this might mean 'right' exceeded the
            // list length
            return head;
        }

        aft_tail_rev = tail_rev->next;
        int count = (right - left) + 1;
        bef_head_rev->next = reverseList(head_rev, nullptr, count);
        head_rev->next = aft_tail_rev;
        return dummy->next;
    }
};