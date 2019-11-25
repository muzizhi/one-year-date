//二叉树的层次遍历：给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
//如给定二叉树: [3,9,20,null,null,15,7]，输出[[3],[9,20],[15,7]]。
//思路：访问根节点输出值，然后访问左子树输出值，访问右子树输出值。递归实现，注意定义输出对应层数
// and尝试一下用队列的形式怎么进行输入，访问根放队列，每层 输出值去第一个，放左、右，到队列为空。队列个数为循环次数。


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
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q;  //定义队列
    q.push(root);  //添加元素，压入队列
    while(!q.empty())
    {
        vector<int> tmp;
        int len=q.size();
        cout<<len<<endl; //len 目前队列里 有几个节点需要迭代子树
        for(int i=0;i<len;i++){
            TreeNode* node=q.front();  //定义指针来自队列开头
            q.pop();
            tmp.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        res.push_back(tmp);
    }
    return res;
}
};


/*
要不然就是递归实现，要不然就是层次遍历用队列实现，可以尝试
递归：成功之后，运行时间0ms，但是内存占用贼大 15mb。
//我的第一版运行不了，没有办法分层
    void Order(TreeNode* root,vector<vector<int>> &tree) //remind & & &
    {
        if(root==NULL)
        {
            //return 0; //return 0 报错，但是想让它结束，然后迭代返回
            return ;
        }
        else
        {
            vector<int> layer;
            layer.push_back(root->val);
            tree.push_back(layer); //错误，这里的话 左右子树没有合并，并且访问没有按照层
            Order(root->left,tree);
            Order(root->right,tree);
        }            
    }
//第二版，然后引入深度值（注意重点，要给初始扩充，要不然没法定义）
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> tree;
        Order(root,0,tree);
        return tree;            
    }
    void Order(TreeNode* root,int depth,vector<vector<int>> &tree) //remind & & &,按照层存储
    {
        if(root==NULL)
            //return 0; //return 0 报错，但是想让它结束，然后迭代返回
            return ;
        //抄的定义，tree能到depth那里
        if (depth >= tree.size())
            tree.push_back(vector<int> {});
        //else
        {
            cout<<depth<<" "<<root->val<<endl;
            tree[depth].push_back(root->val); //要不然不能用tree【depth】表示
            Order(root->left,depth+1,tree);
            Order(root->right,depth+1,tree); //depth 会不会乱,不会，一下子访问完的
        }            
    }

队列，尝试一下：



*/
