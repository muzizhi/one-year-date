//96.不同的二叉搜索树：给定一个整数 n，求以 1 … n 为节点组成的二叉搜索树有多少种？
//比较难想，看了解答用的是动态规划。对于每一个根i他都是由左边子树（1, 2, …, i - 1)和右边子树（i + 1, i + 2, …, n)组成的。
//因此他的个数肯定是两个子树情况的积。而且，这种根一共有n个，再将这些加起来就可以了。
//本来觉得一层循环不就直接出来了，结果懂了，如果你n=5，它并没有dp【n=2】、dp[n=3]的情况，所以没法直接带入。你要从dp[n=1\2\3\4]求完，才能在5进行调用。



class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++) //第一个循环是为了求取dp【n-1、n-2、到2】，便于最后dp【n】调用
            for(int j=1;j<=i;j++) //然后这个是用来求取 dp【i】，j从1到i，分成j左右两边情况 相乘
            {
                dp[i]=dp[i]+dp[j-1]*dp[i-j];
            }
        return dp[n];
    }
};

/*
//还有公式法，居然
事实上 G(n)函数的值被称为 卡塔兰数 ，卡塔兰数更便于计算的定义如下:
C0=1,
Cn+1=2(2n+1)/(n+2) *cn

class Solution {
public:
    int numTrees(int n) {
        long c = 1;
        for(int i = 0; i < n; i++)
            c = c * 2 * (2 * i  + 1) /(i + 2);
        return c;
    }
};

作者：jerry-peng
链接：https://leetcode-cn.com/problems/unique-binary-search-trees/solution/xi-xiang-yi-xia-huan-shi-hen-jian-dan-de-by-jerry-/

*/
