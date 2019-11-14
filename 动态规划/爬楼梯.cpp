//70、爬楼梯：你每次只能走一步或者两步，n阶台阶多少种方法爬到
//思路：第一节是1，dp[2]是2，之后每节dp[i]=dp[i-1]+dp[i-2];输出dp[n]。
//注意当n=1的输出


class Solution {
public:
    int climbStairs(int n) {
        vector<long int> dp(n+1); //因为输出的是n，所以定义要定义到n+1
        dp[1]=1; //0级台阶不跳，所以设定从1开始
        if(n>1) //否则 输入n=1时，报错
            dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};



