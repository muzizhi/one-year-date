//100、相同二叉树：给定两个二叉树，编写一个函数来检验它们是否相同（结构、值）。
//思路：比较根，然后递归其两个子树。选好迭代终止条件，感觉这种递归每个if都有return；easy
//树和二叉搜索树构建 框架感，便于书写


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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL) //怎么设定迭代终止值，循环停止
            return true; 
        if(p!=NULL&&q!=NULL&&p->val==q->val)
        {
            
            int i=isSameTree(p->left,q->left);
            int j=isSameTree(p->right,q->right); 
            return i&&j;  //两个数，第一个return 就完了,要and
            //return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 还可以这样表达
        }
        else
            return false;
    }
};

/*上述递归，整体遍历了树一遍，时间复杂度o（n），空间复杂度最大o（n）
要学习树的基本框架，java语言
树的基本框架
void traverse(TreeNode root) {
    // root 需要做什么？在这做。
    // 其他的不用 root 操心，抛给框架
    traverse(root.left);
    traverse(root.right);
}

二叉搜索树，还可以考虑树的值大小信息
void BST(TreeNode root, int target) {
    if (root.val == target)
        // 找到目标，做点什么
    if (root.val < target) 
        BST(root.right, target);
    if (root.val > target)
        BST(root.left, target);
}

作者：labuladong
链接：https://leetcode-cn.com/problems/same-tree/solution/xie-shu-suan-fa-de-tao-lu-kuang-jia-by-wei-lai-bu-/
*/
