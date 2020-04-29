//695、岛屿最大面积：0水，1土地，然后1左右上下连通，被0包围的最大面积。
//思路：结合之前还是dp。1234，if4是0，dp=0；if4=1，dp=2+3+自己；然后找最大dp。尝试错了，如果2/3都非0，dp=2+3-1+itself;又错了对于1110无法传递，45min看解析
//官方思路：深度遍历，dfs，四个方向，走过必须标记，不需要直接改为0代表不走。Ok

class Solution {
public:
    int getarea(vector<vector<int>>& grid,int i,int j){
        //判断 i和j 合法,边界时候 i-1，j-1
        if(i<0||i>=grid.size())
        return 0;
        if(j<0||j>=grid[0].size())
        return 0;
        if(grid[i][j]==0)
        return 0;
        //if (grid[i][j] == 1)
        else
        {
            grid[i][j] = 0; //标记走过的地方
            return 1 + getarea(grid, i + 1, j) + getarea(grid, i - 1, j ) + getarea(grid, i, j + 1) + getarea(grid, i, j - 1);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        int max=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) //每个点if 1，进行一次面积判定，要迭代
            {
                if(grid[i][j]==1){
                    int area=getarea(grid,i,j);
                    max=max>area? max:area;
                }
            }
        }
        return max;
    }
    
};



//按照动态规划，转移方程要注意，对于1234 中 23都大于0，1重复计算了-1；如果只有一个连通不需要-1；
//单独边界也要连接起来，但是没有-1
/*
又错了，错误例子：[[1,1],[1,0]]， 但是我输出是  1 2 2 0  这种怎么传递呢，思路确实不对，保存一下
int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();  //wrong in 111  100  100 =5
        if(m==0) return 0;
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n)); //方便，应该能化简成一维度的
        int max=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                dp[i][j]=0;
                if(i==0&&j==0)
                dp[i][j]=grid[i][j]; //边界起点
                else if(grid[i][j]==1){
                    if(i==0&&j>0)  //边界
                        dp[i][j]=dp[i][j-1]+1;
                    else if(j==0&&i>0)
                        dp[i][j]=dp[i-1][j]+1;

                    else if(dp[i-1][j]>0&&dp[i][j-1]>0)
                        dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+1; //转移方程
                    else
                        dp[i][j]=dp[i-1][j]+dp[i][j-1]+1;
                }
                if(max<dp[i][j])
                max=dp[i][j];
                cout<<dp[i][j];
            }
            cout<<endl;
        }
        return max;
    }
果然，用的是dfs，深度遍历思路做的，对于1四个方向探索，给出面积， 必须走过的标记（不需要直接改为0就不找了）
*/
