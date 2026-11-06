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
public:
    // DFS with early break
    void traverse(TreeNode* root, int currSum, int targetSum, int & found) {
        // should not reutrn an universal false just break this subsearch
        if (root == nullptr) {
            return;
        }
        // reach a leaf node
        currSum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (currSum != targetSum) {
                return;
            }
            if (currSum == targetSum) {
                found = 1;
                return;
            }
        }
        cout << "current node is " << root->val << "    and current sum is " << currSum << endl;
        traverse(root->left, currSum, targetSum, found);
        traverse(root->right, currSum, targetSum, found);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int found = 0;
        traverse(root, 0, targetSum, found);
        return (found == 1) ? true : false;
    }
};