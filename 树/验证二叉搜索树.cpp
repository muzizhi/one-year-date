//98、给定一个二叉树，判断其是否是一个有效的二叉搜索树。假设一个二叉搜索树具有如下特征：
//节点的左子树只包含小于当前节点的数。节点的右子树只包含大于当前节点的数。所有左子树和右子树自身必须也是二叉搜索树。
//思路：判定，左要小根，右要大根，否则false，递归&&注意，右子树的所有值要大于根吗，需要！！所以递归在遍历树的时候保留上下界，每个值看是否在边界范围之内。
//官方也有用中序遍历完成的，思路很巧妙利用左根右得到的序列，是逐步变大对，否则错。



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
    bool isValidBST(TreeNode* root) {
        return validbst(root,INT64_MIN,INT64_MAX);  //用时更短20ms
        //return validbst(root,LONG_MIN,LONG_MAX);  //用时28ms
    }
    bool validbst(TreeNode* root,long int low,long int up) //赋值最大最小
    {
        if(root==NULL)
            return true;
        if(root->val<=low || root->val >= up) //根的值要在约束边界范围内。每个值进行判定
            return false;
            //return isValidBST(root->left,low,root->val)&&isValidBST(root->right,root->val,up);
            return validbst(root->left,low,root->val)&&validbst(root->right,root->val,up);
    }   
};

/*
方法一、递归，但是不能只判断上下子树。根要小于全部右子树所以版本一错误
版本一、
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left&&root->left->val >= root->val) 
            return false;
        if(root->right&&root->right->val <= root->val) 
            return false;
        else
        {
            return isValidBST(root->left)&&isValidBST(root->right);
        }
    }
版本二，应该在递归的时候同时考虑上下边界值。但是死活编译报错如下,emmm 调用错了函数

中序遍历思路：很巧妙利用左根右得到的序列，是逐步变大对，否则错。
利用二叉排序树中序遍历有序来解决。用时比较多，但是思路很清晰。
class Solution { //c++
public:
    long last = LONG_MIN; // 父节点值
    bool flag = true; // 父亲结点是否大于子节点
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        // 遍历左子树
        if(flag && root->left)
            isValidBST(root->left);
        
        // 当前结点不大于父节点，不是排序二叉树
        if(root->val <= last)
            flag = false;
        
        last = root->val; // 记录父节点值
        
        // 遍历右子树
        if(flag && root->right)
            isValidBST(root->right);
        
        // 子树都遍历完 或 不是二叉排序树，就退出
        return flag;
    }
};
官方解法 ，java 实现，其中中序序列 每一步最后一个添加的元素就足以保证树是（或不是）二叉搜索树。
因此，我们可以将步骤整合并复用空间。
class Solution { //java
  public boolean isValidBST(TreeNode root) {
    Stack<TreeNode> stack = new Stack();
    double inorder = - Double.MAX_VALUE;

    while (!stack.isEmpty() || root != null) {
      while (root != null) {
        stack.push(root);
        root = root.left;
      }
      root = stack.pop();
      if (root.val <= inorder) return false;
      inorder = root.val;
      root = root.right;
    }
    return true;
  }
}

*/
