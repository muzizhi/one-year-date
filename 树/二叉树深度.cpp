//104、二叉树的最大深度。给定一个二叉树，找出其最大深度。二叉树的深度为根节点到最远叶子节点的最长路径上的节点数
//思路：深度遍历，通过递归获取深度。叶子为0，反复向上加一，比较左右子树最大的那个。


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
    int maxDepth(TreeNode* root) { //递归不一定要写成两个函数，只要没有全局变量需要
        if(!root) //= root==null
            return 0;  //叶子对应0 层。根对应0层
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        return max(l,r)+1; //自底向上，逐步扩充，叶子1 ，然后加加加到上一级
    }
};

/*
如果想用迭代，就要利用栈/深度遍历，队列/广度层次遍历。
//深度优先：用栈的循环版
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        stack<pair<TreeNode*,int>> s;
        TreeNode* p=root;
        int Maxdeep=0;
        int deep=0;
        while(!s.empty()||p!=NULL)//若栈非空，则说明还有一些节点的右子树尚未探索；若p非空，意味着还有一些节点的左子树尚未探索
        {
            while(p!=NULL)//优先往左边走
            {
                s.push(pair<TreeNode*,int>(p,++deep));
                p=p->left;
            }
            p=s.top().first;//若左边无路，就预备右拐。右拐之前，记录右拐点的基本信息
            deep=s.top().second;
            if(Maxdeep<deep) Maxdeep=deep;//预备右拐时，比较当前节点深度和之前存储的最大深度
            s.pop();//将右拐点出栈；此时栈顶为右拐点的前一个结点。在右拐点的右子树全被遍历完后，会预备在这个节点右拐
            p=p->right;
        }
        return Maxdeep;
    }
};

作者：zzxh
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/cde-san-chong-fang-fa-shi-xian-you-zhu-jie-by-zzxh/

*/
