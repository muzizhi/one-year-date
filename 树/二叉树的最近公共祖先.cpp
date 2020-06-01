236、二叉树的最近公共祖先：两个节点的祖先，最近/层数深好；自己算自己的祖先
思路：递归判定重点，p/q是否在哪个子树，在true/不在false。优化可以同时判定，给出全局res值。
思路2: 假设已经获取了两个子树结果，递归判定，root 里面p/q只有一个，那就是这个；如果两个都没有，就返回空。

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
    TreeNode *res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool s=dfs(root,p,q);
        return res;
    }
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) { //判定p，q是否在root
        if(root==NULL) return false;
        bool lson= dfs(root->left, p,q);
        bool rson= dfs(root->right,p,q);
        //顺便进行判定，返回公共父节点 ;root =q/p 需要&&r/l吗
        if(lson&&rson || ((root->val==p->val||root->val==q->val)&&(lson||rson)) ){
            res=root;
        }
        return (root->val == p->val || root->val == q->val) ||lson||rson; //root son有就有
    }
};

    

/*
思路还是一样，只不过怎么分p/q在树的左右呢
没办法直接2选1了， 去看一下子树。
思路1: 递归判定，p/q是否在 子树范围内，在的话true，不在false。
优化可以同时判定，给出全局res值。


思路2:  假设已经获取了两个子树结果，递归判定，root 里面p/q只有一个，那就是这个； 如果两个都没有，就返回空
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        if(root == p || root == q) 
            return root;
        //假设我们获取了子函数值
        TreeNode* left =  lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
       //如果root 里面p/q只有一个，那就是这个； 如果两个都没有，就返回空
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;      
        if(left && right) // p和q在两侧
            return root;
        
        return NULL; // 必须有返回值
    }
};
*/
