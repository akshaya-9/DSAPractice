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
    TreeNode* prev = NULL;
    void getMin(TreeNode* root, int& mini) {
        if(root!=NULL) {
            if(root->left) getMin(root->left,mini);
            if(prev!=NULL) mini = min(mini, abs((root->val)- (prev->val)));
            prev= root;
            if(root->right) getMin(root->right, mini);
        }
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        getMin(root, mini);
        return mini;
    }
};