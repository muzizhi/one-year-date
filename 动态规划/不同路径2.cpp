//63、不同路径2，基础条件上添加障碍物，1表示障碍，0表示可通行，输入a[m][n]数组。
//思路：一样的思路，i=j=0的时候，且没有障碍物，dp[i][j]=1；其他障碍处位置dp[i][j]=0；非障碍处dp[i][j]=dp[i-1][j]+dp[i][j-1]; 
//ps 测试用例，用int可能溢出


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        //cout<<m<<n;        
        vector<vector<long int>> dp(m,vector<long int>(n)); //int 报错啦
        dp[0][0]=1;
        for(int i=0;i<m;i++)  //两边有障碍物，之后都要设置为0
            for(int j=0;j<n;j++)
            {
                if(j==0 && i>0)
                {
                    if(obstacleGrid[i][j]==1 || dp[i-1][j]==0)
                        dp[i][j]=0;
                    if(obstacleGrid[i][j]==0 && dp[i-1][j]!=0)
                        dp[i][j]=1;
                }
                if(i==0 && j>0)
                {
                    if(obstacleGrid[i][j]==1 || dp[i][j-1]==0)
                        dp[i][j]=0;
                    if(obstacleGrid[i][j]==0 && dp[i][j-1]!=0)
                        dp[i][j]=1;
                }
                if(obstacleGrid[i][j]==1)
                        dp[i][j]=0;// 有障碍物处 =0，其余相加
                
            }
        for(int i=1;i<m;i++) 
            for(int j=1;j<n;j++)
            {                
                if(obstacleGrid[i][j]==0)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        return dp[m-1][n-1];   
    }
};



