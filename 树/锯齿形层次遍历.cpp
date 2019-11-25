//103、二叉树的锯齿形层次遍历，给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先根从左往右，再从下一级右往左进行遍历，以此类推，层与层之间交替进行）。
//上面的那个同样输入，输出：[[3],[20,9],[15,7]]
//思路：同样的队列存储操作，但是对于层数加入判定，如果tree。size是奇数层（1/3/5）就右-左，偶数（0/2/4）左-右。
//错误注意，每层队列获取之后也要逆顺序，这是逆大顺序，里面的层数判定是逆每个数替换的小顺序。
//&&发现弄复杂了，直接对于奇数层（1/3/5）层得到的临时vector逆序，不涉及队列访问。


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { //正好自己再次试一下队列
        vector<vector<int>> tree;
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL) //必须加上，根为空的判定
            return tree;
        while(!q.empty())
        {
            vector<int> temp;
            int len=q.size();//队列有几个元素目前，每个都要处理
            for(int i=0;i<len;i++)
            {
                TreeNode* node=q.front();
                temp.push_back(node->val);
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            int n=tree.size();
            cout<<len<<" "<<n<<endl;
            if(n % 2==1) //奇数层 逆序 n=1 对应于 根下面的第一层子树，放在for循环外面
            {
                reverse(temp.begin(),temp.end());
            }
            tree.push_back(temp);
        }
        return tree;
    }
};






