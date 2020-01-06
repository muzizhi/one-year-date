//54、螺旋矩阵：m*n的数组，输出以顺时针螺旋的方式返回数组元素。
//思路：第一行，最后一列，逆序最后一行，逆序第一列。循环，while所有的元素全部输出。
//然后设定迭代次数count++，每次循环的首位即为（c，c）注意i，j一轮循环中值变化恢复。

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0) return {};
        int n=matrix[0].size();
        vector<vector<int>> flag(m,vector<int>(n,-1));//赋值初始化 flag=-1,其实可以不要flag，while够了
        vector<int> res(m*n,0);
        int i=0,j=0,k=0,count=0;// i/m   j/n   k/m*n  count 迭代轮数
        while(k<m*n)
        {
            i=count,j=count;// 每一次循环的初始位置为 c，c
            for(j=0+count;j<n-count;j++) //回旋 按照第一行 最后一列 最后一行 第一列进行
            {
                if(flag[i][j]==-1)
                {
                    res[k]=matrix[i][j];
                    flag[i][j]=1;
                    k++;
                }
            }
            j--;
            for(i=0+count;i<m-count;i++)
            {
                if(flag[i][j]==-1)
                {
                    res[k]=matrix[i][j];
                    flag[i][j]=1;
                    k++;
                }
            }
            i--;
            //cout<<i<<j<<endl;
            for(j=n-1-count;j>=0+count;j--)
            {
                if(flag[i][j]==-1)
                {
                    res[k]=matrix[i][j];
                    flag[i][j]=1;
                    k++;
                }
            }
            j++;
            //cout<<i<<j<<endl;
            for(i=m-1-count;i>=count;i--)
            {
                if(flag[i][j]==-1)
                {
                    res[k]=matrix[i][j];
                    flag[i][j]=1;
                    k++;
                }
            }
            count++;
        }
        return res;
    }
};
