//59、螺旋矩阵2:给定一个数n，获取按照螺旋1-n^2的一个矩阵，输出矩阵。
//思路：按照之前的思路一圈一圈赋值，直到n个元素完毕。然后输出数组vector。
//其中while每一圈上下边界可以+/-count，也可以直接设定l、r、t、d。


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return {};
        vector<vector<int>> flag(n,vector<int>(n,-1));//赋值初始化 flag=-1,其实可以不要flag，while够了
        vector<vector<int>> matrix(n,vector<int>(n,-1));
        int i=0,j=0,k=1,count=0;// i/m   j/n   k/m*n  count 迭代轮数
        while(k<=n*n)
        {
            i=count,j=count;// 每一次循环的初始位置为 c，c
            for(j=0+count;j<n-count;j++) //回旋 按照第一行 最后一列 最后一行 第一列进行
            {
                if(flag[i][j]==-1)
                {
                    matrix[i][j]=k;
                    flag[i][j]=1;
                    k++;
                }
            }
            j--;
            for(i=0+count;i<n-count;i++)
            {
                if(flag[i][j]==-1)
                {
                    matrix[i][j]=k;
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
                    matrix[i][j]=k;
                    flag[i][j]=1;
                    k++;
                }
            }
            j++;
            //cout<<i<<j<<endl;
            for(i=n-1-count;i>=count;i--)
            {
                if(flag[i][j]==-1)
                {
                    matrix[i][j]=k;
                    flag[i][j]=1;
                    k++;
                }
            }
            count++;
        }
        return matrix;
    }
};

/*简洁版的思路： 嗨，就是我的思路，只不过简练了一下。四个l r t b 分别是四个边的边界值
class Solution {
    public int[][] generateMatrix(int n) {
        int l = 0, r = n - 1, t = 0, b = n - 1;
        int[][] mat = new int[n][n];
        int num = 1, tar = n * n;
        while(num <= tar){
            for(int i = l; i <= r; i++) mat[t][i] = num++; // left to right.
            t++;
            for(int i = t; i <= b; i++) mat[i][r] = num++; // top to bottom.
            r--;
            for(int i = r; i >= l; i--) mat[b][i] = num++; // right to left.
            b--;
            for(int i = b; i >= t; i--) mat[i][l] = num++; // bottom to top.
            l++;
        }
        return mat;
    }
}

*/
