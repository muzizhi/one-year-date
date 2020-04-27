//120、三角形最小路径和：n行三角形每步只能去下一行相邻位置，求最小路径和
//思路：贪心感觉没法保障全局优；从上向下不知道加哪个，换个感观，后面的dp=min（上，上左）+自己； 
最后比较最后一排的dp就可以了。空间优化：2降1纬度；也可以换方向

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==0) return 0;
        vector<int> dp(n);
        dp[0]=triangle[0][0];
        int temp,pre;//pre= temp_dp(j-1)
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++){
                //j 最后一个时，没有old—dpj；
                if(j==i) dp[j]=triangle[i][j]+pre;
                temp=dp[j];
                if(j==0) dp[j]=triangle[i][j]+dp[j];
                if(j!=0&&j!=i){
                    dp[j]=triangle[i][j]+min(dp[j],pre);
                }
                pre=temp;
                cout<<dp[j]<<pre;
            }
            cout<<endl;
        }
        int min=dp[0];
        for(int j=0;j<n;j++)
        {
            if(min>dp[j])
                min=dp[j];
        }
        return min;
    }
};

/*
贪心，每次都加两个中的小的，感觉不对
动态规划思路：i0-n;j0-i； 要j +dp[j], +dp[j+1]咋选择，最终和max
换个感观，套路题，后面的dp=min（上，上左）+自己； 最后比较最后一排的dp就可以了
1 2
3 4 5

&&感觉也可以二维dp[i][j]降一维； 研究中发现相邻仅仅是两个，不是三个，不需要j+1；
dp[j]= min(dpj,temp_dpj-1)

也可以换个方向，从下往上，然后上=min（下，下右）+自己；  
*/
