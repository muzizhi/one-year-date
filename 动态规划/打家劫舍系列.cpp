//198、打家劫舍：一个数列，盗贼不能偷连续两家，求所偷最大金额。
//思路：动态规划经典题目，dp[i]=max(dp[i-1],dp[i-2]+nums[i]。然后一个for循环结束。
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);

        }        
        return dp[n-1];
    }
};

//213、打家劫舍2:一个环形数组，首尾相连。盗贼不能同时偷两家，同样情况。
//思路：动态规划思路对，但是注意连接处。如果第一个0要，从0开始到n-2结束。如果第一个0不要，从1开始到n-1结束。尝试bingo对了
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n);
        //have no.1
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        int temp=dp[n-2];

        dp[0]=0;// don't have no.1
        dp[1]=nums[1];
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        dp[n-1]=max(dp[n-1],temp);
        return dp[n-1];
    }
};


//337、打家劫舍3:一个二叉树，不一定完全，相连不能同时偷，最大金额。 最难的
//思路：按行偷，偷父节点，只能迭代到孙子节点考虑，要不迭代儿子节点。整棵树按行考虑，感觉不太对-213空4。dp[root]=max(加root考虑孙子,不要root考虑儿子）迭代调用max。
//改进：这里的迭代重复运算多超时，所以可以用map存储搜索的节点。

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
    unordered_map<TreeNode *,int> hash;
    int rob(TreeNode* root) { //超时，所以用map图存储，所以放两个
        return robmoney(root);
    }
    int robmoney(TreeNode *node) //give max
    {
        if(!node)
        return 0;
        if(hash.count(node))
        return hash[node];   // 大佬玩法，递归中引入哈希表
        //have the root
        int res=0;
        res+=node->val;
        if(node->left)
        {
            res+=robmoney(node->left->left)+robmoney(node->left->right);
        }
        if(node->right)
            res+=robmoney(node->right->left)+robmoney(node->right->right);
        int res2=0;
        res2+=robmoney(node->left)+robmoney(node->right);
        hash[node]=max(res,res2); //我的直接输出max超时了，用hash存储,
        return hash[node];

    }
};
