//105、前序+中序输出树：根据一棵树的前序遍历与中序遍历构造二叉树。注意:你可以假设树中没有重复的元素。
//思路：前序提供根信息，中序有根之后，区分左右信息；然后对于左子树/右子树分别递归，继续确定根，然后左右。
//问题是怎么建立递归树的关系。直接head->left/right=递归。
//改善：如果想改善内存和速度，就另开函数，保存索引，不每次创建新的数组。


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)  //当最后（9，9）在下一步递归，就会输出9 叶子结点
            return NULL;

        TreeNode *root=new TreeNode(preorder[0]);// tree create，每次重新创建貌似也成
        vector<int> pre_left,pre_right,in_left,in_right;
        int temp_root;
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==preorder[0])
                temp_root=i;  //获取第一个根 在中序中的位置
        }
        //开始区分，左和右子树，便于后续递归
        for(int i=0;i<temp_root;i++) 
        {
            in_left.push_back(inorder[i]);
            pre_left.push_back(preorder[i+1]);//先序第一个是根，后面的对应个数为左。
        }
        for(int i=temp_root+1;i<inorder.size();i++) 
        {
            in_right.push_back(inorder[i]);
            pre_right.push_back(preorder[i]);// 右子树的 后面的对应个数一致。
        }
        //问题是怎么递归，建立左和右子树的关系？？
        root->left=buildTree(pre_left,in_left);
        root->right=buildTree(pre_right,in_right);
        return root;
    }
};


/*
c++ 简单易懂，复杂度可能有点高。
加快一下速度的话就是传引用了：就是pre/in，不变，一直只更改索引值，到还有一个值，完事
TreeNode* helper(const vector<int>& preorder, int b1, int e1, const vector<int>& inorder, int b2, int e2) {  // 结尾包含e1,e2
    // M L R    b1, e1
    // L M R    b2, e2
    if (b1 > e1) return nullptr;
    if (b1 == e1) return new TreeNode(preorder[b1]);
    TreeNode* root = new TreeNode(preorder[b1]);
    int m = 0; // size of left
    while (b2+m <= e2) {
        if (inorder[b2+m] == preorder[b1]) break;
        m++;
    }
    root->left = helper(preorder, b1+1, b1+m, inorder, b2, b2+m-1);
    root->right = helper(preorder, b1+m+1, e1, inorder, b2+m+1, e2);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) return nullptr;
    return helper(preorder,0,(int)preorder.size()-1, inorder,0,(int)inorder.size()-1);
}


*/





