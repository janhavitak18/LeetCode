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
        bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        bool res = isMirrored(root->left, root->right);
        root->left  = nullptr;
        root->right = nullptr;
        
        return res;
        }

    bool isMirrored(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        else if (!left || !right) return false;
        
        return (left->val == right->val) && 
            isMirrored(left->left, right->right) &&
            isMirrored(right->left, left->right);
    }

};