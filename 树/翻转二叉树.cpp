//226、翻转二叉树：翻转一棵二叉树，左和右完全相反。
//思路：就直接试试递归，左和右子树翻转。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        else
        {
            TreeNode *temp;
            temp=root->left;
            root->left=root->right;
            root->right=temp;  //inverse
            invertTree(root->left);
            invertTree(root->right);  // recursiv
        }
        return root;

    }
};
