//322、零钱兑换：给出有的各种零钱金额和总金额，零钱无限，最少给钱币数。没有-1
//思路：如1 2 5，总金额12=5+5+2，每次拿能拿的最大的。但存在2 5|6，不能用最大，然后再思考倒数第二个开始。错误「可能不拿大的如 234|8不能拿3」
//然后采用自下而上动态规划，求出dp【1...n-1】dp[i]=min(dp[i-coinx+1) ，注意出事赋值amount+1，结果最后》amount说明没有硬币组合情况 -超时，cout取消
//或者：动态规划自上而下i金额看硬币要吗dp[i]=min(dp[i],dp[i-coin]+1) i代指金额。


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(n==0) return -1;
        vector<int> dp(amount+1,amount+1); //如果没有动 就是没有组合 -1，别忘了
        dp[0]=0;
        for(int i=1;i<=amount;i++) //金额dp[i]=min{dp[j-coin[x]]+1 /dp[i]}
        {
            for(int j=0;j<n;j++)
            {
                int temp=i-coins[j];
                if(temp>=0&& dp[i]>dp[temp]+1)
                {
                    dp[i]=dp[temp]+1;
                }
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};
/*
wrong思路太局限
//从最高位置挨个 使用贪心，预防 2 5|6的情况，错误-可能存在 2 3 6|10=226

写的动态规划，并且考虑了每一个值有可能组合成功吗。自下而上（超时了） 别人的动态规划时间都不超的
int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(n==0) return -1;
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1,100); //如果没有动 就是没有组合 -1，别忘了
        dp[0]=0;
        for(int i=1;i<=amount;i++) //金额dp[i]=min{dp[j-coin[x]]+1 /dp[i]}
        {
            for(int j=0;j<n;j++)
            {
                int temp=i-coins[j];
                if(temp>=0&&dp[temp]!=-1&& dp[i]>dp[temp]+1)
                {
                    dp[i]=dp[temp]+1;
                }
            }
            if(dp[i]==100) 
            dp[i]=-1; //获取失败----会超时间的，别每个for判定。
            cout<<i<<dp[i]<<endl;
        }
        return dp[amount];
    }
同一思路，别人的未超时版本。
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins)
            if (coin <= i)
                dp[i] = min(dp[i], dp[i - coin] + 1);
    }
    return dp[amount] > amount ? -1 : dp[amount];
}


*/
