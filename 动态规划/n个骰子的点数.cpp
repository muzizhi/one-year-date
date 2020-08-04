leet60、n个骰子的点数：n骰子返回数组，骰子和s从小到大的概率
思路：最小n，最大6n，分配方式：7/3=5（115 124 133 214 223 313 322 412 511）重复，有的115是3种，有的124是6种，不对。
动规：dp[n,s]= dp[n-1,s-1]+…+dp[n-1,s-i]代表n个和s的可能情况 i=6&&s-i>0，尝试ok



class Solution {
public:
    vector<double> twoSum(int n) {
        vector<vector<double>> dp(n+1,vector<double>(6*n+1));
        vector<double> res(5*n+1);
        for(int i=1;i<=6;i++){
            dp[1][i]=1;
        }
        int allsum=pow(6,n); //指数求解
        for(int i=1;i<=n;i++){
            for(int s=i;s<=6*i;s++){
                for(int j=1;j<=6;j++){
                    dp[i][s]+= s-j>0? dp[i-1][s-j]:0;
                    if(i==n){
                        res[s-i]=dp[i][s]/allsum;
                    }
                }
                //结果要dp[n,s]  s从n -6n，输出是0-5n
            }
        }
        return res;
    }
};

//分不出来规律，easy？？  s最小n，最大6n
//动规：dp[n,s]= dp[n-1,s-1]+...+dp[n-1,s-i] 可能情况 i=6&&s-i>0
/*
在上述解法的基础上，删去一个维度
for(int i=2;i<=n;i++){
        for(int j=6*n;j>=1;j--){
            int temp=0;
            for(int k=1;k<=6;k++){
                temp+=(j>=k)?dp[j-k]:0;
            }
            dp[j]=temp;
            if(i==n && j>=n){
                ans[j-i]=dp[j]/all;
            }
        }
    }
*/
