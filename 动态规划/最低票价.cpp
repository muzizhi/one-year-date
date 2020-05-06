983、最低票价：3中票：1/7/30天，钱不同cost数组；给出时间数组，求这几天的最少钱
思路：肯定动态规划，递推关系估计是钱；dp[i 天]= min（dp[i-1]+2,dp[i-7]+7,dp[i-30]+15)
尝试状态不对，旅游天没结合。dp【i天】= min（dp[days[i-1]]+2,dp[j]+7,dp[k]+15)，j/k是前面最接近7/15天的上一个dp。
错误再看，绝了sb样例1天最贵，dp[days[0]=min。


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        if(n==0) return 0;
        int max=days[n-1]; //最大的那天；
        vector<int> dp(max+1,INT_MAX); //错误问题，min一直取0，如果不赋值的话
        dp[0]=0;
        //dp[days[0]]=costs[0];  //绝了sb样例
        dp[days[0]]=min(costs[0],min(costs[1],costs[2]));
        int i,j,k;
        for(i=1;i<n;i++){
            if(days[0]>days[i]-6 ||days[i]-6<0){
                    j=-1; 
                }               
            else{
                for(j=n-1;j>=0;j--){  //j 统计7天
                    if(days[j]<days[i]-6)
                    break;
                }
            } 
            if(days[0]>days[i]-29 ||days[i]-29<0){
                    k=-1; 
            }
            else{
                for(k=n-1;k>=0;k--){  //k 统计30天
                    if(days[k]<days[i]-30+1)
                    break;
                } 
            }
            cout<<j<<k<<endl; 
            if(i-1>=0){
                int tempj= j==-1? 0:days[j];
                int tempk= k==-1? 0:days[k];
                //cout<<tempj<<" tempk="<<tempk<<endl;
                //cout<<dp[days[i-1]]+costs[0]<<endl;
                dp[days[i]]=min(min(dp[days[i-1]]+costs[0],dp[tempj]+costs[1]), dp[tempk]+costs[2]);    
                cout<<"days[i]="<<days[i]<<" dp[days[i]]="<<dp[days[i]]<<endl;
            } 
        } 
        return dp[max]; 
    }
};


/*
dp肯定，估计是钱；dp【i 天】= min（dp[i-1]+2,dp[i-7]+7,dp[i-30]+15)
可以这样尝试一下,不对没有结合旅游 的天days[i]
dp【i 天】= min（dp[days[i-1]]+2, x +7, y +15)
x=dp[i-7]= ~ dp[days[j]] j<i-7
y=dp[i-30]=~ dp[days[k]] k<i-30

解答错误：[1,3,7] [1,4,20]  dp【days【0】】wrong
[1,4,6,7,8,20] [7,2,15]  绝了咋有这种sb例子，dp【days【0】】要取最小


官方思路差不多，他是反着，钱 dp【i到最后天】= min（dp[i-1]+2,dp[j]+7,dp[k]+15)
他的j，k是i后面最接近+7/+30的，可以一遍出来
*/
