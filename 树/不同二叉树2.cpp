//95、不同的二叉搜索树：给定一个整数 n，生成所有由 1 … n 为节点所组成的二叉搜索树。
//思路：重点显示出来各种树，还是利用动态规划，求长度为 2、3 的所有情况直到 n。
//那么当根是i的时候，左子树是i-1的所有可能组合，右子树不用重新计算，其实是n-i的那几个树的组合，只不过对应value+偏值i；
//如i=2，（3-4）其实是（1-2）情况对应。

//官方也有用递归的，i左边，右边，继续递归下去求解。更简单一点
//动态规划太恶心了，写了3个小时，debug疯狂，最后也不懂。反正就是前三句错了，定义，以及0/1判定有问题


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {  // so hard
public:
    vector<TreeNode*> generateTrees(int n) { 
        
        //vector<vector<TreeNode*>> dp(n+1,vector<TreeNode*>(1, NULL)); //每个dp【i】都有多个树，定义指针,只能输出一个,改成下面就好了,加判定也不行，为啥啊 不懂不懂不懂
        vector<vector<TreeNode*>> dp(1, vector<TreeNode*>(1, NULL));
        if (n+1 > dp.size())
            dp.resize(n+1);

        //dp[1].push_back(new TreeNode(1));  要不然0的时候，编译出错，特别无语
        for(int i=1;i<=n;i++) //依次求解从2到n的结果
            for(int j=1;j<=i;j++) //当前在求解i的结果
            {
                //拷贝数，只能一颗一颗拷贝，对于左/右子树所有情况的拷贝，要for
                const auto &left = dp[j - 1];  //抄的取地址，dp是指针指针
                const auto &right = dp[i - j];
                for(const auto left_ptr : left)  //左子树全部复制了，感觉是定义左指针来自left
                for(const auto right_ptr: right)
                {
                    TreeNode *temp=new TreeNode(j);
                    temp->left=left_ptr;  //可以直接用，这两种方式都可以
                   // temp->left=copy(left_ptr,0);
                    temp->right=copy(right_ptr,j);
                    //cout<<j;
                    dp[i].push_back(temp);
                }
            }
        if(n==0)
            return {};
        return dp[n];
    }

    TreeNode *copy(TreeNode *n,int offset)  //前面一定要是指针类型的树结构，对应返回
    {
        if(n==NULL)
            return NULL;
        else
        {
            TreeNode *node=new TreeNode(n->val+offset);
            node->left=copy(n->left,offset);
            node->right=copy(n->right,offset);
            return node;
        }
    }
};


/*
动态规划版本参考：（我的思路）
依次求解从1到n的结果
设当前在求解k的结果
则可以设根值r为1到k分别的情况
左子树的所有可能情况在dp[r - 1]中
右子树的所有可能情况在dp[k - r]中
备注: 右子树最终拷贝的时候启示值需要从r + 1开始

copy版本代码掠过，可以迭代/非迭代考虑 
    TreeNode *copyTree(TreeNode *root, int delta = 0) {  //c++
        auto nroot = new TreeNode(root->val + delta);
        if (root->left)
            nroot->left = copyTree(root->left, delta);
        if (root->right)
            nroot->right = copyTree(root->right, delta);
        return nroot;
    }

    vector<TreeNode*> generateTrees(int n) {
        // 使用static变量，节省用例不同用例执行时的重复求解开销。这个设定不错，但是我用报错
        static vector<vector<TreeNode*>> dp(1, vector<TreeNode*>(1, NULL));
        int c_size = n + 1; 
        int o_size = dp.size();
        if (c_size > dp.size())
            dp.resize(c_size);

        for (int i = o_size; i <= n; i++) { // 升序求解
            for (int j = 1; j <= i; j++) { // 遍历以不同的数的为根
                const auto &left = dp[j - 1];
                const auto &right = dp[i - j];
                auto &cc = dp[i];
                for (const auto left_ptr : left) // 遍历所有可能的左子树
                    for (const auto right_ptr : right) { // 遍历所有可能的右子树
                        auto root = new TreeNode(j);
                        if (j > 1)
                            root->left = copyTree(left_ptr); // 拷贝左子树
                        if (i > j)
                            root->right = copyTree(right_ptr, j); // 拷贝右子树，并加上偏移值
                        cc.push_back(root);
                    }
            }
        }
        if (n == 0)
            return {};
        return dp[n];
作者：infinite-15
链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii/solution/c-dong-tai-gui-hua-by-infinite-15-2/

递归思路的代码展示： 对于i的左边 1-i ，右边i+1 - n 都可以继续细化。如果只有一个数字，那么所有可能就是一种情况，把该数字作为一棵树。而如果是 [ ]，那就返回 null。
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n) return generate(1, n);
        else return vector<TreeNode *>{};
    }
    
    vector<TreeNode *> generate(int left, int right) {
        vector<TreeNode *> ans;
        if (left > right) {
            ans.push_back(NULL);
            return ans;
        }
        for (int i = left; i <= right; i++) {
            vector<TreeNode *> left_nodes = generate(left, i - 1);
            vector<TreeNode *> right_nodes = generate(i + 1, right);
            for (TreeNode *left_node : left_nodes) {
                for (TreeNode *right_node : right_nodes) {
                    TreeNode *t = new TreeNode(i);
                    t->left = left_node;
                    t->right = right_node;
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};

我的第一版，写了2h，找bug 1h 结果还是只能输出一个值
vector<TreeNode*> generateTrees(int n) { //只能输出一个，找bug，前三句全错
        static vector<vector<TreeNode*>> dp(n+1); //每个dp【i】都有多个树，定义指针
        dp[0]={}; //空值表示输出
        dp[1].push_back(new TreeNode(1));

        for(int i=2;i<=n;i++) //依次求解从2到n的结果
            for(int j=1;j<=i;j++) //当前在求解i的结果
            {
                //拷贝数，只能一颗一颗拷贝，对于左/右子树所有情况的拷贝，要for
                const auto &left = dp[j - 1];  //抄的取地址，dp是指针指针
                const auto &right = dp[i - j];
                for(const auto left_ptr : left)  //左子树全部复制了，感觉是定义左指针来自left
                for(const auto right_ptr: right)
                {
                    TreeNode *temp=new TreeNode(j);
                    //temp->left=copy(dp[j-1],0); //左子树的所有可能情况在dp[j - 1]中
                    //temp->right=copy(dp[i-j],j);//右子树的所有可能情况在dp[i - j]中,偏差j
                    temp->left=copy(left_ptr,0);
                    temp->right=copy(right_ptr,j);
                    cout<<j;
                    dp[i].push_back(temp);
                }
            }
        return dp[n];
    }

    TreeNode *copy(TreeNode *n,int offset)  //前面一定要是指针类型的树结构，对应返回
    {
        if(n==NULL)
            return NULL;
        else
        {
            TreeNode *node=new TreeNode(n->val+offset);
            node->left=copy(n->left,offset);
            node->right=copy(n->right,offset);
            return node;
        }
    }
*/
