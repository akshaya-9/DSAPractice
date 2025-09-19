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
    bool check(TreeNode* root, long lhs, long rhs) {
        if(root==NULL) return true;
        if( root->val <= lhs || root->val >= rhs) return false;
        return check(root->left, lhs, root->val) && check(root->right, root->val, rhs );
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        return check(root, LONG_MIN, LONG_MAX);
    }
};