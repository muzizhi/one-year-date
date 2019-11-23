//101、对称二叉树：给定一个二叉树，检查它是否是镜像对称的。例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
//思路：这个怎么是easy题，我第一思路是层次遍历结果是对称的（依次输入头，左，右，遍历左右）。
//第二思路是左子树和右子树有规律，左左=右右&&左右=右左的时候，递归下去表达。


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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isSymmetric_subtree(root->left,root->right);
    }
    bool isSymmetric_subtree(TreeNode* l,TreeNode* r)
    {
        if(l==NULL&&r==NULL) //先后顺序很重要
            return true;
        if(l==NULL||r==NULL||l->val!=r->val)
            return false;
        //if(l->val==r->val)
        {
            return isSymmetric_subtree(l->left,r->right)&&isSymmetric_subtree(l->right,r->left);
        }
        //else  去掉这两行编译报错
        //懂了，要不然if if else，要不然 if if return（默认else），否则编译不了
        //    return false;
        
    }
};

/*
思路第一反应：层次遍历左右对称，麻烦
第二反应，左左=右右，左右=右左，然后迭代，但是要写两个函数。


迭代思路：
除了递归的方法外，我们也可以利用队列进行迭代。队列中每两个连续的结点应该是相等的，而且它们的子树互为镜像。最初，队列中包含的是 root 以及 root。该算法的工作原理类似于 BFS，但存在一些关键差异。每次提取两个结点并比较它们的值。然后，将两个结点的左右子结点按相反的顺序插入队列中。当队列为空时，或者我们检测到树不对称（即从队列中取出两个不相等的连续结点）时，该算法结束。
bool isSymmetric(struct TreeNode* root){
    struct TreeNode* ltree;
    struct TreeNode* rtree;
    Queue queue;

    if (root == NULL) return true;

    InitQueue(&queue);

    PushQueue(&queue, root);
    PushQueue(&queue, root);

    while (!IsEmpty(&queue)) {
        if (!PopQueue(&queue, &ltree)) return false;
        if (!PopQueue(&queue, &rtree)) return false;

        if (ltree == NULL && rtree == NULL) continue;
        if (ltree == NULL || rtree == NULL) return false;
        if (ltree->val != rtree->val) return false;

        PushQueue(&queue, ltree->left);
        PushQueue(&queue, rtree->right);
        PushQueue(&queue, ltree->right);
        PushQueue(&queue, rtree->left);
    }
    return true;
}

递归思路：
就是我的思路
我有点分不清这两个词汇了
*/
