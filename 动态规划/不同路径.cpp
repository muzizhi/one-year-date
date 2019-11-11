//62 不同路径，从左上到右下，每次只能向下或者向右走一步，有多少路径可到达。
//思路：动态规划。如果是i行j列，i=j=0的时候，dp[i][j]=1;其他dp[i][j]=dp[i-1][j]+dp[i][j-1];然后试一下，成功 （很像杨辉三角）
//总结：排列组合，从x到y，一定向下m-1步，向右n-1步，就是先谁后谁了，Cm-1 /m+n-2 


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=1;
            }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        return dp[m-1][n-1];
    }
};


