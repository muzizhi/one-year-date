188、买卖股票最佳时机4:最多k次交易，最大利润和，一样规矩
思路：官方给的那个思路可以尝试一下了，dp【天】【至多k次】【持股01】。找一下状态转移方程。运行报错，where。然后又数值错误，懵不懂，k次交易必须按买入




class Solution {
public:
    int maxProfit(int maxk, vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        if(maxk>=n/2){
            int max=0;
            for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                max+=prices[i]-prices[i-1];
            }
            }
            return max;
        }
        //vector<vector<vector<int>>> dp(n); 貌似不能这样，这样会报错，时间错误找好久
        int dp[n][maxk+1][2];
        int res=0;
        for(int k=0;k<=maxk;k++){
            //初始状态
            dp[0][k][1]=-prices[0];  //no possible
            dp[0][k][0]=0;
        }
            for(int i=1;i<n;i++){
                dp[i][0][0]=0;
                dp[i][0][1]=-prices[i];// 是不是这里错了，-1太大了，后面有0-price
                for(int k=1;k<=maxk;k++){
                    dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);//i天买入股票
                    dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);//i天给卖了
                    //cout<<dp[0][0][1]<<dp[0][1][0]<<endl;
                    cout<<i<<k<<dp[i][k][0]<<endl;
                    cout<<i<<k<<dp[i][k][1]<<endl;
                    res=max(res,dp[i][k][0]);
                } 
            }
        return res;
    }
        
};

/*
上一个超时看了好久，发现一个模版，我来看看
三维dp【i 天】【k次】【1有股票】
转移方程的话：如果k》n/2，那就是随便买无约束，跟之前的题一样
如果k《n/2，有点类似上一题。
重点 设定在卖出时加1次交易次数
dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k][0]-prices[i])//i天买入股票
dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k-1][1]+prices[i]);//i天给卖了
need dp[n-1][k][0];

错误1:k加上for，要全体max
错误2:时间运行错误，我没问题啊；vector<vector<vector<int>>> dp(n)不能这样，用int表示（1h）
错误3:结果错误，为啥是7，dp[i][0][1]=-prices[i]; 成功
换了一个还是错误，我不懂我哪错了，换了k的表示成功，k交易为啥要按照买入算交易量呢，不能按卖出
dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);//i天买入股票
dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);//i天给卖了
*/
