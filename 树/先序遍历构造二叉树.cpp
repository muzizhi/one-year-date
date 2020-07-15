1008、先序遍历构造二叉树：给一个先序列根左左左右，输出二叉树按行左右，返回根
思路：递归和迭代方式都要学习！！递归是确认上下界，然后left/right，也难。但是迭代没看太懂，利用栈。总体就是左边直接放，右边找比他大的，存最后一个弹出的作为父亲。
知识点：【2020.7.16】学习树架构/定义 hard
（1）迭代思想理解半天：将栈顶的元素作为父节点，当前先序遍历中的元素作为子节点。如果栈顶的元素值小于子节点的元素值，（则将栈顶的元素弹出并作为新的父节点，直到栈空或栈顶的元素值大于子节点的元素值。注意，这里作为父节点的是最后一个被弹出栈的元素，而不是此时栈顶的元素）-目的找右节点的父节点）；
	◦	如果父节点的元素值小于子节点的元素值，则子节点为右孩子，否则为左孩子；
	◦	将子节点放入栈中。




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
    int index=0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root=preconstruct(preorder,INT_MIN,INT_MAX);
        return root;
    }
    TreeNode* preconstruct(vector<int>& preorder,int left,int right) {
        if(index==preorder.size()){
            return NULL;
        }
        if(preorder[index]>right || preorder[index]<left){
            return NULL;
        }
        TreeNode *root=new TreeNode(preorder[index]);  //符合做root，返回
        index++;
        //可能有父子节点
        root->left=preconstruct(preorder,left,root->val);  
        root->right=preconstruct(preorder,root->val,right);
        return root; // forget
    }
};




/*
递归思路，确定上下界,


迭代-java，看了好久难理解。栈
class Solution {
  public TreeNode bstFromPreorder(int[] preorder) {
    int n = preorder.length;
    if (n == 0) return null;

    TreeNode root = new TreeNode(preorder[0]);
    Deque<TreeNode> deque = new ArrayDeque<TreeNode>();
    deque.push(root);

    for (int i = 1; i < n; i++) {
      // take the last element of the deque as a parent
      // and create a child from the next preorder element
      TreeNode node = deque.peek();
      TreeNode child = new TreeNode(preorder[i]);
      // adjust the parent 
      while (!deque.isEmpty() && deque.peek().val < child.val)
        node = deque.pop();

      // follow BST logic to create a parent-child link
      if (node.val < child.val) node.right = child;
      else node.left = child;
      // add the child into deque
      deque.push(child);
    }
    return root;
  }
}

作者：LeetCode
链接：https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/solution/jian-kong-er-cha-shu-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
