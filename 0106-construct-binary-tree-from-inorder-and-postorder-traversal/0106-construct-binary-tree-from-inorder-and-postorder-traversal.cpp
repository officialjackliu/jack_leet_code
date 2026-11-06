/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    int index = 0;
    map<int, int> map;      // map value of treenode to their index on in order, as we can access root reversely on postorder
public:
    TreeNode* helper(vector<int> &postorder, int start, int end) {
        // partition is completed 
        if (start > end) {
            return nullptr;
        }
        // debug 
        
        int rootVal = postorder[index--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = map[rootVal]; // split
        // create a 
        root->right = helper(postorder, mid + 1, end);
        root->left = helper(postorder, start, mid - 1);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // last node in postorder vec is the root
        index = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        // build the root first, then use helper to build left and right substree
        return helper(postorder, 0, postorder.size() - 1);
    }
};