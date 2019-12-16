//121、买卖股票的最佳时机：数组第i个元素是股票第i天价格。如果只能做一笔交易输出最大利润（其实算是动态规划）
//思路：遍历一次i从第二天，i天卖货，i前最低价格买入。比较卖货中最大值。O（n^ 2）
//官方：一次遍历思路：可以维持两个变量——minprice 和 maxprofit，它们分别对应迄今为止所得到的最小的谷值和最大的利润，o（n）

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0;
        int n=prices.size();
        if(n==0)
            return max;
        int min=prices[0];//不能在for里面定义
        for(int i=1;i<n;i++) //第i天卖出货品
        {
            for(int j=0;j<i;j++) //第j天买入货品
            {
                if(min>=prices[j])
                    min=prices[j];
            }
            if(max<prices[i]-min)
                max=prices[i]-min;
        }
         return max;   
    }
};

/*
我们可以维持两个变量——minprice 和 maxprofit，它们分别对应迄今为止所得到的最小的谷值和最大的利润（卖出价格与最低价格之间的最大差值）。
Java
public class Solution {
    public int maxProfit(int prices[]) {
        int minprice = Integer.MAX_VALUE;
        int maxprofit = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
}
*/
