/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
/*
deep copy of the list, which has n brand new nodes where node->val == original node's value

difficulty: assign position for random value, use a vector / pre-allocated 1(D) data structure to record the value (index) each random is pointing to 

hashmap of ListNode -> ListNode   
Node data strucutre in map data strucutre, maximize the map functionality and understand how to chain nodes together     
map accessing node (old) point by key element vs accessing deep copy value element point by value 
*/
    // run 1, create deep copy of original, assign the value only, acquire the index of the random?  save the random in a vector of ListNode 
    unordered_map<Node *, Node*> old_to_new;
    Node* old_curr = head; 
    while (old_curr != nullptr) {
        old_to_new[old_curr] = new Node(old_curr->val);
        old_curr = old_curr->next;
    } 
    // run 2, assign random? and chain nodes together 
    old_curr = head;
    while (old_curr != nullptr) {
        old_to_new[old_curr]->next = old_to_new[old_curr->next];
        old_to_new[old_curr]->random = old_to_new[old_curr->random];
        old_curr = old_curr->next;
    }
    return old_to_new[head];
    }
};