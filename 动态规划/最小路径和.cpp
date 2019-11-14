//64、最小路径和：给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小
//对于两边而言，就是一条路径，直接加和就好；对于中间部分，看x左边小还是上面小，选择小的加自身作为对应的dp，然后输出dp[m-1][n-1]；
//路径和系列真的比较简单感觉

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //cout<<m<<n;        
        vector<vector<int>> dp(m,vector<int>(n)); //定义dp，grid/dp
        dp[0][0]=grid[0][0];

        for(int i=0;i<m;i++)  //两边固定，一条路径，设置为加和
            for(int j=0;j<n;j++)
            {
                if(j==0 && i>0)
                {
                    dp[i][j]=grid[i][j]+dp[i-1][j];
                }
                if(i==0 && j>0)
                    dp[i][j]=grid[i][j]+dp[i][j-1];
            }
        for(int i=1;i<m;i++)  //其余谁小加谁
            for(int j=1;j<n;j++)
            {                
                if(dp[i-1][j]<dp[i][j-1])
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                if(dp[i-1][j]>=dp[i][j-1])
                    dp[i][j]=dp[i][j-1]+grid[i][j];
            }
        return dp[m-1][n-1];   
    }
};



