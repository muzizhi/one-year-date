class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int n=prices.size();
        if(n==0) return 0;
        int maxProfit=0;
        vector<int> dp1(n); dp1[0]=0;//n卖出
        vector<int> dp2(n); dp2[n-1]=0;//n天买入
        int min=prices[0],maxpri=prices[n-1];
        for(int i=1;i<n;i++){
            //每个i前后一次交易，空间换时间，数组保存每个值，i卖出//i+1买入
            min=min<=prices[i]? min:prices[i];
            dp1[i]=max(dp1[i-1],prices[i]-min);
            int j=n-1-i;
            //cout<<j<<endl;
            maxpri=maxpri>=prices[j]? maxpri:prices[j];
            dp2[j]=max(dp2[j+1],maxpri-prices[j]);

        }
        for(int i=0;i<n-1;i++){
            maxProfit= max(maxProfit,dp1[i]+dp2[i+1]);
            cout<<dp1[i]<<" "<<dp2[i+1]<<endl;
        }
        maxProfit=max(maxProfit,dp1[n-1]); //有可能只进行了一次交易最大 wrong
        return maxProfit;
    }
    /*
    int maxProfit(vector<int>& prices) { 
        int n=prices.size();
        if(n==0) return 0;
        int max=0;
        for(int i=1;i<n;i++){
            //每个i前后一次交易
            int max1=maxonce(prices,0,i);
            int max2=maxonce(prices,i+1,n-1);
            max=max>max1+max2? max:max1+max2;
        }
        return max;
    }
    int maxonce(vector<int>& prices,int l,int r) { 
        int n=prices.size();
        if(n==0) return 0;
        int max=0,min=prices[l];
        for(int i=l;i<=r;i++){
            //每个i前后一次交易
            min=min<=prices[i]? min:prices[i];
            max=max>prices[i]-min? max:prices[i]-min;
        }
        return max;
    }*/
};

/*
股票系列题目：印象中做过，两端同时进行，想不起来
可以尝试，对于每个i，假设前后各有一次交易，然后利用之前的max-min 获取两个max值，求和，更新和
超时。。 看了一圈


（1）双向选择，设定数组空间换时间，dp【i买】；dp【i卖】从后往前遍历是指，看i天买不买，即 dp2[i] = max(dp[i+1], maxval - prices[i]) 表示i-n的最大利润
dp=max（dp【i卖】+dp【i买】）
官方思路：有一个提供了一个通用框架，就是采用dp【天】【至多k次交易】【持股01】
*/
