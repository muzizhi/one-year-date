309、买卖股票含冷冻期：多次交易，每次停一天，利润
思路：按照多次k考虑，换一下。不对无k限制，无限变形。本题加入冷冻期，so 买入前
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])；dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        //int dp[n+1][2]; 
        vector<vector<int>> dp(n+1,vector<int>(2)); //不能用这个，不懂
        //初始状态
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<n;i++){
            if(i==1){
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
                dp[i][1] = max(dp[i-1][1], -prices[i]); continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        }
        return dp[n-1][0];
    }
        
};

/*
有束缚，还是按照多次k考虑，换一下冷冻，不对没有k限制，那就按照无限考虑。
那就是dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i])  //i天买了
dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]); //i天给卖了

本题加入冷冻期，so 买入前
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]) //买

*/


714、买卖股票含手续费：无限次交易，但是每一个卖出交手续费fee，利润
//思路：无限变形，同样i天卖出：dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]-fee)；
//i天买入dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(2)); //必须int2
        //初始状态
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]-fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[n-1][0];
    }
};


/*
无限变形，同样
i天卖出：dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]-fee)；
i天买入dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
*/
