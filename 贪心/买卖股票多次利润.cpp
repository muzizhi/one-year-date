//122、买卖股票的最佳时机2:数组i是股票i天价格，可多次买卖，买之前要卖，最优利润。
//思路：一次就是贪心，最小价格最大利润。多次贪心原则反而更简单：明天股票上升留着，下降卖了。所以利润就是所以上升的值加和。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(i+1<n&&prices[i]<prices[i+1])
            {
                res+=prices[i+1]-prices[i];
            }
        }
        return res;
    }
};
