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
    bool checker(TreeNode* A, TreeNode* B){
         if (A ==NULL && B==NULL) return true;
         if ((A !=NULL && B==NULL) || (A==NULL && B!=NULL)) return false;
         if (A->val != B->val) return false;
         bool rootLeft = checker(A->left,B->right);
         bool rootRight = checker(A->right,B->left);
        return rootLeft && rootRight;
    }
    bool isSymmetric(TreeNode* root) {
        return checker(root->left,root->right); 
    }
};

// TC:O(N) , SC:O(N) in case of skew tree it would occupy auxillary stack space
